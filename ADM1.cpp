#include <iostream>
#include <vector>
using namespace std;

vector<int> ADM(vector<int>& dt, int initial, int factor) {
    vector<int> modulated;
    int pre = 0;
    int st = initial;

    for (int i = 0; i < dt.size(); i++) {
        if (dt[i] > pre) {
            modulated.push_back(1);pre += st;
            st += factor;
        } else {
            modulated.push_back(0);
            pre -= st;
            st += factor;
        }
        if (i > 0 && modulated[i] != modulated[i-1]) {
            st = max(initial, st - factor);
        }
    }

    return modulated;
}

int main() {
    vector<int> dt = {1,2,3,4,-10,-20,-30,-50,10};
    int initial = 1;
    int factor = 1;
    vector<int> dm = ADM(dt, initial, factor);
    cout << "Adaptive Modulated dt: ";
    for (int i = 0; i < dm.size(); i++) {
        cout << dm[i] << " ";
    }
    cout << endl;

    return 0;
}
