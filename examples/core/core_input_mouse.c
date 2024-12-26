/*******************************************************************************************
*
*   raylib [core] example - Mouse input
*
*   Example originally created with raylib 1.0, last time updated with raylib 4.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2014-2024 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - mouse input");

    Vector2 ballPosition = { -100.0f, -100.0f };
    Color ballColor = rl_DARKBLUE;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //---------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        ballPosition = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) ballColor = rl_MAROON;
        else if (IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE)) ballColor = rl_LIME;
        else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) ballColor = rl_DARKBLUE;
        else if (IsMouseButtonPressed(MOUSE_BUTTON_SIDE)) ballColor = rl_PURPLE;
        else if (IsMouseButtonPressed(MOUSE_BUTTON_EXTRA)) ballColor = rl_YELLOW;
        else if (IsMouseButtonPressed(MOUSE_BUTTON_FORWARD)) ballColor = rl_ORANGE;
        else if (IsMouseButtonPressed(MOUSE_BUTTON_BACK)) ballColor = rl_BEIGE;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(rl_RAYWHITE);

            DrawCircleV(ballPosition, 40, ballColor);

            DrawText("move ball with mouse and click mouse button to change color", 10, 10, 20, rl_DARKGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}