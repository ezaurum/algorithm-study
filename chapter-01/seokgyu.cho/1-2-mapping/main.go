package main

import (
	"fmt"
	"math/rand"
)

func main() {
	var randomScore []int

	for i := 0; i < 1000; i++ {
		randomScore = append(randomScore, rand.Int()%100)
	}

	scoreStore := make([]int, 10)

	for _, v := range randomScore {
		i := v / 10
		scoreStore[i] = scoreStore[i] + 1
	}

	for _, v := range scoreStore {
		fmt.Printf("%v ", v)
	}

}
