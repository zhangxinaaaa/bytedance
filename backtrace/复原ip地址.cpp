//
// Created by 张新 on 2022/9/4.
//

#include <vector>
#include <string>
using namespace std;
// 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
//
//例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址
// ，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
//给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，
//这些地址可以通过在 s 中插入'.' 来形成。你 不能重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。
//

class Solution {
public:
    vector<string>ans;
    void backtrace(string& s,int cnt,int index,string& str){
        if(cnt==4 || index==s.size() ){
            if(cnt==4 && index==s.size())
                ans.push_back(str.substr(0,str.size()-1));
            return;
        }
        for(int i=1;i<=3;i++){
            if(index+i>s.size()) return;
            if(s[index]=='0' && i!=1) return;
            if(i==3 && s.substr(index,i)>"255") return;
            str+=s.substr(index,i);
            str.push_back('.');
            backtrace(s,cnt+1,index+i,str);
            str = str.substr(0,str.size()-i-1);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        string str ="";
        backtrace(s,0,0,str);
        return ans;

    }
};