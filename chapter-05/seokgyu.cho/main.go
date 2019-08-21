package main

import (
	"errors"
	"fmt"
)

func main() {
	queue := New(10)
	add := queue.Push(10)
	i, e := queue.Pop()
	fmt.Println(e)
	fmt.Println(i)
	fmt.Println(add)
}

type Stack struct {
	array []int
	Size  int
	index int
}

func New(size int) *Stack {
	return &Stack{
		array: make([]int, size),
		Size:  size,
		index: -1,
	}
}

func (q *Stack) Push(v int) error {
	if q.index > q.Size {
		return errors.New("empty queue")
	}
	q.index++
	q.array[q.index] = v
	return nil
}

func (q *Stack) Pop() (int, error) {
	if q.index < 0 {
		return -1, errors.New("empty queue")
	}
	v := q.array[q.index]
	q.index--
	return v, nil
}
