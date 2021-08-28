 /**
 * 61. 扑克牌中的顺子
 * https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof/
 */

#include<algorithm>
#include<vector>

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int joker = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < 4; ++i){
            if(nums[i] == 0) joker++;
            else if(nums[i] == nums[i+1]) return false;
        }
        return nums[4] - nums[joker] < 5;
    }
};