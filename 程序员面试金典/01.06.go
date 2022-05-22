func compressString(S string) string {
    sLen := len(S)
    res := make([]byte, 0, sLen)
    for i, j := 0, 0; i < sLen; {
        for j < sLen && S[i] == S[j] {
            j++
        }
        res = append(res, S[i])
        res = append(res, []byte(strconv.Itoa(j-i))...)
        if len(res) >= sLen {
            return S
        }
        i = j
    }
    return string(res)
}

func compressString(S string) string {
    sLen := len(S)
    res := ""
    for i, j := 0, 0; i < sLen; {
        for j < sLen && S[i] == S[j] {
            j++
        }
        res += string(S[i])
        res += strconv.Itoa(j-i)
        if len(res) >= sLen {
            return S
        }
        i = j
    }
    return res
}

func compressString(S string) string {
    sLen := len(S)
    var res strings.Builder
    for i, j := 0, 0; i < sLen; {
        for j < sLen && S[i] == S[j] {
            j++
        }
        res.WriteByte(S[i])
        res.WriteString(strconv.Itoa(j-i))
        if res.Len() >= sLen {
            return S
        }
        i = j
    }
    return res.String()
}