/**
 * 32 - I. 从上到下打印二叉树
 * https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-i-lcof/
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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> qu;
        qu.emplace(root);
        while(!qu.empty()){
            TreeNode* node = qu.front();
            res.emplace_back(node->val);
            qu.pop();
            if(node->left) qu.emplace(node->left);
            if(node->right) qu.emplace(node->right);
        }
        return res;
    }
};