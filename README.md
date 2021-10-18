# Raytracer

This project is a derivative work of Raytracing in One Weekend, done in ANSI C. The formatting style tries to stick as much as it possibly can to ANSI C standards, particularly by using ```std=c99``` and ```-pedantic``` compiler flags.

## Compilation Directions
- Make a local clone of the repository through ```git clone https://github.com/poal023/raytraCer```
- If make is not installed on your machine, you can install it on either Windows using Chocolatey (```choco install make```) or on Debian-based systems through ```sudo apt install make```
- Run the makefile through ```make``` while in the ```src/``` directory. 

## Navigating the Repository

All .c and .h source files are stored in the ```src/``` directory, while example images will be stored in ```examples/```.

## Changes

Although this project will follow Raytracing in One Weekend to an extent, it also aims to build off of it by adding in more features such as triangle/polygonal objects, textures, lighting, exportation through JPEG and much more.

## Output Examples

![Example 1](examples/Example1.jpg?raw=true)
![Example 2](examples/Example2.jpg?raw=true)
