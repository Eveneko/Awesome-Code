func oneEditAway(first string, second string) bool {
    m, n := len(first), len(second)
    if diff := m - n; diff < -1 || diff > 1 {
        return false
    }
    for i, j, flag := 0, 0, false; i < m && j < n; {
        if first[i] == second[j] {
            i++
            j++
        } else if flag {
            return false
        } else {
            if m > n {
                i++
            } else if m < n {
                j++
            } else {
                i++
                j++
            }
            flag = true
        }
    } 
    return true
}

func oneEditAway(first string, second string) bool {
    m, n := len(first), len(second)
    if m < n {
        return oneEditAway(second, first)
    }
    if m - n > 1 {
        return false
    }
    for i, c := range second {
        if first[i] != byte(c) {
            if m == n {
                return first[i+1:] == second[i+1:]
            }
            return first[i+1:] == second[i:]
        }
    }
    return true
}