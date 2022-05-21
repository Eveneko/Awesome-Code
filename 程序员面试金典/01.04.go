func canPermutePalindrome(s string) bool {
    table := make(map[rune]int, len(s))
    n := 0
    for _, v := range s {
        table[v]++
    }
    for _, v := range table {
        if v != 2 {
            n++
            if n > 1 {
                return false
            }
        }
    }
    return true
}