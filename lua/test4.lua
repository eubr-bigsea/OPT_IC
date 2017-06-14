-- DAG definition: it is encoded as an array of stages.
Stages = {{ name="J1S1", tasks="2", distr={type="replay", params={samples=solver.fileToArray("./lua/test4/J1S1.txt")}}, pre={}, post={"J3S3","J3S4"}},{ name="J0S0", tasks="2", distr={type="replay", params={samples=solver.fileToArray("./lua/test4/J0S0.txt")}}, pre={}, post={"J3S3","J3S4"}},{ name="J3S3", tasks="500", distr={type="replay", params={samples=solver.fileToArray("./lua/test4/J3S3.txt")}}, pre={"J1S1","J0S0","J2S2"}, post={"J3S5"}},{ name="J2S2", tasks="2", distr={type="replay", params={samples=solver.fileToArray("./lua/test4/J2S2.txt")}}, pre={}, post={"J3S3","J3S4"}},{ name="J3S5", tasks="200", distr={type="replay", params={samples=solver.fileToArray("./lua/test4/J3S5.txt")}}, pre={"J3S3","J3S4"}, post={"J3S6"}},{ name="J3S4", tasks="500", distr={type="replay", params={samples=solver.fileToArray("./lua/test4/J3S4.txt")}}, pre={"J1S1","J0S0","J2S2"}, post={"J3S5"}},{ name="J3S6", tasks="200", distr={type="replay", params={samples=solver.fileToArray("./lua/test4/J3S6.txt")}}, pre={"J3S5"}, post={}}};

-- Number of computation nodes in the system
Nodes = @@nodes@@;

-- Number of users accessing the system
Users = 1;

-- Distribution of the think time for the users
UThinkTimeDistr = {type = "exp", params = {rate = 0.001}};

-- Total number of jobs to simulate
maxJobs = 1000;

-- Coefficient for the Confidence Intervals
confIntCoeff = 1.96;
