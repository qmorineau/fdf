# FdF - 3D Wireframe Render Engine

## Overview

FdF (Fil de Fer) is a 3D graphic engine developed in C using the MiniLibX library. It transforms coordinate maps into interactive wireframe landscapes.

While FdF is an elective project at 42, this implementation, featuring Stereographic Projections, became a reference among my peers, encouraging many to tackle this graphical project. This project focuses on the intersection of linear algebra and low-level pixel manipulation.

![Earth Rotating gif](https://github.com/user-attachments/assets/b85ad195-1599-43d0-b514-8a17cccfc7c9)

Unlike standard versions of this project, I implemented Stereographic Projection to render spherical bodies. By mapping 2D heightmap data onto a 3D sphere and projecting it back onto a 2D plane, I was able to recreate realistic planetary models with accurate topographic color relief.

## Core Features
* **Multi-Projection System:** Switch instantly between **Isometric**, **Orthographic**, and **Stereographic** views.
* **Real-time Interaction:** Smooth 3-axis rotation, dynamic zooming, translation, altitude scaling and color changing.
* **Performance:** Optimized rendering using **MLX Library**, pushing raw pixels to the screen in a single operation to ensure zero flickering.
* **Adaptive Gradients:** Custom color logic mapped to Z coordinates to simulate realistic terrain and shaders.

## The Math & Constraints
* **Line Rasterization:** Built from scratch using **Bresenham's Algorithm** to draw segments between coordinates.
* **Planetary Mapping:** Transformation of Cartesian coordinates into spherical space using trigonometry to support global projections.
* **Graphic Stack:** Built on top of the minimalist **MiniLibX**.
* **Linear Algebra Pipeline:** Optimized vertex processing by using Matrix Concatenation. Rotation, Scaling, and Translation are combined into a single transformation matrix to minimize floating-point operations per frame.

## Gallery

| Isometric Projection | Stereographic Projection |
| :---: | :---: |
| ![Isometric](https://github.com/user-attachments/assets/fc4fd0f0-662d-42a0-aede-27a837883324) | ![Stereographic](https://github.com/user-attachments/assets/aec846c3-2950-4ff4-be11-c659115b3c47) |
| 42 Object | The Moon |

## Quick Start & Controls


This project is built for Linux/X11. Ensure you have the necessary X11 development libraries installed (libx11-dev, libxext-dev), and Minilibx installed in the repository.


Clone the repository
```bash
git clone https://github.com/qmorineau/fdf.git && cd fdf
```

Setup the library: Place the MiniLibX directory at the root of the project.

Compile and start the program.
```bash
make bonus
./fdf_bonus planet_maps/earth.fdf
```

---
Developed by *Quentin Morineau* (qmorineau) as part of the 42 Common Core.
