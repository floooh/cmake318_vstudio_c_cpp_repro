# Bug Description

cmake 3.18.0 has a behaviour change in the Visual Studio generator 
(compared to 3.17.x and earlier) which may cause existing projects to miscompile
.c files as C++ in projects that contain both C and C++ source files.

# Reproduction

## Prerequisites

A Windows machine with Visual Studio 2017 (not tested in other
VStudio versions), plus cmake 3.18.0 and cmake 3.17.0.

Clone the project and prepare two separate build directories:

```
> git clone https://github.com/floooh/cmake318_vstudio_c_cpp_repro
> cd cmake cmake318_vstudio_c_cpp_repro
> mkdir build_318
> mkdir build_317
```

## To reproduce the faulty behaviour (use cmake 3.18.0)

```
> cmake --version
cmake version 3.18.0
...
> cd build_318
> cmake ..
> cmake --build .
> Debug\bug.exe
!!!BUG!!! main.c is compiled as C++!
```

## To reproduce the previous correct behaviour (use cmake 3.17.0)

```
> cmake --version
cmake version 3.17.0
...
> cd build_317
> cmake ..
> cmake --build .
> Debug\bug.exe
OK: main.c is compiled as C.
```

## More Info

The problem seems to happen when the following C and C++ flags are set, AND
a project contains both C and C++ files.

```cmake
set(CMAKE_CXX_FLAGS "/TP")
set(CMAKE_C_FLAGS "/TC")
```

In such a situation, cmake 3.17 explicitely tells Visual Studio to compile
the main.c file as C (from the generated bug.vcxproj):

```xml
    <ClCompile Include="E:\projects\cmake318_vstudio_c_cpp_repro\main.c">
      <CompileAs Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">CompileAsC</CompileAs>
      <CompileAs Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">CompileAsC</CompileAs>
      <CompileAs Condition="'$(Configuration)|$(Platform)'=='MinSizeRel|Win32'">CompileAsC</CompileAs>
      <CompileAs Condition="'$(Configuration)|$(Platform)'=='RelWithDebInfo|Win32'">CompileAsC</CompileAs>
    </ClCompile>
```

In cmake 3.18 the ```CompileAsC``` is missing:

```xml
    <ClCompile Include="E:\projects\cmake318_vstudio_c_cpp_repro\main.c" />
```

...which in turn causes Visual Studio to compile this file as C++ (which seems to be triggered
by having both C and C++ files in the same project).

However this behaviour seems to be triggered by the presence of those command line options:

```cmake
set(CMAKE_CXX_FLAGS "/TP")
set(CMAKE_C_FLAGS "/TC")
```

...which in turn looks like cmake 3.18 classifies the main.c file as C++?

(this is where I stopped investigating deeper)
