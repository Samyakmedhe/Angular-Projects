#ifndef SNAKE_H
#define SNAKE_H

typedef struct SnakeNode
{
    int x, y;
    struct SnakeNode *next;
} SnakeNode;

void initSnake();
void insertHead(int x, int y);
void deleteTail();
int checkSelfCollision();
void moveSnake();

extern SnakeNode *head, *tail;
extern char direction;

#endif