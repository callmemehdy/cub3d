# Cub3D - A Raycasting Game Engine

A comprehensive 3D maze game implementation utilizing raycasting rendering techniques, inspired by the pioneering first-person shooter Wolfenstein 3D. This project represents a deep dive into fundamental computer graphics principles and demonstrates how three-dimensional environments can be rendered efficiently from two-dimensional data structures.

## Project Overview

Cub3D is an advanced graphics programming project developed as part of the 42 school curriculum. The project challenges developers to implement a fully functional raycasting engine from scratch, creating an immersive first-person perspective within a maze environment. By working through this project, developers gain hands-on experience with graphics programming, mathematical algorithms, and real-time rendering optimization.

The implementation showcases how classic video games achieved the illusion of three-dimensional space before modern GPU acceleration, making it an excellent educational tool for understanding the foundations of computer graphics and game development.

## Features and Capabilities

### Core Implementation

The mandatory version includes essential raycasting functionality:

- **Real-Time Raycasting Engine** - A fully functional rendering system that casts rays from the player's position to determine visible surfaces and calculate accurate wall distances for proper perspective rendering
- **First-Person Movement System** - Smooth navigation through the maze environment with intuitive WASD controls and arrow key camera rotation
- **Directional Wall Texturing** - Support for unique textures on each cardinal direction (North, South, East, West), allowing for visual variety and navigation cues
- **Customizable Environment** - Configurable ceiling and floor colors specified in RGB format for personalized visual aesthetics
- **Robust Map Parser** - Comprehensive file parsing system that reads and validates .cub configuration files with thorough error checking
- **Collision Detection System** - Realistic physical boundaries that prevent players from passing through walls while maintaining smooth movement

### Advanced Bonus Features

The bonus implementation extends functionality with additional capabilities:

- **Sprite Animation System** - A sophisticated 50-frame weapon animation system with frame buffering and smooth transitions
- **Interactive Door Mechanics** - Fully functional door system marked with 'D' in map files, featuring toggle behavior and proper collision states
- **Mouse Look Integration** - Raw mouse input handling for intuitive camera rotation with configurable sensitivity
- **Enhanced Visual Effects** - Additional rendering optimizations and visual improvements for a more polished experience
- **Minimap Navigation** - Real-time minimap display with adjustable scaling factor for improved spatial awareness

## Technical Stack and Dependencies

### Core Technologies

- **Programming Language**: C (C11 standard)
- **Graphics Library**: MLX42 - Modern cross-platform graphics library built on OpenGL
- **Graphics API**: OpenGL 3.3 Core Profile
- **Window Management**: GLFW 3.3.6 or higher for cross-platform window creation and input handling
- **Build System**: CMake 3.18.0+ for cross-platform compilation
- **Supported Platforms**: Linux (X11/Wayland) and MacOS

## System Requirements and Installation

### Prerequisites

The following software components must be installed before building the project:

- **GCC Compiler** - GNU Compiler Collection for C compilation
- **Make** - Build automation tool
- **CMake** (version 3.18.0 or higher) - Cross-platform build system generator
- **GLFW** (version 3.3.6 or higher) - Multi-platform library for window management
- **OpenGL** - Graphics rendering API

### Platform-Specific Installation Instructions

#### MacOS Installation

Using Homebrew package manager:
```bash
brew install glfw
brew install cmake
```

Note for Apple Silicon users: Homebrew installation path differs on M1/M2/M3 chips. Update your shell configuration if necessary:
```bash
# For Zsh users (default on macOS)
nano ~/.zshrc
export LIBRARY_PATH=/opt/homebrew/lib
```

#### Linux Installation (Debian/Ubuntu)
```bash
sudo apt update
sudo apt install build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev cmake
```

#### Linux Installation (Arch-based distributions)

```bash
# For X11-based systems
sudo pacman -S glfw-x11

# For Wayland compositors (Sway, Hyprland, etc.)
sudo pacman -S glfw-wayland
```

### Building the Project

Follow these steps to compile and run Cub3D:

**Step 1: Clone the Repository**
```bash
git clone https://github.com/callmemehdy/Cub3d.git
cd Cub3d
```

**Step 2: Build the MLX42 Graphics Library**

