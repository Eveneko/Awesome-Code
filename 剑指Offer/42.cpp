/**
 * 42. 连续子数组的最大和
 * https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
 */

#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            nums[i] += max(nums[i-1], 0);
            res = max(res, nums[i]);
        }
        return res;
    }
};