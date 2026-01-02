Prison Escape Game (C)

A grid-based stealth game written in C, where the player tries to escape a prison without being caught by guards. The project is a console application and focuses on matrix operations, line-of-sight logic, and basic game mechanics.

Project Description

The player (O) moves inside a 20x20 matrix to reach the exit (C) while avoiding guards (G).
Each guard has a fixed vision direction and range. If the player enters a guard’s line of sight without a wall (#) blocking it, the game is lost.

The main focus of the project is the line-of-sight (LOS) algorithm, which determines whether a guard can see the player.

Symbols Used
Symbol	Meaning
O	Player
G	Guard
C	Exit
#	Wall
.	Walkable floor
> < ^ v	Guard vision direction
Game Mechanics

The player moves using arrow keys.

Guards are static and look in a single fixed direction.

If a guard sees the player directly and no wall blocks the view, the player is caught.

Reaching the exit without being detected wins the game.

The game consists of one single level.

Technologies Used

C (Standard C Library)

Console-based rendering

2D arrays (matrix-based map)

How to Compile and Run
gcc real_oyun.c -o prison_escape
./prison_escape

Learning Outcomes

Working with 2D arrays in C

Implementing a line-of-sight algorithm

Basic game logic and state management

Modular function design

Author

Enes Kılıç