func isUnique(astr string) bool {
    num := 0
    for _, c := range astr {
        bit := c - 'a'
        if num & (1 << bit) != 0 {
            return false
        } else {
            num = num | (1 << bit)
        }
    }
    return true
}