/**
 * 45. 把数组排成最小的数
 * https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/
 */

#include<algorithm>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    static bool cmp(const string &a, const string &b){
        return a + b < b + a;
    }
    string minNumber(vector<int>& nums) {
        string res;
        vector<string> strs;
        for(auto num : nums){
            strs.emplace_back(to_string(num));
        }
        sort(strs.begin(), strs.end(), cmp);
        for(auto str : strs){
            res += str;
        }
        return res;
    }
};