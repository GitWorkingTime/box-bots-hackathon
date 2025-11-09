# Snackatron
This contains the source code for our helper robot, "Snackatron", made for the Box Bots hackathon where the main material was cardboard. Snackatron can be controlled using an IR remote to turn and move forward, and pushes out a tray from its frame containing goodies. 

The code uses an ESP32 and was developed on the platformIO extension on VSCode, seperated between the `/include` and `/src` directories
- The `/include` folder contains header files for the function declarations of helper functions found in `/src`

The actual code that runs the robot can be found in  `/src/main.cpp`, utilizing the Arduino framework, libraries, and the ESP32 libraries
