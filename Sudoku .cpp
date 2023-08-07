#include <iostream>
#include <vector>

const int BOARD_SIZE = 9;
const int SUBGRID_SIZE = 3;
const int EMPTY_CELL = 0;

typedef std::vector<std::vector<int>> SudokuBoard;

// Function to print the Sudoku board
void printBoard(const SudokuBoard& board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            std::cout << board[i][j] << " ";
            if ((j + 1) % SUBGRID_SIZE == 0)
                std::cout << " ";
        }
        std::cout << std::endl;
        if ((i + 1) % SUBGRID_SIZE == 0)
            std::cout << std::endl;
    }
}

// Function to check if a digit is safe to be placed in the cell
bool isSafe(const SudokuBoard& board, int row, int col, int digit) {
    // Check row and column
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[row][i] == digit || board[i][col] == digit) {
            return false;
        }
    }

    // Check subgrid
    int subgridRow = (row / SUBGRID_SIZE) * SUBGRID_SIZE;
    int subgridCol = (col / SUBGRID_SIZE) * SUBGRID_SIZE;
    for (int i = 0; i < SUBGRID_SIZE; ++i) {
        for (int j = 0; j < SUBGRID_SIZE; ++j) {
            if (board[subgridRow + i][subgridCol + j] == digit) {
                return false;
            }
        }
    }

    return true;
}

// Function to find an empty cell in the board
bool findEmptyCell(const SudokuBoard& board, int& row, int& col) {
    for (row = 0; row < BOARD_SIZE; ++row) {
        for (col = 0; col < BOARD_SIZE; ++col) {
            if (board[row][col] == EMPTY_CELL) {
                return true;
            }
        }
    }
    return false;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(SudokuBoard& board) {
    int row, col;

    if (!findEmptyCell(board, row, col)) {
        // All cells are filled
        return true;
    }

    for (int digit = 1; digit <= BOARD_SIZE; ++digit) {
        if (isSafe(board, row, col, digit)) {
            board[row][col] = digit;
            if (solveSudoku(board)) {
                return true;
            }
            board[row][col] = EMPTY_CELL; // Backtrack
        }
    }

    return false;
}

int main() {
    SudokuBoard board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(board)) {
        std::cout << "Sudoku solution:" << std::endl;
        printBoard(board);
    } else {
        std::cout << "No solution exists." << std::endl;
    }

    return 0;
}