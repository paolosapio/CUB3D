# cub3D — ALGO-ALGA

A small 3D exploration game written in C as part of the 42 curriculum. The project combines a raycasting renderer with a custom underwater-inspired scene, animated visual elements, mouse-based camera control, and a map parser for `.cub` files.

> **Screenshots**
>
> Add your own captures to `screenshots/` and replace the filenames below when needed.

| Gameplay | Map and environment |
|:---:|:---:|
| ![Gameplay](screenshots/gameplay.png) | ![Environment](screenshots/environment.png) |
| **Start screen** | **Minimap** |
| ![Start screen](screenshots/start-screen.png) | ![Minimap](screenshots/minimap.png) |

## Features

- **Raycasting renderer.** Casts rays through the map grid to find wall intersections and render a first-person view with directional wall textures.
- **`.cub` map parser.** Reads wall texture paths, floor and ceiling colours, and the map layout; validates the map and the player's starting position before launching the game.
- **Player movement and camera control.** WASD movement, arrow-key rotation, and mouse-look controls.
- **Animated scene.** Includes bubbles, moving environmental elements, animated fauna, and a start-screen sequence.
- **Minimap.** Toggle the map overlay while exploring.
- **Custom visual assets.** Loads textures and image assets for the environment and interface.

## How it works

The game follows a setup-and-render pipeline:

**argument validation → map parsing → resource loading → event loop → raycasting and drawing**

1. **Argument validation and parsing.** The program expects one `.cub` map path. The parser reads the configuration and map, checks the required texture and colour entries, and validates the map boundaries and player spawn.
2. **Resource loading.** The game initialises MLX42, loads the wall textures and scene images, and prepares the map and player state.
3. **Raycasting.** For each screen column, the renderer calculates a ray from the player's position, steps through the map grid until it hits a wall, determines the wall face and texture coordinates, and draws the corresponding vertical wall strip.
4. **Input and updates.** MLX42 hooks process keyboard and mouse input. Movement updates the player's position and view angle, then refreshes the camera and rendered scene.
5. **Animation loop.** A frame loop updates the animated assets, including bubbles and environmental elements, while the game is running.

## Controls

| Input | Action |
|---|---|
| `W` / `A` / `S` / `D` | Move forward, left, backward, and right |
| Mouse movement | Rotate the view |
| `←` / `→` | Rotate the view |
| `Left Shift` | Move forward faster |
| `Tab` | Toggle the map overlay |
| `F` | Toggle the map/info view |
| `Q` / `E` or left/right mouse buttons | Change the character's expression/pose |
| `Enter` | Continue from the start screen |
| `Esc` | Close the overlay or exit the game |

## Map format

Maps are stored in `.cub` files. A map file defines the four wall textures, floor and ceiling colours, and a grid describing walls, open space, and the player's starting direction.

Example configuration:

```text
NO ./textures/north.png
SO ./textures/south.png
WE ./textures/west.png
EA ./textures/east.png
F 80,90,100
C 135,190,220

111111
100001
10N001
100001
111111
```

The configuration keys are:

- `NO`, `SO`, `WE`, `EA`: paths to the north, south, west, and east wall textures.
- `F`: floor RGB colour.
- `C`: ceiling RGB colour.
- `1`: wall; `0`: walkable space; `N`, `S`, `E`, `W`: player spawn and initial viewing direction.

Use one player start position and ensure that walkable areas are enclosed by walls. Several example maps are available in `maps/`.

## Build and run

### Requirements

- A C compiler (`cc`)
- `make`
- CMake
- GLFW
- The dependencies required by [MLX42](https://github.com/codam-coding-college/MLX42)

The repository includes MLX42 as a submodule/vendor directory and a local `libft` implementation. On Debian/Ubuntu, install the system build tools and GLFW development package before compiling.

### Compile

```bash
git clone https://github.com/paolosapio/CUB3D.git
cd CUB3D
make
```

### Run

```bash
./cub3D maps/map.cub
```

Pass exactly one `.cub` file as the argument. Other sample maps can be found in `maps/`.

Available Make targets:

```bash
make        # Build the game
make clean  # Remove object files and clean dependencies
make fclean # Clean and remove the executable
make re     # Rebuild from scratch
```

## Project structure

| Path | Purpose |
|---|---|
| `SRCS/PARSER/` | Reads and validates `.cub` files and map layouts |
| `SRCS/RENDER/` | Raycasting, camera calculations, wall direction and texture drawing |
| `SRCS/LOAD_GAME/` | Initialises the game and loads textures and image assets |
| `SRCS/INPUT_KEYS/` | Keyboard and mouse hooks |
| `SRCS/MOVEMENTS/` | Player movement calculations |
| `SRCS/ANIMATIONS/` | Animation updates and frame loops |
| `SRCS/DRAW_CREATE_IMAGES/` | Creates and draws game images and the map overlay |
| `SRCS/TOOLS_GRAPHICS/` | Graphics utilities, colours and line drawing |
| `SRCS/GNL/` | `get_next_line` implementation used by the parser |
| `INC/` | Main data structures and shared headers |
| `PNG/` | Game artwork and image assets |
| `maps/` | Example `.cub` maps |
| `libft/` | Custom C utility library |
| `MLX42/` | MLX42 graphics library |

## Authors

- [Paolo Sapio](https://github.com/paolosapio)
- [Yolanda Muñoz](https://github.com/anfipatica)


