#include <iostream>
#include <vector>
using namespace std;

// solve function: inx (current element index), target (remaining sum needed)
void solve(int inx, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    // BASE CASE: We have considered every element in the array
    if (inx == arr.size())
    {
        // If the remaining target is exactly 0, the current path (ds) is a valid subset
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return; // Backtrack to the previous decision
    }

    // OPTION 1: "PICK" the current element
    // Only pick if the element isn't larger than the remaining target
    if (arr[inx] <= target)
    {
        ds.push_back(arr[inx]); // Add element to the current combination
        
        // Move to the next index (inx+1) with a reduced target
        solve(inx + 1, target - arr[inx], arr, ans, ds);
        
        // BACKTRACK: Remove the element to try the "NOT PICK" scenario
        ds.pop_back(); 
    }

    // OPTION 2: "NOT PICK" the current element
    // Skip this element and move to the next index with the SAME target
    solve(inx + 1, target, arr, ans, ds);
}

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50}; // Our candidates
    vector<vector<int>> ans;                // Stores all successful subsets
    vector<int> ds;                         // "Data Structure" to store the current path
    int target = 60;

    solve(0, target, arr, ans, ds);

    // Print the results
    for (const auto &subset : ans)
    {
        cout << "[ ";
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << "] ";
    }
    return 0;
}