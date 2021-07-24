/**
 * 28. 对称的二叉树
 * https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/
 */

#include<stdio.h>
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
    bool isSymmetric(TreeNode* root) {
        return dfs(root, root);
    }

    bool dfs(TreeNode* leftNode, TreeNode* rightNode){
        if(!leftNode && !rightNode) return true;
        if(leftNode && rightNode && leftNode->val == rightNode->val){
            return dfs(leftNode->left, rightNode->right) && dfs(leftNode->right, rightNode->left);
        }
        return false;
    }
};