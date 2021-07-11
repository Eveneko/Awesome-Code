/**
 * 17. 打印从1到最大的n位数
 * https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/
 */

#include<vector>
using namespace std;

class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        int num = 1;
        for(int i = 0; i < n; ++i){
            num *= 10;
        }
        for(int i = 1; i < num; ++i){
            res.push_back(i);
        }
        return res;
    }
};