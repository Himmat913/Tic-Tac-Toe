#include <stdio.h>

char board[3][3];
char player = 'X';

void initBoard() {
    for (int i = 0, count = 1; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = '0' + count++;
}

void drawBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i != 2) printf("---|---|---\n");
    }
    printf("\n");
}

int checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;
    return 0;
}

int checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
    return 1;
}

int main() {
    int move, row, col;
    initBoard();
    while (1) {
        drawBoard();
        printf("Player %c, enter position (1-9): ", player);
        scanf("%d", &move);
        if (move < 1 || move > 9) {
            printf("Invalid move.\n");
            continue;
        }
        row = (move - 1) / 3;
        col = (move - 1) % 3;
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Cell already taken.\n");
            continue;
        }
        board[row][col] = player;
        if (checkWin()) {
            drawBoard();
            printf("Player %c wins!\n", player);
            break;
        }
        if (checkDraw()) {
            drawBoard();
            printf("It's a draw!\n");
            break;
        }
        player = (player == 'X') ? 'O' : 'X';
    }
    return 0;
}
