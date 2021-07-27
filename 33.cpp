/**
 * 33. 二叉搜索树的后序遍历序列
 * https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/
 */

#include<limits.h>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        stack<int> st;
        int root = INT_MAX;
        int size = postorder.size();
        for(int i = size - 1; i >= 0; --i){
            if(postorder[i] > root) return false;
            while(!st.empty() && st.top() > postorder[i]){
                root = st.top();
                st.pop();
            }
            st.push(postorder[i]);
        }
        return true;
    }
};

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return rec(postorder, 0, postorder.size() - 1);
    }
    bool rec(vector<int>& postorder, int start, int end){
        if(start >= end) return true;
        int index = start;
        while(postorder[index] < postorder[end]) ++index;
        int div = index;
        while(postorder[index] > postorder[end]) ++index;
        if(index != end) return false;
        return rec(postorder, start, div-1) && rec(postorder, div, end-1);
    }
};