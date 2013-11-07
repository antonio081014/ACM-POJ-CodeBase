#!/usr/bin/env python

import sys, os

if os.path.exists('output.txt'):
		os.remove('output.txt')
top = './'

fd = open('output.txt', 'w+')

for root, dirs, files in os.walk(top, topdown=False):
	for name in dirs:
			if name[:-4] == 'Volumn':
				fd.write(name + ' has : ')
				count = 0
				for root, dirs, files in os.walk(name):
						for f in files:
								count = count + 1
				fd.write(str(count) + '\n')
fd.close()
