package main

import "fmt"

var maze = [][]int{
	{2, 2, 2, 2, 2, 2, 2},
	{2, 0, 0, 0, 0, 0, 2},
	{2, 0, 2, 0, 2, 0, 2},
	{2, 0, 0, 2, 0, 2, 2},
	{2, 2, 0, 0, 0, 2, 2},
	{2, 0, 0, 0, 0, 0, 2},
	{2, 2, 2, 2, 2, 2, 2},
}

var exit = []int{5, 5,}

func main() {
	fmt.Println(visit(1,1))
	fmt.Println(maze)
}

func visit(i, j int) bool {
	// 지나간 곳
	maze[i][j] = 1

	fmt.Println(i, j)

	if i == exit[0] && j== exit[1] {
		return true
	}

	switch  {
	case maze[i+1][j] == 0:
		return visit(i+1, j)
	case maze[i][j+1] == 0:
		return visit(i, j+1)
	case maze[i-1][j] == 0:
		return visit(i-1, j)
	case maze[i][j-1] == 0:
		return visit(i, j-1)
	}

	return false
}
