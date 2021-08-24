/**
 * 57 - II. 和为s的连续正数序列
 * https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/
 */

#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        for(int l = 1, r = 2; l < r;){
            int sum = (l + r) * (r - l + 1) / 2;
            if(sum == target){
                vector<int> tmp;
                for(int i = l; i <= r; ++i){
                    tmp.emplace_back(i);
                }
                res.emplace_back(tmp);
                l++;
            }else if (sum < target){
                r++;
            }else{
                l++;
            }
        }
        return res;
    }
};