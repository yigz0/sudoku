#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// n -> n + 1
int board[9][9];
int row[9][10] = {};
int col[9][10] = {};
int squ[9][10] = {};

int zero = 0;
int fin = 0;

struct Blank
{
    int x, y;
} blanks[100];

int square(int x, int y)
{
    return 3 * (x / 3) + (y / 3);
}

void roll(int step)
{
	if(step > zero) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        fin = 1;
        return;
	}

	int X = blanks[step].x;
	int Y = blanks[step].y;

    for(int k = 1; k <= 9; k++) {
        if(fin == 1) return;

        if(row[X][k] == 0 && col[Y][k] == 0 && squ[square(X, Y)][k] == 0) {
            board[X][Y] = k;
            row[X][k] = 1;
            col[Y][k] = 1;
            squ[square(X, Y)][k] = 1;

            roll(step + 1);

            board[X][Y] = 0;
            row[X][k] = 0;
            col[Y][k] = 0;
            squ[square(X, Y)][k] = 0;
        }
    }
}

int main()
{
    int tmp;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            scanf("%d", &tmp);
            board[i][j] = tmp;

            row[i][tmp] = 1;
            col[j][tmp] = 1;
            squ[square(i, j)][tmp] = 1;

            if(tmp == 0) {
                zero++;

                blanks[zero].x = i;
                blanks[zero].y = j;
            }
        }
    }

    roll(1);

    return 0;
}
