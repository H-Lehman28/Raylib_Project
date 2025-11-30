#include <raylib.h>
#include "game.h"
#include "block.h"
#include <iostream>

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main() 
{
    InitWindow(500, 620, "Raylib project");
    Texture2D Iblock = LoadTexture("assets/Iblock.png");
    SetTargetFPS(60);

    Game game = Game();

    while(WindowShouldClose() == false)
    {
        game.HandleInput();
        if(EventTriggered(0.2))
        {
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(DARKBLUE);
        DrawText("Score", 355, 15, 38, WHITE);
        DrawText("High Score", 325, 175, 28, WHITE);
        DrawText("Next", 365, 335, 38, WHITE);
        if(game.gameOver)
        {
            DrawText("GAME OVER", 322, 570, 28, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, BLUE);
        DrawRectangleRounded({320, 215, 170, 60}, 0.3, 6, BLUE);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        int scoreTextSize = MeasureText(scoreText, 38);

        char highScoreText[10];
        sprintf(highScoreText, "%d", game.highScore);
        int highScoreTextSize = MeasureText(highScoreText, 38);

        DrawText(scoreText, 320 + (170 - scoreTextSize)/2, 65, 38, WHITE);
        DrawText(highScoreText, 320 + (170 - highScoreTextSize)/2, 225, 38, WHITE);
        DrawRectangleRounded({320, 375, 170, 180}, 0.3, 6, BLUE);
        game.Draw();
        EndDrawing();
    }

    UnloadTexture(Iblock);
    
    CloseWindow();
}