/**
 * 43. 1～n 整数中 1 出现的次数
 * https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/
 */

#include<cstring>
using namespace std;

class Solution {
public:
    int digit[11];
    int dp[11][11];
    int dfs(int pos, int count, bool limit){
        if(pos == 0){
            return count;
        }
        if(!limit && dp[pos][count] != -1){
            return dp[pos][count];
        }
        int res = 0;
        int max = limit?digit[pos]:9;
        for(int i = 0; i <= max; ++i){
            if(i == 1){
                res += dfs(pos-1, count + 1, limit && (i == max));
            }else{
               res += dfs(pos-1, count, limit && (i == max)); 
            }
        }
        if(!limit){
            dp[pos][count] = res;
        }
        return res;
    }
    int solve(int n){
        memset(dp, -1, sizeof(dp));
        int pos = 0;
        while(n){
            digit[++pos] = n%10;
            n /= 10;
        }
        return dfs(pos, 0, true);
    }
    int countDigitOne(int n) {
        if(n <= 0){
            return 0;
        }
        return solve(n);
    }
};