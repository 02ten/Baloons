#include <iostream>

using namespace std;

void F(bool select[], int n, int& c, int step = 0, int b = 0) {
    if (step < n) {
        for (int i = 0; i < n; i++) {
            bool flag = false;
            if (step == 0) {
                b = 0;
            }
            if (!select[i]) {
                if (step == i) {
                    b++;
                    flag = true;
                }
                select[i] = true;
                F(select, n, c, step + 1, b);
                select[i] = false;
                if (flag == true) {
                    b--;
                }
            }

        }
    }
    else {
        if (b > 0) {
            c++;
        }
    }
    return;
}

int main() {
    unsigned n;
    int z = 0;
    cin >> n;
    bool* select = new bool[n];
    for (unsigned i = 0; i < n; i++) {
        select[i] = false;
    }
    F(select, n, z);
    cout << z;
    return 0;
}