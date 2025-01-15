def move_tower(h, st, en):
    if h == 1:
        print(st, en)
        return
    
    temp = 6 - st - en
    move_tower(h-1, st, temp)
    move_tower(1, st, en)
    move_tower(h-1, temp, en)
    
n = int(input())
print(2 ** n - 1)

if n <= 20:
    move_tower(n, 1, 3)