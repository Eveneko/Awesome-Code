/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func isPalindrome(head *ListNode) bool {
    pt := head
    var isRecursive func(*ListNode) bool
    isRecursive = func(node *ListNode) bool {
        if node != nil {
            if !isRecursive(node.Next){
                return false
            }
            if node.Val != pt.Val {
                return false
            }
            pt = pt.Next
        }
        return true
    }
    return isRecursive(head)
}

// 反转链表

func isPalindrome(head *ListNode) bool {
    tail := reverse(findMiddle(head))

    for head != nil && tail != nil {
        if head.Val != tail.Val {
            return false
        }
        head = head.Next
        tail = tail.Next
    }
    return true
}

func findMiddle(head *ListNode) *ListNode {
    if head == nil {
        return nil
    }
    fast, slow := head, head
    for fast != nil && fast.Next != nil {
        fast = fast.Next.Next
        slow = slow.Next
    }
    return slow
}

func reverse(head *ListNode) *ListNode {
    if head == nil {
        return nil
    }
    cur := head.Next
    head.Next = nil
    for cur != nil {
        next := cur.Next
        cur.Next = head
        head = cur
        cur = next
    }
    return head
}