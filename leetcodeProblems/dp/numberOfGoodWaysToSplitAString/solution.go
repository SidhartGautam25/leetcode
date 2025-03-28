package numberofgoodwaystosplitastring

// easy one actually
func solutionOne(s string) int {
	n := len(s)

	left := make([]int, n) // dynamic

	dict := [26]bool{} // Fixed-size boolean array

	ps := 0
	for i := range s {
		if !dict[s[i]-'a'] {
			dict[s[i]-'a'] = true
			ps++
		}
		left[i] = ps
	}

	right := make([]int, n)
	dict = [26]bool{}
	ps = 0
	for i := n - 1; i >= 0; i-- {
		if !dict[s[i]-'a'] {
			dict[s[i]-'a'] = true
		}
		right[i] = ps
	}
	result := 0
	for i := 0; i < n-1; i++ {
		if left[i] == right[i+1] {
			result++
		}
	}

	return result
}

func numSplits(s string) int {

	ans := solutionOne(s)
	return ans

}
