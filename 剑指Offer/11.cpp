/**
 * 11. 旋转数组的最小数字
 * https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/
 */

#include<vector>
using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int len = numbers.size();
        if(len == 0){
            return 0;
        }
        int left = 0;
        int right = len - 1;
        int mid = 0;
        while(left < right){
            mid = (right + left) >> 1;
            if(numbers[right] < numbers[mid]){
                left = mid + 1;
            }else if(numbers[right] > numbers[mid]){
                right = mid;
            }else{
                right = right - 1;
            }
        }
        return numbers[left];
    }
};