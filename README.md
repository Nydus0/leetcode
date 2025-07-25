# leetcode
Solving leetcode problems.
In some cases solutions do not work on leetcode compiler (due to a use of c++20 features, such as std::ranges and views)

Actual tests are regrouped in this internet page : https://neetcode.io/

## Build Instructions
This project uses [CMake](https://cmake.org/) for compilation.  
It generates a library from the directory **solutions**.

## Running Tests
Test suite uses the [GoogleTest](https://github.com/google/googletest) framework (automatically downloaded via CMake when building).  
Run Cmake target "tests".

## License
This project is licensed under the [GNU General Public License v3.0](https://www.gnu.org/licenses/gpl-3.0.html).  
By using or modifying this code, you agree to release any derivative work under the same license.