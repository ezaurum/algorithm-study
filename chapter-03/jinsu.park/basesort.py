n = 6

a = [80, 41, 35, 90, 40, 20]
count = 0

for i in range(n - 1):
    min = a[i]
    s = i
    for j in range(1, n):
        count += 1
        if (a[j] < min):
            min = a[j]
            s = j

    t = a[i]
    a[i] = a[s]
    a[s] = t

for i in range(0, n):
    print(a[i], end=' ')

print("count : " + str(count))
