def rotate_by_90_degrees(key):
    n = len(key)
    for i in range(n):
        for j in range(n):
            key[j][n-i-1] = key[i][j]
    return key

def check(new_lock,m):
    for i in range(m,2*m):
        for j in range(m,2*m):
            if new_lock[i][j] != 1:
                return False
    return True

def solution(key, lock):
    n = len(key)
    m = len(lock)

    # initialize
    new_lock = [[0]*3*m for _ in range(3*m)]
    for i in range(m):
        for j in range(m):
            new_lock[i+m][j+m] = lock[i][j]
    
    for _ in range(4):
        key = rotate_by_90_degrees(key)
        
        for i in range(m):
            for j in range(m):
                for x in range(n):
                    for y in range(n):
                        new_lock[i+x][j+y] += key[x][y]
                if check(new_lock,m):
                    return True
                for x in range(n):
                    for y in range(n):
                        new_lock[i+x][j+y] -= key[x][y]
    
    return False