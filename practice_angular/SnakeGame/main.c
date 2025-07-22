#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <time.h>
#include "snake.h"
#include "food.h"
#include "utils.h"

int main()
{
    initGame();
    while (!gameOver)
    {
        drawBoard();
        getInput();
        updateGame();
        usleep(speed);
    }
    printf("\nGame Over! Your Score: %d\n", score);
    return 0;
}
