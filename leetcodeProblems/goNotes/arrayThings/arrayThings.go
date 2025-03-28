package arraythings

func levelZero() {
	var len1 int
	var len2 int
	// declare a 2D array
	dp := make([][]bool, len1+1)
	for i := range dp {
		dp[i] = make([]bool, len2+1)
	}
}
