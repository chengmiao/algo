package myqueue

import (
	"array"
	"fmt"
	"link"
)

type Queue struct {
	arr  *array.Arr
	head int
	tail int
	num  int
}

func NewQueue(size int) *Queue {
	arr := array.NewArr(size)
	for i := 0; i < size; i++ {
		arr.Append(0)
	}

	q := &Queue{
		arr:  arr,
		head: 0,
		tail: 0,
		num:  size,
	}

	return q
}

func (q *Queue) Enqueue(value int) bool {
	if q.head == 0 && q.tail == q.num {
		return false
	}

	if q.head != 0 && q.tail == q.num {
		for i := q.head; i < q.tail; i++ {
			res, _ := q.arr.GetArr(i)
			q.arr.SetArr(i-q.head, res)
		}

		q.tail = q.tail - q.head
		q.head = 0
	}

	q.arr.SetArr(q.tail, value)
	q.tail++

	return true
}

func (q *Queue) Dequeue() bool {
	if q.head == q.tail {
		return false
	}

	q.head++
	return true
}

func (q *Queue) Print() {
	for i := q.head; i < q.tail; i++ {
		fmt.Println(q.arr.GetArr(i))
	}
}

type LinkedQueue struct {
	head *link.Linkednode
	tail *link.Linkednode
}

func NewLinkedQueue() *LinkedQueue {
	lq := &LinkedQueue{
		head: nil,
		tail: nil,
	}

	return lq
}

func (lq *LinkedQueue) Enqueue(value int) bool {
	new_node := &link.Linkednode{Next: nil, Data: value}
	if lq.tail != nil {
		lq.tail.Next = new_node
	}

	if lq.head == nil {
		lq.head = new_node
	}

	lq.tail = new_node

	return true
}

func (lq *LinkedQueue) Dequeue() bool {
	if lq.head == nil {
		return false
	}

	lq.head = lq.head.Next
	if lq.head == nil {
		lq.tail = nil
	}

	return true
}

func (lq *LinkedQueue) Print() {
	p := lq.head
	for {
		if p == nil {
			break
		}

		fmt.Println(p.Data)
		p = p.Next
	}
}

type RingQueue struct {
	arr  *array.Arr
	head int
	tail int
	num  int
}

func NewRingQueue(size int) *RingQueue {
	arr := array.NewArr(size)
	for i := 0; i < size; i++ {
		arr.Append(0)
	}

	rq := &RingQueue{
		arr:  arr,
		head: 0,
		tail: 0,
		num:  size,
	}

	return rq
}

func (rq *RingQueue) Enqueue(value int) bool {
	if (rq.tail+1)%rq.num == rq.head {
		return false
	}

	rq.arr.SetArr(rq.tail, value)
	rq.tail = (rq.tail + 1) % rq.num
	return true
}

func (rq *RingQueue) Dequeue() bool {
	if rq.head == rq.tail {
		return false
	}

	rq.head = (rq.head + 1) % rq.num
	return true
}

func (rq *RingQueue) Print() {
	pos := rq.head
	for {
		if pos == rq.tail {
			break
		}

		fmt.Println(rq.arr.GetArr(pos))
		pos = (pos + 1) % rq.num
	}
}
