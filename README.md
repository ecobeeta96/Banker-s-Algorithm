Initial state of the system including the following properties must be taken as user inputs.
• Number of processors n.
• Number of resource types m.
• Available: A vector of length m indicates the number of available resources of each type.
• Max: An n × m matrix defines the maximum demand of each process.
• Allocation: An n × m matrix defines the number of resources of each type currently
  allocated to each process.

Using these user inputs, the program initialize and update following data matrices.
• Need: An n × m matrix indicates the remaining resource need of each process.
• Work and Finish: Vectors of length m and n, respectively. Initially Work = Available
and Finish[i] = false for i = 0, 1, . . . , n – 1.

Using this information,the program check whether the system is in safe mode
or not. If it is in the safe mode, then your program should ask for a process number and
its resource Request and check whether that request can be granted or not.