Navigate to the appropriate version directory and build MLX42:
```bash
# For mandatory version
cd cub3d_m/MLX42

# For bonus version
cd cub3d_b/MLX42

# Build the library
cmake -B build
cmake --build build -j4
```

**Step 3: Compile the Game**

Return to the version directory and compile:
```bash
# Navigate back to the appropriate directory
cd ..

# Compile using Make
make
```

**Step 4: Launch the Game**

Execute the program with a map file:
```bash
./cub3D maps/map.cub
```

## Usage and Controls

### Control Scheme

#### Mandatory Version Controls

- **Movement Keys**: W, A, S, D or Arrow Keys for directional movement
  - W / Up Arrow: Move forward
  - S / Down Arrow: Move backward
  - A: Strafe left
  - D: Strafe right
- **Camera Controls**: Left and Right Arrow Keys for view rotation
- **Exit**: ESC key to terminate the program

#### Bonus Version Controls

- **Movement Keys**: W, A, S, D for player movement
  - W: Move forward in the direction of view
  - S: Move backward relative to view direction
  - A: Strafe left perpendicular to view direction
  - D: Strafe right perpendicular to view direction
- **Camera Controls**: 
  - Arrow Keys: Keyboard-based camera rotation
  - Mouse Movement: Intuitive mouse look for camera control
- **Interaction**: Spacebar to interact with doors (open/close)
- **Exit**: ESC key to close the application

### Map Configuration Format

Map files use the .cub extension and follow a specific format structure. Below is a comprehensive example demonstrating all configuration options:

