/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include <vector>

using namespace std;

bool solveSATProblem(const vector<vector<int>>& cnfClauses) {
    int variableCount = 0;

    for (const auto& clause : cnfClauses) {
        for (int literal : clause) {
            int variable = abs(literal);
            variableCount = max(variableCount, variable);
        }
    }

    for (int i = 0; i < (1 << variableCount); ++i) {
        vector<bool> variableAssignment(variableCount + 1, false);

        for (int j = 1; j <= variableCount; ++j) {
            variableAssignment[j] = (i & (1 << (j - 1))) != 0;
        }

        bool isFormulaSatisfied = true;

        for (const auto& clause : cnfClauses) {
            bool isClauseSatisfied = false;

            for (int literal : clause) {
                int variable = abs(literal);
                bool value = (literal > 0) ? variableAssignment[variable] : !variableAssignment[variable];

                isClauseSatisfied |= value;
            }

            isFormulaSatisfied &= isClauseSatisfied;
        }

        if (isFormulaSatisfied) {
            return true;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> cnfClauses1 = {{1, 2, -3}, {-1, -2, 3}, {2, -3}};
    vector<vector<int>> cnfClauses2 = {{1, 2}, {-1, 3}, {-2, -3}};
    vector<vector<int>> cnfClauses3 = {{1, 2, 3}, {-1, -2, 3}, {1, -3}};
    vector<vector<int>> cnfClauses4 = {{1, 2}, {-1, -2}, {1, -2}};

    cout << "SAT Formula 1: " << (solveSATProblem(cnfClauses1) ? "True" : "False") << endl;
    cout << "SAT Formula 2: " << (solveSATProblem(cnfClauses2) ? "True" : "False") << endl;
    cout << "SAT Formula 3: " << (solveSATProblem(cnfClauses3) ? "True" : "False") << endl;
    cout << "SAT Formula 4: " << (solveSATProblem(cnfClauses4) ? "True" : "False") << endl;

    return 0;
}