package array

import (
	"errors"
	//"fmt"
)

type SortedArray struct {
	*Arr
}

func NewSortedArr(capacity int) *SortedArray {

	arr := NewArr(capacity)

	s := &SortedArray{
		arr,
	}

	return s
}

func (s *SortedArray) Append(value int) error {
	if s.m_size == s.m_capacity {
		return errors.New("out of range")
	}

	index := s.m_size - 1
	for ; index >= 0; index-- {
		if value < s.m_array[index] {
			s.m_array[index+1] = s.m_array[index]
		} else {
			break
		}
	}

	s.m_array[index+1] = value
	s.m_size++
	return nil
}
