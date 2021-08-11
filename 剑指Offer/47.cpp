/**
 * 47. 礼物的最大价值
 * https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/
 */

#include<vector>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n+1, 0);
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                dp[j] = max(dp[j], dp[j-1]) + grid[i-1][j-1];
            }
        }
        return dp[n];
    }
};