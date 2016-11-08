# CommonUtils
These are a few common utilities that I use on daily basis for cross platform development. 

They do not require dependencies on any other library and should work with any C++11 compliant compiler (only tested with MinGW, GCC though).

**Build**

* mkdir build
* cd build
* cmake ..
* make -j 4

**Note:** The top-level CMakeLists.txt defines a few commands for storing build output (DLL's / EXE's) into the parent's folder bin.  

This will automatically be created if it does not exist.

**Project Layout**

This project uses a very simple structure utilizing the CMake build system.  
At the top level there are two folders: **common** and **products** as well as a CMakeLists.txt file.
* The common folder should contain only libraries/source that is shared among other common libraries **OR** with projects in the products folder.
* The products folder should contain deliverables/executables **OR** non-generic libraries that support deliverables/executable projects.

**Common libraries should never reference or depend on a project/library in the products folder.  Enforcing this rule ensures that projects remain simple and dependency hell can be avoided.**

Each project should be stored in its own folder and by default should contain an **inc** folder, a **src** folder and a **CMakeLists.txt** file describing the project. 

Other folders that may exist in the project folder include:
* docs - for documenentation related to the project or its source files
* resx - resources (images, audio, video, xml,etc) that are needed by the project
* tests - sub project containing unit tests for each class/module in the parent project
* contrib - sub folder containing 3rd party library used by parent project. I choose contrib/3rd party libraries based on the rating below (Ideally I want Best or Better):
    - **Best**: Simple Self-contained .hpp file(s) that can be included directly
    - **Better**: 3rd party project that already uses CMake
    - **Bad**: Precompiled DLLs or static libraries with Headers
    - **Worst**: Complicated project with weird build system that does not compile

**TODO**
I am adding more unit tests for each of the methods in CommonUtils

