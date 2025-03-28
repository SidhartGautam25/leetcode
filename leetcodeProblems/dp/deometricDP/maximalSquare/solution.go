package maximalsquare

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func solutionOne(matrix [][]byte) int {
	if len(matrix) == 0 {
		return 0
	}

	m, n := len(matrix), len(matrix[0])

	dp := make([][]int, m)
	maxSize := 0

	for i := range dp {
		dp[i] = make([]int, n)
	}

	for i := m - 1; i >= 0; i-- {
		for j := n - 1; j >= 0; j-- {
			if (i == m-1 || j == n-1) && matrix[i][j] == '1' {
				dp[i][j] = 1
			} else if matrix[i][j] == '1' {
				dp[i][j] = 1 + min(dp[i][j+1], min(dp[i+1][j], dp[i+1][j+1]))
			}
			maxSize = max(maxSize, dp[i][j])
		}
	}

	return maxSize * maxSize

}

func maximalSquare(matrix [][]byte) int {
	ans1 := solutionOne(matrix)
	return ans1

}
