package main 

import (
	"fmt"
	"os/signal"
	"os"
	"syscall"
)


type Connect struct {
	writeC chan []string
}


func (c *Connect) SendPackets(data []string) error {
	c.writeC <- data
	return nil
}

func (c *Connect) printpackets() {
	fmt.Println(<-c.writeC)
}

func NewConnect() *Connect {
	return &Connect{writeC: make(chan []string, 10)}
}


func main() {

	c := NewConnect()
	go func() {
		for {
			data1 := []string{"1"}
			data2 := []string{"2"}
			data3 := []string{"3"}
			data4 := []string{"4"}
			data5 := []string{"5"}

			go c.SendPackets(data1)
			go c.SendPackets(data2)
			go c.SendPackets(data3)
			go c.SendPackets(data4)
			go c.SendPackets(data5)
		}
	}()

	go func() {
		for {
			c.printpackets()
		}
	}()

	done := make(chan os.Signal)
	signal.Notify(done, syscall.SIGINT)
	<-done
	fmt.Println("\nBye!")
}