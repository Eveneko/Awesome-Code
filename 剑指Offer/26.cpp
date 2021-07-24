/**
 * 26. 树的子结构
 * https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/
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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A == NULL || B == NULL) return false;
        return isSameStructure(A, B) || isSubStructure(A->right, B) || isSubStructure(A->left, B);
    }

    bool isSameStructure(TreeNode* A, TreeNode* B){
        if(B == NULL) return true;
        if(A == NULL) return false;
        return A->val == B->val && isSameStructure(A->right, B->right) && isSameStructure(A->left, B->left);
    }
};