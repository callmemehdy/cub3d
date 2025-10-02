# Cub3D

A 3D maze game built with raycasting techniques, inspired by the legendary Wolfenstein 3D - the world's first FPS game.

## 📖 About

Cub3D is a 42 school project that explores the fundamentals of raycasting to create a dynamic first-person view inside a maze. This project demonstrates how early 3D games created the illusion of three-dimensional space using 2D raycasting algorithms.

## 🎮 Features

- **Raycasting Engine**: Real-time 3D rendering using raycasting techniques
- **First-Person Navigation**: Move through the maze with smooth controls
- **Textured Walls**: Different textures for each cardinal direction (North, South, East, West)
- **Customizable Ceiling and Floor Colors**: Configurable environment colors
- **Map Parsing**: Load custom maps from `.cub` configuration files
- **Collision Detection**: Realistic wall collision system

## 🛠️ Technologies

- **Language**: C
- **Graphics Library**: MiniLibX (MLX)
- **Platform**: Linux/MacOS

## 📋 Requirements

- GCC compiler
- Make
- MiniLibX library
- X11 (for Linux)
- OpenGL and AppKit (for MacOS)

## 🚀 Installation

1. Clone the repository:
```bash
git clone https://github.com/callmemehdy/Cub3d.git
cd Cub3d
```

2. Compile the project:
```bash
make
```

3. Run the game with a map file:
```bash
./cub3D maps/map.cub
```

## 🎯 Usage

### Controls

- **W/A/S/D** or **Arrow Keys**: Move through the maze
- **Left/Right Arrows**: Rotate camera view
- **ESC**: Exit the game

### Map Configuration

Create a `.cub` file with the following specifications:

```
NO ./path/to/north_texture.xpm
SO ./path/to/south_texture.xpm
WE ./path/to/west_texture.xpm
EA ./path/to/east_texture.xpm

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

#### Map Rules:
- `1`: Wall
- `0`: Empty space
- `N/S/E/W`: Player starting position and orientation
- `F`: Floor color (RGB format)
- `C`: Ceiling color (RGB format)
- Texture paths for each wall direction

## 🏗️ Project Structure

```
cub3d/
├── src/              # Source files
├── include/          # Header files
├── maps/             # Map configuration files
├── textures/         # Texture files (.xpm)
├── Makefile          # Compilation rules
└── README.md         # This file
```

## 🎓 Learning Objectives

This project teaches:
- **Raycasting algorithms**: Understanding how to create 3D perspective from 2D maps
- **Graphics programming**: Working with pixels and graphical libraries
- **Mathematical concepts**: Trigonometry, vector mathematics, DDA algorithm
- **Performance optimization**: Efficient rendering techniques
- **File parsing**: Reading and validating configuration files
- **Memory management**: Proper allocation and deallocation in C

## 🐛 Error Handling

The program validates:
- Map file format and syntax
- Texture file existence and format
- Map closure (walls surrounding the playable area)
- Valid player position and orientation
- Color values (RGB range 0-255)

## 📝 Notes

- The map must be surrounded by walls (1s)
- Only one player starting position is allowed
- RGB values must be in range 0-255
- Texture files must be in `.xpm | .png | .jpeg` format

## 🤝 Contributing

This is an educational project from 42 school. Feel free to fork and experiment with your own improvements!

## 📄 License

This project is part of the 42 school curriculum and follows the school's guidelines.

## 🙏 Acknowledgments

- 42 School for the project subject
- Wolfenstein 3D for the inspiration
- The raycasting community for documentation and resources

---

Made with ❤️ by [callmemehdy](https://github.com/callmemehdy) and [Anas](https://github.com/Anas-RI).
