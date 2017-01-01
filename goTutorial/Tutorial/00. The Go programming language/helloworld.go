// Hello world in Go

// The main package, defines an executable program that does not depend on other ones for compilation

package main // One or more files that are designed to accomplish some task

// One can run this file by runnnig the command go run helloworld.go
// One can also compile the program by typing go build helloworld.go && ./helloworld

import "fmt" // fmt, stands for format

func main() {
	fmt.Println("Hello, gopher!") // Gopher is the Go puppet
	fmt.Println("Hello, world; or καλημερα");
}