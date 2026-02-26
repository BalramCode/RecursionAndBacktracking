#include <iostream>
#include <vector>
#include <string>
using namespace std;

// sr, sc: Starting Row/Column | n: Maze size (max index)
// ans: Stores all valid paths | ds: Stores current path sequence
// maze: The grid (1 is path, 0 is wall) | visited: Tracks cells already in current path
void ratInMaze(int sr, int sc, int n, vector<vector<string>> &ans, vector<string> &ds, vector<vector<int>> &maze, vector<vector<int>> &visited)
{
    // 1. BOUNDARY & VALIDITY CHECK
    // Check if out of bounds, hitting a wall (0), or already visited (1)
    if (sr < 0 || sc < 0 || sr > n || sc > n || maze[sr][sc] == 0 || visited[sr][sc] == 1)
        return;

    // 2. BASE CASE (Destination Reached)
    // If current position is (n, n), we found a path!
    if (sr == n && sc == n)
    {
        ans.push_back(ds);
        return;
    }

    // 3. RECURSIVE EXPLORATION
    if (maze[sr][sc] == 1)
    {
        // Mark current cell as visited so we don't go in circles
        visited[sr][sc] = 1;

        // Try moving DOWN (D)
        ds.push_back("D");
        ratInMaze(sr + 1, sc, n, ans, ds, maze, visited);
        ds.pop_back(); // Backtrack: remove "D" to try other directions

        // Try moving LEFT (L)
        ds.push_back("L");
        ratInMaze(sr, sc - 1, n, ans, ds, maze, visited);
        ds.pop_back(); // Backtrack

        // Try moving RIGHT (R)
        ds.push_back("R");
        ratInMaze(sr, sc + 1, n, ans, ds, maze, visited);
        ds.pop_back(); // Backtrack

        // Try moving UP (U)
        ds.push_back("U");
        ratInMaze(sr - 1, sc, n, ans, ds, maze, visited);
        ds.pop_back(); // Backtrack

        // 4. UNMARK VISITED (Essential Backtracking)
        // Reset the cell to 0 so other potential paths can use this cell
        visited[sr][sc] = 0;
    }
}

int main()
{
    int n = 5;
    // Initialize visited matrix with 0s
    vector<vector<int>> visited(n, vector<int>(n, 0));

    // 1: Path, 0: Wall
    vector<vector<int>> maze = {
        {1, 0, 0, 1, 1},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 1, 1, 1, 1}};

    vector<vector<string>> ans;
    vector<string> temp;

    // Start recursion from (0,0) to target (4,4)
    ratInMaze(0, 0, n - 1, ans, temp, maze, visited);

    // Print all discovered paths
    if (ans.empty())
        cout << "No path found!";
    for (auto &path : ans)
    {
        for (auto &p : path)
        {
            cout << p << " ";
        }
        cout << endl;
    }

    return 0;
}