#include <raylib.h>
#include <stdio.h>

#include "grid.h"
#include "raymath.h"
#include "rlgl.h"
#include "snake.h"

#define CELL_SIZE 40

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
  GameGrid *grid = createGameGrid(10, 10);
  Snake *snake = createSnake(5, 5, UP);
  const int screenWidth = grid->width * CELL_SIZE;
  const int screenHeight = grid->height * CELL_SIZE;
  int cellWidth = screenWidth / grid->width;
  int cellHeight = screenHeight / grid->height;

  InitWindow(screenWidth, screenHeight, "Snake!");

  SetTargetFPS(60);  // Set our game to run at 60 frames-per-second

  /* Populate the grid with some initial cell states */
  // setToroidalGrid(grid, 0, 1, ALIVE);

  /* Loop until window close button or ESC key is pressed */
  while (!WindowShouldClose()) {
    /* Begin drawing */
    BeginDrawing();

    /* Draw background */
    DrawRectangle(
        0, 0, cellWidth * grid->height, cellHeight * grid->height, BLACK);

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

    // SnakeSegment * temp = snake->head;
    // while (temp != NULL) {
    //   // DrawRectangle(temp->x * cellWidth, temp->y * cellHeight, cellWidth,
    //   cellHeight, GREEN);
    //   }
    //   temp = temp->next;
    // }

    // /* End drawing */
    // EndDrawing();

    // /* Update the grid */
    // moveSnake(snake, grid);
  }

  /* Close window and OpenGL context */
  CloseWindow();
  freeGameGrid(grid);
  return 0;
}