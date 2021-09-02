 /**
 * 65. 不用加减乘除做加法
 * https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/
 */

using namespace std;

class Solution {
public:
    int add(int a, int b) {
        while(b != 0){
            int tmp = a^b;
            // left shift of negative value
            b = (unsigned int)(a&b) << 1;
            a = tmp;
        }
        return a;
    }
};