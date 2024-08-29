#include <iostream>

using namespace std;

const int N = 9;

// Function to check if placing `num` at `board[row][col]` is valid
bool isSafe(int board[N][N], int row, int col, int num) {
    // Check row and column
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    // Check 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

// Function to solve the Sudoku puzzle
bool solveSudoku(int board[N][N]) {
    int row, col;
    bool foundEmpty = false;

    // Find an empty cell
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (board[row][col] == 0) {
                foundEmpty = true;
                break;
            }
        }
        if (foundEmpty) {
            break;
        }
    }

    // If no empty cell found, the puzzle is solved
    if (!foundEmpty) {
        return true;
    }

    // Try placing numbers from 1 to 9
    for (int num = 1; num <= N; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;

            // Recursively solve the puzzle
            if (solveSudoku(board)) {
                return true;
            }

            // If the current placement doesn't lead to a solution, backtrack
            board[row][col] = 0;
        }
    }

    // If none of the numbers from 1 to 9 work, the puzzle is unsolvable
    return false;
}

// Function to print the Sudoku board
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int board[N][N];

    cout << "Enter the Sudoku puzzle (0 for empty cells):\n";

    // Input the Sudoku board
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    // Solve the Sudoku puzzle
    if (solveSudoku(board)) {
        cout << "Sudoku solved:\n";
        printBoard(board);
    } else {
        cout << "No solution exists\n";
    }

    return 0;
}
