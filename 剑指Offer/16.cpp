/**
 * 16. 数值的整数次方
 * https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/
 */

using namespace std;

class Solution {
public:
    double myPow(double x, long long n) {
        if(x == 0) return 0;
        double res = 1;
        if(n < 0) {
            x = 1 / x;
            n = -n; 
        }
        while(n){
            if(n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }
};