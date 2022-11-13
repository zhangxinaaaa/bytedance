//
// Created by 张新 on 2022/9/3.
//
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty())
                    return false;
                char top = st.top();
                st.pop();
                if (top == '(' && c == ')')
                    continue;
                if (top == '[' && c == ']')
                    continue;
                if (top == '{' && c == '}')
                    continue;
                return false;
            }
        }
        if (!st.empty())
            return false;
        return true;
    }
};