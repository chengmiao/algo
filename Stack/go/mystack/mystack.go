package mystack

import (
	"array"
	"fmt"
	"link"
)

type MyStack struct {
	arr *array.Arr
	top int
	num int
}

func NewMyStack(size int) *MyStack {
	arr := array.NewArr(size)
	for i := 0; i < size; i++ {
		arr.Append(nil)
	}

	stack := &MyStack{
		arr: arr,
		top: 0,
		num: size,
	}

	return stack
}

func (s *MyStack) Push(value int) bool {
	if s.top == s.num {
		s.arr.Append(nil)
		s.num = s.arr.GetCapacity()
	}

	s.arr.SetArr(s.top, value)
	s.top++
	return true
}

func (s *MyStack) Pop() bool {
	if s.top <= 0 {
		return false
	}

	s.top--
	return true
}

func (s *MyStack) Print() {
	for i := 0; i < s.top; i++ {
		fmt.Println(s.arr.GetArr(i))
	}
}

type LinkedStack struct {
	list *link.LinkedList
}

func NewLinkedStack() *LinkedStack {
	list := &link.LinkedList{}
	l := &LinkedStack{list: list}
	return l
}

func (l *LinkedStack) Push(value int) bool {
	return l.list.Insert(value)
}

func (l *LinkedStack) Pop() bool {
	return l.list.DeleteByIndex(0)
}

func (l *LinkedStack) Print() {
	l.list.Print()
}
