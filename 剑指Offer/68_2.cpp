 /**
 * 68 - II. 二叉树的最近公共祖先
 * https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/
 */

#include<cstddef>
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* res;

    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr) return false;
        bool l = dfs(root->left, p, q);
        bool r = dfs(root->right, p, q);
        if((l && r) || (root->val == p->val || root->val == q->val) && (l || r)){
            res = root;
        }
        return l || r || (root->val == p->val || root->val == q->val);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return res;
    }
};