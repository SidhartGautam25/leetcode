package dp

func isPalindrome(str string) bool {
	i, j := 0, len(str)-1
	for i < j {
		if str[i] != str[j] {
			return false
		}
		i++
		j--
	}
	return true
}

func recursiveHelp(s string, result *[][]string, temp []string) {

	if len(s) == 0 {
		*result = append(*result, append([]string{}, temp...))
		return
	}

	for i := 0; i < len(s); i++ {
		leftPart := s[:i+1]
		if isPalindrome(leftPart) {
			temp = append(temp, leftPart)
			recursiveHelp(s[i+1:], result, temp)
			temp = temp[:len(temp)-1]
		}

	}
}

func solutionOneOfPartition(s string) [][]string {

	var result [][]string
	var temp []string

	recursiveHelp(s, &result, temp)

	return result

}

func partition(s string) [][]string {

	res := solutionOneOfPartition(s)
	return res

}
