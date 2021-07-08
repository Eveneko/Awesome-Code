/**
 * 14- II. 剪绳子 II
 * https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof/
 */

using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        if(n <= 3){
            return n - 1;
        }
        long long res = 1;
        while(n > 4){
            res = (res * 3) % 1000000007;
            n -= 3;
        }
        return (res * n) % 1000000007;
    }
};