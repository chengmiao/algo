package main

import (
	"demo/array"
)


func merge(a, b *array.SortedArray) *array.SortedArray {
	new_size := a.GetSize() + b.GetSize()
	new_sorted := array.NewSortedArr(new_size)

	i, j := 0, 0
	for i < a.GetSize() && j < b.GetSize() {
		value_a, _ := a.GetArr(i)
		value_b, _ := b.GetArr(j)
		if value_a < value_b {
			new_sorted.Append(value_a)
			i++
		} else if value_b < value_a {
			new_sorted.Append(value_b)
			j++
		} else {
			new_sorted.Append(value_a)
			new_sorted.Append(value_b)
			i++
			j++
		}
	}

	if i < a.GetSize() {
		for index := i; index < a.GetSize(); index++ {
			value, _ := a.GetArr(i)
			new_sorted.Append(value)
		}
	} else if j < b.GetSize() {
		for index := j; index < b.GetSize(); index++ {
			value, _ := b.GetArr(j)
			new_sorted.Append(value)
		}
	}

	return new_sorted
}


func main() {

	arr1 := array.NewArr(2)

	arr1.Append(123)
	arr1.Append(12)
	arr1.Append(13)
	arr1.Append(1)
	arr1.Append(3)

	arr1.SetArr(10, 5)

	arr1.Print()

	sorted := array.NewSortedArr(20)

	sorted.Append(10)
	sorted.Append(1)
	sorted.Append(19)
	sorted.Append(5)

	sorted.Print()


	sorted1 := array.NewSortedArr(20)

	sorted1.Append(4)
	sorted1.Append(1)
	sorted1.Append(75)
	//sorted1.Append(15)

	sorted1.Print()

	new_sorted := merge(sorted, sorted1)
	new_sorted.Print()

}
