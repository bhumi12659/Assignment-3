#include <stdio.h>

char board[3][3]; 

void boardpositions() {
    int num = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '0' + num++;
        }
    }
}


void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i != 2) printf("\n---|---|---\n");
    }
    printf("\n");
}


int checkingWinner() {

    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;

        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0;
}


int boardisFull() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
    return 1;
}

int main() {
    int choice, row, column;
    char Player1 = 'X';

    boardpositions();

    while (1) {
        printBoard();
        printf("Player %c, enter a number (1-9): ", Player1);
        scanf("%d", &choice);

        if (choice < 1 || choice > 9) {
            printf("Move is invalid! Please Try again.\n");
            continue;
        }

        row = (choice - 1) / 3;
        column = (choice - 1) % 3;

        if (board[row][column] == 'X' || board[row][column] == 'O') {
            printf("Spot is already taken! Please try again.\n");
            continue;
        }

        board[row][column] = Player1;

        if (checkingWinner()) {
            printBoard();
            printf("Player %c wins!\n", Player1);
            break;
        }

        if (boardisFull()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }

        Player1 = (Player1 == 'X') ? 'O' : 'X';
    }

    return 0;
}