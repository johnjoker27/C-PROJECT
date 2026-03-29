
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef enum
{
    PLAYER_X,
    PLAYER_O
} player;

void print_grid();
void swap_player();
bool check_tie();
bool check_rows();
bool check_columns();
bool check_diagonals();
bool check_winner();
void computer_move();

char GRID[3][3] =
{
    {'-','-','-'},
    {'-','-','-'},
    {'-','-','-'}
};

player CURRENT_PLAYER = PLAYER_X;
bool vs_computer = false;

int main()
{
    srand(time(NULL));


    int mode = 1;
    printf("Choose mode:\n1. Player vs Player\n2. Player vs Computer\n");
    scanf("%d", &mode);
    if(mode == 2)
    {
        vs_computer = true;
    }


    bool game_running = true;

    while(game_running)
    {
        int row, column;

        printf("\n*************************************************************************\n\n");
        print_grid();

        if(vs_computer && CURRENT_PLAYER == PLAYER_O)
        {
            computer_move();

            if(check_winner())
            {
                print_grid();
                printf("\nWinner: Computer (O)\n");
                game_running = false;
                continue;
            }

            if(check_tie())
            {
                print_grid();
                printf("\nTIE\n");
                game_running = false;
                continue;
            }

            swap_player();
            continue;
        }


        printf("\nPlayer: %c\nPlease enter row column (1-3): ",
               CURRENT_PLAYER == PLAYER_X ? 'X' : 'O');

        if(scanf("%d %d", &row, &column) != 2)
        {
            printf("Invalid input!\n");
            return 1;
        }

        if(row < 1 || row > 3 || column < 1 || column > 3)
            continue;

        if(GRID[row - 1][column - 1] != '-')
        {
            printf("That space is already taken\n");
            continue;
        }


        GRID[row - 1][column - 1] =
            CURRENT_PLAYER == PLAYER_X ? 'X' : 'O';


        if(check_winner())
        {
            print_grid();
            printf("\nWinner: %c\n",
                   CURRENT_PLAYER == PLAYER_X ? 'X' : 'O');
            game_running = false;
            continue;
        }


        if(check_tie())
        {
            print_grid();
            printf("\nTIE\n");
            game_running = false;
            continue;
        }

        swap_player();
    }

    return 0;
}

void print_grid()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
            printf("%c ", GRID[i][j]);
        printf("\n");
    }
}

void swap_player()
{
    CURRENT_PLAYER = (CURRENT_PLAYER == PLAYER_X) ? PLAYER_O : PLAYER_X;
}

bool check_tie()
{
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(GRID[i][j] == '-')
                return false;
    return true;
}

bool check_rows()
{
    for(int i = 0; i < 3; i++)
        if(GRID[i][0] != '-' && GRID[i][0] == GRID[i][1] && GRID[i][1] == GRID[i][2])
            return true;
    return false;
}

bool check_columns()
{
    for(int i = 0; i < 3; i++)
        if(GRID[0][i] != '-' && GRID[0][i] == GRID[1][i] && GRID[1][i] == GRID[2][i])
            return true;
    return false;
}

bool check_diagonals()
{
    if(GRID[0][0] != '-' && GRID[0][0] == GRID[1][1] && GRID[1][1] == GRID[2][2])
        return true;
    if(GRID[0][2] != '-' && GRID[0][2] == GRID[1][1] && GRID[1][1] == GRID[2][0])
        return true;
    return false;
}

bool check_winner()
{
    return check_rows() || check_columns() || check_diagonals();
}

void computer_move()
{
    int row, col;
    do
    {
        row = rand() % 3;
        col = rand() % 3;
    } while(GRID[row][col] != '-');

    GRID[row][col] = 'O';
    printf("Computer chooses: %d %d\n", row + 1, col + 1);
}
