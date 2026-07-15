#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <raylib.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef i8 b8;
typedef i32 b32;

typedef float f32;
typedef double f64;

#define CELL_SIZE 42
#define BOARD_SIZE 8 
#define NUM_MINES 12

Vector2 mouse = { -1, -1};
Vector2 selectedTile = {-1, -1};

typedef struct {
  i32 x;
  i32 y;
} mine;

typedef struct {
  u32* nums;
  u32 size;
} mine_array;

i32 nums[BOARD_SIZE+2][BOARD_SIZE+2];
char cells[BOARD_SIZE+2][BOARD_SIZE+2];

void populate(i32 p, i32 q ) {
  nums[p-1][q-1] += 1;
  nums[p-1][q] += 1;
  nums[p-1][q+1] += 1;
  nums[p][q-1] += 1;
  nums[p][q+1] += 1;
  nums[p+1][q-1] += 1;
  nums[p+1][q] += 1;
  nums[p+1][q+1] += 1;

}
mine* initBoard(mine* mines){
  for (i32 i = 0; i< 12; i++){
     mines[i].x = (rand() % BOARD_SIZE)+1;
     mines[i].y = (rand() % BOARD_SIZE)+1;
     populate(mines[i].x,mines[i].y);
  }
  return mines;
}

mine* addMines(mine* mines) {
  for ( i32 i = 0; i < NUM_MINES; i++) {
       nums[mines[i].x][mines[i].y] = 9;
  }
  return mines;
}

void clearBoard() {
  memset(nums, 0, sizeof(nums));
  memset(cells, '%', sizeof(cells));
}

void openTile(i32 x, i32 y){
   char b[2];
   sprintf(b, "%d",nums[x+1][y+1]);
   // cells[x+1][y+1] = (char)nums[x+1][y+1];
   cells[x+1][y+1] = b[0];
}


int main(void) {


  clearBoard();
  u32 numMines = NUM_MINES;
  mine* mines = (mine*)malloc(sizeof(mine) * numMines);
  srand(time(NULL));

  mines = initBoard(mines);
  printf("intialised board\n");

  addMines(mines);
  free(mines);

  printf("%d %d %d \n", nums[8][1], nums[6][2],nums[4][3]);



  const i32 screenWidth = 800;
  const i32 screenHeight = 450;


  InitWindow(screenWidth, screenHeight, "bello");
  SetTargetFPS(20);

  while(!WindowShouldClose()) {

    mouse = GetMousePosition();
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      i8 x = mouse.x / CELL_SIZE;
      i8 y = mouse.y / CELL_SIZE;
      if ( x >= 0 && x <= BOARD_SIZE && y >= 0 && y <= BOARD_SIZE ) {
        selectedTile = (Vector2){ x, y };
      }
    }
        


    BeginDrawing();
    ClearBackground(BLACK);

    for (i32 x = 0; x< BOARD_SIZE; x++){
      for (i32 y =0; y< BOARD_SIZE; y++){
        Rectangle rect = {
          x * CELL_SIZE,
          y * CELL_SIZE,
          CELL_SIZE,
          CELL_SIZE
        };
        DrawRectangleLinesEx(rect, 1, DARKBLUE);

        DrawTextEx(
          GetFontDefault(),
          TextFormat("%c", cells[x+1][y+1]),
          (Vector2) { rect.x +12, rect.y+8},
          20, 1, WHITE
        );
          
      }
    }

    if (selectedTile.x >= 0) {
      DrawRectangleLinesEx((Rectangle) {
        selectedTile.x * CELL_SIZE,
        selectedTile.y * CELL_SIZE,
        CELL_SIZE, CELL_SIZE
        }, 2, GREEN);
        openTile(selectedTile.x, selectedTile.y);
    }



    EndDrawing();
  }

  CloseWindow();
return 0;
}
