cub3D - My First RayCaster with miniLibX
cub3D is a 3D maze exploration game created as part of my project to explore Ray-Casting techniques and graphics programming. Inspired by the iconic Wolfenstein 3D, this project allows users to navigate through a maze with a first-person perspective. The program is built using C and the miniLibX graphics library.<br>

🚀 Features
Ray-Casting Engine: A 3D perspective is generated from a 2D maze map using ray-casting techniques.<br>
First-Person Movement: Use W, A, S, D to move and the arrow keys to look around.<br>
Texture Mapping: Different textures are applied to walls based on the cardinal directions (North, South, East, West).<br>
Floor and Ceiling Colors: Configurable colors for the floor and ceiling in the game environment.<br>
Smooth Window Management: Handles window events like minimizing, resizing, and closing gracefully.<br>
Customizable Map: The game loads a map from a .cub file and checks for any misconfigurations.<br>
Error Handling: Proper error messages and program exits in case of invalid map configurations or other errors.<br>
<br>
🛠️ Installation
To get started with cub3D, follow these steps:<br>

Clone the repository:<br>

git clone https://github.com/oelbouha/cub3d.git<br>
cd cub3D<br>
Install dependencies:<br>

You will need the miniLibX graphics library. On macOS, it is typically available via brew. On Linux, you can install it through your package manager or build it from source.<br>
Compile the program:<br> Ensure you have Makefile configured to build the project:<br>


make<br>
Run the program:<br> After compilation, you can run the game by providing a .cub map file as an argument:<br>

./cub3D path_to_map.cub<br>
📝 Map Format
The game requires a .cub file that defines the textures, colors, and the maze layout. A simple example of a .cub file is as follows:<br>

NO ./textures/north_texture.xpm<br>
SO ./textures/south_texture.xpm<br>
WE ./textures/west_texture.xpm<br>
EA ./textures/east_texture.xpm<br>
F 220,100,0<br>
C 225,30,0<br>

111111111111111<br>
100000000000001<br>
101100000000001<br>
100100000000001<br>
111111111111111<br>

Textures: Path to the .xpm texture files for North, South, East, and West.<br>
Colors: RGB values for the floor (F) and ceiling (C) colors.<br>
Map: A grid of 1s (walls) and 0s (empty spaces), with N, S, E, or W representing the starting position and orientation.<br>
⚙️ Controls
W: Move forward<br>
A: Move left<br>
S: Move backward<br>
D: Move right<br>
Arrow keys: Look left, right, up, or down<br>
ESC: Exit the game<br>
Red cross (top-right corner): Close the game window<br>
💻 Technologies Used
C Programming Language<br>
miniLibX for graphics rendering<br>
Makefile for project build and compilation<br>
Math Functions for ray-casting calculations<br>
🐛 Troubleshooting
Invalid Map Format: If your map is not in the correct format or has errors, the program will display an error message and exit gracefully.<br>
Missing Textures: Ensure your .cub file points to the correct paths for texture images.<br>



<img width="1681" alt="Screen Shot 2024-12-08 at 8 27 03 PM" src="https://github.com/user-attachments/assets/bd64fb4e-2851-4f99-8e60-5be38fae3a6f"><br>


<img width="1681" alt="Screen Shot 2024-12-08 at 8 27 46 PM" src="https://github.com/user-attachments/assets/6998f526-8f4e-4353-8f8e-00810a509001"><br>

<img width="1678" alt="Screen Shot 2024-12-08 at 8 26 26 PM" src="https://github.com/user-attachments/assets/72fc4a38-ef74-4311-bb1b-123eaadc57f6">




