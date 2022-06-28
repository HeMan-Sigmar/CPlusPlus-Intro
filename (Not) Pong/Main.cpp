
#include "raylib.h"
#include <iostream>

struct Ball
{
    float x, y; //position of the ball
    float speedX, speedY; // speed of the ball
    float radius; // size of the ball

    void Draw()
    {
        DrawCircle((int)x, (int)y, radius, WHITE); // Draws the ball while positioned in the middle of the screen
    }
};
struct Paddle
{
    float x, y; // position of the paddles
    float speed; // speed of the paddles
    float width, height; // size of the paddles

    Rectangle GetRect()
    {
        return Rectangle { x - width / 2 ,y - height / 2, 10, 100 }; 
    } 

    void Draw()
    {
        DrawRectangleRec(GetRect(), WHITE); // draws rectangle as white
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
    ball.y = GetScreenHeight() / 2.0f; //inital position of the ball (Positioned in middle of screen)
    ball.speedX = 300;
    ball.speedY = 300; // Inital Speed of Ball on both direction X and Y
    ball.radius = 5; // Size of the pong ball
#pragma endregion

#pragma region leftPaddle
    Paddle leftPaddle;
    leftPaddle.x = 50;
    leftPaddle.y = GetScreenHeight() / 2; // inital position of left paddle
    leftPaddle.width = 10;
    leftPaddle.height = 100; // size of paddle
    leftPaddle.speed = 500; // speed of the paddle
#pragma endregion

#pragma region rightPaddle 
    Paddle rightPaddle;
    rightPaddle.x = GetScreenWidth() - 50;
    rightPaddle.y = GetScreenHeight() / 2; // inital position of right paddle
    rightPaddle.width = 10;
    rightPaddle.height = 100;// size of paddle
    rightPaddle.speed = 500;// speed of the paddle
#pragma endregion

    const char* scoreText = nullptr;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        deltaTime = GetFrameTime();
        ball.x += ball.speedX * GetFrameTime();
        ball.y += ball.speedY * GetFrameTime(); // gives direction of the ball
        // Update
        //----------------------------------------------------------------------------------
#pragma region Ball Movement Update
        if (ball.y < 0) //if ball hits bottom or top of screen -> goes other direction
        {
            ball.y = 0;
            ball.speedY *= -1;
        }
        if (ball.y > GetScreenHeight())//if ball hits top of screen -> goes other direction
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

#pragma region  Paddle Bound
        if (leftPaddle.y > GetScreenHeight()) //Setting up bounds on left paddle in order to prevent from going out of screen
        {
            leftPaddle.y = GetScreenHeight();
        }
        if (leftPaddle.y < 0)
        {
            leftPaddle.y = 0;
        }

        if (rightPaddle.y > GetScreenHeight())//Setting up bounds on right paddle in order to prevent from going out of screen
        {
            rightPaddle.y = GetScreenHeight();
        }
        if (rightPaddle.y < 0)
        {
            rightPaddle.y = 0;
        }
#pragma endreigon
#pragma region BallRectCollusion
        if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, rightPaddle.GetRect())) // collusion of ball against right paddle while giving different direction and increase the speed
        {
            if (ball.speedX < 0) 
            {
                ball.speedX *= -1.1f;
                ball.speedY = (ball.y - rightPaddle.y) / (rightPaddle.height / 2) * -ball.speedX;
            }
            ball.speedX *= -1;
        }
        if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, leftPaddle.GetRect()))// collusion of ball against left paddle while giving different direction and increase the speed
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
        if (ball.x < 0) // if ball hits left side
        {
            scoreText = "Player Right Scored!!!!";

        }
        if (ball.x > GetScreenWidth()) // if ball hits right side
        {
            scoreText = "Player Left Scored!!!!";
  
        }
        if (scoreText && IsKeyPressed(KEY_SPACE)) // resets the game
        {
            scoreText = nullptr;
            ball.x = GetScreenWidth() / 2;
            ball.y = GetScreenHeight() / 2;
            ball.speedX = 300;
            ball.speedY = 300;
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
            DrawText(scoreText, GetScreenWidth() /  2 - textWidth / 2, GetScreenHeight() / 2 - 30, 60, WHITE); // draws the text when either side wins
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
