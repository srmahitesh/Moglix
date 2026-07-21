#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestValidParentheses(string s) {
    int maxLen = 0;
    // Using two passed from left and right, and solving in Linear time & Constant Space
    int left = 0, right = 0;

    for(int i = 0; i < s.length(); i++){
        char ch = s[i];
        if(ch == ')'){
            right++;
        } else {
            left++;
        }

        if(right > left) {
            left = right = 0;
        }

        if(right == left) {
            maxLen = max(maxLen, left+right);
        }
    }

    left = right = 0;
    for(int i = s.length()-1; i >= 0; i--) {
        char ch = s[i];
        if(ch == ')'){
            right++;
        } else {
            left++;
        }

        if(left > right) {
            left = right = 0;
        }

        if(right == left) {
            maxLen = max(maxLen, left+right);
        }
    }

    return maxLen;
}

int main() {
    vector<string> testCases = {"(()", ")()())", ""};
    for(int i = 0; i < testCases.size(); i++) {
        cout<<i+1<<". : "<<longestValidParentheses(testCases[i])<<endl;
    }

    return 0;
}