#include <stdlib.h>
#include "snake.h"

SnakeNode *head = NULL;
SnakeNode *tail = NULL;
char direction = 'R';

void initSnake()
{
    head = (SnakeNode *)malloc(sizeof(SnakeNode));
    head->x = 10;
    head->y = 10;
    head->next = head;
    tail = head;
}

void insertHead(int x, int y)
{
    SnakeNode *newNode = (SnakeNode *)malloc(sizeof(SnakeNode));
    newNode->x = x;
    newNode->y = y;
    newNode->next = head;
    tail->next = newNode;
    head = newNode;
}

void deleteTail()
{
    SnakeNode *temp = head;
    while (temp->next != tail)
        temp = temp->next;
    free(tail);
    tail = temp;
    tail->next = head;
}

int checkSelfCollision()
{
    SnakeNode *temp = head->next;
    while (temp != head)
    {
        if (temp->x == head->x && temp->y == head->y)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void moveSnake()
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
    insertHead(newX, newY);
    deleteTail();
}
