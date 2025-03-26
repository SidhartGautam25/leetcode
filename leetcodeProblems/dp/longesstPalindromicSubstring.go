package dp

// O(n*n) time complexity
// This approach is known as expand around center
// Other technique to solve this problem are
// Manacher's algorithm
// dp solution
func solutionOne(str string) string {
	if len(str) <= 1 {
		return str
	}

	result := ""

	fn := func(i int, j int) {
		for i >= 0 && j < len(str) {
			if str[i] != str[j] {
				break
			}

			if len(str[i:j+1]) > len(result) {
				result = str[i : j+1]
			}

			i--
			j++

		}
	}

	for i := 0; i < len(str); i++ {
		fn(i, i)
		fn(i, i+1)
	}

	return result

}

func solutionTwo(str string) string {

}

func longestPalindrome(s string) string {
	ans := solutionOne(s)
	return ans

}
