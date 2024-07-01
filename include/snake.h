#ifndef SNAKE_H
#define SNAKE_H

#include "grid.h"
#include <stdbool.h>

/* Begin typedef declarations */

/* Represents the direction of the snake */
typedef enum SnakeDirection {
  UP,
  DOWN,
  LEFT,
  RIGHT,
} SnakeDirection;

/* Represents a segment of the snake */
typedef struct SnakeSegment {
  int x;
  int y;
  struct SnakeSegment *next;
  SnakeDirection direction;
} SnakeSegment;

/* Represents the entire snake */
typedef struct Snake {
  SnakeSegment *head;
  SnakeSegment *tail;
} Snake;

/* Begin function prototype declarations */

/* Creates a snake segment */
SnakeSegment *createSnakeSegment(int x, int y, SnakeDirection direction);

/* Frees the memory allocated for a snake segment */
void freeSnakeSegment(SnakeSegment *segment);

/* Creates a snake */
Snake *createSnake(int x, int y, SnakeDirection direction);

/* Frees the memory allocated for a snake */
void freeSnake(Snake *snake);

/* Moves the position of a snake */
void moveSnake(Snake *snake, GameGrid* grid);

#endif /* SNAKE_H */