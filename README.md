# Bug Description

cmake 3.18.0 has a behaviour change in the Visual Studio generator 
(compared to 3.17.x and earlier) which may cause existing projects to miscompile 
.c files as C++.

# Reproduction

Prerequisites: a Windows machine with Visual Studio 2017 (not tested in other
VStudio versions), and cmake 3.18.0 and cmake 3.17.0

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

