#include <bits/stdc++.h>
using namespace std;

int n;
string str;
string res;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;
    cin >> str;
    res = "";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < str.length() / n; j++) {
            int index = 0;
            if(j % 2 == 0){
                index = n * j + i;
            }else{
                index = n * (j + 1) - i - 1;
            }
            res += str[index];
        }
    }
    
    cout << res << '\n';

    return 0;
}