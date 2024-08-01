#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int numberOfTestCases;
    cin >> numberOfTestCases;

    while (numberOfTestCases-- > 0) {
        int inputNumber;
        cin >> inputNumber;

        int originalNumber = inputNumber;
        int binaryDigitCount = 0;
        int tempNumber = inputNumber;

        while (tempNumber > 0) {
            tempNumber /= 2;
            binaryDigitCount++;
        }

        cout << binaryDigitCount << endl;

        int sequenceStart = 2;
        int appendCount = 1;

        for (int i = 1; i <= originalNumber; i++) {
            if (i == sequenceStart) {
                sequenceStart *= 2;
                appendCount++;
            }

            cout << appendCount << " ";
        }

        cout << endl;
    }

    return 0;
}