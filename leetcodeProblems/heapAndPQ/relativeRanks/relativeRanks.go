package relativeranks

import (
	"container/heap"
	"sort"
	"strconv"
)

type rankPair struct {
	rank  int
	index int
}

type maxHeap []rankPair

func (h maxHeap) Len() int           { return len(h) }
func (h maxHeap) Less(i, j int) bool { return h[i].rank > h[j].rank }
func (h maxHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *maxHeap) Push(x any) {
	*h = append(*h, x.(rankPair))
}
func (h *maxHeap) Pop() any {
	old := *h
	n := len(old)
	item := old[n-1]
	*h = old[:n-1]
	return item
}

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

// Using priority queue
func solutionTwo(score []int) []string {

	n := len(score)
	result := make([]string, n)

	h := maxHeap{}

	for i, val := range score {
		h = append(h, rankPair{rank: val, index: i})
	}

	heap.Init(&h)

	for i := 0; i < n; i++ {
		pair := heap.Pop(&h).(rankPair)

		switch i {
		case 0:
			result[pair.index] = "Gold Medal"
		case 1:
			result[pair.index] = "Silver Medal"
		case 2:
			result[pair.index] = "Bronze Medal"
		default:
			result[pair.index] = strconv.Itoa(i + 1)
		}

	}

	return result

}

func findRelativeRanks(score []int) []string {
	ans1 := solutionOne(score)
	return ans1

}
