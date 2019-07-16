num =10

a = [56, 25, 67,88,100,61,55,67,76,56]
rank = [0 for _ in range(10)]

for i in range(num): 
  rank[i]=1;
  
  for j in range(num):
    if a[j]>a[i]:
      rank[i]+=1 #파이썬은 후위 연산자가 뿔뿔이 안되네

print("점수 순위\n")
for i in range(num):
  print(a[i],rank[i])

print("파이썬은 들여쓰기가 참 중요합니다.")