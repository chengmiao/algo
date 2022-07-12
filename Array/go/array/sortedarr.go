package array

import (
	"errors"
	"reflect"
	//"fmt"
	//"golang.org/x/exp/constraints"
)

func Less(a, b interface{}) bool {
		vala := reflect.ValueOf(a)
		switch vala.Kind() {
		case reflect.Int, reflect.Int8, reflect.Int16, reflect.Int32, reflect.Int64:
			valb := reflect.ValueOf(b)
			return vala.Int() < valb.Int()
		case reflect.Uint, reflect.Uint8, reflect.Uint16, reflect.Uint32, reflect.Uint64, reflect.Uintptr:
			valb := reflect.ValueOf(b)
			return vala.Uint() < valb.Uint()
		case reflect.Float32, reflect.Float64:
			valb := reflect.ValueOf(b)
			return vala.Float() < valb.Float()
		default:
			return false
		}

		return false
}

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

func (s *SortedArray) Append(value interface{}) error {
	if s.m_size == s.m_capacity {
		return errors.New("out of range")
	}

	index := s.m_size - 1
	for ; index >= 0; index-- {
		if Less(value, s.m_array[index]) {
			s.m_array[index+1] = s.m_array[index]
		} else {
			break
		}
	}

	s.m_array[index+1] = value
	s.m_size++
	return nil
}
