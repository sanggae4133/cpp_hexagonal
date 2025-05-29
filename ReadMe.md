# C++ Hexagonal Project Template

This is a template for a C++ project that follows the hexagonal architecture pattern. It is designed to be easily extensible and maintainable, with a focus on separation of concerns.

## Features
- Hexagonal architecture
- CMake build system
- CLI Controller
- Simple HTTP Server & Controller
- File System Database
- Create, Read, Delete (CRD) operations in User Data

## Platform Support
- Linux

## Compiler Support
- Upper GCC 8.x.x
- c++ 17 or higher

## Dependencies
- CMake
- GCC

## Usage
1. Clone the repository:
   ```bash
   git clone
   ```
2. Navigate to the project directory:
   ```bash
    cd cpp_hexagonal
    ```
3. Create a build directory:
    ```bash
   mkdir build && cd build
   ```
4. Run CMake to configure the project:
   ```bash
    cmake ..
    ```
5. Build the project:
    ```bash
   cmake --build .
   ```
6. Run the application:
   ```bash
   cd src/main
   ./CppHexagonal
   ```
   
## How to check data file(file system database)
   ```bash
   cd build/src/data
   cat users.csv
   ```
   
## License
This project is licensed under the MIT License.
```text
The MIT License (MIT)

Copyright (c) <year> <copyright holders>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of the X Consortium shall not be used in advertising or otherwise to promote the sale, use or other dealings in this Software without prior written authorization from the X Consortium.

X Window System is a trademark of X Consortium, Inc.
```
