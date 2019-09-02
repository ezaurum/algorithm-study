def heap_add(array, n):
    array.append(n)

    n = len(array) - 1
    while n > 0:
        if array[n] >= array[n // 2]:
            break
        array[n], array[n // 2] = array[n // 2], array[n]
        n = n // 2


def heap_shift_down(array, j):
    length = len(array)
    n = j
    while n < length // 2:
        n2 = 1 if n == 0 else n * 2
        if n2 + 1 < length and array[n2] > array[n2 + 1]:
            n2 += 1
        if array[n] <= array[n2]:
            break
        array[n], array[n2] = array[n2], array[n]
        n = n2


def find_second_largest_element(numbers):
    heap = []
    for num in numbers:
        # heap에 2개까지 넣어두고.
        if len(heap) < 2:
            heap_add(heap, num)
            continue

        # heap top 값보다 num이 크다면,
        # 0번째 값을 업데이트하고, heap 재구성하기.
        if num > heap[0] and len(heap) == 2:
            heap[0] = num
            heap_shift_down(heap, 0)

    #
    print(heap)
    if len(heap) == 2:
        return heap[0]
    return None


# min heap을 구성하기.

def main():
    print(find_second_largest_element([10, 5, 4, 3, -1]), 5)
    print(find_second_largest_element([1, 2, 3, 4, 5]), 4)
    print(find_second_largest_element([3, 3, 3]), None)


if __name__ == "__main__":
    main()
