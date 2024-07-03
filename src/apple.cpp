#include "../include/apple.hpp"

#include <random>

Apple::Apple(GameGrid* grid) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> distr_x(0, grid->height);
  std::uniform_int_distribution<int> distr_y(0, grid->height);
  x = distr_x(gen);
  y = distr_y(gen);
}

bool Apple::appleTouchingSnake(Snake *snake, GameGrid *grid) {
  SnakeSegment *temp = snake->head;
  while (temp != NULL) {
    if (temp->x == x && temp->y == y) {
      return true;
    }
    temp = temp->next;
  }
  return false;
}
