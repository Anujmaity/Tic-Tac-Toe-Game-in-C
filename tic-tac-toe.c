#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void displayBoard(char board[][SIZE]);
int checkWinner(char board[][SIZE], char player);

int main()
{
    char board[SIZE][SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int row, col, moveCount = 0;
    char currentPlayer = 'X';
    printf("Welcome to Tic-Tac-Toe!\n");
    displayBoard(board);
    while (moveCount < SIZE*SIZE) {
        printf("\nPlayer %c's turn. Enter row and column number to place your move: ", currentPlayer);
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            displayBoard(board);
            if (checkWinner(board, currentPlayer)) {
                printf("Player %c wins!\n", currentPlayer);
                return 0;
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            moveCount++;
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }
    printf("Game over. It's a draw.\n");
    return 0;
}

void displayBoard(char board[][SIZE])
{
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i != SIZE - 1) {
            printf("\n---|---|---\n");
        }
    }
    printf("\n");
}

int checkWinner(char board[][SIZE], char player)
{
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    // Check columns
    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}
