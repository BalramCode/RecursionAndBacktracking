#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to generate permutations
// inx → current level (position to fill)
// num → original string
// ans → stores all permutations
// temp → current permutation being built
// used → tracks which characters are already used

void permutation(int inx, string num,
                 vector<vector<string>> &ans,
                 vector<string> &temp,
                 vector<int> &used)
{
    // ✅ BASE CASE
    // If we filled all positions
    if (inx == num.length())
    {
        ans.push_back(temp); // store current permutation
        return;
    }

    // Try picking each character
    for (int i = 0; i < num.length(); i++)
    {
        // Only pick if not used
        if (!used[i])
        {
            used[i] = 1; // mark as used

            // convert char to string and add to temp
            temp.push_back(string(1, num[i]));

            // recursive call to fill next position
            permutation(inx + 1, num, ans, temp, used);

            // BACKTRACK
            temp.pop_back(); // remove last added character
            used[i] = 0;     // mark as unused
        }
    }
}

int main()
{
    string num = "123";

    vector<vector<string>> ans; // stores all permutations
    vector<string> temp;        // current permutation

    // create used array initialized to 0
    vector<int> used(num.length(), 0);

    // start recursion
    permutation(0, num, ans, temp, used);

    // print permutations
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



//                      []
//         /            |            \
//       1              2              3
//     /   \          /   \          /   \
//   12    13        21    23       31    32
//    |      |        |      |        |      |
//  123    132      213    231      312    321
