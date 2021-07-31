/**
 * 37. 序列化二叉树
 * https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof/
 */

#include<stdio.h>
#include<string>
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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "N";
        string left = "[" + serialize(root->left) + "]";
        string right = "[" + serialize(root->right) + "]";
        return left + to_string(root->val) + right;
    }

    // parse string to int
    int parseInt(const string &data, int &index){
        int num = 0;
        int sgn = 1;
        if(!isdigit(data[index])){
            sgn = -1;
            ++index;
        }
        while(isdigit(data[index])){
            num = num * 10 + data[index++] - '0';
        }
        return sgn * num;
    }

    // parse the string
    TreeNode* parse(const string &data, int &index){
        if(data[index] == 'N'){
            ++index;
            return nullptr;
        }
        TreeNode* node = new TreeNode(0);
        ++index;
        node->left = parse(data, index);
        ++index;
        node->val = parseInt(data, index);
        ++index;
        node->right = parse(data, index);
        ++index;
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return parse(data, index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));