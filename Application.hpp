#ifndef _APPLICATION_HPP_
#define _APPLICATION_HPP_

#include "Job.hpp"
#include "Helper.hpp"
#include "Stage.hpp"
#include "InfrastructureConfiguration.hpp"
#include "MachineLearningModel.hpp"


#include <vector>
#include <string>
#include <iostream>

class Application
{
  std::string id_application;
  std::vector<Job> jobs;
  std::vector<Stage> stages;

  std::string lua_name;

    std::string infr_config_name;

  help::time_instant submission_time;
  help::time_instant deadline;
  help::time_instant real_execution_time;

  double alpha;
  double beta;
  unsigned int n_core;


    InfrastructureConfiguration infr_config;
    MachineLearningModel mlm;

public:
  Application() = default;

  std::vector<Stage>& modify_stages() {return stages;}
  const std::vector<Stage>& get_stages() const {return stages;}
  const std::vector<Job>& get_jobs() const {return jobs;}
  unsigned int get_n_core() const {return n_core;}

  void add_job(Job);
  void add_stage(Stage);

  unsigned int get_num_stages() const {return stages.size();}
  help::time_instant get_submission_time() const {return submission_time;}
  help::time_instant get_deadline() const {return deadline;}
  std::string get_id_app()const {return id_application;}

  help::time_instant execution_time_avg() const;
  help::time_instant execution_time_avg(unsigned int) const;
  double get_alpha() const { return alpha;}
  double get_beta() const {return beta;}
  help::time_instant get_real_execution_time() const {return real_execution_time;}
  unsigned int get_n_tasks() const;
  unsigned get_max_tasks() const;
  std::string get_lua_name() const { return lua_name;}

  void set_id(const std::string& );
  void set_n_core(const unsigned int c) { n_core = c;}
  void set_submission_time(help::time_instant sub) {submission_time = sub;}
  void set_deadline(help::time_instant dead) {deadline = dead;}
  void set_real_execution_time(help::time_instant ret) {real_execution_time = ret;}
  void set_alpha_beta(unsigned int, unsigned int);
  void set_alpha(const double a) { alpha = a; }
  void set_beta(const double b) { beta = b; }
  void set_lua_name(const std::string&);

    const InfrastructureConfiguration &get_infr_config() const;

    void set_infr_config(const InfrastructureConfiguration &infr_config);

    const std::string &get_infr_config_name() const;

    void set_infr_config_name(const std::string &infr_config_name);

    const MachineLearningModel &get_mlm() const;

    void set_mlm(const MachineLearningModel &ml);

    void print() const;
  void print_job() const;
  void print_stage() const;
  void print_ret() const { std::cout << "ret: "<< real_execution_time << '\n';}

  Application& operator=(const Application&);
};

#endif
