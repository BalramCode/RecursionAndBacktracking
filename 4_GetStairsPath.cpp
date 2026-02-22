#include <iostream> // for input and output (cout)
#include <vector>   // for using vector container
using namespace std;

// Recursive function to generate all possible stair paths
// n = remaining steps to reach
// ans = stores all valid paths (2D vector)
// temp = current path being built
void getStairsPath(int n, vector<vector<int>> &ans, vector<int> &temp)
{

    // BASE CASE 1 → if we reached exactly step 0
    // it means current path is valid
    if (n == 0)
    {
        ans.push_back(temp); // store current path
        return;              // stop recursion
    }

    // BASE CASE 2 → if steps go negative
    // this path is invalid
    if (n < 0)
        return;

    // CHOICE 1 → take step of size 1

    temp.push_back(1);               // add step 1 to current path
    getStairsPath(n - 1, ans, temp); // explore remaining steps
    temp.pop_back();                 // BACKTRACK → remove last step

    // CHOICE 2 → take step of size 2

    temp.push_back(2);               // add step 2 to path
    getStairsPath(n - 2, ans, temp); // explore remaining steps
    temp.pop_back();                 // BACKTRACK → remove last step
}

int main()
{

    int n = 4; // total steps to climb

    // 2D vector to store all possible paths
    vector<vector<int>> ans;

    // temporary vector to build current path
    vector<int> temp;

    // start recursion
    getStairsPath(n, ans, temp);

    // Print all paths
    for (auto path : ans)
    { // loop through each path
        for (int step : path)
        { // loop through steps in path
            cout << step << " ";
        }
        cout << endl; // new line after each path
    }

    return 0;
}
