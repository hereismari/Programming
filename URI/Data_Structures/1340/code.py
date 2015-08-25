import Queue

while True:
    stack = True
    queue = True
    prio_queue = True

    try:
        n = int(raw_input())
    except:
        break

    s = Queue.LifoQueue()
    q = Queue.Queue()
    p = Queue.PriorityQueue()

    for i in xrange(n):
        operacao, saida = map(int,raw_input().split())
        if operacao == 1:
            s.put(saida)
            p.put(-saida)
            q.put(saida)
        else:
            if(s.empty() or s.get() != saida): stack = False
            if(q.empty() or q.get() != saida): queue = False
            if(p.empty() or p.get() != -saida): prio_queue = False

#    print prio_queue,queue,stack
    if (prio_queue and queue) or (prio_queue and stack):
        print "not sure"
    elif not prio_queue and not queue and not stack:
        print "impossible"
    elif prio_queue:
        print "priority queue"
    elif queue:
        print "queue"
    else:
        print "stack"
