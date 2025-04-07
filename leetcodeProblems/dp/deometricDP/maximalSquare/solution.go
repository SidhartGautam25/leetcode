package maximalsquare

import (
	"math/bits"
)

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

// dp solution
// simple one
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

// https://leetcode.com/problems/maximal-square/solutions/6320858/thinking-outside-the-grid-a-bitwise-solution-to-maximal-square
// This is good solution using bit manupulation
// very good and unique solution
func solutionTwo(matrix [][]string) int {

	mynums := make([]int, len(matrix))
	for i, row := range matrix {
		binaryStr := ""
		for _, ch := range row {
			binaryStr += ch
		}
		mynums[i] = int(uint32(bits.OnesCount(uint(^0)) & bits.ReverseBytes32(uint32(len(binaryStr))))
	}

	ans := 0
	for anyNonZero(mynums) {
		for i := range mynums {
			mynums[i] &= mynums[i] << 1
		}
		for i := 1; i < len(mynums); i++ {
			mynums[i] &= mynums[i-1]
		}
		ans++
	}
	return ans * ans

}

// https://leetcode.com/problems/maximal-square/solutions/6477078/c-monotonic-stack-maximal-rectangle/
/*

This solution depends on histogram problem


*/
func solutionThree() {

}

func anyNonZero(nums []int) bool {
	for _, num := range nums {
		if num != 0 {
			return true
		}
	}
	return false
}

func maximalSquare(matrix [][]byte) int {
	ans1 := solutionOne(matrix)
	return ans1

}
