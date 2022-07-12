package array

import (
	"errors"
	"fmt"
	//"golang.org/x/exp/constraints"
)


type Arr struct {
	m_array    []interface{}
	m_capacity int
	m_size     int
}

func NewArr(capacity int) *Arr {
	arr := &Arr{
		m_capacity: capacity,
		m_size:     0,
		m_array:    make([]interface{}, capacity),
	}

	return arr
}

func (arr *Arr) SetArr(index int, value interface{}) error {
	if index < 0 || index >= arr.m_size {
		return errors.New("out of range")
	}

	arr.m_array[index] = value
	return nil
}

func (arr *Arr) GetArr(index int) (val interface{}, err error) {
	if index < 0 || index >= arr.m_size {
		err = errors.New("out of range")
		return
	}

	return arr.m_array[index], nil
}

func (arr *Arr) Append(value interface{}) error {
	if arr.m_size >= arr.m_capacity {
		new_array := make([]interface{}, arr.m_capacity*2)
		for i := 0; i < arr.m_size; i++ {
			new_array[i] = arr.m_array[i]
		}

		arr.m_array = new_array
		arr.m_capacity = cap(arr.m_array)

		fmt.Println("Arr resized")
	}

	arr.m_array[arr.m_size] = value
	arr.m_size++
	return nil
}

func (arr *Arr) Print() {
	for index := 0; index < arr.m_size; index++ {
		fmt.Println(arr.m_array[index])
	}
}

func (arr *Arr) GetSize() int {
	return arr.m_size
}
