/**
 * 46. 把数字翻译成字符串
 * https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/
 */

#include<string>
using namespace std;

class Solution {
public:
    int rec(string& str, int index){
        int len = str.size();
        if(index == len) return 1;
        if(index == len - 1 || str[index] == '0' || str.substr(index, 2) > "25"){
            return rec(str, index + 1);
        }
        return rec(str, index + 1) + rec(str, index + 2);
    }
    int translateNum(int num) {
        string str = to_string(num);
        return rec(str, 0);
    }
};