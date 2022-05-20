func replaceSpaces(S string, length int) string {
    return strings.Join(strings.Split(S[0:length], " "), "%20")
}

func replaceSpaces(S string, length int) string {
    return strings.ReplaceAll(S[0:length]," ","%20")
}

func replaceSpaces(S string, length int) string {
    return strings.Replace(S[0:length]," ","%20", -1)
}

func replaceSpaces(S string, length int) string {
    c := []byte(S)
    i := length - 1
    j := len(S) - 1
    for i >= 0 {
        if c[i] == ' ' {
            c[j] = '0'
            j--
            c[j] = '2'
            j--
            c[j] = '%'
            j--
        } else {
            c[j] = c[i]
            j--
        }
        i--
    }
    return string(c[j+1:len(S)])
}