num = 10
max = 100
min = 0

a = [56, 25, 67, 88, 100, 61, 55, 67, 76, 56]
rank = [0 for _ in range(max+2)]
count = 0

for i in range(num):  # 각 점수를 index로 하는 배열 요소 + 1
    count += 1
    rank[a[i]] += 1

rank[max + 1] = 1
for i in range(max, 0, -1):
    count += 1
    rank[i] = rank[i]+rank[i+1]

print("점수 순위 " + str(count))
for i in range(num):
    print(a[i], rank[a[i]+1])
