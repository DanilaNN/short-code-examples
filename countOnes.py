##-----------------------------------------------------------##
##       Count the longest subsequence of once in input numerical array
##       input format:
##           first string - length of input array
##           next n strings - the next elements of input array
##       output format:
##           length of maximal subsequence of once
##-----------------------------------------------------------##
import sys

InputLength = int(sys.stdin.readline().strip())

if (InputLength == 0):
	print(0)
else:
	i = 0
	arr = []
	while i < int(InputLength):
		arr.append(int(sys.stdin.readline().strip()))
		i += 1

	max = 0
	count = 1
	flag = 0
	for i in range(len(arr) - 1):
		if not(flag):
			if arr[i]==1:
				flag = 1
				max = 1
		if flag:
			if arr[i]==arr[i+1] and arr[i]==1:
				count += 1
			else:
				max = count if count > max else max
				count = 1
	if (arr[-1]):
		max = count if count > max else max
		
	print(max)