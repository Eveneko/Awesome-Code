/**
 * 32 - III. 从上到下打印二叉树 III
 * https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/
 */

#include<stdio.h>
#include<queue>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> qu;
        qu.emplace(root);
        bool flag = true;
        while(!qu.empty()){
            vector<int> tmp;
            int size = qu.size();
            for(int i = 0; i < size; ++i){
                TreeNode* node = qu.front();
                tmp.emplace_back(node->val);
                qu.pop();
                if(node->left) qu.emplace(node->left);
                if(node->right) qu.emplace(node->right);
            }
            if(flag){
                res.emplace_back(tmp);
            }else{
                res.emplace_back(vector<int>(tmp.rbegin(), tmp.rend()));
            }
            flag = !flag;
        }
        return res;
    }
};