/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

bool evaluateBooleanExpression(const string& booleanExpression, const unordered_map<char, bool>& variableAssignments) {
    stack<bool> evaluationStack;

    for (char character : booleanExpression) {
        if (isalpha(character)) {
            evaluationStack.push(variableAssignments.at(character));
        } else if (character == '~') {
            bool topElement = evaluationStack.top();
            evaluationStack.pop();
            evaluationStack.push(!topElement);
        } else if (character == '|') {
            bool secondOperand = evaluationStack.top();
            evaluationStack.pop();
            bool firstOperand = evaluationStack.top();
            evaluationStack.pop();
            evaluationStack.push(firstOperand || secondOperand);
        } else if (character == '&') {
            bool secondOperand = evaluationStack.top();
            evaluationStack.pop();
            bool firstOperand = evaluationStack.top();
            evaluationStack.pop();
            evaluationStack.push(firstOperand && secondOperand);
        }
    }

    return evaluationStack.top();
}

int main() {
    string booleanExpression = "(A | ~B) & (~A | B | C)";