/**
 * 59 - I. 滑动窗口的最大值
 * https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/
 */

#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size() == 0 || k == 0) return {};
        deque<int> dq;
        vector<int> res;
        for(int i = 0; i < k; ++i){
            while(!dq.empty() && dq.back() < nums[i]){
                dq.pop_back();
            }
            dq.emplace_back(nums[i]);
        }
        res.emplace_back(dq.front());
        for(int i = k; i < nums.size(); ++i){
            if(dq[0] == nums[i - k]){
                dq.pop_front();
            }
            while(!dq.empty() && dq.back() < nums[i]){
                dq.pop_back();
            }
            dq.emplace_back(nums[i]);
            res.emplace_back(dq.front());
        }
        return res;
    }
};