package main 

import (
	"fmt"
	//"os/signal"
	//"os"
	//"syscall"
	"demo/linkedlist"
)




func main() {

	test := link.LinkedList{}

	if test.Head == nil {
		fmt.Println("nil")
	}

	// done := make(chan os.Signal)
	// signal.Notify(done, syscall.SIGINT)
	// <-done
	fmt.Println("\nBye!")
}