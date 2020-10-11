# C++ algorithm question practice template

This template is inspired by https://github.com/bast/gtest-demo.git

This template allows user to practice algorithm question offline
and check the correctness by running unit test powered by 
[GoogleTest](https://code.google.com/p/googletest)




## How to build and run this demo

prerequisite to run: 
	1. build system (Ninja or make) 
	2. CMake

method 1. execute the bootstrap.sh

At the top directory, execute the command
```
$ ./bootstrap.sh
```
To run test, execute the command
```
$ ./bin/unit_tests
```
or
```
$ ctest
```

method 2. use vscode with CMake Tool (https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)


## References
- https://coveralls.io/r/bast/gtest-demo
