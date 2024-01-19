/*
 * Author:
 * Date:
 * Name:
 */

class PartitionProblem {
public:
    bool partitionCheckBottomUp(int targetSum, vector<int>& inputNumbers){
        vector<vector<int>> dpTable(inputNumbers.size()+1, vector<int>(targetSum+1, 0));
        for(int i=0; i<inputNumbers.size(); i++)
            dpTable[i][0] = 1;

        for(int currentIndex = inputNumbers.size()-1; currentIndex >= 0; currentIndex--){
            for(int currentSum = 1; currentSum <= targetSum; currentSum++){
                bool includeCurrentNumber = 0;
                if(currentSum - inputNumbers[currentIndex] >= 0)
                    includeCurrentNumber = dpTable[currentIndex+1][currentSum - inputNumbers[currentIndex]];
                bool excludeCurrentNumber = dpTable[currentIndex+1][currentSum];
                dpTable[currentIndex][currentSum] = (includeCurrentNumber || excludeCurrentNumber);
            }
        }
        return dpTable[0][targetSum];
    }
    bool canPartition(vector<int>& inputNumbers) {
        int totalSum = 0;
        for(int i=0; i<inputNumbers.size(); i++){
            totalSum += inputNumbers[i];
        }
        if(totalSum & 1)
            return false;
        int targetSum = totalSum / 2;
        return partitionCheckBottomUp(targetSum, inputNumbers);
    }
};