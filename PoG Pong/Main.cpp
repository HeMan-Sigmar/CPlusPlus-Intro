#include "raylib.h"
#include <iostream>

struct Ball
{
    float x, y;
    float speedX, speedY;
    float radius;
    
    void Draw()
    {
        DrawCircle((int)x, (int)y, radius, WHITE);
    }
};
struct Paddles
{
    float x, y;
    float speed;
    float width, height;

    void Draw()
    {

    }
};
    int main(int argc, char* argv[])
    {
        // Initialization
       //--------------------------------------------------------------------------------------
        InitWindow(800, 600, "Bonk");
        SetWindowState(FLAG_VSYNC_HINT);
        //--------------------------------------------------------------------------------------
        Ball ball;
        float deltaTime = 0;
        ball.x = GetScreenWidth() / 2.0f;
        ball.speedX = 300;
        ball.y = GetScreenHeight() / 2.0f;
        ball.speedY = 300;
        ball.radius = 5;
        
        Paddles leftPaddle;
        leftPaddle.x = 50;
        leftPaddle.y = GetScreenHeight() / 2 - 50;
        leftPaddle.width = 10;
        leftPaddle.height = 100; 
        leftPaddle.speed = 500; 
        // Main game loop
        while (!WindowShouldClose())    // Detect window close button or ESC key
        {
            deltaTime = GetFrameTime();
            ball.x += ball.speedX * GetFrameTime();
            ball.y += ball.speedY * GetFrameTime();
            // Update
            //----------------------------------------------------------------------------------
            if (ball.y < 0)
            {
                ball.y = 0;
                ball.speedY *= -1;
            }
            if (ball.y > GetScreenHeight())
            {
                ball.y = GetScreenHeight();
                ball.speedY *= -1;
            }


            //----------------------------------------------------------------------------------

            // Draw
            //----------------------------------------------------------------------------------
            BeginDrawing();
            ClearBackground(BLACK);
            ball.Draw();
            DrawRectangle(leftPaddle.x, leftPaddle.y, leftPaddle.width, leftPaddle.height, WHITE);
            DrawRectangle(GetScreenWidth() - 50 - 10, GetScreenHeight() / 2 - 50, 10, 100, WHITE);
            DrawFPS(0, 0);
            EndDrawing();
            //----------------------------------------------------------------------------------
        }
        CloseWindow();
        // De-Initialization
        //--------------------------------------------------------------------------------------   
        
        //--------------------------------------------------------------------------------------

        return 0;
    }

