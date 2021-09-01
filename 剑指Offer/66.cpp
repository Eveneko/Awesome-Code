 /**
 * 66. 构建乘积数组
 * https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof/
 */

#include<vector>
using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int len = a.size();
        if(len == 0) return {};
        vector<int> b(len, 1);
        for(int i = 1; i < len; ++i) {
            b[i] = b[i - 1] * a[i - 1];
        }
        int tmp = 1;
        for(int i = len - 2; i >= 0; --i) {
            tmp *= a[i + 1];
            b[i] *= tmp;
        }
        return b;
    }
};
