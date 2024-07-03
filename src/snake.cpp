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
  while (temp != NULL) {
    switch (temp->direction) {
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
    temp = temp->next;
  }
}

void Snake::growSnake() {
  int previousX = this->tail->x;
  int previousY = this->tail->y;
  switch (this->tail->direction) {
    case (SnakeDirection::UP):
      previousY++;
      break;
    case (SnakeDirection::DOWN):
      previousY--;
      break;
    case (SnakeDirection::LEFT):
      previousX++;
      break;
    case (SnakeDirection::RIGHT):
      previousX--;
      break;
  }
  if (previousY < 0) {
    previousY = 0;
  }
  if (previousY > 9) {
    previousY = 9;
  }
  if (previousX < 0) {
    previousX = 0;
  }
  if (previousX > 9) {
    previousX = 9;
  }
  SnakeSegment *newSegment = new SnakeSegment(previousX, previousY, this->tail->direction);
  this->tail->next = newSegment;
  this->tail = newSegment;
}

bool Snake::snakeTouchingSelf() {
  SnakeSegment *temp = this->head->next;
  while (temp != NULL) {
    if (temp->x == this->head->x && temp->y == this->head->y) {
      return true;
    }
    temp = temp->next;
  }
  return false;
}