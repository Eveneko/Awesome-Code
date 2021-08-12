/**
 * 48. 最长不含重复字符的子字符串
 * https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/
 */

#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> dp(256, false);
        int res = 0;
        int pos = 0;
        int left = 0;
        int len = s.size();
        while(pos < len){
            while(dp[s[pos]]){
                dp[s[left++]] = false;
            }
            res = max(res, pos - left + 1);
            dp[s[pos++]] = true;
        }
        return res;
    }
};