/**
 * 15. 二进制中1的个数
 * https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/
 */

#include<stdint.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n != 0){
            cnt++;
            n &= (n-1);
        }
        return cnt;
    }
};