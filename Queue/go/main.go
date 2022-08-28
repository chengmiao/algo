package main

import (
	"demo/myqueue"
	"fmt"
)

func main() {

	q := myqueue.NewRingQueue(5)
	q.Enqueue(1)
	q.Enqueue(2)
	q.Enqueue(3)
	q.Enqueue(4)
	q.Enqueue(5)

	q.Dequeue()
	q.Dequeue()
	q.Dequeue()

	q.Enqueue(6)
	q.Enqueue(7)

	q.Print()

	fmt.Println("Queue Test!")
}
