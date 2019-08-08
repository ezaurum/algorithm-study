n = 6
a = [80, 41, 35, 90, 40, 20]
count = 0;

for i in range(n - 1):
    for j in range(n - 1, 0, -1):
        count += 1
        if a[j] < a[j - 1]:
            t = a[j]
            a[j] = a[j - 1]
            a[j] = t

for i in a:
    print(i, end=' ')

print()
print("count:", str(count))
