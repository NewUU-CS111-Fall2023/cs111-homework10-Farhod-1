/*
 * Author:
 * Date:
 * Name:
 */


#include <iostream>
#include <vector>

using namespace std;

enum TuringState {
    Start,
    ReadZero,
    ReadOneOrC,
    BackToStart,
    MoveToEnd,
    Stop
};

void compareUnaryNumbers(string& inputTape) {
    TuringState currentState = Start;
    int tapeHead = 0;

    while (currentState != Stop) {
        char currentSymbol = inputTape[tapeHead];

        switch (currentState) {
            case Start:
                if (currentSymbol == '0') {
                    tapeHead++;
                    currentState = ReadZero;
                } else {
                    currentState = Stop;
                }
                break;

            case ReadZero:
                if (currentSymbol == '1' || currentSymbol == 'c') {
                    tapeHead++;
                } else if (currentSymbol == ' ') {
                    tapeHead--;
                    currentState = BackToStart;
                }
                break;

            case ReadOneOrC:
                if (currentSymbol == '1' || currentSymbol == 'c') {
                    tapeHead++;
                } else if (currentSymbol == '0') {
                    tapeHead--;
                    currentState = BackToStart;
                }
                break;

            case BackToStart:
                if (currentSymbol == '1' || currentSymbol == '0' || currentSymbol == 'c') {
                    tapeHead--;
                } else if (currentSymbol == ' ') {
                    tapeHead++;
                    currentState = MoveToEnd;
                }
                break;

            case MoveToEnd:
                if (currentSymbol == '1') {
                    inputTape[tapeHead] = '1';
                    tapeHead++;
                } else if (currentSymbol == '0') {
                    inputTape[tapeHead] = '0';
                    tapeHead++;
                } else if (currentSymbol == 'c') {
                    tapeHead++;
                    currentState = ReadOneOrC;
                } else if (currentSymbol == ' ') {
                    tapeHead++;
                    currentState = Stop;
                }
                break;

            case Stop:
                // End of the tape
                break;
        }
    }
}

int main() {
    string inputTape = "0 1 1 1 c 1 1 1 1 0";

    compareUnaryNumbers(inputTape);

    cout << "Result: " << inputTape << endl;

    return 0;
}
