#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

int a[MAX];

int main() {
    int n, x, y;

    cin >> n >> x >> y;
    for (int i=1; i<=n; ++i)
        cin >> a[i];

    for (int i=1; i<=n; ++i) {
        bool flag = true;
        for (int j = max(i-x,1); j < i && flag; ++j)
            if (a[i] > a[j])
                flag = false;
        for (int j = min(i+y,n); j > i && flag; --j)
            if (a[i] > a[j])
                flag = false;
        if (flag) {
            cout << i << endl;
            return 0;
        }
    }
}
