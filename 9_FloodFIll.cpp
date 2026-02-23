#include <iostream>
#include <vector>
using namespace std;

// Define the grid (0 = free cell, 1 = obstacle)
vector<vector<int>> grid = {
    {0, 1, 0, 0, 0, 0},
    {0, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 1},
    {1, 0, 0, 0, 0, 0}
};

// Get number of rows and columns in the grid
int rows = grid.size();
int cols = grid[0].size();

// Create a visited matrix to track visited cells during recursion
vector<vector<int>> visited(rows, vector<int>(cols, 0));

/*
    Recursive backtracking function to explore all paths
    i, j -> current position in the grid
    path -> current path as a string of directions ("R", "L", "U", "D")
    ans -> vector to store all valid paths
*/
void solve(int i, int j, string path, vector<string> &ans)
{
    // 1. Check boundaries: if we are outside the grid, return
    if (i < 0 || j < 0 || rows <= i || cols <= j)
        return;

    // 2. Check if current cell is blocked (1) or already visited
    if (grid[i][j] == 1 || visited[i][j] == 1)
        return;

    // 3. Check if we reached the bottom-right cell (destination)
    if (i == rows - 1 && j == cols - 1)
    {
        ans.push_back(path); // store the current path
        return;
    }

    // 4. Mark current cell as visited
    visited[i][j] = 1;

    // 5. Explore all 4 directions recursively
    solve(i, j + 1, path + "R", ans); // move Right
    solve(i, j - 1, path + "L", ans); // move Left
    solve(i - 1, j, path + "U", ans); // move Up
    solve(i + 1, j, path + "D", ans); // move Down

    // 6. Backtrack: unmark the current cell so other paths can use it
    visited[i][j] = 0;
}

// Function to find all paths from top-left to bottom-right
vector<string> findPaths(vector<vector<int>> &grid)
{
    vector<string> ans; // to store all valid paths
    solve(0, 0, "", ans); // start from top-left cell (0,0)
    return ans;
}

int main()
{
    // Call function to get all paths
    vector<string> paths = findPaths(grid);

    // Print all paths
    for (string p : paths)
        cout << p << endl;

    return 0;
}
