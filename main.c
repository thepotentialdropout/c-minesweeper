#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <raylib.h>

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

typedef struct {
  f32 x;
  f32 y;
} vec2f;

typedef struct {
  u32* nums;
  u32 size;
} num_array;

int main(void) {
  const i32 screenWidth = 800;
  const i32 screenHeight = 450;


  InitWindow(screenWidth, screenHeight, "bello");
  SetTargetFPS(60);

  while(!WindowShouldClose()) {


    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawText("niggamooooooo", 190, 200, 20, LIGHTGRAY );

    EndDrawing();
  }

  CloseWindow();

  return 0;

}
