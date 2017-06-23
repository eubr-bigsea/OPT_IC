#ifndef _STAGE_HPP_
#define _STAGE_HPP_

#include <vector>
#include <iostream>
#include "Helper.hpp"

class Stage
{
public:


    // compute max execution time in a stage, v includes tasks times
    void set_max(const std::vector<help::time_instant>& v);
    // compute min execution time in a stage, v includes tasks times
    void set_min(const std::vector<help::time_instant>& v);
    // compute average execution time in a stage, v includes tasks times
    void set_avg(const std::vector<help::time_instant>& v);


    void set_avg(const unsigned long int a) {avg = a;};

    void set_dependencies(const std::vector<help::id_type>& v);


    const help::id_type get_ID() const {return id_Stage;}

    help::time_instant get_min() const {return min;}

    help::time_instant get_max() const {return max;}

    help::time_instant get_avg() const {return avg;}

    unsigned int get_n_tasks() const {return n_tasks;}

    const std::vector<help::id_type>& get_depend() const {return dependencies;}

    Stage(help::id_type id, unsigned int ntasks): id_Stage(id), n_tasks(ntasks) {}

    void prints() const;

    Stage& operator=(const Stage& stage);

private:
    help::id_type id_Stage;
    help::time_instant max;
    help::time_instant min;
    help::time_instant avg;
  unsigned int n_tasks;
  std::vector<help::id_type> dependencies;

};

#endif
