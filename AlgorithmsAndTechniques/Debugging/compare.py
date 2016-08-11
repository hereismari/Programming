from os import system
import sys

# Arquivo que deve ser comparado: cpp (C++), java (Java), python (Python)

# Nome do arquivo:
# Python ---> main.py
# Java   ---> Main.java (Classe Main)
# C++    ---> main (arquivo compilado)

s = sys.argv[1]

def getLines(f): return [e for e in f]

def compare(s, input_name):

    if s == 'cpp':
        system("./main < %s > auxiliar.txt" % (input_name))
    elif s == 'java':
        system("java -cp . Main < %s > auxiliar.txt" % (input_name))
    elif s == 'python':
        system("python main.py < %s > auxiliar.txt" % (input_name))

accepteds = 0
name = 'abcdefghijkl'
number_of_tests = len(name)
for e in name:

    input_name = 'io/%s.in' % e
    output_name = 'io/%s.out' % e

    compare(s, input_name)

    expected = open(output_name, 'r')
    result = open('auxiliar.txt', 'r')

    expected = getLines(expected)
    result = getLines(result)

    flag = True
    print len(result), len(expected)
    if len(result) != len(expected):
        flag = False
        print 'WRONG ANSWER'
    else:
        for i in xrange(len(result)):
            if result[i] != expected[i]:
                flag = False
                print 'WRONG ANSWER case %s' % input_name
            else:
                print 'Ok!'

    if flag: accepteds += 1
print 'accepteds:', accepteds / (number_of_tests * 1.0) * 100, '%'
