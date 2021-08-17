/**
 * 53 - I. 在排序数组中查找数字 I
 * https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/
 */

#include<vector>
using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int flag){
        int left = 0;
        int right = nums.size() - 1;
        int res = nums.size();
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] > target || (flag && nums[mid] >= target)){
                right = mid - 1;
                res = mid;
            }else{
                left = mid + 1;
            }
        }
        return res;
    }
    int search(vector<int>& nums, int target) {
        int left = binarySearch(nums, target, true);
        int right = binarySearch(nums, target, false) - 1;
        if(left <= right && right < nums.size() && nums[left] == target && nums[right] == target){
            return right - left + 1;
        }
        return 0;
    }
};