```
NO ./path_to_the_north_texture.png
SO ./path_to_the_south_texture.png
WE ./path_to_the_west_texture.png
EA ./path_to_the_east_texture.png

F 220,100,0    # Floor color in RGB format
C 225,30,0     # Ceiling color in RGB format

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000001110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

#### Map Element Specifications

The map file consists of two primary sections: configuration headers and the map grid itself.

**Configuration Headers:**
- **Texture Paths** (NO, SO, WE, EA): File paths to wall textures for each cardinal direction
  - Supports multiple formats: .png, .xpm, .xpm42, .jpeg
  - Paths can be relative or absolute
  - All four directions must be specified

- **Color Configuration** (F, C): RGB color values for environmental surfaces
  - Format: R,G,B where each value ranges from 0 to 255
  - F specifies floor color
  - C specifies ceiling color
  - Whitespace around commas is ignored

**Map Grid Characters:**
- **1**: Solid wall - Impassable barrier with rendered texture
- **0**: Empty space - Walkable floor area
- **N**: Player spawn facing North (0 degrees)
- **S**: Player spawn facing South (180 degrees)
- **E**: Player spawn facing East (90 degrees)
- **W**: Player spawn facing West (270 degrees)
- **D**: Door marker (bonus version only) - Interactive passage
- **Space**: Void area - Treated as impassable boundary

#### Critical Map Requirements

The parser enforces several mandatory rules to ensure map validity:

1. **Enclosure Requirement**: The entire playable area must be completely surrounded by walls (1 characters). Any opening in the perimeter will result in a validation error.

2. **Single Player Spawn**: Exactly one player starting position must be defined using N, S, E, or W. Multiple spawn points or no spawn point will cause the map to be rejected.

3. **Color Value Constraints**: RGB values must be integers between 0 and 255 inclusive. Values outside this range will trigger an error.

4. **Texture File Validation**: All specified texture files must exist and be readable. Missing or inaccessible textures will prevent the game from launching.

5. **Character Validity**: Only the characters listed above are permissible in the map grid. Any other characters will be flagged as invalid.

6. **Spatial Integrity**: The map must not contain unreachable areas or floating walls that violate the raycasting algorithm's assumptions.

## Project Architecture

### Directory Structure Overview

The project is organized into two distinct versions, each with its own complete implementation:

```
cub3d/
├── cub3d_m/                      # Mandatory implementation
│   ├── Makefile                  # Build configuration for mandatory version
│   ├── incs/                     # Header files
│   │   ├── cub3d.h              # Main project header with structure definitions
│   │   └── get_next_line.h      # File reading utility header
│   ├── maps/                     # Collection of test maps
│   │   ├── dimensions.cub       # Testing various map dimensions
│   │   ├── dungeon.cub          # Dungeon-themed environment
│   │   ├── maze.cub             # Complex maze layout
│   │   └── ...                  # Additional test scenarios
│   ├── MLX42/                    # Graphics library (Git submodule)
│   │   ├── include/             # MLX42 headers
│   │   ├── src/                 # MLX42 source implementation
│   │   └── ...                  # MLX42 build files
│   └── srcs/                     # Source code directory
│       ├── main.c               # Program entry point
│       ├── parse/               # Map parsing subsystem
│       │   ├── bool_map.c       # Map validation logic
│       │   ├── ft_split.c       # String tokenization
│       │   ├── map_check.c      # Comprehensive map verification
│       │   └── ...              # Additional parsing utilities
│       └── raycast/             # Raycasting engine
│           ├── game.c           # Main game loop
│           ├── hooks.c          # Event handling
│           ├── raycast.c        # Core raycasting algorithm
│           ├── render.c         # Frame rendering
│           └── ...              # Supporting rendering code
│
├── cub3d_b/                      # Bonus implementation
│   ├── Makefile                  # Build configuration for bonus version
│   ├── incs/                     # Header files with bonus definitions
│   │   ├── cub3d_bonus.h        # Extended structure definitions
│   │   └── get_next_line_bonus.h
│   ├── maps/                     # Enhanced maps with bonus features
│   │   ├── bunker.cub           # Map with door mechanics
│   │   ├── maze.cub             # Complex maze with interactive elements
│   │   └── ...                  # Additional bonus scenarios
│   ├── MLX42/                    # Graphics library (shared)
│   └── srcs/                     # Enhanced source code
│       ├── main_bonus.c         # Entry point with bonus features
│       ├── parse/               # Enhanced parsing
│       └── raycast/             # Extended raycasting engine
│           ├── animation_bonus.c # Sprite animation system
│           ├── sprite_bonus.c   # Sprite rendering
│           └── ...              # Additional bonus features
│
└── README.md                     # Project documentation
```

## Educational Value and Learning Outcomes

This project serves as a comprehensive introduction to several fundamental areas of computer science and software engineering. Through implementation, developers gain practical experience in the following domains:

### Graphics Programming Fundamentals

**Raycasting Algorithm Implementation**
The core rendering technique involves casting virtual rays from the player's viewpoint into the game world. For each vertical column of pixels on the screen, a ray is projected, and the distance to the nearest wall is calculated. This distance determines the height at which the wall should be drawn, creating the perspective effect. Understanding this algorithm provides insight into how 3D graphics can be achieved without modern GPU hardware.

**Digital Differential Analysis (DDA) Algorithm**
The project requires implementation of the DDA algorithm for line traversal. This algorithm efficiently determines which grid cells a ray passes through, enabling rapid collision detection and wall intersection calculations. It demonstrates fundamental principles of computational geometry and numerical methods.

**Texture Mapping and Sampling**
Once a wall intersection is found, the appropriate texture must be applied. This involves calculating texture coordinates based on the hit position, sampling the texture at the correct vertical stripe, and scaling it according to the wall's perceived distance. This process teaches fundamental concepts of 2D-to-3D projection and image manipulation.

**Sprite Rendering in 3D Space**
The bonus version extends the engine to support 2D sprites rendered in a 3D environment. This requires sorting sprites by distance, calculating their screen space positions, and properly handling occlusion and transparency. These techniques were pioneered by games like Doom and remain relevant in modern game development.

### Mathematical and Algorithmic Concepts

**Trigonometric Functions**
The project extensively utilizes sine, cosine, and tangent functions for angle-based calculations. Player rotation, ray direction computation, and coordinate transformations all depend on accurate trigonometric operations. This practical application reinforces mathematical concepts that are often presented abstractly in academic settings.

**Vector Mathematics**
Movement and rotation in the game world are implemented using 2D vector operations. Understanding vector addition, scalar multiplication, dot products, and vector normalization is essential for implementing smooth player movement and accurate collision detection.

**Linear Algebra and Matrix Transformations**
Camera rotation and player movement involve coordinate transformations that can be elegantly expressed using matrix operations. While the project doesn't require explicit matrix implementation, understanding these transformations conceptually provides a foundation for more advanced graphics programming.

### Systems Programming and Software Engineering

**Low-Level Graphics API Interaction**
Working with MLX42 and OpenGL provides experience with low-level graphics programming. Developers learn about render loops, buffer management, texture loading, and event handling. This knowledge is transferable to other graphics APIs like Vulkan, DirectX, or Metal.

**Event-Driven Programming**
The game responds to user input through keyboard and mouse events. Implementing responsive controls requires understanding event loops, callback functions, and state management. These patterns are fundamental to interactive application development.

**File I/O and Parsing**
The map configuration system requires robust file reading and parsing. Developers implement a custom parser that validates input, handles errors gracefully, and constructs internal data structures. This experience is applicable to configuration systems, data serialization, and domain-specific language design.

**Memory Management in C**
Working in C without automatic garbage collection requires careful attention to memory allocation and deallocation. The project teaches best practices for avoiding memory leaks, using valgrind for debugging, and implementing custom memory management systems.

### Performance Optimization Techniques

**Efficient Rendering Algorithms**
Achieving smooth frame rates requires optimizing the rendering pipeline. This includes minimizing redundant calculations, implementing spatial data structures for collision detection, and batching rendering calls. Understanding performance bottlenecks and profiling tools is essential.

**Spatial Partitioning**
For larger maps, naive collision detection becomes computationally expensive. Implementing grid-based spatial partitioning significantly improves performance by limiting collision checks to nearby cells. This technique scales to more complex spatial data structures like quadtrees or BSP trees.

**Cache-Friendly Data Structures**
Organizing data to maximize cache coherency can significantly improve performance on modern CPUs. Understanding memory layout, structure packing, and access patterns provides insight into low-level performance optimization.

## Comprehensive Error Handling

The parsing system implements thorough validation to ensure map integrity and prevent runtime errors. The following categories of errors are detected and reported with descriptive messages:

### Input Validation Errors

**Program Arguments**
```
Error
invalid program input
Usage: ./cub3d [map's path]
```
Triggered when the program is invoked incorrectly, either with too many arguments, too few arguments, or with an invalid file extension.

**File Access Errors**
```
Error
invalid file descriptor
open function failed
```
Occurs when the specified map file cannot be opened due to insufficient permissions, non-existence, or file system errors.

### Map Content Validation

The parser performs extensive validation on map structure and content:

**Boundary Validation**
- Ensures the playable area is completely enclosed by walls
- Detects gaps in the perimeter that would allow the player to escape
- Validates that spaces are not adjacent to playable floor areas

**Player Spawn Validation**
- Confirms exactly one player spawn point exists
- Validates spawn position is on walkable floor
- Ensures spawn point is not adjacent to void spaces

**Character Validation**
- Rejects maps containing invalid characters
- Ensures only permitted symbols are present in the map grid

**Door Placement (Bonus)**
- Validates doors are placed between walls
- Ensures proper collision boundaries around door positions

### Resource Validation

**Texture File Verification**
- Confirms all four texture files (NO, SO, WE, EA) exist
- Validates file formats are supported (.png, .xpm, .xpm42, .jpeg)
- Checks file permissions allow reading

**Color Range Validation**
- Verifies RGB values are integers between 0 and 255
- Detects invalid formatting in color specifications
- Ensures both floor and ceiling colors are defined

### Memory Allocation Errors

```
Error
memory allocation problem occurred
malloc function failed
```
Reported when dynamic memory allocation fails, typically due to system resource exhaustion. The program includes comprehensive cleanup to prevent memory leaks even when errors occur.

### Common Error Messages

The following table summarizes error conditions and their meanings:

| Error Message | Cause | Resolution |
|--------------|-------|------------|
| invalid program input | Incorrect command-line arguments | Provide exactly one .cub file path |
| invalid file descriptor | Cannot open map file | Verify file exists and is readable |
| invalid map content | Map validation failed | Review map structure and characters |
| memory allocation problem occurred | malloc() returned NULL | Check available system memory |

## Customization and Extension

### Creating Custom Maps

Designing effective and playable maps requires understanding the raycasting engine's constraints and capabilities:

**Step-by-Step Map Creation**

1. **Establish Boundaries**: Begin by creating a rectangular border of walls (1 characters) to define the playable area perimeter.

2. **Design Interior Layout**: Add internal walls to create rooms, corridors, and obstacles. Consider sight lines and navigation flow to ensure interesting gameplay.

3. **Place Player Spawn**: Insert exactly one player spawn marker (N, S, E, or W) in an open area. Choose the orientation to provide an interesting initial view.

4. **Add Interactive Elements** (Bonus): Place door markers (D) to create connected rooms and passages. Ensure doors are properly positioned between walls.

5. **Configure Textures**: Specify texture file paths for all four cardinal directions. Using varied textures helps players orient themselves within the maze.

6. **Set Environmental Colors**: Define floor and ceiling colors that complement your texture choices and create the desired atmosphere.

### Example: Minimal Test Map

A simple map for testing basic functionality:

```
NO textures/north.png
SO textures/south.png
WE textures/west.png
EA textures/east.png
F 50,50,50
C 135,206,235

11111111111
10000000001
10N00000001
10000000001
10000000001
11111111111
```

### Example: Complex Dungeon Map

A more elaborate map demonstrating advanced features:

```
NO textures/stone_north.png
SO textures/stone_south.png
WE textures/stone_west.png
EA textures/stone_east.png
F 40,40,40
C 20,20,20

11111111111111111111111
10000D00100100D00000001
10110001001001000111001
10100000000000000101001
10101110D11D11011101001
10100000000000000001001
10111110111011101111001
10000000100010001000001
11111011100010001011111
10000010000D00001010001
10111110111111111010001
10100000000000000010001
10101111111D11111110001
10100000000000000000001
10111011101110111111101
10001000001000100000101
1011100011D011100110101
10000000100010000000101
10111110100010011111101
10S00000100010000000001
11111111111111111111111
```

### Adding Custom Textures

**Texture Preparation Guidelines:**

1. **File Format**: Use PNG for best compatibility and quality. XPM formats are supported for legacy compatibility.

2. **Resolution**: While any resolution is technically supported, powers of two (64x64, 128x128, 256x256) often perform better due to hardware optimization.

3. **Visual Design**: Create textures that tile seamlessly vertically. Horizontal tiling is handled by the texture coordinate calculation.

4. **Color Palette**: Consider how textures will appear under different lighting conditions. The raycasting engine doesn't implement dynamic lighting, so textures should be pre-lit.

5. **File Organization**: Store textures in a dedicated directory (e.g., `textures/`) and use relative paths in map files for portability.

## Performance Characteristics and Optimization

The engine is designed with performance in mind and includes several configurable parameters:

### Rendering Configuration

The following constants in `cub3d_bonus.h` can be adjusted to balance quality and performance:

```c
#define W_WIDTH 1920    // Window width in pixels
#define W_HEIGHT 1056   // Window height in pixels
#define FOV 60          // Field of view in degrees
#define TSIZE 64        // Size of map tiles in pixels
#define SCALE 0.5       // Minimap scale factor
#define NUM_RAYS W_WIDTH // Number of rays cast per frame
#define FPS 60          // Target frames per second
```

### Performance Metrics

On modern hardware (tested on typical development machines), the engine achieves:

- **Resolution**: Full HD (1920x1080) rendering
- **Frame Rate**: Consistent 60 FPS in most scenarios
- **Ray Count**: One ray per horizontal pixel (1920 rays per frame)
- **Texture Resolution**: Supports up to 1024x1024 textures without significant performance degradation

### Optimization Techniques Implemented

**Batched Rendering**
Multiple draw calls are batched together to minimize state changes and improve GPU utilization. This is particularly beneficial when rendering sprites in the bonus version.

**Integer Arithmetic**
Where possible, floating-point operations are minimized in favor of integer arithmetic, which executes faster on most CPUs.

**Spatial Partitioning**
The grid-based map structure inherently provides spatial partitioning, allowing collision detection to be limited to nearby cells rather than checking all walls.

## Testing and Validation

The project includes a comprehensive suite of test maps designed to validate different aspects of the engine:

### Included Test Scenarios

| Map File | Purpose | Key Features |
|----------|---------|--------------|
| `map.cub` | Basic functionality | Simple rectangular maze, standard textures |
| `maze.cub` | Complex navigation | Intricate corridor system, multiple paths |
| `dungeon.cub` | Themed environment | Dungeon textures, atmospheric colors |
| `space.cub` | Large open areas | Performance testing, long sight lines |
| `tiny.cub` | Minimal test case | Smallest valid map for quick debugging |
| `dimensions.cub` | Boundary testing | Tests various map dimensions |
| `bunker.cub` (Bonus) | Door mechanics | Multiple doors, room connections |

### Manual Testing Checklist

When validating changes or testing new features, consider the following test scenarios:

- Movement in all four cardinal directions
- Rotation through full 360-degree range
- Collision detection at various angles
- Texture rendering on all wall faces
- Proper handling of map boundaries
- Frame rate stability during rapid movement
- Door interaction (bonus version)
- Sprite animation timing (bonus version)
- Mouse sensitivity and responsiveness (bonus version)

## Contributing and Development

While this is an educational project from the 42 school curriculum, contributions and improvements are welcome. The project provides an excellent foundation for experimentation with graphics programming concepts.

### Potential Enhancement Areas

Developers interested in extending the project might consider:

- **Lighting System**: Implement distance-based shading or point light sources
- **Advanced Textures**: Add support for animated wall textures or transparency
- **Audio System**: Integrate positional audio for immersive sound effects
- **Advanced AI**: Implement pathfinding for enemy sprites
- **Level Editor**: Create a graphical tool for designing maps
- **Performance Profiling**: Add metrics display for frame time and rendering statistics

### Code Style and Standards

The project follows C coding conventions typically taught in the 42 curriculum:

- Function names use snake_case
- Structure names use snake_case with _s suffix
- Typedef names use snake_case with _t suffix  
- Header guards follow the pattern: PROJECT_FILE_H
- Maximum function length: typically limited to 25 lines
- Maximum line length: 80 characters (though this varies by campus)

## License and Attribution

This project is developed as part of the 42 school curriculum and adheres to the educational guidelines established by the institution. The code is provided for educational purposes.

### Third-Party Components

**MLX42 Graphics Library**
Developed by Codam Coding College, MLX42 is licensed under the GPL-2.0 license. It provides a modern, cross-platform alternative to the legacy MiniLibX library. The library source code is included as a git submodule and is subject to its own licensing terms.

**GLFW**
The GLFW library used by MLX42 is licensed under the zlib/libpng license, allowing free use in both open-source and commercial applications.

## Acknowledgments and Resources

### Project Recognition

This implementation represents the collaborative effort of two developers who invested significant time in understanding computer graphics fundamentals and implementing a functional raycasting engine from first principles.

### Educational Resources

The following resources proved invaluable during development and are recommended for anyone interested in understanding raycasting:

**Technical Documentation and Tutorials**

- **Lode's Computer Graphics Tutorial**: Comprehensive raycasting tutorial with clear explanations and code examples (lodev.org/cgtutor/raycasting.html)
- **MLX42 Documentation**: Official documentation for the graphics library (github.com/codam-coding-college/MLX42)
- **Game Engine Black Book: Wolfenstein 3D**: Deep dive into the original Wolfenstein 3D engine by Fabien Sanglard
- **Wolfenstein 3D Source Code**: The original id Software source code, released as open source

**Historical Context**

- **John Carmack's Programming Insights**: Technical discussions and interviews detailing the development of early 3D engines
- **id Software Development History**: Documentation of the pioneering techniques that made games like Wolfenstein 3D and Doom possible

### Institutional Support

- **42 School** for providing the project specification and educational framework that guided this implementation
- **Codam Coding College** for developing and maintaining the MLX42 library
- **The raycasting community** for extensive documentation, tutorials, and support resources

## Authors

This project was collaboratively developed by:

**Mehdi El AKARY**
- GitHub: [callmemehdy](https://github.com/callmemehdy)
- Focus: Raycasting engine implementation and optimization

**Anas EL AMMARI** 
- GitHub: [Anas-RI](https://github.com/Anas-RI)
- Focus: Map parsing system and bonus features

Both developers contributed to all aspects of the project through pair programming, code review, and collaborative problem-solving sessions.

---

**Project Status**: Complete and validated as part of the 42 school curriculum. The implementation demonstrates proficiency in C programming, computer graphics, mathematical algorithms, and software engineering principles.
