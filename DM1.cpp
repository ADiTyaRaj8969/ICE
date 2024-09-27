#include <iostream>
#include <vector>
using namespace std;

vector<int> dm(vector<int>& modulatedSignal, int st) {
    vector<int> demodulated;
    int pre = 0; 

    for (int i = 0; i < modulatedSignal.size(); i++) {
        if (modulatedSignal[i] == 1) {
            pre += st;  
        } else {
            pre -= st;  
        }
        demodulated.push_back(pre);
    }

    return demodulated;
}

int main() {
    vector<int> modulatedSignal = {0, 1, 1, 0, 0, 1, 1, 1, 0};  
    int st = 1;  

    
    vector<int> demodusignal = dm(modulatedSignal, st);

    
    cout << "Demodulated signal: ";
    for (int i = 0; i < demodusignal.size(); i++) {
        cout << demodusignal[i] << " ";
    }
    cout << endl;

    return 0;
}
