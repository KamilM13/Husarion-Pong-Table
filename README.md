# Husarion-Pong-Table

Code for a Basics of Mechatronics project realised during the second semester on AGH University, done by me.
The project made use of Husarion libraries, specifically connecting three motors, five Ultrasonic sensors and a numpad for manual control.
There is also autonomous control mode.

# Ball movement system
The ball moved simply by tilting the table back and forth with a delay based on trial and error.

# Manual control system
Two players could play the game using one numpad located in the middle. 
Previous versions had four limit switches for manual gameplay but that proved to be too many sensor inputs to be worth using.

# Autonomous control system
In autonomous play the code decided where to place the bumpers. 
Using five Ultrasonic sensors detecting the ball in nine different zones the bumpers were moved to a specific location.
This part could definetly use some upgrades but it could play until heap memory exhaustion (a problem we could not solve).

# Mechanical part of the project
This is how the final version looked. 
![pongt](https://user-images.githubusercontent.com/109474440/179421418-6ef8e4ae-2eb9-4dc8-a9d5-f50f71356c80.jpg)
Cable management is overrated.

I had limited input into the mechanical side of this project.
