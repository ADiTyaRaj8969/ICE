#include <iostream>
#include <vector>
using namespace std;

vector<int> ADM(vector<int>& ms, int initial, int factor) {
    vector<int> demodulated;
    int pre = 0;
    int st = initial;

    for (int i = 0; i < ms.size(); i++) {
        if (ms[i] == 1) {
            pre += st;
        } else {
            pre -= st;
        }
        demodulated.push_back(pre);
        st += factor;


        if (i > 0 && ms[i] != ms[i-1]) {
            st = max(initial, st - factor);
        }
    }

    return demodulated;
}
int main() {
    vector<int> ms = {0, 1, 1, 0, 0, 1, 1, 1, 0};
    int initial = 1;
    int factor = 1;
    vector<int> dems = ADM(ms, initial, factor);
    cout << "Adaptive Demodulated signal: ";
    for (int i = 0; i < dems.size(); i++) {
        cout << dems[i] << " ";
    }
    cout << endl;

    return 0;
}
