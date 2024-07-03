#pragma once

#include <stdbool.h>

#include "../include/grid.hpp"
#include "../include/snake.hpp"

// A class representing an Apple
class Apple {
  public:
    // Constructor to initialize memory
    Apple(GameGrid* grid);

    // Frees the memory allocated
    ~Apple();

    // The x-coordinate of the apple
    int x;
    // The y-coordinate of the apple
    int y;

    // Check if an apple is touching a snake
    bool appleTouchingSnake(Snake *snake, GameGrid *grid);
};
