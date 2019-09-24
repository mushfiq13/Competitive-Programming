#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;

int a[MAX];

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    sort(a, a+n);
    int col = 0;
    for (int i=0; i<n; ++i) {
        if (a[i] > -1) {
            for (int j=i+1; j<n; ++j) {
                if (a[j] > -1 && a[j] % a[i] == 0)
                    a[j] = -1;
            }
            ++col;
        }
    }

    cout << col << endl;
    return 0;
}
