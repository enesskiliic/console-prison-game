#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    int x, y;
    char dir; // '>', '<', '^', 'v'
} Guard;

char map[][21] = {
    "####################",
    "#.........#........#",
    "#.#####...#........#",
    "#.#...#...#........#",
    "#.#...#...#####..#.#",
    "#...#.#.......#..#.#",
    "#####.#.......#..#.#",
    "#...#.#.......#..#.#",
    "#...#.#####...#..#.#",
    "#...#...#...#.#..#.#",
    "#...#####...#.#....#",
    "#.........#...######",
    "#.........#.....#.#.",
    "#####.....#.....#.#.",
    "#...#.....#.....#.#.",
    "#...#.....#.....#.#.",
    "#...#####.#.....#.#.",
    "#.........#.....#.#.",
    "#.........#......E#.",
    "####################"};

int ROWS;
int COLS;

Guard guards[] = {
    {3, 4, 'v'},
    {2, 8, '<'},
    {6, 17, '>'},
    {13, 13, '^'}};
int guardCount = sizeof(guards) / sizeof(guards[0]);

int playerX = 1, playerY = 1;

void printMap();
void placeGuardsOnMap();
bool isGuardSymbol(char c);
bool checkGuardsSeePlayer();

int main()
{
    ROWS = sizeof(map) / sizeof(map[0]);
    COLS = strlen(map[0]);

    placeGuardsOnMap();
    char move;

    while (1)
    {
        system("cls");
        printMap();

        if (checkGuardsSeePlayer())
        {
            printf("\nGuard spotted you! Game over!\n");
            break;
        }

        if (map[playerY][playerX] == 'E')
        {
            printf("\nCongratulations! You escaped successfully!\n");
            break;
        }

        printf("\nUse WASD to move (Q = quit): ");
        move = getch();

        if (move == 'q' || move == 'Q')
        {
            printf("\nYou quit the game.\n");
            break;
        }

        int newX = playerX;
        int newY = playerY;

        if (move == 'w' || move == 'W')
            newY--;
        else if (move == 's' || move == 'S')
            newY++;
        else if (move == 'a' || move == 'A')
            newX--;
        else if (move == 'd' || move == 'D')
            newX++;

        if (map[newY][newX] == '#')
            continue;

        if (isGuardSymbol(map[newY][newX]))
        {
            printf("\nYou walked into a guard. Caught!\n");
            break;
        }

        if (map[newY][newX] == 'E')
        {
            printf("\nYou reached the exit, escape successful!\n");
            break;
        }

        map[playerY][playerX] = '.';
        playerX = newX;
        playerY = newY;
        map[playerY][playerX] = 'O';
    }

    return 0;
}

void printMap()
{
    for (int i = 0; i < ROWS; i++)
        printf("%s\n", map[i]);
}

void placeGuardsOnMap()
{
    for (int i = 0; i < guardCount; i++)
        map[guards[i].y][guards[i].x] = guards[i].dir;

    map[playerY][playerX] = 'O';
}

bool isGuardSymbol(char c)
{
    return (c == '>' || c == '<' || c == '^' || c == 'v');
}

bool checkGuardsSeePlayer()
{
    for (int i = 0; i < guardCount; i++)
    {
        Guard g = guards[i];
        int x = g.x;
        int y = g.y;

        if (g.dir == '>')
        {
            for (int j = x + 1; j < COLS; j++)
            {
                if (map[y][j] == '#')
                    break;
                if (playerX == j && playerY == y)
                    return true;
            }
        }
        else if (g.dir == '<')
        {
            for (int j = x - 1; j >= 0; j--)
            {
                if (map[y][j] == '#')
                    break;
                if (playerX == j && playerY == y)
                    return true;
            }
        }
        else if (g.dir == '^')
        {
            for (int i2 = y - 1; i2 >= 0; i2--)
            {
                if (map[i2][x] == '#')
                    break;
                if (playerX == x && playerY == i2)
                    return true;
            }
        }
        else if (g.dir == 'v')
        {
            for (int i2 = y + 1; i2 < ROWS; i2++)
            {
                if (map[i2][x] == '#')
                    break;
                if (playerX == x && playerY == i2)
                    return true;
            }
        }
    }
    return false;
}
