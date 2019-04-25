n, m = map(int, raw_input().split())

row_s, col_s = map(int, raw_input().split())
row_e, col_e = map(int, raw_input().split())

v, res = 0, 0

matrix = [[0 for _ in xrange(m+1)] for _ in xrange(n+1)]
for i in range(2, n+1, 2):
    for j in range(2, m+1, 2):
        matrix[i][j] = 1


def valid(r, c):
    return r >= 1 and c >= 1 and r <= n and c <= m and matrix[r][c] == 0

def dfs(r, c):
    global res, v
    matrix[r][c] = 1
    v += 1
    if r == row_e and c == col_e and v > res:
        res = v
    else:
        for inc_row, inc_col in [(0, 2), (0, -2), (2, 0), (-2, 0)]:
            new_row, new_col = r + inc_row, c + inc_col
            if valid(new_row, new_col):
                v += 1
                dfs(new_row, new_col)
                v -= 1
    v -= 1
    matrix[r][c] = 0
    
dfs(row_s, col_s)

print(res)
