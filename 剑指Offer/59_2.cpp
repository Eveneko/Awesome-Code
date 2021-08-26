/**
 * 59 - II. 队列的最大值
 * https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/
 */

#include<queue>
#include<deque>
using namespace std;

class MaxQueue {
public:
    queue<int> qu;
    deque<int> dq;
    MaxQueue() {

    }
    
    int max_value() {
        if(dq.empty()){
            return -1;
        }
        return dq.front();
    }
    
    void push_back(int value) {
        while(!dq.empty() && dq.back() < value){
            dq.pop_back();
        }
        dq.emplace_back(value);
        qu.push(value);
    }
    
    int pop_front() {
        if(qu.empty()){
            return -1;
        }
        int res = qu.front();
        if(res == dq.front()){
            dq.pop_front();
        }
        qu.pop();
        return res;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */