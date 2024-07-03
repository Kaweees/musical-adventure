#include "snake.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "grid.h"

SnakeSegment *createSnakeSegment(int x, int y, SnakeDirection direction) {
  SnakeSegment *segment = malloc(sizeof(SnakeSegment));
  if (segment == NULL) {
    perror("Error allocating memory for snake segment");
    exit(EXIT_FAILURE);
  }
  segment->x = x;
  segment->y = y;
  segment->direction = direction;
  segment->next = NULL;
  return segment;
}

void freeSnakeSegment(SnakeSegment *segment) { free(segment); }

Snake *createSnake(int x, int y, SnakeDirection direction) {
  Snake *snake = malloc(sizeof(Snake));
  if (snake == NULL) {
    perror("Error allocating memory for snake");
    exit(EXIT_FAILURE);
  }
  snake->head = createSnakeSegment(x, y, direction);
  snake->tail = snake->head;
  return snake;
}

void freeSnake(Snake *snake) {
  SnakeSegment *current = snake->head;
  while (current != NULL) {
    SnakeSegment *next = current->next;
    freeSnakeSegment(current);
    current = next;
  }
  free(snake);
}

/* Moves the position of a snake */
void moveSnake(Snake *snake, GameGrid *grid) {
  SnakeSegment *temp = snake->head;
  SnakeDirection previousDirection = temp->direction;
  while (temp != NULL) {
    switch (previousDirection) {
      case (UP):
        temp->y--;
        if (temp->y < 0) {
          temp->y = grid->height - 1;
        }
        break;
      case (DOWN):
        temp->y++;
        if (temp->y > grid->height - 1) {
          temp->y = 0;
        }
        break;
      case (LEFT):
        temp->x--;
        if (temp->x < 0) {
          temp->x = grid->width - 1;
        }
        break;
      case (RIGHT):
        temp->x++;
        if (temp->x > grid->width - 1) {
          temp->x = 0;
        }
        break;
    }
    // printf("x: %d, y: %d\n", temp->x, temp->y);
    previousDirection = temp->direction;
    temp = temp->next;
  }
}