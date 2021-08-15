/**
 * 51. 数组中的逆序对
 * https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/
 */

#include<vector>
using namespace std;

class Solution {
public:
    int mergeSort(vector<int>& nums, vector<int>& tmp, int left, int right){
        if(left >= right) return 0;
        int mid = (left + right) / 2;
        int res = mergeSort(nums, tmp, left, mid) + mergeSort(nums, tmp, mid+1, right);
        int i = left;
        int j = mid + 1;
        for(int k = left; k <= right; ++k){
            tmp[k] = nums[k];
        }
        for(int k = left; k <= right; ++k){
            if(i == mid + 1){
                nums[k] = tmp[j++];
            }else if(j == right + 1 || tmp[i] <= tmp[j]){
                nums[k] = tmp[i++];
            }else{
                nums[k] = tmp[j++];
                res += mid - i + 1;
            }
        }
        return res;
    }

    int reversePairs(vector<int>& nums) {
        vector<int> tmp(nums.size());
        return mergeSort(nums, tmp, 0, nums.size()-1);
    }
};