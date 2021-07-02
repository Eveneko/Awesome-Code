#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 30

string str;
int num;

struct strcmp {
    bool operator ()(string &a, string &b) {
        return a > b;
    }
};

class FS {
    struct DIR {
        string name;
        priority_queue<string, vector<string>, struct strcmp> subfiles;
        DIR *subDirs[MAX_SIZE];
        int cntDir;

        DIR(string name) {
            this->name = name;
            cntDir = 0;
        }
        void gen() {
            str.resize(MAX_SIZE);
            while(scanf("%s", &str[0]) != EOF){
                if(str[0] == ']') {
                    break;
                }
                if(str[0] == '#') {
                    exit(0);
                }
                if(str[0] == '*') {
                    output(this);
                    return;
                }
                if(str[0] == 'f') {
                    subfiles.push(str);
                }else {
                    subDirs[cntDir] = new DIR(str);
                    subDirs[cntDir++]->gen();
                }
            }
        }
    };

public:
    DIR *ROOT;
    FS() {
        ROOT = new DIR("ROOT");
        ROOT->gen();
    }
    friend void output(DIR *dir) {
        printf("DATA SET %d:\n", num);
        output(dir, 0);
        printf("\n");
    }
    friend void output(DIR *dir, int level) {
        for(int i = 0; i < level; i++) {
            printf("|     ");
        }
        printf("%s\n", dir->name.c_str());
        for(int i = 0; i < dir->cntDir; i++) {
            output(dir->subDirs[i], level + 1);
        }
        while(!dir->subfiles.empty()) {
            for(int i = 0; i < level; i++) {
                printf("|     ");
            }
            printf("%s\n", dir->subfiles.top().c_str());
            dir->subfiles.pop();
        }
    }
};

void init() {
    num = 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    init();

    while (true) {
        num++;
        FS fs;
    }
    
    return 0;
}