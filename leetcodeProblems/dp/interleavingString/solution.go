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

// 1D DP Solution
func solutionTwo(s1 string, s2 string, s3 string) bool {
	m := len(s1)
	n := len(s2)

	if m+n != len(s3) {
		return false
	}
	prev_row_dp := make([]bool, n+1)

	for i := 0; i <= m; i++ {
		curr_row_dp := make([]bool, n+1)
		for j := 0; j <= n; j++ {
			if i == 0 && j == 0 {
				// base
				curr_row_dp[j] = true
			} else if i == 0 {
				curr_row_dp[j] = curr_row_dp[j-1] && (s2[j-1] == s3[i+j-1])
			} else if j == 0 {
				curr_row_dp[j] = prev_row_dp[j] && (s1[i-1] == s3[i+j-1])
			} else {
				// three condition again
				// first --> s1 curr == s3 curr
				if s1[i-1] == s3[i+j-1] && s2[j-1] != s3[i+j-1] {
					curr_row_dp[j] = prev_row_dp[j]

				} else if s2[j-1] == s3[i+j-1] && s1[i-1] != s3[i+j-1] {
					// second --> s2 curr == s3 curr
					curr_row_dp[j] = curr_row_dp[j-1]

				} else if s1[i-1] == s3[i+j-1] && s2[j-1] == s3[i+j-1] {
					// third --> s1 curr==s2 curr == s3 curr
					curr_row_dp[j] = curr_row_dp[j-1] || prev_row_dp[j]

				}
			}
		}

		prev_row_dp = curr_row_dp

	}
	return prev_row_dp[n]
}

func isInterleave(s1 string, s2 string, s3 string) bool {

	ans1 := solutionOne(s1, s2, s3)
	ans2 := solutionTwo(s1, s2, s3)

	sol := "first"
	if sol == "first" {
		return ans1
	}

	return ans2

}
