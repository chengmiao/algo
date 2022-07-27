package link

import (
	"fmt"
)

type linkednode struct {
	data int
	next *linkednode
}

func (n *linkednode) SetData(value int) {
	n.data = value
}

type LinkedList struct {
	head *linkednode
}

func (l *LinkedList) Insert(value int) bool {
	new_node := &linkednode{data: value, next: nil}
	new_node.next = l.head
	l.head = new_node

	return true
}

func (l *LinkedList) FindByValue(value int) *linkednode {
	p := l.head
	for {
		if p == nil || p.data == value {
			break
		}
		p = p.next
	}

	return p
}

func (l *LinkedList) FindByIndex(index int) *linkednode {
	p := l.head
	pos := 0
	for {
		if p == nil || pos == index {
			break
		}
		p = p.next
		pos++
	}

	return p
}

func (l *LinkedList) DeleteByValue(value int) bool {
	if l.head == nil {
		return false
	}

	if l.head.data == value {
		l.head = l.head.next
		return true
	}

	prev := l.head
	p := prev.next
	for {
		if p == nil {
			break
		}

		if p.data == value {
			prev.next = p.next
			return true
		}

		prev = p
		p = p.next
	}

	return false
}

func (l *LinkedList) DeleteByIndex(index int) bool {
	if l.head == nil {
		return false
	}

	if index == 0 {
		l.head = l.head.next
		return true
	}

	prev := l.head
	p := prev.next
	pos := 1
	for {
		if p == nil {
			break
		}

		if pos == index {
			prev.next = p.next
			return true
		}

		prev = p
		p = p.next
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

		fmt.Println(p.data)
		p = p.next
	}
}
