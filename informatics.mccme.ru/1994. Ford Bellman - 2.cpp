#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cin >> n;

    vector<int> d (n+1, INT_MAX);
    d[1] = 0;
    for (int v = 1; v <= n; ++v) {
        for (int i=v+1; i<=n; ++i) {
            int cost = (179*v+719*i)%1000 - 500;
            if (d[i] > d[v] + cost)
                d[i] = d[v] + cost;
        }
    }

    cout << d[n] << endl;
    return 0;
}
