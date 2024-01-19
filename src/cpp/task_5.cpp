/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkZeroSumTriplet(const vector<int>& inputNumbers) {
    int arraySize = inputNumbers.size();

    sort(inputNumbers.begin(), inputNumbers.end());

    for (int index = 0; index < arraySize - 2; ++index) {
        // Skip duplicates
        if (index > 0 && inputNumbers[index] == inputNumbers[index - 1]) {
            continue;
        }

        int leftIndex = index + 1;
        int rightIndex = arraySize - 1;
        int targetSum = -inputNumbers[index];

        while (leftIndex < rightIndex) {
            int currentSum = inputNumbers[leftIndex] + inputNumbers[rightIndex];

            if (currentSum == targetSum) {
                return true;
            } else if (currentSum < targetSum) {
                ++leftIndex;
            } else {
                --rightIndex;
            }
        }
    }

    return false;
}

int main() {
    vector<int> inputNumbers = {-5, -17, 7, -4, 3, -2, 4};

    bool isZeroSumTripletPresent = checkZeroSumTriplet(inputNumbers);

    cout << (isZeroSumTripletPresent ? "True" : "False") << endl;

    return 0;
}