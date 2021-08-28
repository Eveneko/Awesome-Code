/**
 * 60. n个骰子的点数
 * https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/
 */

#include<vector>
using namespace std;

class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> res;
        vector<int> dp(67, 0);
        for(int i = 1; i <= 6; ++i){
            dp[i] = 1;
        }
        for(int i = 2; i <= n; ++i){
            for(int j = 6*i; j >= i; --j){
                dp[j] = 0;
                for(int k = 1; k <= 6; ++k){
                    if(j - k < i - 1){
                        break;
                    }
                    dp[j] += dp[j-k];
                }
            }
        }
        int max = pow(6, n);
        for(int i = n; i <= 6*n; ++i){
            res.emplace_back(dp[i]*1.0/max);
        }
        return res;
    }
};