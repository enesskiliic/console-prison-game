# Prison Escape Game (C)

A grid-based stealth game written in **C**, where the player tries to escape a prison without being caught by guards. The project is developed as a console application and focuses on matrix operations, line-of-sight logic, and basic game mechanics.

## Project Description

The player (`O`) navigates a **20x20** matrix to reach the exit (`C`) while avoiding guards (`G`). Each guard has a defined **vision direction and range**, and if the player enters a guard’s line of sight without a wall (`#`) blocking it, the game is lost.

The core of the project is the **line-of-sight (LOS) algorithm**, which checks whether a guard can see the player.

## Symbols Used

| Symbol    | Meaning                |
| --------- | ---------------------- |
| `O`       | Player                 |
| `G`       | Guard                  |
| `C`       | Exit                   |
| `#`       | Wall                   |
| `.`       | Walkable floor         |
| `> < ^ v` | Guard vision direction |

## Game Mechanics

* The player moves using arrow keys.
* Guards patrol or stay fixed depending on the level.
* If a guard sees the player directly and no wall blocks the view, the player is caught.
* Reaching the exit without being detected wins the game.

## Levels

### Level 1

* Static guards
* Guards only look in a single fixed direction

### Level 2

* Patrolling guards that move along a predefined path

### Level 3

* Guards have **cone-shaped vision** (including diagonal vision)

### Advanced (Optional)

* Keys (`K`) and locked doors (`D`)

## Technologies Used

* C (Standard C Library)
* Console-based rendering
* 2D arrays (matrix-based map)

## How to Compile and Run

```bash
gcc main.c -o prison_escape
./prison_escape
```

## Learning Outcomes

* Working with 2D arrays in C
* Implementing line-of-sight algorithms
* Game logic and state management
* Modular function design

## Screenshot

![Game Screenshot](screenshot.png)

## Author

**Enes Kılıç**

---

Feel free to fork the project or suggest improvements.
