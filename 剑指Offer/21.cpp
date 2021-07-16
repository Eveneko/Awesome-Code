/**
 * 21. 调整数组顺序使奇数位于偶数前面
 * https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/
 */

#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    static bool isOdd( int i){
        return i&1;
    }

    vector<int> exchange(vector<int>& nums) {
        partition(nums.begin(), nums.end(), isOdd);
        return nums;
    }
};

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int low = 0;
        int fast = 0;
        while(fast < nums.size()){
            if(nums[fast]&1){
                swap(nums[low], nums[fast]);
                ++low;
            }
            ++fast;
        }
        return nums;
    }
};