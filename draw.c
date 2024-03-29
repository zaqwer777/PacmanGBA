#include "draw.h"
#include "gba.h"
#include "images/pacman.h"
#include "images/pacChar.h"
#include "images/gg.h"
#include <stdio.h>

// TA-TODO: Include any header files for images generated by nin10kit.
// Example for the provided garbage image:
// #include "images/garbage.h"

// TA-TODO: Add any draw/undraw functions for sub-elements of your app here.
// For example, for a snake game, you could have a drawSnake function
// or a drawFood function
//
// e.g.:
// static void drawSnake(Snake* snake);
// static void drawFood(Food* food);

// This function will be used to draw everything about the app
// including the background and whatnot.
void fullDrawAppState(AppState *state) {
    // TA-TODO: IMPLEMENT.
    fillScreenDMA(BLACK);

    drawRectDMA(0, 0, 180, 160, BLUE);
    for (int i = 0; i < state->foodStart; i++) {
        int rand1 = randint(1, 15);
        int rand2 = randint(1, 15);
        while (70 < 10 * rand1 && 10 * rand1 < 100) {
            rand1 = randint(0, 15);
        }
        while (60 < 10 * rand2 && 10 * rand2 < 90) {
            rand2 = randint(0, 15);
        }
        drawRectDMA(10 * rand1, 10 * rand2, 1, 1, MAGENTA);
    }
    //SCORE
    drawString(190, 10, "Score:" , YELLOW);
    char scoreNum[2];
    sprintf(scoreNum, "%d", state->foodEaten);
    drawString(205, 20, scoreNum, YELLOW);

    drawString(182, 50, "Use your", YELLOW);
    drawString(182, 60, "arrows to", YELLOW);
    drawString(182, 70, "move the", YELLOW);
    drawString(182, 80, "character.", YELLOW);

    drawString(182, 100, "Press the", YELLOW);
    drawString(182, 110, "select", YELLOW);
    drawString(182, 120, "button to", YELLOW);
    drawString(182, 130, "restart.", YELLOW);
}

// This function will be used to undraw (i.e. erase) things that might
// move in a frame. E.g. in a Snake game, erase the Snake, the food & the score.
void undrawAppState(AppState *state) {
    // TA-TODO: IMPLEMENT.
    drawRectDMA(20, 205, 20, 10, BLACK);

    //Pacman
    if (state->oldCharRow > state->charRow) {
        drawRectDMA(state->charRow + PACCHAR_HEIGHT, state->charCol - 1, PACCHAR_WIDTH + 2, 1, BLUE);
    }
    //Move Down
    if (state->oldCharRow < state->charRow) {
        drawRectDMA(state->charRow - 1, state->charCol - 1, PACCHAR_WIDTH + 2, 1, BLUE);
    }
    //Move Left
    if (state->oldCharCol > state->charCol) {
        drawRectDMA(state->charRow - 1, state->charCol + PACCHAR_WIDTH, 1, PACCHAR_HEIGHT + 2, BLUE);
    }
    //Move Right
    if (state->oldCharCol < state->charCol) {
        drawRectDMA(state->charRow - 1, state->charCol - 1, 1, PACCHAR_HEIGHT + 2, BLUE);
    }
}

// This function will be used to draw things that might have moved in a frame.
// For example, in a Snake game, draw the snake, the food, the score.
void drawAppState(AppState *state) {
    // TA-TODO: IMPLEMENT
    drawImageDMA(state->charRow, state->charCol, PACCHAR_WIDTH, PACCHAR_HEIGHT, pacChar);

    char scoreNum[2];
    sprintf(scoreNum, "%d", state->foodEaten);
    drawString(205, 20, scoreNum, YELLOW);
}

void drawStartScreen(void) {
    drawFullScreenImageDMA(pacman);
    drawString(60, 80, "PRESS START TO BEGIN", MAGENTA);
    drawString(50, 30, "Scuffed Pacman Edition", YELLOW);
}
