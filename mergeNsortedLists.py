##-----------------------------------------------------------##
##       Merge N sorted lists
##       input format:
##           first string - number of input lists
##           next n strings - the next list (first number in string - length of list)
##			maximum value in list should be 100
##       output format:
##           string with merged lists
##-----------------------------------------------------------##
import sys

length = int(sys.stdin.readline().strip())
inputLists = []
MAXIMAL_VALUE = 101
i = 0
if length == 0:
    pass
else:
	while i < length:
		inputLists.append(list(map(lambda x: int(x), sys.stdin.readline().strip().split(' '))))
		i += 1

ans = ''

def findMinK(findMinArr):
    min = MAXIMAL_VALUE
    idx = 0
    idxMin = []
    for v in findMinArr:
        if (v == min):
            idxMin.append(idx)
        if v < min:
            idxMin = []
            min = v
            idxMin.append(idx)
        idx += 1

    return [idxMin, min]


idxs = []
lens = []
totalLen = 0
for i in range(length):
    lens.append(inputLists[i][0])
    totalLen += inputLists[i][0]
    idxs.append(1) if inputLists[i][0] != 0 else idxs.append(-1)

lenAns = 0
while lenAns < totalLen:
    findMinArr = []
    cnt_idx = 0
    for idx in idxs:
        if idx != -1:
            findMinArr.append(inputLists[cnt_idx][idx])
        else:
            findMinArr.append(MAXIMAL_VALUE)
        cnt_idx += 1

    [idxMins, min] = findMinK(findMinArr)

    for idxMin in idxMins:
        ans += str(min) + ' '
        lenAns += 1

        flag = 1
        while flag:
            if idxs[idxMin] != lens[idxMin]:
                if inputLists[idxMin][idxs[idxMin] + 1] == min:
                    ans += str(inputLists[idxMin][idxs[idxMin] + 1]) + ' '
                    lenAns += 1
                    idxs[idxMin] += 1
                else:
                    flag = 0
            else:
                idxs[idxMin] = -1
                flag = 0

        if idxs[idxMin] != -1:
            idxs[idxMin] += 1
        if idxs[idxMin] == lens[idxMin] + 1:
            idxs[idxMin] = -1

print(ans)