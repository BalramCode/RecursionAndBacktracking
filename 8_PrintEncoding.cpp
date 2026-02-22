// // Question :
// 1️⃣ You are given a string of digits (like "123").
// 👉 It will never start with 0.

// 2️⃣ You must convert the digits into letters using this mapping:
// 1 → a
// 2 → b
// 3 → c
// …
// 25 → y
// 26 → z

// 3️⃣ Your task is to print all possible valid letter combinations (encodings) of the string.

// Example: "123"
// You can decode it in different ways:
// 1 | 2 | 3 → a b c → abc
// 12 | 3 → l c → lc
// 1 | 23 → a w → aw
// So output = abc, lc, aw



#include <iostream>
#include <vector>
using namespace std;

// Function to generate all possible encodings
// s = remaining string to process
// ans = vector to store all final encodings
// temp = current partial encoding being built
void Encoding(string s, vector<string> &ans, string temp)
{
    // ✅ BASE CASE: If no characters left
    // We have formed one valid encoding
    if (s.length() == 0)
    {
        ans.push_back(temp); // store result
        return;              // stop recursion
    }

    // ❌ If string starts with 0 → invalid encoding
    if (s[0] == '0')
        return;

    // 🔹 Take ONE digit

    // Convert first character digit to number
    int num1 = s[0] - '0';

    // Convert number to corresponding letter
    // Example: 1 → 'a'
    char ch1 = 'a' + num1 - 1;

    // Add character to current path
    temp.push_back(ch1);

    // Recursive call with remaining string after removing first digit
    Encoding(s.substr(1), ans, temp);

    // 🔙 Backtrack → remove last character to try other options
    temp.pop_back();

    // 🔹 Take TWO digits (if possible)

    // Check if at least 2 characters exist
    if (s.length() >= 2)
    {
        // Convert first two digits to number
        int num2 = (s[0] - '0') * 10 + (s[1] - '0');

        // Check if valid mapping (1–26)
        if (num2 <= 26)
        {
            // Convert number to letter
            char ch2 = 'a' + num2 - 1;

            // Add to current path
            temp.push_back(ch2);

            // Recursive call after removing two digits
            Encoding(s.substr(2), ans, temp);

            // 🔙 Backtrack
            temp.pop_back();
        }
    }
}

int main()
{
    vector<string> ans; // Stores all encodings

    // Start recursion with input "123" and empty temp string
    Encoding("123", ans, "");

    // Print all results
    for (string str : ans)
    {
        cout << str << endl;
    }

    return 0;
}
