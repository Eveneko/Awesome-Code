func CheckPermutation(s1 string, s2 string) bool {
    if len(s1) != len(s2) {
        return false
    }
    s1_list := strings.Split(s1, "")
    s2_list := strings.Split(s2, "")
    sort.Strings(s1_list)
    sort.Strings(s2_list)
    res_s1 := strings.Join(s1_list, "")
    res_s2 := strings.Join(s2_list, "")
    return res_s1 == res_s2
}

func CheckPermutation(s1 string, s2 string) bool {
    b1 := []byte(s1)
    b2 := []byte(s2)
    sort.Slice(b1, func(i, j int) bool { return b1[i] < b1[j] })
    sort.Slice(b2, func(i, j int) bool { return b2[i] < b2[j] })
    return string(b1) == string(b2)
}

func CheckPermutation(s1 string, s2 string) bool {
    var c1, c2 [26]int
    for _, c := range s1 {
        c1[c-'a']++
    }
    for _, c := range s2 {
        c2[c-'a']++
    }
    return c1 == c2
}