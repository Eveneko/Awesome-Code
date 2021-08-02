/**
 * 39. 数组中出现次数超过一半的数字
 * https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/
 */

#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;

// sort
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

// hash
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int res;
        int len = nums.size();
        for(int i = 0; i < len; ++i){
            map[nums[i]]++;
            if(map[nums[i]] > len / 2){
                res = nums[i];
                break;
            }
        }
        return res;
    }
};

// 摩尔投票法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0;
        int cnt = 0;
        int len = nums.size();
        for(int i = 0; i < len; ++i){
            if(cnt == 0){
                res = nums[i];
                cnt++;
            }
            else{
                res == nums[i]?cnt++:cnt--;
            }
        }
        return res;
    }
};