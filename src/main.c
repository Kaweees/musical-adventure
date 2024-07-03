#include <raylib.h>
#include <stddef.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "grid.h"
#include "raymath.h"
#include "rlgl.h"
#include "snake.h"

#define CELL_SIZE 20

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
  srand(time(NULL)); // Seed the RNG with current time
  GameGrid *grid = createGameGrid(10, 10);
  Snake *snake = createSnake(0, 0, UP);
  const int screenWidth = grid->width * CELL_SIZE;
  const int screenHeight = grid->height * CELL_SIZE;
  int cellWidth = screenWidth / grid->width;
  int cellHeight = screenHeight / grid->height;

  InitWindow(screenWidth, screenHeight, "Snake!");

  SetTargetFPS(10);  // Set our game to run at 60 frames-per-second

  /* Loop until window close button or ESC key is pressed */
  while (!WindowShouldClose()) {
    /* Begin drawing */
    BeginDrawing();

    /* Draw background */
    ClearBackground(BLACK);

    /* Draw snake on the grid */
    SnakeSegment *temp = snake->head;
    while (temp != NULL) {
      DrawRectangle(temp->x * cellWidth, temp->y * cellHeight, cellWidth,
          cellHeight, GREEN);
      temp = temp->next;
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

    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
      snake->head->direction = UP;
    }
    if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
      snake->head->direction = DOWN;
    }
    if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
      snake->head->direction = LEFT;
    }
    if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
      snake->head->direction = RIGHT;
    }

    /* Generate a random coordinate for apple */
    int random_x = rand() % (grid->height + 1);
    int random_y = rand() % (grid->width + 1);

    /* Update the snake */
    moveSnake(snake, grid);
  }

  /* Close window and OpenGL context */
  CloseWindow();

  /* De-allocate memory */
  freeGameGrid(grid);
  freeSnake(snake);
  return 0;
}