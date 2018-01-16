package main

import (
	"fmt"
	"time"
)

func nombresImpairs(c chan int) {
	// fonction à completer
	// le numero suivant de la suite
	// chaque 300 milliseconds
	numberTick := time.Tick(300 * time.Millisecond)
	for{
		<-numberTick
		if(c%2==1) {
			c <- c
		}
		// cette fonction doit renvoyer sur le canal c
		
	}
}
func main() {
	endSignal := time.After(10000 * time.Millisecond)
	n := make(chan int)
	go nombresImpairs(n)
	for {
		select {
		case numero := <-n:
			fmt.Print(numero)
		case <-endSignal:
			fmt.Println("BINGO!")
			return
		default:
			fmt.Print(".")
			time.Sleep(50 * time.Millisecond)
		}
	}
}
