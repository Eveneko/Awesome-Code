#include <bits/stdc++.h>
using namespace std;

int n;
int vis[25][50];
int dir[3][2] = {{1, 0}, {0, 1}, {0, -1}};

int find(int i, int j, int k) {
    if(k == 0) {
        return 1;
    }
    vis[i][j] = 1;
    int cnt = 0;
    for(int x = 0; x < 3; x++){
        int tmpi = i + dir[x][0];
        int tmpj = j + dir[x][1];
        if(vis[tmpi][tmpj] != 1) {
            cnt += find(tmpi, tmpj, k-1);
        }
    }
    vis[i][j] = 0;
    return cnt;
}

void init() {
    memset(vis, 0, sizeof(vis));
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;

    cout << find(0, 25, n) << '\n'; 

    return 0;
}