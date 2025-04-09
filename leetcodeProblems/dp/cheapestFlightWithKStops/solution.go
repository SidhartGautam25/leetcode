package cheapestflightwithkstops

import (
	"container/heap"
	"math"
)

// start of things for heap
// for solution 2
type FlightGraph [][][2]int

// min heap
type PriorityQueue [][]int

func (pq PriorityQueue) Len() int { return len(pq) }
func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i][0] < pq[j][0]
}
func (pq PriorityQueue) Swap(i, j int) { pq[i], pq[j] = pq[j], pq[i] }
func (pq *PriorityQueue) Push(x interface{}) {
	*pq = append(*pq, x.([]int))
}
func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[:n-1]
	return item
}

// end

// simple approach
// time complexity --> O(k*n)
// limited bfs type approach
func solutionOne(n int, flights [][]int, src int, dst int, k int) int {
	cost := make([]int, n)
	for i := 0; i < n; i++ {
		cost[i] = -1
	}

	cost[src] = 0

	for stop := 0; stop <= k; stop++ {
		temp := make([]int, n)

		copy(temp, cost)

		for _, flight := range flights {
			from := flight[0]
			to := flight[1]
			p := flight[2]

			if cost[from] == -1 {
				continue
			}

			total := cost[from] + p

			if temp[to] == -1 || temp[to] > total {
				temp[to] = total
			}

			if temp[to] == -1 || temp[to] > total {
				temp[to] = total
			}
		}
		cost = temp

	}

	return cost[dst]

}

// using dijikstra
// using priority queue
func solutionTWo(n int, flights [][]int, src int, dst int, k int) int {

	// adjancy graph
	graph := make(FlightGraph, n)
	for _, flight := range flights {
		graph[flight[0]] = append(graph[flight[0]], [2]int{flight[1], flight[2]})
	}

	pq := &PriorityQueue{}
	heap.Init(pq)
	heap.Push(pq, []int{0, src, 0})

	stops := make([]int, n)
	for i := range stops {
		stops[i] = math.MaxInt32
	}

	for pq.Len() > 0 {
		temp := heap.Pop(pq).([]int)
		cost, node, stop := temp[0], temp[1], temp[2]

		if stop > stops[node] || stop > k+1 {
			continue
		}

		stops[node] = stop
		if node == dst {
			return cost
		}

		for _, neighbor := range graph[node] {
			nextNode, price := neighbor[0], neighbor[1]
			heap.Push(pq, []int{cost + price, nextNode, stop + 1})
		}
	}

	return -1

}

// Using Bellman ford algorithm
func solutionThree(n int, flights [][]int, src int, dst int, k int) int {

	dist := make([]int, n)
	for i := 0; i < n; i++ {
		dist[i] = math.MaxInt32
	}
	dist[src] = 0

	for i := 0; i <= k; i++ {
		temp := make([]int, n)
		copy(temp, dist)

		for _, flight := range flights {
			from, to, price := flight[0], flight[1], flight[2]
			if dist[from] != math.MaxInt32 {
				if temp[to] > dist[from]+price {
					temp[to] = dist[from] + price
				}
			}
		}
		dist = temp

	}
	return dist[dst]
}

func findCheapestPrice(n int, flights [][]int, src int, dst int, k int) int {
	return solutionOne(n, flights, src, dst, k)

}
