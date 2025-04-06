// A heap is a binary tree-based data structure used primarily for priority queues.
// It comes in two main types:

// Min-Heap: The root node has the smallest value.
// Max-Heap: The root node has the largest value.

// Go provides a heap interface in the container/heap package, but you need to implement
//
//	the heap yourself by satisfying that interface.
package heapthings

import (
	"container/heap"
	"fmt"
)

// defining heap types
// This means IntHeap is a custom type based on []int (a slice of integers).
// So we can now attach methods to IntHeap, just like you attach methods to a struct.
type IntHeap []int

// Now we are attaching method to IntHeap type
func (h IntHeap) Len() int { return len(h) }

// if element at index i is smaller than at index j, return true.
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

// This is part of Go's heap.Interface, which expects you to implement Push(x any) and
//  Pop() any.

// This is a method with a pointer receiver. That means h is not a value copy of the heap
//  — it's a reference to the actual heap slice.

// So if you change *h, you're modifying the original heap, not just a copy of it.

// Why Do We Reassign to *h?
// Because slices in Go are not always modified in-place.
// append() might return a new slice, especially if it grows
//
//	beyond its current capacity.
func (h *IntHeap) Push(x any) {
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func usingHeap() {
	h := &IntHeap{3, 2, 1}
	heap.Init(h)
	heap.Push(h, 5)
	heap.Push(h, 0)

	fmt.Println("Heap : ", *h)
	for h.Len() > 0 {
		fmt.Printf("Pop: %d\n", heap.Pop(h))
	}
}
