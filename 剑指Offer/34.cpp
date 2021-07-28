/**
 * 34. 二叉树中和为某一值的路径
 * https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/
 */

#include<vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        rec(root, target);
        return res;
    }

    void rec(TreeNode* root, int target){
        if(!root) return;
        path.emplace_back(root->val);
        target -= root->val;
        if(target == 0 && !root->left && !root->right){
            res.emplace_back(path);
        }
        rec(root->left, target);
        rec(root->right, target);
        path.pop_back();
    }
};