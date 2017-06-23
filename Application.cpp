#include "Application.hpp"

void Application::set_id(const std::string& id)
{
  id_application = id;
}

void Application::add_job(Job j)
{
  jobs.push_back(j);
}

void Application::add_stage(Stage s)
{
  stages.push_back(s);
}

help::time_instant Application::execution_time_avg() const
{
  //return the approximate execution time_instant
  //this method uses the following formula: sum of wave * stage average time
  help::time_instant sum = 0;
  for(auto s : stages)
  {
    if(s.get_n_tasks() % n_core != 0)
      sum += s.get_avg();

    unsigned coeff = s.get_n_tasks() / n_core;
    sum += coeff * s.get_avg();
  }
  return sum;
}

help::time_instant Application::execution_time_avg(unsigned int n) const
{
  //return the approximate execution time_instant
  //this method uses the following formula: sum of wave * stage average time
  help::time_instant sum = 0;
  for(auto s : stages)
  {
    if(s.get_n_tasks() % n != 0)
      sum += s.get_avg();

    unsigned coeff = s.get_n_tasks() / n;
    sum += coeff * s.get_avg();

  }
  return sum;
}

void Application::print() const
{
  std::cout << "Application name: " << id_application << '\n';
}

void Application::print_job() const
{
  print();
  for(auto j : jobs)
      j.print();
}

void Application::print_stage() const
{
  print();
  for(auto s : stages)
    s.prints();
}

Application& Application::operator=(const Application& app)
{
  id_application = app.get_id_app();
  submission_time = app.get_submission_time();
  deadline = app.get_deadline();
  jobs = app.get_jobs();
  stages = app.get_stages();
  alpha = app.get_alpha();
  beta = app.get_beta();
  n_core = app.get_n_core();
  real_execution_time = app.get_real_execution_time();
  lua_name = app.get_lua_name();
  infr_config_name =app.get_infr_config_name();
  infr_config = app.get_infr_config();

  return *this;
}

void Application::set_alpha_beta(unsigned int n1, unsigned int n2)
{
  if (n1 == n2)
  {
    std::cerr << "n1 = n2" << '\n';
    return;
  }

  help::time_instant r1 = execution_time_avg(n1);
  help::time_instant r2 = execution_time_avg(n2);

  if(n1 > n2)
  {
    alpha = double(r2 - r1) * n1 * n2 / (n1 - n2);
    beta = double(r1) - alpha / n1;
  }
  else
  {
    alpha = double(r1 - r2) * n1 * n2 / (n2 - n1);
    beta = double(r1) - alpha / n1;
  }
}

unsigned int Application::get_n_tasks() const
{
  unsigned int temp = 0;
  for(auto s : stages)
    temp += s.get_n_tasks();

  return temp;
}

unsigned Application::get_max_tasks() const
{
  unsigned max = 0;
  for(auto s : stages)
    if(s.get_n_tasks() > max)
      max = s.get_n_tasks();
      
  return max;
}

void Application::set_lua_name(const std::string& ln)
{
  lua_name = ln;
}

const std::string &Application::get_infr_config_name() const {
  return infr_config_name;
}

void Application::set_infr_config_name(const std::string &infr_config_name) {
  Application::infr_config_name = infr_config_name;
}

const InfrastructureConfiguration &Application::get_infr_config() const {
  return infr_config;
}

void Application::set_infr_config(const InfrastructureConfiguration &infr_config) {
  Application::infr_config = infr_config;
}

const MachineLearningModel &Application::get_mlm() const {
    return mlm;
}

void Application::set_mlm(const MachineLearningModel &ml) {
    Application::mlm = ml;
}
