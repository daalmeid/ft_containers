# ft_containers - Under the hood of C++'s STL

This project's main goal was to recode a few templates from the Standard Template Library (vector, map, stack).

## Objectives
* Understand the usage and capabilities of these containers;
* Learn to create and implement complex data structures (dynamic arrays, AVL trees);
* Deepen the knowledge of template usage and data type-related operations.

## What you can do with this repo

Tests were created for all of the member functions of the created templates and will print out the results.
Use the following code after cloning the repo and getting inside of it:  
` make && make test `
the first *make* will create the executables (one with my templates and the other with the original files), while
*make test* will redirect their output to separate files (called **ft** and **stl**). You can follow that with the usage of ` diff ft stl `
to check differences in the outputs.  
**NOTE:** A few tests cause intentional segmentation fault to check if the error is the same in both executables, however, to use them,
you need to remove the comment inside the test files.

## Use as tester

If you decide to do this project, feel free to use my tests. To do so, just substitute my container header files for yours inside the *header_ft/* directory
WITHOUT erasing the *containers.hpp* header. Also, don't forget to put all your utils headers in the *utils/* directory. Have fun! :grinning:
