 /**
 * 68 - I. 二叉搜索树的最近公共祖先
 * https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof/
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node = root;
        while(true){
            if(p->val < node->val && q->val < node->val){
                node = node->left;
            }else if(p->val > node->val && q->val > node->val){
                node = node->right;
            }else{
                break;
            }
        }
        return node;
    }
};