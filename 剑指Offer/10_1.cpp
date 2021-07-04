class Solution {
public:
    int fib(int n) {
        int a = 0;
        int b = 1;
        int tmp = 0;
        for(int i = 0; i < n; ++i){
            tmp = (a + b) % 1000000007;
            a = b;
            b = tmp;
        }
        return a;
    }
};