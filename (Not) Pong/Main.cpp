
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
struct Paddle
{
    float x, y;
    float speed;
    float width, height;

    Rectangle GetRect()
    {
        return Rectangle { x - width / 2 ,y - height / 2, 10, 100 };
    } 

    void Draw()
    {
        DrawRectangleRec(GetRect(), WHITE);
    }
};
int main(int argc, char* argv[])
{
    // Initialization
   //--------------------------------------------------------------------------------------
    InitWindow(800, 600, "Definitely (Not) Pong");
    SetWindowState(FLAG_VSYNC_HINT);
    //--------------------------------------------------------------------------------------

    float deltaTime = 0;
    
#pragma region Ball
    Ball ball;
    ball.x = GetScreenWidth() / 2.0f; 
    ball.y = GetScreenHeight() / 2.0f; //inital position of the ball (should be in middle of screen)
    ball.speedX = 300;
    ball.speedY = 300; // Inital Speed of Ball on both direction X and Y
    ball.radius = 5; // Size of the pong ball
#pragma endregion

#pragma region leftPaddle
    Paddle leftPaddle;
    leftPaddle.x = 50;
    leftPaddle.y = GetScreenHeight() / 2;
    leftPaddle.width = 10;
    leftPaddle.height = 100;
    leftPaddle.speed = 500;
#pragma endregion

#pragma region rightPaddle 
    Paddle rightPaddle;
    rightPaddle.x = GetScreenWidth() - 50;
    rightPaddle.y = GetScreenHeight() / 2;
    rightPaddle.width = 10;
    rightPaddle.height = 100;
    rightPaddle.speed = 500;
#pragma endregion

    const char* scoreText = nullptr;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        deltaTime = GetFrameTime();
        ball.x += ball.speedX * GetFrameTime();
        ball.y += ball.speedY * GetFrameTime();
        // Update
        //----------------------------------------------------------------------------------
#pragma region Ball Movement Update
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
#pragma endregion

#pragma region Paddle Movement
        if (IsKeyDown(KEY_W))
        {
            leftPaddle.y -= leftPaddle.speed * GetFrameTime();
        }
        if (IsKeyDown(KEY_S))
        {
            leftPaddle.y += leftPaddle.speed * GetFrameTime();
        }
        if (IsKeyDown(KEY_UP))
        {
            rightPaddle.y -= leftPaddle.speed * GetFrameTime();
        }
        if (IsKeyDown(KEY_DOWN))
        {
            rightPaddle.y += leftPaddle.speed * GetFrameTime();
        }

#pragma endregion

#pragma region BallRectCollusion
        if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, rightPaddle.GetRect()))
        {
            if (ball.speedX < 0)
            {
                ball.speedX *= -1.1f;
                ball.speedY = (ball.y - rightPaddle.y) / (rightPaddle.height / 2) * -ball.speedX;
            }
            ball.speedX *= -1;
        }
        if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, leftPaddle.GetRect()))
        {
            if (ball.speedX > 0)
            {
                ball.speedX *= -1.1;
                ball.speedY = (ball.y - leftPaddle.y) / (leftPaddle.height / 2) * -ball.speedX;
            }
            ball.speedX *= -1;
        }
#pragma endregion

#pragma region WinCondition
        if (ball.x < 0)
        {
            scoreText = "Player Right Scored!!!!";
        }
        if (ball.x > GetScreenWidth())
        {
            scoreText = "Player Left Scored!!!!";
        }
        if (scoreText && IsKeyPressed(KEY_SPACE))
        {
            ball.x = GetScreenWidth() / 2;
            ball.y = GetScreenHeight() / 2;
            ball.speedX = 300;
            ball.speedY = 300;
            scoreText = nullptr;
        }
#pragma endregion

        
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(BLACK);
        ball.Draw();
        leftPaddle.Draw();
        rightPaddle.Draw();
        if (scoreText)
        {
            int textWidth = MeasureText(scoreText, 60);
            DrawText(scoreText, GetScreenWidth() /  2 - textWidth / 2, GetScreenHeight() / 2 - 30, 60, WHITE);
        }
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
