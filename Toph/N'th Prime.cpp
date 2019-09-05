#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 10000000;
bool mark[MAX];

int sieve (int n) {
    if (n == 1) return 2;

    ll i, j;
    mark[1] = 1;
    for (i = 3; i*i <= MAX; i+=2) {
        if (mark[i] == 0){
            for (j = i*i; j <= MAX; j+=i+i){
                mark[j] = 1;
            }
        }
    }

    int cnt = 1;
    for (int i=3; i<=MAX; i+=2) {
        if (mark[i] == 0)
            ++cnt;
        if (n == cnt)
            return i;
    }
}

int main() {
    int n;
    cin >> n;
    cout << sieve(n) << endl;
    return 0;
}
