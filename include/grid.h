#ifndef GRID_H
#define GRID_H

#include <stdbool.h>

/* Begin typedef declarations */

/* Represents the grid */
typedef struct GameGrid {
  int width;
  int height;
} GameGrid;

/* Begin function prototype declarations */

/* Creates a game grid */
GameGrid *createGameGrid(int width, int height);

/* Frees the memory allocated for a game grid */
void freeGameGrid(GameGrid *grid);

#endif /* GRID_H */