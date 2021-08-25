/**
 * 58 - II. 左旋转字符串
 * https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/
 */

#include<string>
using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        s += s;
        return s.substr(n, s.size() /  2);
    }
};