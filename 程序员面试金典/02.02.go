/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func kthToLast(head *ListNode, k int) int {
    pt := head
    for ;k > 1; k-- {
        pt = pt.Next
    }
    for pt.Next != nil {
        head = head.Next
        pt = pt.Next
    }
    return head.Val
}