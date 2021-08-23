/**
 * 56 - II. 数组中数字出现的次数
 * https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/
 */

#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < 32; ++i){
            int cnt = 0;
            for(auto num : nums){
                cnt += ((num >> i) & 1);
            }
            if(cnt % 3){
                res |= (1 << i);
            }
        }
        return res;
    }
};