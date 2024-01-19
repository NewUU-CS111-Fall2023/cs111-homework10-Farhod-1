/*
 * Author:
 * Date:
 * Name:
 */



#include <iostream>
#include <vector>

using namespace std;

enum MachineState {
    Initial,
    ReadOne,
    ReadZero,
    BackToStart,
    MoveToEnd,
    Final
};

void performUnaryAddition(string& inputTape) {
    MachineState currentState = Initial;
    int tapeHead = 0;

    while (currentState != Final) {
        char currentSymbol = inputTape[tapeHead];

        switch (currentState) {
            case Initial:
                if (currentSymbol == '1') {
                    currentState = ReadOne;
                } else {
                    currentState = Final;
                }
                break;

            case ReadOne:
                if (currentSymbol == '1') {
                    tapeHead++;
                } else if (currentSymbol == '0') {
                    inputTape[tapeHead] = 'X';
                    tapeHead--;
                    currentState = ReadZero;
                }
                break;

            case ReadZero:
                if (currentSymbol == '1') {
                    tapeHead--;
                } else if (currentSymbol == 'X') {
                    tapeHead++;
                    currentState = BackToStart;
                }
                break;

            case BackToStart:
                if (currentSymbol == '1' || currentSymbol == 'X') {
                    tapeHead++;
                } else if (currentSymbol == ' ') {
                    tapeHead--;
                    currentState = MoveToEnd;
                }
                break;

            case MoveToEnd:
                if (currentSymbol == 'X') {
                    tapeHead--;
                } else if (currentSymbol == ' ') {
                    tapeHead++;
                    currentState = Final;
                }
                break;

            case Final:
                break;
        }
    }
}

int main() {
    string unaryNumber1 = "1111";  // Representing 4 in unary
    string unaryNumber2 = "111";   // Representing 3 in unary

    string inputTape = unaryNumber1 + "0" + unaryNumber2 + " ";

    performUnaryAddition(inputTape);

    cout << "Result: " << inputTape << endl;

    return 0;
}