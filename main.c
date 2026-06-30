#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <raylib.h>
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

#define BLOCK_SIZE 42
#define BOARD_SIZE 8 

typedef struct {
  i32 x;
  i32 y;
} mine;

typedef struct {
  u32* nums;
  u32 size;
} mine_array;

i32 mineboard[BOARD_SIZE+2][BOARD_SIZE+2];
i32 nums[BOARD_SIZE+2][BOARD_SIZE+2];
mine* mines;
i32 x, y;

void populate(i32 p, i32 q) {
  nums[p-1][q-1] += 1;
  nums[p-1][q] += 1;
  nums[p-1][q+1] += 1;
  nums[p][q-1] += 1;
  nums[p][q+1] += 1;
  nums[p+1][q-1] += 1;
  nums[p+1][q] += 1;
  nums[p+1][q+1] += 1;

}
void mines(){
  for (i32 i = 0; i< 12; i++){
     mines[i]->x = (rand() % BOARD_SIZE)+1;
     y = (rand() % BOARD_SIZE)+1;
     mineboard[x][y] = -1;
     populate(x,y);
  }
}


int main(void) {
  const i32 screenWidth = 800;
  const i32 screenHeight = 450;


  InitWindow(screenWidth, screenHeight, "bello");
  SetTargetFPS(20);

  while(!WindowShouldClose()) {


    BeginDrawing();
    ClearBackground(BLACK);

    DrawText("mooooooo", 190, 200, 20, LIGHTGRAY );

    EndDrawing();
  }

  CloseWindow();

  return 0;

}
