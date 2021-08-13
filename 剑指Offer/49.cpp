/**
 * 49. 丑数
 * https://leetcode-cn.com/problems/chou-shu-lcof/
 */

#include<vector>
using namespace std;`

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 1);
        int cnt2 = 0, cnt3 = 0, cnt5 = 0;
        int num2 = 0, num3 = 0, num5 = 0;
        for(int i = 1; i < n; ++i){
            num2 = dp[cnt2] * 2;
            num3 = dp[cnt3] * 3;
            num5 = dp[cnt5] * 5;
            dp[i] = min(min(num2, num3), num5);
            if(dp[i] == num2) cnt2++;
            if(dp[i] == num3) cnt3++;
            if(dp[i] == num5) cnt5++;
        }
        return dp[n - 1];
    }
};