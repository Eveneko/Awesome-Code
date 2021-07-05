/**
 * 07. 重建二叉树
 * https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/
 */

#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    unordered_map<int, int> indexmap;
    TreeNode* gen(vector<int>& preorder, int prestart, int preend, vector<int>& inorder, int instart, int inend) {
        if(prestart <= preend && instart <= inend){
            TreeNode *newnode = new TreeNode(preorder[prestart]);
            int offset = indexmap[preorder[prestart]] - instart;
            newnode->left = gen(preorder, prestart+1, prestart+offset, inorder, instart, instart+offset-1);
            newnode->right = gen(preorder, prestart+offset+1, preend, inorder, instart+offset+1, inend);
            return newnode;
        }
        return nullptr;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            indexmap[inorder[i]] = i;
        }
        return gen(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};