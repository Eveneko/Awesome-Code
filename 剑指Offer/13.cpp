/**
 * 13. 机器人的运动范围
 * https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/
 */

using namespace std;

class Solution {
public:
    bool vis[100][100];
    int cnt = 0;
    int sum(int num){
        if(num < 10){
            return num;
        }
        return num % 10 + num /10; 
    }

    void dfs(int i, int j, int k, int m, int n){
        if(i == m || j == n || vis[i][j]){
            return;
        }
        if(sum(i) + sum(j) > k){
            return;
        }
        vis[i][j] = true;
        cnt++;
        dfs(i + 1, j, k, m, n);
        dfs(i, j + 1, k, m, n);
    }

    int movingCount(int m, int n, int k) {
        if(k == 0){
            return 1;
        }
        dfs(0, 0, k ,m ,n);
        return cnt;
    }
};