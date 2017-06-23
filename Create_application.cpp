/*
Copyright 2017 Andrea Vescovini
Copyright 2017 Sara Zaninelli
Copyright 2017 Biagio Festa <biagio.festa@gmail.com>

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <utility>
#include "Create_application.hpp"
#include "Job.hpp"

Application c_app::create_app(const std::string& name_of_file) {
  Application app;

  // the file name_of_file is open and read
  std::ifstream ifs{name_of_file};
  if (!ifs) {
    std::cerr << '\n' << name_of_file << " not found!" << std::endl;
    exit(-1);
  }

  // Read the line of the file in order to get all app informations
  std::string file_line;

  getline(ifs, file_line);

  // Tokenize the line and get app information in raw strings
  std::istringstream iss(file_line);
  std::string ap, job, st, taskk, lua, infr_config;
  std::string deadline_str;
  iss >> ap >> job >> st >> taskk >> lua >> infr_config >> deadline_str;

  if (deadline_str.empty()) {
    std::cerr << '\n'
              << "The file '" << name_of_file
              << "' does not contain all informations\n";
    exit(-1);
  }

  // we add the path of the correct directories
  help::add_data_dir(ap);
  help::add_data_dir(job);
  help::add_data_dir(st);
  help::add_data_dir(taskk);
  help::add_data_dir(infr_config);
  help::add_lua_dir(lua);

  // Parse deadline string into number
  const auto deadline = std::stoul(deadline_str);

  // Construct a map with all needed filepaths
  std::map<std::string, std::string> file2filename;
  file2filename["application_file"] = std::move(ap);
  file2filename["jobs_file"] = std::move(job);
  file2filename["stages_file"] = std::move(st);
  file2filename["tasks_file"] = std::move(taskk);
  file2filename["lua_file"] = std::move(lua);
  file2filename["configuration_file"] = std::move(infr_config);

  // Read type is a matrix of string
  // This type is useful in order to read and parse files as CSV
  using read_type = std::vector<std::vector<std::string>>;

  // Set some informations in the application object
  app.set_lua_name(file2filename.at("lua_file"));
  app.set_submission_time(0);
  app.set_infr_config_name(file2filename.at("configuration_file"));
  app.set_deadline(deadline);
  app.set_n_core(1);

  // Parse the application file
  read_type reader_appfile;
  help::create_vector(file2filename.at("application_file"), reader_appfile);

  // Set the application id as the second row, first column of applicaton file
  const auto application_id = reader_appfile.at(1).at(0);
  app.set_id(application_id);

  // Get the duration of application as time different and set in app object
  const auto app_time_start = std::stoul(reader_appfile.at(1).at(1));
  const auto app_time_stop = std::stoul(reader_appfile.at(2).at(1));
  help::time_instant ret = app_time_stop - app_time_start;
  app.set_real_execution_time(ret);

  // Parse the jobs file
  read_type jobsfile_data;
  help::create_vector(file2filename.at("jobs_file"), jobsfile_data);

  // Well-organized data structure from jobs file
  std::map<help::id_type, unsigned long int> sub_time, compl_time;
  std::map<help::id_type, std::vector<help::id_type> > id_stages;

  // Fill the data structures of jobs file (for each row in jobs file)
  for (unsigned row_index = 1; row_index < jobsfile_data.size(); ++row_index) {
    // Get the current row
    const auto& row = jobsfile_data.at(row_index);

    const unsigned number_of_cols = row.size();

    // Get the job id at the current row
    const help::id_type job_id = std::stoi(row.at(0));

    // Get the submission_time
    const auto& submission_time_str = row.at(1);
    if (submission_time_str != "NOVAL") {
      const auto submission_time = std::stoul(submission_time_str);
      sub_time.insert(std::make_pair(job_id, submission_time));
    }

    // Get the completion time (as last field in row)
    const auto& completion_time_str = row.at(number_of_cols - 1);
    if (completion_time_str != "NOVAL") {
      const auto completion_time = std::stoul(completion_time_str);
      compl_time.insert(std::make_pair(job_id, completion_time));
    }

    // Get the stage dependency of the job
    std::vector<help::id_type> stageIDs;
    for (unsigned col_index = 2; col_index < number_of_cols - 1; ++col_index) {
      auto col = row.at(col_index);
      auto stage_id = help::read_id(col);
      stageIDs.push_back(std::move(stage_id));
    }
    id_stages.insert(std::make_pair(job_id, std::move(stageIDs)));
  }  // for all row in jobs file

  // Insert all jobs into the application object
  for (const auto& it : sub_time) {
    const auto& job_id = it.first;
    Job job_temp(job_id,                            // job id
                 application_id,                    // application id
                 it.second,                         // sub time
                 compl_time.find(job_id)->second);  // completion time

    job_temp.set_id_stages(id_stages.find(job_id)->second);

    app.add_job(std::move(job_temp));
  }  // for all submission times


  // Parse the stages file
  read_type stagesfile_data;
  help::create_vector(file2filename.at("stages_file"), stagesfile_data);

  // Fill the data structures of stages file (for each row in stages file)
  for (unsigned row_index = 1; row_index < stagesfile_data.size();
       ++row_index) {
    // Get the current row
    const auto& row = stagesfile_data.at(row_index);
    const auto number_of_cols = row.size();

    // Get the stage id at the current row
    const help::id_type stage_id = std::stoi(row.at(0));

    const unsigned number_of_tasks = std::stoi(row.at(3));

    // Create stage object
    Stage stage_temp(stage_id, number_of_tasks);

    // Parse stage dependencies
    std::vector<help::id_type> parentIDs;
    const auto& parents_str = row.at(2);
    if (!help::check_empty(parents_str)) {
      for (unsigned col_index = 2; col_index < number_of_cols - 3;
           ++col_index) {
        auto col = row.at(col_index);
        auto parent_id = help::read_id(col);
        parentIDs.push_back(std::move(parent_id));
      }
    }
    stage_temp.set_dependencies(parentIDs);
    app.add_stage(std::move(stage_temp));
  }  // for each row in stages file

  // Parse the tasks file
  read_type tasksfile_data;
  help::create_vector(file2filename.at("tasks_file"), tasksfile_data);

  // Map a ID stage with a execution times of stage2tasks
  std::map<help::id_type,std::vector<help::time_instant>> stage2tasks;

  // Fill the data structures of task file (for each row in task file)
  for (unsigned row_index = 1; row_index < tasksfile_data.size(); ++row_index) {
    // Get the current row
    const auto& row = tasksfile_data.at(row_index);

    // Get task information
    const unsigned long launch_time = std::stoul(row.at(4));
    const unsigned long finish_time = std::stoul(row.at(5));
    const help::id_type id_stage = std::stoi(row.at(16));
    const auto execution_time = finish_time - launch_time;
    stage2tasks[id_stage].push_back(execution_time);
  }

  // Update stages of application with the max min a avg task
  for (auto& stage : app.modify_stages()) {
    const auto stage_id = stage.get_ID();
    stage.set_max(stage2tasks.at(stage_id));
    stage.set_min(stage2tasks.at(stage_id));
    stage.set_avg(stage2tasks.at(stage_id));
  }

  // Read the configuration file
  std::ifstream ifs_config{file2filename.at("configuration_file")};
  if(!ifs_config) {
    std::cerr << '\n' << file2filename.at("configuration_file")
              << " not found!" << std::endl;
    return app;
  }

  // Read the second line (skip the first line -header-)
  std::string configfile_line;
  getline(ifs_config, configfile_line);
  getline(ifs_config, configfile_line);

  // Parse the line saving parameters
  std::istringstream iss_config(configfile_line);
  std::string app_id, chi_0, chi_c, container_memory, executor_memory,
      container_cores, executor_cores;
  iss_config >> app_id >> chi_0 >> chi_c >> container_memory >>
      executor_memory >> container_cores >> executor_cores;

  // Print on the standard output
  std::cout << '\n' << " Optimizing configuration" << std::endl;
  std::cout << app_id << " "
            << " " << chi_0 << " " << chi_c << " " << container_memory << " "
            << executor_memory << " " << container_cores << " "
            << executor_cores;

  InfrastructureConfiguration ic(std::stof(container_memory),
                                 std::stof(executor_memory),
                                 std::stoul(container_cores),
                                 std::stoul(executor_cores));

  MachineLearningModel mlm(std::stof(chi_0), std::stof(chi_c));

  // Set infrastructure configuraiton and ML into the application object
  app.set_infr_config(ic);
  app.set_mlm(mlm);

  mlm.print();

  return app;
}
