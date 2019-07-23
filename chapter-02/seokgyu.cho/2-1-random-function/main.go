package main

import (
	"fmt"
	"math"
)

func main() {
	// 균등 분포 난수
	// xn = (Axn-1 + C) % M

	result := make([]int, m)

	for i := 0; i < math.MaxInt16; i++ {
		i2 := next()
		result[i2]++
	}

	// 검증
	// 기대값
	f := float64(m) / math.MaxInt16

	e:=0.0
	for i :=0; i< len(result); i++ {
		e += math.Pow(float64(result[i]) - f, 2.0)  / f
	}

	// 기대값
	fmt.Println(f)
	// 실제값
	fmt.Println(e)

}

const (
	a  = 109
	c  = 1021
	m  = 32768
	x0 = 13
)

var currentRand = x0

func next() int {
	currentRand = a * (currentRand + c) % m
	return currentRand
}
