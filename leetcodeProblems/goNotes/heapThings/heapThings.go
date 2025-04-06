// A heap is a binary tree-based data structure used primarily for priority queues.
// It comes in two main types:

// Min-Heap: The root node has the smallest value.
// Max-Heap: The root node has the largest value.

// Go provides a heap interface in the container/heap package, but you need to implement
//
//	the heap yourself by satisfying that interface.
package heapthings

// defining heap types
// This means IntHeap is a custom type based on []int (a slice of integers).
// So we can now attach methods to IntHeap, just like you attach methods to a struct.
type IntHeap []int

// Now we are attaching method to IntHeap type
func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
