package link

import (
	"fmt"
)

type Linkednode struct {
	Data int
	Next *Linkednode
}

func (n *Linkednode) SetData(value int) {
	n.Data = value
}

type LinkedList struct {
	head *Linkednode
}

func (l *LinkedList) Insert(value int) bool {
	new_node := &Linkednode{Data: value, Next: nil}
	new_node.Next = l.head
	l.head = new_node

	return true
}

func (l *LinkedList) FindByValue(value int) *Linkednode {
	p := l.head
	for {
		if p == nil || p.Data == value {
			break
		}
		p = p.Next
	}

	return p
}

func (l *LinkedList) FindByIndex(index int) *Linkednode {
	p := l.head
	pos := 0
	for {
		if p == nil || pos == index {
			break
		}
		p = p.Next
		pos++
	}

	return p
}

func (l *LinkedList) DeleteByValue(value int) bool {
	if l.head == nil {
		return false
	}

	if l.head.Data == value {
		l.head = l.head.Next
		return true
	}

	prev := l.head
	p := prev.Next
	for {
		if p == nil {
			break
		}

		if p.Data == value {
			prev.Next = p.Next
			return true
		}

		prev = p
		p = p.Next
	}

	return false
}

func (l *LinkedList) DeleteByIndex(index int) bool {
	if l.head == nil {
		return false
	}

	if index == 0 {
		l.head = l.head.Next
		return true
	}

	prev := l.head
	p := prev.Next
	pos := 1
	for {
		if p == nil {
			break
		}

		if pos == index {
			prev.Next = p.Next
			return true
		}

		prev = p
		p = p.Next
		pos++
	}

	return false
}

func (l *LinkedList) Print() {

	p := l.head
	for {
		if p == nil {
			break
		}

		fmt.Println(p.Data)
		p = p.Next
	}
}
