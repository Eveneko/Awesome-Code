func rotate(matrix [][]int)  {
    n := len(matrix)
    for i := 0; i < n/2; i++ {
        matrix[i], matrix[n-1-i] = matrix[n-1-i], matrix[i]
    }
    for i := 0; i < n; i++ {
        for j := 0; j < i; j++ {
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        }
    }
}

func rotate(matrix [][]int)  {
    n := len(matrix)
    for i := 0; i < n/2; i++ {
        for j := 0; j < (n+1)/2; j++ {
            matrix[i][j], matrix[n-1-j][i], matrix[n-1-i][n-1-j], matrix[j][n-1-i] = matrix[n-1-j][i], matrix[n-1-i][n-1-j], matrix[j][n-1-i], matrix[i][j]
        }
    }
}