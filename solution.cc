// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

// For "(()", the longest valid parentheses substring is "()", which has length = 2.

// Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        stack<int> myStack;
        int last = -1;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(') {
                myStack.push(i);
            } else {
                if(myStack.empty()) {
                    last = i;
                } else {
                    myStack.pop();
                    res = max(res, myStack.empty() ? i-last : i-myStack.top());
                }
            }
        }
        return res;
    }
};
