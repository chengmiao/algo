package main

import (
	"fmt"
	//"os/signal"
	//"os"
	//"syscall"
	"demo/linkedlist"
)

func main() {

	list := link.LinkedList{}

	list.Insert(2)
	list.Insert(51)
	list.Insert(223)
	list.Insert(98)
	list.Insert(13)

	list.Print()

	list.DeleteByValue(223)

	list.Print()

	p := list.FindByValue(98)
	p.SetData(100)

	list.Print()
	// done := make(chan os.Signal)
	// signal.Notify(done, syscall.SIGINT)
	// <-done
	fmt.Println("\nBye!")
}
