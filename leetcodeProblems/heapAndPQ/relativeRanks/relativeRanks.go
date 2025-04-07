package relativeranks

import (
	"sort"
	"strconv"
)

// simple solution
// just using array as map
func solutionOne(score []int) []string {
	n := len(score)
	result := make([]string, n)
	temp := make([][]int, n)

	// create pairs of {score,index}
	for i := 0; i < n; i++ {
		temp[i] = []int{score[i], i}
	}

	// sort in descending order
	sort.Slice(temp, func(i, j int) bool {
		return temp[i][0] > temp[j][0]
	})

	for i := 0; i < n; i++ {
		idx := temp[i][1]
		switch i {
		case 0:
			result[idx] = "Gold Medal"
		case 1:
			result[idx] = "Silver Medal"
		case 2:
			result[idx] = "Bronze Medal"
		default:
			result[idx] = strconv.Itoa(i + 1)
		}

	}

	return result

}

func findRelativeRanks(score []int) []string {
	ans1 := solutionOne(score)
	return ans1

}
