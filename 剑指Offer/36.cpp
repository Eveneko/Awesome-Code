/**
 * 36. 二叉搜索树与双向链表
 * https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/
 */

#include<stdio.h>
using namespace std;

/*
 * Definition for a Node.
*/
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* head;
    Node* pre;
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr) return nullptr;
        rec(root);
        head->left = pre;
        pre->right = head;
        return head;
    }

    void rec(Node* node){
        if(node == nullptr) return;
        rec(node->left);
        if(pre == nullptr){
            head = node;
        }else{
            pre->right = node;
        }
        node->left = pre;
        pre = node;
        rec(node->right);
    }
};