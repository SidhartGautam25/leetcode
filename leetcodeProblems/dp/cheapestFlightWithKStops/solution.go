package cheapestflightwithkstops

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

}

func findCheapestPrice(n int, flights [][]int, src int, dst int, k int) int {
	return solutionOne(n, flights, src, dst, k)

}
