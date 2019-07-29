package main

import "fmt"

func main() {

	instance := GetInstance(1000)

	s := "test"
	key := instance.Key(s)
	fmt.Println(key)
	instance.Table[key] = s
	fmt.Println(instance.Get(key) )

}

type HashTable struct {
	TableSize int
	Table     []string
}

func GetInstance(size int) *HashTable {
	return &HashTable{
		TableSize: size,
		Table: make([]string, size),
	}
}

func (ht *HashTable) Set(text string )int {
	key := ht.Key(text)
	ht.Table[key] = text
	return key
}

func (ht *HashTable) Get(key int ) string {
	return ht.Table[key]
}

func (ht HashTable) Key(text string) int {
	runes := []rune(text)
	i := len(runes)
	if i > 0 {
		last := runes[i-1]
		first := runes[0]
		middle := runes[i/2]

		return int(last+first+middle) % ht.TableSize
	}
	return -1
}
