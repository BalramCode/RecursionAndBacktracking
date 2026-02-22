#include <iostream>
#include <vector>
using namespace std;

// Function to generate all maze paths with jumps
// sc = source column (current column)
// sr = source row (current row)
// dc = destination column
// dr = destination row
// ans = stores all final paths
// temp = stores current path being explored

void getMazePathsWithJump(int sc, int sr, int dc, int dr,
                          vector<vector<string>> &ans,
                          vector<string> &temp)
{
    // ✅ BASE CASE
    // If current position is destination
    // store the path and stop recursion
    if (sc == dc && sr == dr)
    {
        ans.push_back(temp);
        return;
    }

    // ✅ HORIZONTAL MOVES (RIGHT)
    // Try all possible jumps from 1 to remaining columns
    for (int i = 1; i <= dc - sc; i++)
    {
        // choose move
        temp.push_back("h" + to_string(i));

        // explore next cell after jump
        getMazePathsWithJump(sc + i, sr, dc, dr, ans, temp);

        // undo move (BACKTRACK)
        temp.pop_back();
    }

    // ✅ VERTICAL MOVES (DOWN)
    // Try all possible jumps from 1 to remaining rows
    for (int i = 1; i <= dr - sr; i++)
    {
        temp.push_back("v" + to_string(i));

        getMazePathsWithJump(sc, sr + i, dc, dr, ans, temp);

        temp.pop_back();
    }

    // ✅ DIAGONAL MOVES
    // Try jumps while both row and column allow
    for (int i = 1; i <= dc - sc && i <= dr - sr; i++)
    {
        temp.push_back("d" + to_string(i));

        getMazePathsWithJump(sc + i, sr + i, dc, dr, ans, temp);

        temp.pop_back();
    }
}

int main()
{
    vector<vector<string>> ans; // stores all paths
    vector<string> temp;        // current path

    // Start recursion from (0,0) to (2,2)
    getMazePathsWithJump(0, 0, 2, 2, ans, temp);

    // Print all paths
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}
