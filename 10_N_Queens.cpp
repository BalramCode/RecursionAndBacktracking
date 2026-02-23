#include <iostream>   // For input/output (cout, cin)
#include <vector>     // To use vector container
#include <string>     // To use string
using namespace std;

// Function to check whether placing a queen at (row, col) is safe
bool isSafe(int n, vector<string> &board, int row, int col)
{
    // 🔹 Check vertically upwards (same column)
    // Because queens are placed row by row from top to bottom,
    // we only need to check rows above current row
    for (int i = row - 1; i >= 0; i--)
    {
        // If any queen exists in same column above → not safe
        if (board[i][col] == 'Q')
            return false;
    }

    // 🔹 Check upper-right diagonal ↗
    // Move one step up and one step right each time
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        // If queen found → position not safe
        if (board[i][j] == 'Q')
            return false;
    }

    // 🔹 Check upper-left diagonal ↖
    // Move one step up and one step left each time
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        // If queen found → position not safe
        if (board[i][j] == 'Q')
            return false;
    }

    // If no conflicts found → safe position
    return true;
}

// Backtracking function to place queens row by row
void solveNQueens(int n, vector<vector<string>> &ans, vector<string> &board, int row)
{
    // 🔹 Base case: if all rows processed → solution found
    if (row == n)
    {
        ans.push_back(board); // Store current board configuration
        return;
    }

    // 🔹 Try placing queen in each column of current row
    for (int col = 0; col < n; col++)
    {
        // Check if placing queen here is safe
        if (isSafe(n, board, row, col))
        {
            board[row][col] = 'Q'; // Place queen

            // Recur to place queen in next row
            solveNQueens(n, ans, board, row + 1);

            // 🔹 Backtrack: remove queen to try other positions
            board[row][col] = '.';
        }
    }
}

int main()
{
    int n = 4; // Size of board (4x4)

    // Vector to store all valid solutions
    vector<vector<string>> ans;

    // Initialize board with '.' meaning empty cell
    vector<string> board(n, string(n, '.'));

    // Start solving from row 0
    solveNQueens(n, ans, board, 0);

    // 🔹 Print all solutions
    for (const auto &solution : ans)
    {
        for (const auto &row : solution)
        {
            cout << row << endl; // Print each row
        }
        cout << "----" << endl; // Separator between solutions
    }

    return 0;
}
