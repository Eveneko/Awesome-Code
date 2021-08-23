/**
 * 56 - I. 数组中数字出现的次数
 * https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/
 */

#include<vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int x = 0, y = 0;
        int n = 0;
        int m = 1;
        for(auto num : nums){
            n ^= num;
        }
        while((n & m) == 0){
            m <<= 1;
        }
        for(auto num : nums){
            if(num & m){
                x ^= num;
            }else{
                y ^= num;
            }
        }
        return {x, y};
    }
};