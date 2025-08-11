# 🧭 cub3d

**Tiny Wolf3D‑style ray‑casting engine in C (MiniLibX)** — parses `.cub` maps, renders textured walls with floor/ceiling colors, FOV & collision. Built as part of the **École 42** curriculum.

---

## 📑 Table of Contents

1. [Overview](#overview)
2. [Features](#features)
3. [Installing MiniLibX](#installing-minilibx)
4. [Directory Structure](#directory-structure)
5. [Build](#build)
6. [Usage](#usage)
7. [Map Format (.cub)](#map-format-cub)
8. [Controls](#controls)
9. [Rendering Notes](#rendering-notes)
10. [Troubleshooting](#troubleshooting)
11. [Project Context](#project-context)

---

<a id="overview"></a>

## ✨ Overview

`cub3d` implements a simple **ray‑casting** renderer reminiscent of Wolfenstein 3D.
It loads configuration and a 2D map from a `.cub` file, sets up textures and colors, and renders a first‑person view in real time with keyboard/mouse controls.

---

<a id="features"></a>

## ⚙️ Features

* **Ray‑casting** with per‑column DDA and **wall texturing**.
* **Config file** (`.cub`) describing textures for each wall orientation and floor/ceiling colors.
* **Player spawn** (`N/S/E/W`) and **collision** against map walls.
* **Minimap** (optional), **FOV** and **movement speed** tuning.
* Robust **parsing** (errors with line/column), and **resource cleanup** (no leaks).

---

<a id="installing-minilibx"></a>

## 🛠️ Installing MiniLibX

### macOS (Homebrew)

```bash
brew install mlx
```

Then link with: `-lmlx -framework OpenGL -framework AppKit`.

### Ubuntu/Debian (minilibx-linux)

```bash
sudo apt-get update
sudo apt-get install -y libxext-dev libx11-dev libbsd-dev
# Option A: use system package (if available)
# sudo apt-get install -y minilibx
# Option B: build the official 42 fork
git clone https://github.com/42Paris/minilibx-linux.git external/minilibx-linux
make -C external/minilibx-linux
# Optionally install system-wide (needs sudo):
# sudo make -C external/minilibx-linux install
```

Typical Linux link flags: `-lmlx -lXext -lX11 -lm -lz`.

If your project uses **MLX42** instead, adapt includes and link flags accordingly (`-lglfw` on Linux).

---

<a id="directory-structure"></a>

## 🗂️ Directory Structure

```text
cub3d/
├── include/           # headers (cub3d.h, parser.h, render.h, mlx wrappers)
├── libft/             # embedded libft (static library)
├── src/
├── textures/            # textures (.xpm)
├── map/                # sample maps
├── mlx/                # graphics library
├── Makefile
└── README.md          # you are here
```

---

<a id="build"></a>

## 🚀 Build

```bash
# Clone repository
git clone https://github.com/<your-username>/cub3d.git
cd cub3d

# Build (expects MiniLibX available)
make                # produces ./cub3d
```

If MiniLibX is in a non‑standard location, pass custom paths/flags (example):

```bash
make MLX_PATH=/usr/local/lib MLX_INC=/usr/local/include MLX_LIBS="-lmlx -lXext -lX11 -lm -lz"
```

Clean targets:

```bash
make clean          # remove objects
make fclean         # remove objects + binaries + libs
make re             # full rebuild
```

---

<a id="usage"></a>

## 📚 Usage

```bash
./cub3d path/to/map.cub
```

Example:

```bash
./cub3d assets/maps/basic.cub
```

On error (bad path/color/map), the program exits with a non‑zero status and a clear message.

---

<a id="map-format-cub"></a>

## 🗺️ Map Format (.cub)

A `.cub` file contains **texture paths**, **floor/ceiling colors**, and the **map layout**.

**Header (order may vary):**

```
NO ./assets/textures/wall_north.xpm
SO ./assets/textures/wall_south.xpm
WE ./assets/textures/wall_west.xpm
EA ./assets/textures/wall_east.xpm
F  220,100,0        # floor color  (R,G,B)
C  225,30,0         # ceiling color (R,G,B)
```

**Map (last block):**

```
1111111111
1000000001
1000111001
10N0000001   # player start (N/S/E/W)
1111111111
```

Rules:

* Map must be **closed** by walls (`1`).
* `0` = empty space, `1` = wall, `N/S/E/W` = spawn with facing.
* Only one spawn character allowed.
* Paths typically point to **XPM** images (MiniLibX classic).

---

<a id="controls"></a>

## 🎮 Controls

| Key                | Action                   |
| ------------------ | ------------------------ |
| `W` / `S`          | Move forward / backward  |
| `A` / `D`          | Strafe left / right      |
| `←` / `→`          | Rotate view left / right |
| `ESC`              | Quit                     |

Speeds/FOV can be adjusted via constants or config depending on your implementation.

---

<a id="rendering-notes"></a>

## 🖼️ Rendering Notes

* Ray‑casting via **DDA** grid stepping per screen column.
* **Per‑column texture sampling** based on wall hit coordinate.
* Floor/ceiling filled as solid colors (optional floor‑casting if implemented).
* Double‑buffering / image put once per frame to avoid flicker.

---

<a id="troubleshooting"></a>

## 🧯 Troubleshooting

* **Black window / crash:** check texture paths and `.xpm` validity.
* **Leaky edges / out‑of‑bounds:** ensure the map is fully enclosed and indices clamped.
* **Stutter:** avoid per‑pixel `mlx_pixel_put`; draw to an image buffer then blit.
* **Linux link errors:** verify `-lmlx -lXext -lX11 -lm -lz` and that X11 dev packages are installed.

---

<a id="project-context"></a>

## 🏛️ Project Context

Part of the **42** Common Core graphics branch (after `fdf`). Focus areas:

* Parsing and robust error reporting.
* Classic ray‑casting pipeline & texture mapping.
* Event loop, input handling, and resource management with **MiniLibX**.
