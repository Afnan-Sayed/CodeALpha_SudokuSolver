# Sudoku Solver
Welcome to Sudoku Solver, a C++ program that allows users to generate Sudoku puzzles of varying difficulty levels and interactively solve them.

## Features
Sudoku Puzzle Generation: Generate Sudoku puzzles with three difficulty levels: Easy, Medium, and Hard.
Interactive Solver: Users can input their solutions for the generated puzzles and receive instant feedback on correctness.
User-Friendly Interface: Clear prompts guide users through the puzzle generation and solving process.
Error Handling: Robust error handling mechanisms ensure smooth operation and provide helpful messages in case of invalid inputs or unexpected scenarios.

## How to Use
Compilation: Compile the SudokuSolver.cpp file using a C++ compiler such as g++.
Choose Difficulty: Select the desired difficulty level (Easy, Medium, or Hard) when prompted.
Solve the Puzzle: Input your solutions for the generated Sudoku puzzle. Use 0 to represent empty cells.
Get Feedback: Receive immediate feedback on your solution. If correct, the solved puzzle will be displayed. If incorrect, you'll be shown the correct solution.

## Example Usage
Here's an example of how to use the Sudoku Solver:

Choose the difficulty level:
Easy
Medium
Hard
Enter your choice: 1

Generated Sudoku puzzle:
1 2 3 | 4 5 6 | 7 8 9
1 | 0 0 0 | 0 0 0 | 0 3 0
2 | 0 8 0 | 7 9 6 | 0 0 0
3 | 0 0 7 | 0 0 0 | 0 0 5
4 | 7 0 6 | 0 0 3 | 8 0 0
5 | 0 4 0 | 6 0 5 | 0 9 7
6 | 5 0 0 | 9 0 4 | 3 0 0
7 | 0 0 9 | 5 6 0 | 0 0 0
8 | 0 5 4 | 0 2 0 | 0 0 0
9 | 1 7 0 | 0 0 0 | 0 0 2

Enter the numbers for the empty cells (use 0 for empty cells):
Enter number for cell [1][1]: 4
Enter number for cell [1][2]: 5
Enter number for cell [1][5]: 2
...
