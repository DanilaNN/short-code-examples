/********************************************************
*       Merge N sorted lists
*       input format:
*           first string - number of input lists
*           next n strings - the next list (first number in string - length of list)
*			maximum value in list should be 100
*       output format:
*           string with merged lists
*********************************************************/

#include "stdafx.h"
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::getline;
using std::cout;
using std::min_element;
using std::to_string;

int main() {

    string lengthS;
    getline(cin, lengthS);
    int length = stoi(lengthS);
    if (length == 0)
        return 0;
    int count = 0;
    string inputStr;
    string digit;
    vector<vector<short int>> InputLists;
    vector<vector<short int>::iterator> InputListsIt;
    int totalLen = 0;
    bool getFirstDig = true;
    while (count < length) {
        InputLists.push_back({});
        getline(cin, inputStr);

        digit = "";
        getFirstDig = true;
        for (int i = 0; i < inputStr.length(); i++) {
            if (inputStr[i] == ' ') {
                InputLists[count].push_back(stoi(digit));
                if (getFirstDig) {
                    totalLen += stoi(digit);
                    getFirstDig = false;
                }
                digit = "";
            }
            digit += inputStr[i];
        }
        InputLists[count].push_back(stoi(digit)); // push last digit
        InputListsIt.push_back(InputLists[count].begin() + 1);

        count++;
    }

    string result = "";
    vector<int> compare;
    vector<int>::iterator minCompare;
    bool flag = true;
    int min = 101; // maximal possible value 100
    int idx;
    int len = 0;

    while (len != totalLen) {
        for (int i = 0; i < InputLists.size(); i++) {
            if (InputListsIt[i] != InputLists[i].end())
                compare.push_back(*InputListsIt[i]);
            else
                compare.push_back(min);
        }

        minCompare = min_element(begin(compare), end(compare));
        auto it = begin(compare);
        while ((it = find(it, end(compare), *minCompare)) != end(compare)) {
            idx = distance(begin(compare), it++);
            if (InputListsIt[idx] != InputLists[idx].end()) {
                InputListsIt[idx] += 1;
                result += to_string(*minCompare) + ' ';
                len++;
            }
        }
        compare.clear();
    }

    cout << result << std::endl;
    return 0;
}