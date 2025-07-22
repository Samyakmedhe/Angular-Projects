// SnakeGame/food.c
#include <stdlib.h>
#include <time.h>
#include "food.h"

int foodX = 0;
int foodY = 0;

void generateFood()
{
    foodX = rand() % 20;
    foodY = rand() % 20;
}
