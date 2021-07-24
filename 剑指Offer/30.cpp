/**
 * 30. 包含min函数的栈
 * https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/
 */

#include<stack>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    stack<int> stMin;

    MinStack() {
    }
    
    void push(int x) {
        st.push(x);
        if(stMin.empty() || x <= stMin.top()){
            stMin.push(x);
        }
    }
    
    void pop() {
        if(st.top() == stMin.top()){
            stMin.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int min() {
        return stMin.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */