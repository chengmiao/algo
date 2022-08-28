package main

import (
	"demo/mystack"
	"fmt"
)

func main() {

	test := mystack.NewMyStack(10)
	test.Push(1)
	test.Push(2)
	test.Push(3)
	test.Pop()
	test.Pop()

	test.Print()

	test.Push(4)
	test.Push(5)

	test.Print()

	fmt.Println("Test MyStackGolang!")


	test1 := mystack.NewLinkedStack()
    test1.Push(1)
    test1.Push(2)
    test1.Push(3)
    test1.Pop()

    test1.Print()
}
