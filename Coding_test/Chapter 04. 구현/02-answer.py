start = input()

row = int(start[1])
col = int(ord(start[0])) - int(ord('a')) + 1

steps = [(-2, -1), (-2, 1), (-1, -2), (-1, 2), (1, -2), (1, 2), (2, -1), (2, 1)]

count = 0

for step in steps:
    next_row = row + step[0]
    next_col = col + step[1]

    if 1<=next_row<=8 and 1<=next_col<=8:
        count += 1

print(count)



