 /**
 * 67. 把字符串转换成整数
 * https://leetcode-cn.com/problems/ba-zi-fu-chuan-zhuan-huan-cheng-zheng-shu-lcof/
 */

#include<limits.h>
#include<ctype.h>
using namespace std;

class Solution {
public:
    int strToInt(string str) {
        int i = 0;
        int flag = 1;
        long res = 0;
        while(str[i] == ' ') ++i;
        if(str[i] == '-') flag = -1;
        if(str[i] == '-' or str[i] == '+') ++i;
        for(; i < str.size() && isdigit(str[i]); i++){
            res = res * 10 + (str[i] - '0');
            if(res >= INT_MAX && flag == 1) return INT_MAX;
            if(res > INT_MAX && flag == -1) return INT_MIN;
        }
        return flag * res;
    }
};