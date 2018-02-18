res = 0
vis = []

def get_vis(actual_table):
  v = []
  for i in xrange(len(actual_table)):
    v.append((actual_table[i][0], actual_table[i][-1]))
    # v.append((actual_table[i][-1], actual_table[i][0]))
  
    for j in xrange(1, len(actual_table[i])):
      v.append((actual_table[i][j], actual_table[i][j-1]))
      # v.append((actual_table[i][j-1], actual_table[i][j]))

  return v

def check_vis(actual_table):
  global vis
  
  v = get_vis(actual_table)
  for l in vis:
    flag = False
    for e in v:
      if e not in l:
        flag = True
    if flag == False:
      return False
  
  return True


def update_vis(actual_table):
  global vis
  vis.append(get_vis(actual_table))


def solve(index_pos, index_table, bt, n, actual_table):
  global res

  if index_table >= len(actual_table):
    if check_vis(actual_table): 
      res += 1
      update_vis(actual_table)
  else:
    
    for i in xrange(n):
      actual_table[index_table][index_pos] = i
      if not bt[i]: # and check_tables(actual_table, vis, i):
        bt[i] = True
        if index_pos == len(actual_table[index_table])-1:
          solve(0, index_table+1, bt, n, actual_table)
        else:
          solve(index_pos+1, index_table, bt, n, actual_table)
        bt[i] = False
      actual_table[index_table][index_pos] = -1
   

t = int(raw_input())

for i in xrange(t):

  global res
  global vis
  vis = []
  res = 0
  n, k = map(int, raw_input().split())
  
  tables = [n/k] * k
  s = n/k * k
  j = 0
  while s < n:
    s += 1
    tables[j] += 1
    j += 1
  
  bt = [False] * n
  actual_table = [[] for k in xrange(len(tables))]
  for k in xrange(len(tables)):
    actual_table[k] = [-1 for j in xrange(tables[k])] 
  
  solve(0, 0, bt, n, actual_table)
  # print vis
  print 'Case #%d: %d' % (i+1, res)
  
