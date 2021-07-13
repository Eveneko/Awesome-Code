/**
 * 19. 正则表达式匹配
 * https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/
 */

#include<string.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.size();
        int plen = p.size();
        bool dp[slen + 1][plen + 1];
        memset(dp, false, sizeof(dp));
        dp[slen][plen] = true;
        for (int i = slen; i >= 0; i--) {
            for (int j = plen - 1; j >= 0; j--) {
                bool match = (i < slen && (s[i] == p[j] || p[j] == '.'));
                if (j + 1 < plen && p[j + 1] == '*') {
                    dp[i][j] = dp[i][j + 2] || (match && dp[i + 1][j]);
                } else {
                    dp[i][j] = match && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};