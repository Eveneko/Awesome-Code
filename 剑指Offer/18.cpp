/**
 * 18. 删除链表的节点
 * https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/
 */

using namespace std;

/**
 * Definition for singly-linked list.
 */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(!head) return nullptr;
        if(head->val == val) return head->next;
        head->next = deleteNode(head->next, val);
        return head;
    }
};