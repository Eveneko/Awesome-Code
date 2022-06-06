/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func removeDuplicateNodes(head *ListNode) *ListNode {
    if head == nil {
        return head
    }
    occurred := map[int]bool{head.Val: true}
    pos := head
    for pos.Next != nil {
        cur := pos.Next
        if !occurred[cur.Val] {
            occurred[cur.Val] = true
            pos = pos.Next
        } else {
            pos.Next = pos.Next.Next
        }
    }
    pos.Next = nil
    return head
}

func removeDuplicateNodes(head *ListNode) *ListNode {
    pos := head
    for pos != nil {
        tmp := pos
        for tmp.Next != nil {
            if tmp.Next.Val == pos.Val {
                tmp.Next = tmp.Next.Next
            } else {
                tmp = tmp.Next
            }
        }
        pos = pos.Next
    }
    return head
}
