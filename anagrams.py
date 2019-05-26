##--------------------------------------------------------
##		Check if input strings are anagrams
##		input:
##			two strings consists of small latin letters
##		output:
##			0 - if strings are anagrams
##			1 - otherwize
##--------------------------------------------------------

import sys
 
str1 = sys.stdin.readline().strip()
str2 = sys.stdin.readline().strip()

d1 = {}
d2 = {}
abc = 'abcdefghijklmnopqrstuvwxyz'
for l in abc:
	d1[l] = 0
	d2[l] = 0

for s1 in str1:
	d1[s1] += 1
	
for s2 in str2:
	d2[s2] += 1
	
print(int(d1 == d2))