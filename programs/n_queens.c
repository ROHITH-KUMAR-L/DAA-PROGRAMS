#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int board[MAX][MAX];
int solutionCount = 0;

int isSafe(int row, int col, int n) {
    int i, j;

    for (i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return 0;
    }


    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return 0;
    }


    for (i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1)
            return 0;
    }

    return 1;
}

void printBoard(int n) {
    int i, j;

    solutionCount++;
    printf("\nSolution %d:\n", solutionCount);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (board[i][j] == 1)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

void solve(int row, int n) {
    int col;

    if (row == n) {
        printBoard(n);
        return;
    }

    for (col = 0; col < n; col++) {
        if (isSafe(row, col, n)) {
            board[row][col] = 1;
            solve(row + 1, n);
            board[row][col] = 0;  
        }
    }
}

int main() {
    int n;

    printf("Enter the number of queens: ");
    scanf("%d", &n);

    solve(0, n);

    if (solutionCount == 0)
        printf("No solution exists.\n");
    else
        printf("\nTotal solutions = %d\n", solutionCount);

    return 0;
}