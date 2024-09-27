#include <iostream>
#include <vector>
using namespace std;

vector<int> deltaModulation(vector<int>& signal, int stepSize) {
    vector<int> modulated;
    int previousValue = 0;

    for (int i = 0; i < signal.size(); i++) {
        if (signal[i] > previousValue) {
            modulated.push_back(1);
            previousValue += stepSize;
        } else {
            modulated.push_back(0);
            previousValue -= stepSize;
        }
    }

    return modulated;
}

int main() {
    vector<int> signal = {1,2,3,4,-10,-20,-30,-50,10};
    int stepSize = 1;


    vector<int> modulatedSignal = deltaModulation(signal, stepSize);


    cout << "Modulated signal: ";
    for (int i = 0; i < modulatedSignal.size(); i++) {
        cout << modulatedSignal[i] << " ";
    }
    cout << endl;

    return 0;
}
