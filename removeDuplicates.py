##--------------------------------------------------------
##		Remove duplicates from sorted array
##		input:
##			first string - length of input array
##			next n strings - the next elements of input array
##		output:
##			array without duplicates
##--------------------------------------------------------
import sys

SIZE_2_GET_FROM_INPUT = 100
totalLen = 0
arr = []
arrN = []
length = int(sys.stdin.readline().strip())

if (length == 0):
	pass
else:
	while totalLen < length:
		i = 0
		lastSymb = arr[-1] if arr != [] else ''
		arr = []
		while i < SIZE_2_GET_FROM_INPUT and totalLen < length:
			arr.append(int(sys.stdin.readline().strip()))
			i += 1
			totalLen += 1
		if (lastSymb == ''):
			arrN.append(arr[0])
		if (lastSymb != arr[0]) and (lastSymb != ''):
			arrN.append(arr[0])
		for i in range(len(arr) - 1):
			if arr[i] == arr[i+1]:
				pass
			else:
				if arr[i+1] != lastSymb:
					arrN.append(arr[i+1])
	
	print('\n')
	for i in arrN:
		print(i)