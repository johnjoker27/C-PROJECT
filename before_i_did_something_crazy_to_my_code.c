#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
    PLAYER_X,
    PLAYER_O
} player;

char GRID[3][3];
player CURRENT_PLAYER = PLAYER_X;
bool vs_computer = false;


void init_grid();
void print_grid();
void swap_player();
bool check_tie();
bool check_rows();
bool check_columns();
bool check_diagonals();
bool check_winner();
void computer_move();
void player_move();

int main() {
    srand(time(NULL));

    char play_again = 'y';

    while(play_again=='y'||play_again == 'Y'){

    init_grid();


    int mode = 1;
    printf("Choose mode:\n1. Player vs Player\n2. Player vs Computer\n3.Exit\n");
    if (scanf("%d", &mode) != 1) {
        printf("Invalid input! Defaulting to Player vs Player.\n");
        mode = 1;
    }
    if (mode == 2) {
        vs_computer = true;
    }
    if(mode == 3){
        printf("You choose to leave the game :(  BYE!");
        exit(0);
    }


    bool game_running = true;

    while (game_running) {
        printf("\n***************************\n");
        print_grid();

        if (vs_computer && CURRENT_PLAYER == PLAYER_O) {
            computer_move();
        } else {
            player_move();
        }

        if (check_winner()) {
            print_grid();
            if (vs_computer && CURRENT_PLAYER == PLAYER_O) {
                printf("Winner: Computer (O)\n");
            } else {
                printf("Winner: %c\n", CURRENT_PLAYER == PLAYER_X ? 'X' : 'O');
            }
            break;
        }

        if (check_tie()) {
            print_grid();
            printf("TIE!\n");
            break;
        }

        swap_player();
    }

    printf("Thanks for playing!\n");
    }

    printf("\n Would you want to play again?(y/n): ");
    scanf(" %c",&play_again);


    return 0;
}


void init_grid() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            GRID[i][j] = '-';
}


void print_grid() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf("%c ", GRID[i][j]);
        printf("\n");
    }
}


void swap_player() {
    CURRENT_PLAYER = (CURRENT_PLAYER == PLAYER_X) ? PLAYER_O : PLAYER_X;
}


bool check_tie() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (GRID[i][j] == '-')
                return false;
    return true;
}


bool check_rows() {
    for (int i = 0; i < 3; i++)
        if (GRID[i][0] != '-' && GRID[i][0] == GRID[i][1] && GRID[i][1] == GRID[i][2])
            return true;
    return false;
}


bool check_columns() {
    for (int i = 0; i < 3; i++)
        if (GRID[0][i] != '-' && GRID[0][i] == GRID[1][i] && GRID[1][i] == GRID[2][i])
            return true;
    return false;
}


bool check_diagonals() {
    if (GRID[0][0] != '-' && GRID[0][0] == GRID[1][1] && GRID[1][1] == GRID[2][2])
        return true;
    if (GRID[0][2] != '-' && GRID[0][2] == GRID[1][1] && GRID[1][1] == GRID[2][0])
        return true;
    return false;
}


bool check_winner() {
    return check_rows() || check_columns() || check_diagonals();
}


void player_move() {
    int row, col;

    while (true) {
        printf("\nPlayer %c, enter row and column (1-3): nb:one value before the other[press enter after each value entered..... ] or enter 0 0 to quit",
               CURRENT_PLAYER == PLAYER_X ? 'X' : 'O');

        if (scanf("%d %d", &row, &col) != 2) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Invalid input! Enter numbers between 1 and 3 or 0 0 to quit.\n");
            continue;
        }


        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        if(row == 0 && col == 0){
            printf("Player chose to exit the game. Goodbye!\n");
            exit(0);
        }

        if (row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Invalid input! Row and column must be 1, 2, or 3.\n");
            continue;
        }

        if (GRID[row-1][col-1] != '-') {
            printf("That space is already taken. Try again.\n");
            continue;
        }

        GRID[row-1][col-1] = (CURRENT_PLAYER == PLAYER_X) ? 'X' : 'O';
        break;
    }
}


void computer_move() {
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (GRID[row][col] != '-');

    GRID[row][col] = 'O';
    printf("Computer chooses: %d %d\n", row+1, col+1);
}
