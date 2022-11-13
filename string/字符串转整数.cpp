//
// Created by 张新 on 2022/9/6.
//

#include <iostream>
#include <sstream>
#include <cmath>
#include <climits>
#include <regex>
#include <string>
using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        int result;
        string resultStr;
        smatch tmpMatch;
        //c++中要用\\进行转义
        regex tmpRegex("^[\\+\\-\\d]\\d*");
        //先将左边的空格去除
        trimStart(str);
        regex_search(str, tmpMatch, tmpRegex);

        stringstream ss;
        if (int(tmpMatch.size()) == 0)
        {
            return 0;
        }
        string tmpStr = tmpMatch[0];
        //转换成int
        ss << tmpStr;
        cout << tmpStr << endl;
        long longResult;
        ss >> longResult;
        result = max(min(longResult, long(INT_MAX)), long(INT_MIN));

        return result;
    }

    void trimStart(string &s)
    {
        if (!s.empty())
        {
            s.erase(0, s.find_first_not_of(" "));
            //s.erase(s.find_last_not_of(" ") + 1);
        }
    }
};