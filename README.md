# cub3D  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ![42 logo little](https://github.com/user-attachments/assets/4cecf5b8-a28e-49c5-a4b1-2030e571a0b3)

[![Language: C](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))

## Introduction

**cub3D** is a **raycasting-based 3D maze exploration game** developed using **C** and the **MiniLibX** library.  
It is part of the **second graphical project** at **42 School**, challenging students to implement a basic first-person 3D engine inspired by *Wolfenstein 3D*.

> 🎮 The atmosphere and concept were inspired by *Call of Duty: World at War – Zombies mode*.

This project combines:
- Low-level graphics rendering (MiniLibX)
- File parsing and validation
- Real-time input handling
- Raycasting mathematics and logic

📚 [Raycasting Tutorial (lodev.org)](https://lodev.org/cgtutor/raycasting.html)

---

## Features

### 🗺️ Map & File Parsing
- Reads and validates `.cub` map files
- Handles floor/ceiling colors and texture paths
- Verifies that the map is **closed** and well-formed
- Supports player start position and direction (N, S, E, W)

### 🎮 Player Controls
- `W`, `A`, `S`, `D`: move through the map
- `←`, `→`: rotate viewpoint
- `ESC`: quit the game
- Red cross click: graceful exit

### 🧱 Rendering & Raycasting
- Real-time **3D rendering** via **raycasting**
- Wall textures based on direction (N/S/E/W)
- Distinct ceiling and floor coloring
- Smooth window handling (resize, focus, etc.)

### ⚙️ Error Handling
- Displays `"Error\n"` followed by a clear message if map/config is invalid
- Handles malformed files, missing textures, unclosed maps, and wrong identifiers

---

## 🔫 Custom Features (Inspired by CoD Zombies)

- 💰 **In-game money system**: players earn money by killing zombies  
- 🚪 **Doors unlockable for $500**, allowing access to new areas  
- 📈 **Wave system (manches)**:
  - Zombies increase in HP and difficulty each round
  - New wave starts after clearing the previous one
- 👹 **Zombie boss**:
  - 10% chance to spawn per wave
  - Boss HP = 2 × normal zombie HP (scales with wave)
- 🖼️ **Loading screen** before gameplay starts  
- 🔁 **Weapon switching** using mouse scroll wheel  
- 🎯 **Dynamic crosshair** that shifts depending on walking or sprinting  
- 🌑 **Distance-based shadows** for improved immersion
- ❤️ **Health bar that regenerates over time if no recent damage**

---

## Usage

### 1. Init Libft

```bash
git submodule update --init --recursive
```

### 2. Build the project

```bash
make
```

### 3. Launch the game

```bash
./cub3D maps/valid/example.cub
```

### 4. Example `.cub` map snippet

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
1000N1
111111
```

---

## Team Members

- [**@Zaaii**](https://github.com/Zaaii77) — raycasting, rendering, input
- [**@Zaiicko**](https://github.com/Zaiicko) — parsing, map logic, error handling

---

## Technical Notes

- Compliant with the **42 coding norm**
- Uses **MiniLibX** for graphics and input
- **Cross-platform:** macOS & Linux compatible
- Memory is strictly managed — **no leaks allowed**
- Makefile includes: `all`, `clean`, `fclean`, and `re`
- `.cub` file parser is robust and spec-compliant

---

## Bonus Features (optional)

If the mandatory part is validated flawlessly, additional features may be included:

- 🧱 **Wall collisions**
- 🗺️ **Minimap**
- 🚪 **Openable doors**
- 🎞️ **Animated sprites**
- 🖱️ **Mouse control for camera**

---

## Screenshot

<img width="214" height="188" alt="Capture d’écran 2024-08-02 à 03 04 46" src="https://github.com/user-attachments/assets/cc961eec-0b1a-42b1-b505-01172c95cea6" />
