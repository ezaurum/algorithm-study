package main

import "fmt"

func main() {

	fmt.Println(fac(10))

}

func fac(n int) int {
	if n == 0 {
		return 1
	}
	return n * fac(n-1)
}
