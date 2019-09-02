def intersect(a, b):
    if a[0] <= b[1] or a[1] <= b[0]:
        return True, [min(a[0], b[0]), max(a[1], b[1])]
    return False, a


def merge_intersection(intervals):
    output = []
    for val in intervals:
        n = 0
        intersected = False
        for val2 in output:
            is_intersect, interval_val = intersect(val, val2)
            if is_intersect:
                output[n] = interval_val
                intersected = True
                break
            n += 1
        if not intersected:
            output.append(val)
    return output


def main():
    print(merge_intersection([[2, 4], [1, 5], [7, 9]]), [[1, 5], [7, 9]])
    print(merge_intersection([[3, 6], [1, 3], [2, 4]]), [[1, 6]])


if __name__ == "__main__":
    main()