#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 10000;

int n, op, di;
ll a[MAX], ope[MAX];

void convert (string s) {
    n = op = di = 0;
    int r = s.size();
    for (int i = 0; i < r; ++i) {
        ll val = 0;
        while (s[i] >= '0' && s[i] <= '9')
            val = val * 10 + s[i++] - '0';
        a[n++] = val;
        if (i < r) {
            ope[op++] = s[i];
            if (s[i] == '/') ++di ;
        }
    }
}

void sol () {
    while (op) {
        bool found = 0;
        for (int i=0; i<op; ++i) {
            if (ope[i] == '/') {
                found = 1;
                --di ;
                a[i] /= a[i+1];
            }
            else if (ope[i] == '*' && !di) {
                found = 1;
                a[i] *= a[i+1];
            }
            if (found) {
                for (++i; i<op; ++i) {
                    ope[i-1] = ope[i];
                    a[i] = a[i+1];
                }
                break;
            }
        }
        if (!found)
            break;
        --op ;
        --n ;
        //for (int i=0; i<n; ++i)
          //  cout << a[i] << " ";
       // puts("");
        //for (int i=0; i<op; ++i)
          //  cout << ope[i] <<" ";
       // puts("");
    }

    for (int i=0; i<op; ++i) {
        if (ope[i] == '+')
            a[0] += a[i+1];
        else
            a[0] -= a[i+1];
    }
}

int main() {
    int t;
    string s;

    scanf("%d", &t);
    for (int cs = 1; cs <= t; ++cs) {
        cin >> s;
        convert (s);
        sol ();
        printf("Case %d: %lld\n", cs, a[0]);
    }

    return 0;
}
