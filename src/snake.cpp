#include "../include/snake.hpp"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../include/grid.hpp"

SnakeSegment::SnakeSegment(int x, int y, SnakeDirection direction) {
  this->x = x;
  this->y = y;
  this->direction = direction;
  this->next = NULL;
}

Snake::Snake(int x, int y, SnakeDirection direction) {
  this->head = new SnakeSegment(x, y, direction);
  this->tail = this->head;
}

Snake::~Snake() {
  SnakeSegment *temp = this->head;
  while (temp != NULL) {
    SnakeSegment *next = temp->next;
    free(temp);
    temp = next;
  }
}

void Snake::moveSnake(GameGrid *grid) {
  SnakeSegment *temp = this->head;
  SnakeDirection previousDirection = temp->direction;
  while (temp != NULL) {
    switch (previousDirection) {
      case (SnakeDirection::UP):
        temp->y--;
        if (temp->y < 0) {
          temp->y = grid->height - 1;
        }
        break;
      case (SnakeDirection::DOWN):
        temp->y++;
        if (temp->y > grid->height - 1) {
          temp->y = 0;
        }
        break;
      case (SnakeDirection::LEFT):
        temp->x--;
        if (temp->x < 0) {
          temp->x = grid->width - 1;
        }
        break;
      case (SnakeDirection::RIGHT):
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