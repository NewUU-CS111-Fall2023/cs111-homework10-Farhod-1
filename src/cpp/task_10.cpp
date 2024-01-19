/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

string create3SATFormula(int variableCount, int clauseCount) {
    string satFormula;

    srand(static_cast<unsigned int>(time(0)));

    for (int clauseIndex = 0; clauseIndex < clauseCount; ++clauseIndex) {
        string currentClause;

        for (int variableIndex = 0; variableIndex < 3; ++variableIndex) {
            char variableLetter = 'A' + rand() % variableCount;
            bool isNegated = rand() % 2 == 0;

            if (isNegated) {
                currentClause += "~";
            }

            currentClause += variableLetter;

            if (variableIndex < 2) {
                currentClause += " | ";
            }
        }

        satFormula += "(" + currentClause + ")";

        if (clauseIndex < clauseCount - 1) {
            satFormula += " & ";
        }
    }

    return satFormula;
}

int main() {
    int variableCount = 3;
    int clauseCount = 2;

    string satFormula = create3SATFormula(variableCount, clauseCount);

    cout << "Generated 3-SAT formula: " << satFormula << endl;

    return 0;
}