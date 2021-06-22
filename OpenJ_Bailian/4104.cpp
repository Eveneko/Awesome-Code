#include <bits/stdc++.h>
using namespace std;

string line;
int k;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie();

    getline(cin, line);
    line = line + " ";
    k = 0;
    for(int i = 0; i < line.length(); i++){
        if(line[i] == ' ') {
            for(int j = i - 1; j >= k; j--){
                cout << line[j];
            }
            cout << " ";
            k = i + 1;
        }
    }

    return 0;
}