#include<iostream>
#include<vector>
using namespace std;

void getSubsequence(int inx, string s, vector<string>& ans, string temp){
    if(inx == s.length()){
        ans.push_back(temp);
        return;
    }

    // include character
    temp.push_back(s[inx]);
    getSubsequence(inx + 1, s, ans, temp);

    // exclude character
    temp.pop_back();
    getSubsequence(inx + 1, s, ans, temp);
}

int main(){
    string s = "abc";
    vector<string> ans;

    getSubsequence(0, s, ans, "");

    // print all subsequences
    for(string str : ans){
        cout << str << endl;
    }

    return 0;
}
