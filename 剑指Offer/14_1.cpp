/**
 * 14- I. 剪绳子
 * https://leetcode-cn.com/problems/jian-sheng-zi-lcof/
 */

using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        if(n <= 3){
            return n - 1;
        }
        int res = 1;
        while(n > 4){
            res *= 3;
            n -= 3;
        }
        return res * n;
    }
};

