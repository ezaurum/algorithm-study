package main

import "fmt"

func main() {
	// n < 5 인 경우 조합
	for n := 0; n < 6; n++ {
		for r := 0; r <= n; r++ {
			fmt.Printf("%dC%d = %d ", n, r, combination(n, r))
		}
		fmt.Println("")
	}

	for n := 0; n < 6; n++ {
		for r := 0; r <= n; r++ {
			fmt.Printf("%dC%d = %d ", n, r, recursive(n, r))
		}
		fmt.Println("")
	}
}

// 그냥 베껴적은 공식
func combination(n int, r int) int {
	p := 1
	for i := 1; i <= r; i++ {
		p = p * (n - i + 1) / i
	}
	return p
}

//nCr = nCr-1 * (n-r+1) / r
// 재귀로 정리
func recursive(n int, r int) int {
	if n == r {
		return 1
	}
	if n == 1 {
		return 1
	}
	if r == 1 {
		return n
	}
	return recursive(n, r-1) * (n - r + 1) / r
}
