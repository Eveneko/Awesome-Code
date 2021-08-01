/**
 * 38. 字符串的排列
 * https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/
 */

#include<algorithm>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        vector<string> res;
        res.emplace_back(s);
        while(next_permutation(s.begin(), s.end())){
            res.emplace_back(s);
        }
        return res;
    }
};

class Solution {
public:
    vector<string> res;
    vector<string> permutation(string s) {
        dfs(s, 0);
        return res;
    }

    void dfs(string &s, int index){
        if(index == s.size()){
            res.emplace_back(s);
            return;
        }
        for(int i = index; i < s.size(); ++i){
            bool flag = true;
            for(int j = index; j < i; ++j){
                if(s[i] == s[j]){
                    flag = false;
                }
            }
            if(!flag) continue;
            swap(s[index], s[i]);
            dfs(s, index+1);
            swap(s[index], s[i]);
        }
    }
};