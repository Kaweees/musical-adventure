#pragma once

#include <stdbool.h>

#include "../include/grid.hpp"

// Enum to represent the direction of the snake
enum class SnakeDirection {
  UP,
  DOWN,
  LEFT,
  RIGHT
};

class SnakeSegment {
  public:
    // Constructor to initialize memory
    SnakeSegment(int x, int y, SnakeDirection direction);

    // Destructor to free the memory allocated
    ~SnakeSegment();

    // The x-coordinate of the snake segment
    int x;
    // The y-coordinate of the snake segment
    int y;
    // The direction of the snake segment
    SnakeDirection direction;
    // The next snake segment
    SnakeSegment *next;
};

class Snake {
  public:
    // Constructor to initialize memory
    Snake(int x, int y, SnakeDirection direction);

    // Destructor to free the memory allocated
    ~Snake();

    // The head of the snake
    SnakeSegment *head;
    // The tail of the snake
    SnakeSegment *tail;

    void moveSnake(GameGrid *grid);
};
