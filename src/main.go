package main

import (
	"fmt"
	"os"
	"time"
)

func greet() {
	fmt.Printf("Hello World! %v\n", time.Now())
	b, _ := os.ReadFile("../test-data/simple.gsql")

	fmt.Printf("b: %v\n", string(b))
}

func main() {
	greet()
}
