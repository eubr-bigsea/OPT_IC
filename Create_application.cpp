#include "Create_application.hpp"

Application c_app::create_app(const std::string& name_of_file)
{
  Application app;

  // the file name_of_file is open and read
  std::ifstream ifs{name_of_file};
  if(!ifs)
  {
    std::cerr << '\n' << name_of_file << " not found!" << std::endl;
    return app;
  }

  std::string ap, job, st, taskk, line, deadline, lua, infr_config;
  getline(ifs, line);
  std::istringstream iss(line);
  iss >> ap >> job >> st >> taskk >> lua >> infr_config >> deadline;

  // we add the path of the correct directories
  help::add_data_dir(ap);
  help::add_data_dir(job);
  help::add_data_dir(st);
  help::add_data_dir(taskk);
  help::add_data_dir(infr_config);
  help::add_lua_dir(lua);

  std::vector<std::string> file_names;
  file_names.push_back(ap);
  file_names.push_back(job);
  file_names.push_back(st);
  file_names.push_back(taskk);
  file_names.push_back(infr_config);
  file_names.push_back(deadline);

  // we set the data about the app
  typedef std::vector<std::vector<std::string>> read_type;
  read_type temp;

  const std::string& file_name = file_names[0];
  help::create_vector(file_name, temp);

  app.set_lua_name(lua);
  app.set_id(temp[1][0]);
  app.set_submission_time(0);
  app.set_infr_config_name(infr_config);
  app.set_deadline(std::stoul(file_names[5]));
  app.set_n_core(1);
  help::time_instant ret = std::stoul(temp[2][1]) - std::stoul(temp[1][1]);
  app.set_real_execution_time(ret);

  // we set the data about the jobs
  std::map<help::id_type, unsigned long int> sub_time, compl_time;
  std::map<help::id_type, std::vector<help::id_type> > id_stages;

  read_type temp1;
  help::create_vector(file_names[1], temp1);

  help::id_type id;
  unsigned long int sub, comp;

  for(unsigned i = 1; i < temp1.size(); i++)
  {
    unsigned sz = temp1[i].size();
    id = std::atoi(temp1[i][0].c_str());

    if(temp1[i][1] != "NOVAL")
    {
      sub = std::stoul(temp1[i][1]);
      sub_time.insert({id, sub});
    }

    if (temp1[i][sz - 1] != "NOVAL")
    {
     // auto tempDanilo = temp1[i][sz - 1];
      comp = std::stoul(temp1[i][sz - 1]);
      compl_time.insert({id, comp});
    }

    std::vector<help::id_type> vec;
    for(unsigned j = 2; j < sz - 1; j++)
      vec.push_back(help::read_id(temp1[i][j]));

    id_stages.insert({id, vec});
  }

  for(auto it : sub_time)
  {
    Job job_temp(it.first, temp[1][0],  it.second, compl_time.find(it.first)->second);
    job_temp.set_id_stages(id_stages.find(it.first)->second);
    app.add_job(job_temp);
  }

  // we set the data about stages
  read_type temp2;
  help::create_vector(file_names[2], temp2);

  unsigned int task;
  for (unsigned i = 1; i < temp2.size(); i++)
  {
    unsigned sz = temp2[i].size();
    id = std::atoi(temp2[i][0].c_str());
    task = std::atoi(temp2[i][3].c_str());
    Stage stage_temp(id, task);
    std::vector<help::id_type> vec;

    if(!help::check_empty(temp2[i][2]))
      for(unsigned j = 2; j < sz-3; j++)
        vec.push_back(help::read_id(temp2[i][j]));

    stage_temp.set_dependencies(vec);
    app.add_stage(stage_temp);
  }

  // we set the data about the stasks
  help::time_instant diff;
  unsigned long int launch, finish;
  help::id_type id_stage;
  read_type temp3;

    // Trasformare in mappa di vector di time instant
  //std::vector<std::vector<Job::time_instant>> tasks(app.get_num_stages());
    std::map<help::id_type,std::vector<help::time_instant>>tasks;
  help::create_vector(file_names[3], temp3);

  for(unsigned i = 1; i < temp3.size(); i++)
  {
   /* if (i==25770){
      std::cout<< '\n' << temp3[i][4]<<std::endl;
      std::cout<< temp3[i][5]<<std::endl;
      std::cout<< std::atoi(temp3[i][16].c_str())<<std::endl;
      std::cout<< temp3.size() <<std::endl;
      std::cout<< tasks.size() <<std::endl;

    }*/
    launch = std::stoul(temp3[i][4]);
    finish = std::stoul(temp3[i][5]);
    id_stage = std::atoi(temp3[i][16].c_str());
    diff =  finish - launch;
    tasks[id_stage].push_back(diff);
  }

  for(auto i = app.modify_stages().begin(); i != app.modify_stages().end(); i++)
  {
    unsigned n = i->get_ID();
    i->set_max(tasks[n]);
    i->set_min(tasks[n]);
    i->set_avg(tasks[n]);
  }

  // Read configuration file

  std::ifstream ifs_config{file_names[4]};

  if(!ifs_config)
  {
    std::cerr << '\n' << file_names[4] << " not found!" << std::endl;
    return app;
  }


  getline(ifs_config, line);
  getline(ifs_config, line);
  std::istringstream iss_config(line);
  std::string app_id, chi_0, chi_c, container_memory, executor_memory, container_cores, executor_cores;
  iss_config >> app_id >> chi_0 >> chi_c >> container_memory >> executor_memory >> container_cores >> executor_cores;

  std::cout << '\n' << " Optimizing configuration" << std::endl;
  std::cout << app_id << " " << " " << chi_0 << " "
            << chi_c << " " << container_memory << " "
            << executor_memory << " "<< container_cores << " " << executor_cores;


  InfrastructureConfiguration ic(atof(container_memory.c_str()) , atof(executor_memory.c_str()), atoi(container_cores.c_str()), atoi(executor_cores.c_str()));

  //ic.print();

    MachineLearningModel mlm(atof(chi_0.c_str()), atof(chi_c.c_str()));

  app.set_infr_config(ic);
    app.set_mlm(mlm);


    mlm.print();

  //app.get_infr_config().print();


  return app;
}
