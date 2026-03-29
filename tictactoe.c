#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 3

char board[SIZE][SIZE];
char player = 'X';
char ai = 'O';

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|\");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---+---+---\n");
    }
    printf("\n");
}

bool isMovesLeft() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') return true;
        }
    }
    return false;
}

bool checkWin(char ch) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == ch && board[i][1] == ch && board[i][2] == ch) ||
            (board[0][i] == ch && board[1][i] == ch && board[2][i] == ch)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == ch && board[1][1] == ch && board[2][2] == ch) ||
        (board[0][2] == ch && board[1][1] == ch && board[2][0] == ch)) {
        return true;
    }
    return false;
}

int minimax(int depth, bool isMax) {
    if (checkWin(ai)) return 10 - depth;
    if (checkWin(player)) return depth - 10;
    if (!isMovesLeft()) return 0;

    if (isMax) {
        int best = -1000;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = ai;
                    best = fmax(best, minimax(depth + 1, !isMax));
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    } else {
        int best = 1000;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = player;
                    best = fmin(best, minimax(depth + 1, !isMax));
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
}

void bestMove() {
    int bestVal = -1000;
    int row = -1, col = -1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = ai;
                int moveVal = minimax(0, false);
                board[i][j] = ' ';
                if (moveVal > bestVal) {
                    row = i;
                    col = j;
                    bestVal = moveVal;
                }
            }
        }
    }
    board[row][col] = ai;
}

void playerMove() {
    int row, col;
    while (true) {
        printf("Enter row and column (0, 1, or 2) separated by space: ");
        if (scanf("%d %d", &row, &col) != 2 || row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
            printf("Invalid input. Please try again.\n");
            while (getchar() != '\n'); // clear the buffer
        } else {
            break;
        }
    }
    board[row][col] = player;
}

int main() {
    initializeBoard();
    printf("Tic-Tac-Toe Game\n");
    while (isMovesLeft()) {
        printBoard();
        playerMove();
        if (checkWin(player)) {
            printBoard();
            printf("Player wins!\n");
            return 0;
        }
        if (!isMovesLeft()) break;
        bestMove();
        if (checkWin(ai)) {
            printBoard();
            printf("AI wins!\n");
            return 0;
        }
    }
    printBoard();
    printf("It's a draw!\n");
    return 0;
}