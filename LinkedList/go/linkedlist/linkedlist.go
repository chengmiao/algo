package link


import (
	//"fmt"
)


type linkednode struct {
	data int
	next *linkednode
}


type LinkedList struct {
	Head *linkednode
}

func (l *LinkedList) Insert(value int) bool {
	return false
}

func (l *LinkedList) FindByValue(value int) *linkednode {
	return nil
}

func (l *LinkedList) FindByIndex(index int) *linkednode {
	return nil
}

func (l *LinkedList) DeleteByValue(value int) bool {
	return false
}

func (l *LinkedList) DeleteByIndex(index int) bool {
	return false
}