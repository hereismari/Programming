from os import system

name = 'abcdefghijkl'

for e in name:

    input_name = 'io/%s.in' % e
    output_name = 'io/%s.out' % e

    print 'Generating output for %s' % input_name
    system("python sol.py < %s > %s" % (input_name, output_name))
