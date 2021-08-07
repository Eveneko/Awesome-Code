/**
 * 44. 数字序列中某一位的数字
 * https://leetcode-cn.com/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof/
 */

#include<string>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        long long num = 1;
        int digit = 1;
        long long count = num * digit * 9;
        while(n > count){
            n -= count;
            ++digit;
            num *= 10;
            count = num * digit * 9;
        }
        num = num + (n - 1) / digit;
        return to_string(num)[(n - 1) % digit] - '0';
    }
};