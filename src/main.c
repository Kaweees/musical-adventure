#include <raylib.h>

#include "raymath.h"
#include "rlgl.h"
#include "snake.h"
#include "grid.h"

#define CELL_SIZE 40

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
  ToroidalGrid *grid = createToroidalGrid(10, 10);
  const int screenWidth = grid->width * CELL_SIZE;
  const int screenHeight = grid->height * CELL_SIZE;
  int cellWidth = screenWidth / grid->width;
  int cellHeight = screenHeight / grid->height;

  InitWindow(screenWidth, screenHeight, "Snake!");

  SetTargetFPS(60);  // Set our game to run at 60 frames-per-second

  /* Populate the grid with some initial cell states */
  setToroidalGrid(grid, 0, 1, ALIVE);

  /* Loop until window close button or ESC key is pressed */
  while (!WindowShouldClose()) {
    /* Begin drawing */
    BeginDrawing();

    /* Draw horizontal lines */
    for (int i = 0; i < grid->width; i++) {
      for (int j = 0; j < grid->height; j++) {
        DrawRectangle(i * cellWidth, j * cellHeight, cellWidth, cellHeight,
            getToroidalGrid(grid, i, j) ? GREEN : BLACK);
      }
    }

    /* Draw horizontal lines */
    for (int i = 1; i < grid->height; ++i) {
      DrawLine(0, i * cellHeight, screenWidth, i * cellHeight, WHITE);
    }

    /* Draw vertical lines */
    for (int j = 1; j < grid->width; ++j) {
      DrawLine(j * cellWidth, 0, j * cellWidth, screenHeight, WHITE);
    }

    /* End drawing */
    EndDrawing();

    /* Update the grid */
    updateBoard(&grid);
  }

  /* Close window and OpenGL context */
  CloseWindow();
  freeToroidalGrid(grid);
  return 0;
}