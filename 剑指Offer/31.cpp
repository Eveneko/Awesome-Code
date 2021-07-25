/**
 * 31. 栈的压入、弹出序列
 * https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/
 */

#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
       stack<int> st;
       int index = 0;
       for(int num : pushed){
           st.push(num);
           while(!st.empty() && st.top() == popped[index]){
               st.pop();
               ++index;
           }
       } 
       return st.empty();
    }
};