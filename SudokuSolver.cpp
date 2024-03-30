#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Define the size of the Sudoku grid
const int N = 9;

// Function to print the Sudoku grid with row and column numbers
void printGrid(const vector<vector<int>>& grid) {
    cout << "   ";
    for (int j = 0; j < N; ++j) {
        cout << j + 1 << " ";
        if ((j + 1) % 3 == 0 && j < N - 1) {
            cout << "| ";
        }
    }
    cout << endl;
    cout << "  ---------------------" << endl;
    for (int i = 0; i < N; ++i) {
        cout << i + 1 << " | ";
        for (int j = 0; j < N; ++j) {
            cout << grid[i][j] << " ";
            if ((j + 1) % 3 == 0 && j < N - 1) {
                cout << "| ";
            }
        }
        cout << endl;
        if ((i + 1) % 3 == 0 && i < N - 1) {
            cout << "  ---------------------" << endl;
        }
    }
}

// Function to check if a number can be placed in the given cell
bool isSafe(const vector<vector<int>>& grid, int row, int col, int num) {
    // Check if the number already exists in the row or column
    for (int i = 0; i < N; ++i) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }
    // Check if the number already exists in the 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

// Function to solve the Sudoku puzzle (backtracking algorithm)
bool solveSudoku(vector<vector<int>>& grid) {
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            // Find an empty cell
            if (grid[row][col] == 0) {
                // Try placing numbers 1-9 in the cell
                for (int num = 1; num <= 9; ++num) {
                    if (isSafe(grid, row, col, num)) {
                        // If it's safe to place the number, do so
                        grid[row][col] = num;
                        // Recursively solve the rest of the puzzle
                        if (solveSudoku(grid)) {
                            return true;
                        }
                        // If no solution found, backtrack and try the next number
                        grid[row][col] = 0;
                    }
                }
                // If no number can be placed, return false
                return false;
            }
        }
    }
    // If all cells are filled, puzzle is solved
    return true;
}

// Function to generate a Sudoku puzzle of the specified difficulty level
void generatePuzzle(vector<vector<int>>& grid, int difficultyLevel) {
    // Generate a complete Sudoku solution
    solveSudoku(grid);

    // Remove numbers based on difficulty level
    int numToRemove = 0;
    switch (difficultyLevel) {
        case 1: // Easy
            numToRemove = 40; // Adjust the number of cells to remove for different difficulty levels
            break;
        case 2: // Medium
            numToRemove = 50;
            break;
        case 3: // Hard
            numToRemove = 60;
            break;
        default:
            cerr << "Invalid difficulty level! Exiting program.\n";
            exit(1);
    }

    // Remove numbers from the grid
    while (numToRemove > 0) {
        int row = rand() % N;
        int col = rand() % N;
        if (grid[row][col] != 0) {
            grid[row][col] = 0;
            numToRemove--;
        }
    }
}

// Function to check if the user's solution matches the correct solution
bool isCorrectSolution(const vector<vector<int>>& userSolution, const vector<vector<int>>& correctSolution) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (userSolution[i][j] != correctSolution[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    // Initialize the Sudoku grid
    vector<vector<int>> grid(N, vector<int>(N, 0));

    // Seed the random number generator
    srand(time(nullptr));

    // Prompt the user to choose the difficulty level
    int difficultyLevel;
    cout << "Choose the difficulty level:\n";
    cout << "1. Easy\n2. Medium\n3. Hard\n";
    cin >> difficultyLevel;

    // Generate a Sudoku puzzle based on the chosen difficulty level
    generatePuzzle(grid, difficultyLevel);

    // Print the generated Sudoku puzzle
    cout << "Generated Sudoku puzzle:\n";
    printGrid(grid);

    // Solve the Sudoku puzzle to get the correct solution
    vector<vector<int>> correctSolution = grid;
    solveSudoku(correctSolution);

    // Let the user fill in the empty cells
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (grid[i][j] == 0) {
                int num;
                cout << "Enter number for cell [" << i + 1 << "][" << j + 1 << "]: ";
                cin >> num;
                grid[i][j] = num;
            }
        }
    }

    // Check if the user's solution matches the correct solution
    if (isCorrectSolution(grid, correctSolution)) {
        cout << "Congratulations! You solved the Sudoku puzzle correctly.\n";
    } else {
        cout << "Sorry, your solution is incorrect.\n";
        cout << "Correct solution:\n";
        printGrid(correctSolution);
    }

    return 0;
}
