# 하노이의 탑
def hanoi(n, fromStick, toStick, centerStick):
    if n == 1:
        print(fromStick, "->", toStick)
        return

    hanoi(n-1, fromStick, centerStick, toStick)
    print(fromStick, "->", toStick)
    hanoi(n-1, centerStick, toStick, fromStick)

print("원반의 개수는?") # 10 이상의 수 금지! 콘솔 터짐-_-
param = int(input())
hanoi(param, 1, 3, 2)