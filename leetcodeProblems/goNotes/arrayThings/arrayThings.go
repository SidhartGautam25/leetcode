package arraythings

import "fmt"

func levelZero() {
	var len1 int
	var len2 int
	// declare a 2D array
	dp := make([][]bool, len1+1)
	for i := range dp {
		dp[i] = make([]bool, len2+1)
	}

	// making array of pairs
	type Pair struct {
		first  int
		second string
	}

	pairs := []Pair{
		{first: 1, second: "navneet"},
		{first: 2, second: "sidhart"},
	}

	for _, pair := range pairs {
		fmt.Printf("first is %d , and second is %s \n", pair.first, pair.second)
	}

	size := 10
	pairs2 := make([]Pair, size)

	for i := 0; i < size; i++ {
		pairs2[i] = Pair{first: i, second: "random"}
	}
}
