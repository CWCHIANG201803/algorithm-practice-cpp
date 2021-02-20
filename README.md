# C++ algorithm question practice template

This template is inspired by https://github.com/bast/gtest-demo.git

This template allows user to practice algorithm question offline
and check the correctness by running unit test powered by 
[GoogleTest](https://code.google.com/p/googletest)


## Prerequisite to execute this tempalte
	1. operating system: Windows, Ubuntu 16.04LTS, or MACOS BigSur 11.1
	2. C++ standard : C++ 17 or above
	3. shell script : 
		(1) Unix-like : bash 4.x
		(2) windows : mintty 3.2.0
	4. cross-platform build system : cmake 3.16 or above
	5. generator : GNU make or Ninja 
	6. GUI : vscode. some extensions will be helpful:
		(1) cmake tools
		(2) MS C/C++
	7. compiler : GNU C++ 10.x or CLANG 10.x 



## How to start this template?

method 1 - run via terminal
step 1. build the project
At the root directory, run
```
$ ./build.sh
```

step 2. execute the target
To execute main, at the root directory, run
```
$ ./run.sh
```

To execute unit test, at the root directory, run
```
$./run.sh test
```

method 2 - run via vscode
	please refer https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools


## References
- https://coveralls.io/r/bast/gtest-demo

