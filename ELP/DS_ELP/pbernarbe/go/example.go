package main

import (
	"fmt"
	"time"
)

// fonction qui affiche la séquence de nombres naturels
// à un interval de 500 milliseconds chaque nombre.

func main() {
	numberTick := time.Tick(500 * time.Millisecond)
	for i := 0; ; i++ {
		fmt.Printf("%d ", i)
		<-numberTick
	}
}
