#include <iostream>
#include <vector>
using namespace std;

// Recursive function to generate all paths
void getMazePaths(int sc, int sr, int dc, int dr,
                  vector<vector<string>> &ans, // stores all final paths
                  vector<string> &temp)        // stores current path
{
    // ✅ Base case: if we reached destination cell
    if (sc == dc && sr == dr)
    {
        // store current path into answer list
        ans.push_back(temp);
        return; // stop further recursion
    }

    // ✅ Move horizontally (right) if we haven't reached last column
    if (sc < dc)
    {
        temp.push_back("h"); // choose move

        // recursive call → move right
        getMazePaths(sc + 1, sr, dc, dr, ans, temp);

        temp.pop_back(); // backtrack (remove last move)
    }

    // ✅ Move vertically (down) if we haven't reached last row
    if (sr < dr)
    {
        temp.push_back("v"); // choose move

        // recursive call → move down
        getMazePaths(sc, sr + 1, dc, dr, ans, temp);

        temp.pop_back(); // backtrack
    }
}

int main()
{
    vector<vector<string>> ans; // stores all paths
    vector<string> temp;        // stores current path

    // start from (0,0) to destination (2,2)
    getMazePaths(0, 0, 2, 2, ans, temp);

    // print all paths
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
