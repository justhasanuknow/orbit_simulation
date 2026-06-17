# C++ Planet Simulation

A small C++ learning project that renders a simple orbital planet simulation with [raylib](https://www.raylib.com/) and CMake.

The goal of this repository is not to build a physically perfect astronomy simulator. It is a hands-on project for practicing C++ fundamentals through a visual, game-development-style codebase: classes, encapsulation, coordinates, entity collections, rendering, animation, and basic input handling.

## Current Features

- A raylib window that renders the Sun and planets.
- Planets are created dynamically with their own:
  - name
  - gravity modifier
  - screen position
  - diameter
  - color
  - orbit radius and speed
- Planets orbit around the Sun using simple `sin` / `cos` based circular motion.
- Orbit paths are drawn on screen.
- A basic speed slider controls the simulation speed at runtime.
- Project is organized into small C++ classes for simulation, rendering helpers, coordinates, planets, and planet collections.

## Project Structure

```text
.
|-- CMakeLists.txt
|-- build.sh
|-- README.md
`-- src/
    |-- main.cpp
    |-- core/
    |   `-- simulation/
    |-- entities/
    |   |-- planet/
    |   `-- planet_collection/
    |-- helpers/
    |   `-- raylib/
    `-- utils/
        `-- coordinates/
```

## Requirements

- CMake 3.14+
- A C++17 compatible compiler
- Bash
- Internet access on the first configure step, because CMake fetches raylib with `FetchContent`

## Build and Run

Use the helper script from the project root:

```bash
./build.sh
```

Clean and rebuild from scratch:

```bash
./build.sh clean
```

The script configures CMake, builds the project, and then runs the executable.

## Manual Build

If you prefer running the commands yourself:

```bash
cmake -S . -B build
cmake --build build -j$(nproc)
./build/main
```

## Learning Goals

This project is a playground for improving C++ and game-development fundamentals:

- Modeling data with classes and structs
- Separating responsibilities across files and modules
- Passing objects between systems
- Using smart pointers and collections
- Building with CMake
- Rendering with raylib
- Updating objects over time with a game loop
- Handling simple UI input

## Notes

The orbital values are intentionally scaled for readability on screen. Planet sizes, distances, and speeds are not real-world accurate; they are tuned to make the simulation easy to see and useful for learning.
