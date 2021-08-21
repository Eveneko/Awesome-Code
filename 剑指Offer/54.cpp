/**
 * 54. 二叉搜索树的第k大节点
 * https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/
 */

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
    int res;
    void dfs(TreeNode* root, int &k) {
        if(!root) return;
        dfs(root->right, k);
        k--;
        if(k == 0){
            res = root->val;
        }
        dfs(root->left, k);
    }
    int kthLargest(TreeNode* root, int k) {
        dfs(root, k);
        return res;
    }
};