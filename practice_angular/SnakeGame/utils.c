// SnakeGame/utils.c
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>          // ✅ Required for time()

#include "snake.h"         // ✅ Must match filename case exactly!
#include "food.h"
#include "utils.h"


int gameOver = 0;
int score = 0;
int speed = 200000;

static struct termios old, current;

void initTermios()
{
    tcgetattr(0, &old);
    current = old;
    current.c_lflag &= ~ICANON;
    current.c_lflag &= ~ECHO;
    tcsetattr(0, TCSANOW, &current);
}

void resetTermios()
{
    tcsetattr(0, TCSANOW, &old);
}

char getch()
{
    char ch;
    initTermios();
    ch = getchar();
    resetTermios();
    return ch;
}

void drawBoard()
{
    system("clear");
    for (int y = 0; y < 20; y++)
    {
        for (int x = 0; x < 20; x++)
        {
            if (x == foodX && y == foodY)
                printf("F");
            else
            {
                SnakeNode *temp = head;
                int printed = 0;
                do
                {
                    if (temp->x == x && temp->y == y)
                    {
                        printf("O");
                        printed = 1;
                        break;
                    }
                    temp = temp->next;
                } while (temp != head);
                if (!printed)
                    printf(".");
            }
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
}

void getInput()
{
    if (getchar() == 27 && getchar() == 91) // Arrow keys
    {
        switch (getchar())
        {
        case 'A': if (direction != 'D') direction = 'U'; break; // up
        case 'B': if (direction != 'U') direction = 'D'; break; // down
        case 'C': if (direction != 'L') direction = 'R'; break; // right
        case 'D': if (direction != 'R') direction = 'L'; break; // left
        }
    }
}

void updateGame()
{
    int newX = head->x;
    int newY = head->y;
    switch (direction)
    {
    case 'U': newY--; break;
    case 'D': newY++; break;
    case 'L': newX--; break;
    case 'R': newX++; break;
    }

    if (newX < 0 || newY < 0 || newX >= 20 || newY >= 20)
    {
        gameOver = 1;
        return;
    }

    insertHead(newX, newY);

    if (newX == foodX && newY == foodY)
    {
        score++;
        generateFood();
    }
    else
    {
        deleteTail();
    }

    if (checkSelfCollision())
        gameOver = 1;
}

void initGame()
{
    srand(time(0));
    initSnake();
    generateFood();
    direction = 'R';
}
