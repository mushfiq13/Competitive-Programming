#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6 + 10;

char mark[MAX];
ll phi[MAX];

void euler_phi () {
    for (int i=2; i<MAX; ++i)
        phi[i] = i;
    for (int i=2; i<MAX; ++i) {
        if (mark[i]) continue;
        for (int j=i; j<MAX; j+=i) {
            mark[j] = 1;
            phi[j] -= phi[j]/i;
        }
    }
}

int main() {
    euler_phi();
    ll n, t;

    cin >> t;
    while (t--) {
        cin >> n;
        cout << (n * (n+1) / 2) - n - (n * phi[n] / 2)  << endl;
    }

    return 0;
}
