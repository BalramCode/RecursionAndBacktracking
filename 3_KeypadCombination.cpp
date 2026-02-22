#include<iostream>  
#include<vector>    
using namespace std;

// Recursive function to generate all possible letter combinations
void solve(int inx, string digits, vector<string>& words, vector<string>& ans, string temp){

    // length of input digits
    int n = digits.length();

    // BASE CASE → if we have processed all digits
    if(inx == n){

        // current built string is a complete combination
        ans.push_back(temp);

        // stop recursion
        return;
    }

    // Convert current digit character to integer
    // Example: '1' → 1 , '2' → 2
    int num = digits[inx] - '0';

    // Get corresponding letters from keypad mapping
    string letters = words[num];

    // Loop through all possible letters for this digit
    for(int i = 0; i < letters.length(); i++){

        // CHOOSE → add current letter to temporary string
        temp.push_back(letters[i]);

        // EXPLORE → move to next digit
        solve(inx + 1, digits, words, ans, temp);

        // UNDO → remove last character (backtrack)
        // so we can try next letter
        temp.pop_back();
    }
}

int main(){

    // Input digits
    string digits = "678";

    // Phone keypad mapping
    // index = digit , value = letters
    vector<string> words = {
        ".;",   // 0
        "abc",  // 1
        "def",  // 2
        "ghi",  // 3
        "jkl",  // 4
        "mno",  // 5
        "pqrs", // 6
        "tu",   // 7
        "vwx",  // 8
        "yz"    // 9
    };

    // Vector to store all combinations
    vector<string> ans;

    // Start recursion from index 0 with empty temp string
    solve(0, digits, words, ans, "");

    // Print all generated combinations
    for(string s : ans) {
        cout << s << endl;
    }

    return 0;
}
