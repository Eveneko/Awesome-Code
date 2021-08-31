 /**
 * 64. 求1+2+…+n
 * https://leetcode-cn.com/problems/qiu-12n-lcof/
 */

using namespace std;

class Solution {
public:
    int sumNums(int n) {
        n && (n += sumNums(n-1));
        return n;
    }
};