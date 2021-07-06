/**
 * 12. 矩阵中的路径
 * https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/
 */

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool isFind = false;
    int len, m, n;
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    void dfs(int i, int j, int index, vector<vector<char>>& board, string word, vector<vector<bool>>& vis){
        if(index == len || isFind){
            isFind = true;
            return;
        }
        int x, y;
        for(int k = 0; k < 4; ++k){
            x = i + dir[k][0];
            y = j + dir[k][1];
            if(x < 0 || x >= m || y < 0 || y >= n || vis[x][y]){
                continue;
            }
            if(board[x][y] == word[index]){
                vis[x][y] = true;
                dfs(x, y, index+1, board, word, vis);
                vis[x][y] = false;
            }
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        len = word.size();
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(word[0] == board[i][j]){
                    vis[i][j] = true;
                    dfs(i, j, 1, board, word, vis);
                    vis[i][j] = false;
                }
                if(isFind){
                    return true;
                }
            }
        }
        return false;
    }
};