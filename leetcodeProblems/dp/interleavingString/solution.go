package interleavingstring

// 2D DP
// simple one
func solutionOne(s1 string, s2 string, s3 string) bool {
	len1 := len(s1)
	len2 := len(s2)
	len3 := len(s3)

	if len1+len2 != len3 {
		return false
	}

	dp := make([][]bool, len1+1)
	for i := range dp {
		dp[i] = make([]bool, len2+1)
	}

	dp[0][0] = true

	// filling the first column
	for i := 1; i <= len1; i++ {
		if s1[i-1] == s3[i-1] {
			dp[i][0] = dp[i-1][0]
		}
	}

	// filling the first row
	for j := 1; j <= len2; j++ {
		if s2[j-1] == s3[j-1] {
			dp[0][j] = dp[0][j-1]
		}
	}

	// filling the dp table
	for i := 1; i <= len1; i++ {
		for j := 1; j <= len2; j++ {
			// if only s1[i-1] char is equal to s3 current character
			if s1[i-1] == s3[i+j-1] && s2[j-1] != s3[i+j-1] {
				dp[i][j] = dp[i-1][j]

			}
			// if only s2[j-1] char is equal to s3 current character
			if s1[i-1] != s3[i+j-1] && s2[j-1] == s3[i+j-1] {
				dp[i][j] = dp[i][j-1]

			}
			// if both s1[i-1]  and  s2[j-1] char are equal to s3 current char
			if s1[i-1] == s3[i+j-1] && s2[j-1] == s3[i+j-1] {
				dp[i][j] = dp[i-1][j] || dp[i][j-1]

			}
		}
	}

	return dp[len1][len2]

}

func isInterleave(s1 string, s2 string, s3 string) bool {

	return solutionOne(s1, s2, s3)

}
