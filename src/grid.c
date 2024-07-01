#include "grid.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

GameGrid *createGameGrid(int width, int height) {
  GameGrid *grid = malloc(sizeof(GameGrid));
  if (grid == NULL) {
    perror("Error allocating memory for game grid");
    exit(EXIT_FAILURE);
  }
  grid->width = width;
  grid->height = height;
  return grid;
}

void freeGameGrid(GameGrid *grid) { free(grid); }