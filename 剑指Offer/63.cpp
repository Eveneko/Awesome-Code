 /**
 * 63. 股票的最大利润
 * https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/
 */

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int res = 0;
        int min_price = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            min_price = min(min_price, prices[i]);
            res = max(res, prices[i] - min_price);
        }
        return res;
    }
};