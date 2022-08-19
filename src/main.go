package main

import (
	"fmt"
	"time"
)

func greet() {
	fmt.Printf( "Hello World! %v\n", time.Now())
}

func main() {
	greet()
}