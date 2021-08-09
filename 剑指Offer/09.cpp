/**
 * 09. 用两个栈实现队列
 * https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/
 */

#include<stack>
using namespace std;

class CQueue {
public:
    stack<int> stack1;
    stack<int> stack2;
    CQueue() {}
    
    void appendTail(int value) {
        stack1.push(value);
    }
    
    int deleteHead() {
        if (stack1.empty()) return -1;
        
        while (!stack1.empty()){ // 1 -> 2
            int tmp = stack1.top();
            stack1.pop();
            stack2.push(tmp);
        }
        // delete head
        int res = stack2.top();
        stack2.pop();
        while (!stack2.empty()){ // 1 <- 2
            int temp = stack2.top();
            stack2.pop();
            stack1.push(temp);
        }
        return res;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */