#include "Engine.h"
#include "Board.h"
#include "Structs.h"

#include <stdlib.h>
#include <iostream>
#include <math.h>


#define PI 3.141592653589793

#define NUM_BLOCK_TYPES 4

vector<Piece> pieceShapes;

Piece* Engine::createPiece() {
    int shape = rand() % pieceShapes.size();
    Piece* piece = new Piece(pieceShapes[shape]);

    for(Piece::iterator i = piece->blocks.begin();
        i != piece->blocks.end(); ++i) 
        {
        i->type = rand() % NUM_BLOCK_TYPES;
    }
}

void Engine::initBoard(int difficulty, Board* board) {
    // The average height of the heap is determined by
    // the difficulty level.
    int avgLevel = rand() % 4 + ((difficulty + 2) / 2);
    // The spread is the difference in heights of antecedent columns.
    int spread = (rand() % difficulty + 1);

    printf("avglevel=%d,", avgLevel);
    printf("spread=%d\n", spread);

    /* A column is a block of the prefilled section of board that is all
       purposely at the same height.
       The number of columns is exactly the difficulty value.
       We will build the columns based on a cosine curve whose peaks and
       troughs will represent columns. We will take >0 and <0 to decide
       when new columns start, and adjust their height using the spread. */

    bool gt0 = false;
    int colheight = 0;

    for (int i = 0; i < board->width(); ++i) {
        float y;
        if (difficulty == 1) {
            y = 1;
        }
        else {
            y = cos((i * PI) / (board->width() / (difficulty - 1)));
        }

        printf("y=%f,", y);

        // A new column when we turn around.
        if ((y > 0) != gt0) {
            int localSpread = rand() % spread;
            colheight = ((y > 0 ? 1 : -1)  * localSpread) + avgLevel;
            gt0 = y > 0;
            printf("colheight=%d\n", colheight);
        }

        for (int j = 0; j < board->height(); ++j) {
            BlockInfo* piece = new BlockInfo;
            piece->x = j;
            piece->y = i;
            piece->highlighted = false;

            // Fill with empty above the column
            if (j < board->height() - colheight) {
                piece->type = 0;
            }
            else {
                piece->type = (rand() % NUM_BLOCK_TYPES)  + 1;
            }
            board->set(piece);
        }
    }
}
