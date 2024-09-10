# COMS4156-demo
## How to build and run tests for C++ code?
### Step 1
 Run the command:
    `cmake -S . -B build` to generate build files.
    From the manual of cmake:
```
    -B <path-to-build>
              Path to directory which CMake will use as the root of build directory.

              If the directory doesn’t already exist CMake will make it.
    
    -S <path-to-source>
              Path to root directory of the CMake project to build.
```
### Step 2
 Execute `cd build && make` <br>
This will build the project using the environment build tools. While building the project, we also run `cpplint` on each file. <br>
Reference: `set(CMAKE_CXX_CPPLINT "cpplint")`

### Step 3
Execute `ctest` in the build directory. This will run all the discovered tests by Cmake and return the output.
