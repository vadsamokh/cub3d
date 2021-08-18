# cub3d

**A project of School 21.**

In this project i had to make a 3D graphical representation of the inside of a maze from a first-person perspective.
This project is inspired by **Wolfenstein 3D** game  and uses raycasting technology to draw all necessary objects.

Installation:

```
$ git clone https://github.com/vadsamokh/cub3d && cd cub3d && make
```

Launch:

```
$ ./cub3d map.cub
```

# Configuration file

**map.cub** is a configuration file, where all necessary settings are represented. You are free to edit it as you want.

Here is the list of all settings:

R - resolution;

NO - path to the North wall texture;

SO - path to the South wall texture;

WE - path to the West wall texture;

EA - path to the East wall texture;

S - path to the sprite texture;

F - floor color <R,G,B>

C - ceiling color <R,G,B>

Map field: 1 - wall, 2 - sprite, 0 - free space for walking.

N (or S / W / E) - starting player position and direction, in which he looks.

The map must be located after all other settings in configuration file.

All free spaces (0), sprites (2) and player position (N/S/W/E) must be surrounded by walls (1).

# Control

W, A, S, D - move.

Left/right arrows - turn.
