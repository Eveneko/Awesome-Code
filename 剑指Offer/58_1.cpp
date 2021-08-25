/**
 * 58 - I. 翻转单词顺序
 * https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/
 */

#include<string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        int right = s.size() - 1;
        int left = s.size() - 1;
        while(left >= 0){
            while(s[left] == ' '){
                --right;
                --left;
                if(left < 0) break;
            }
            if(left < 0) break;
            while(s[left] != ' '){
                --left;
                if(left < 0) break;
            }
            res = res + s.substr(left + 1, right - left) + " ";
            right = left;
        }
        return res.substr(0, res.size() - 1);
    }
};