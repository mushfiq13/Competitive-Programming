#include <bits/stdc++.h>
using namespace std;

#define fs          first
#define sc          second
#define mp          make_pair
#define pb          push_back
#define lb          lower_bound
#define ub          upper_bound

#define sz(x)       (int)x.size()
#define ms(a,b)     memset(a, b, sizeof(a))
#define all(x)      x.begin(), x.end()

#define GCD(a,b)    __gcd(a, b)
#define LCM(a,b)    a / GCD(a, b) * b

#define FASTREAD    ios_base::sync_with_stdio(0); cin.tie(0)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

typedef pair<int, int> pii;
typedef pair<int, bool> pib;

typedef vector<int> vi;
typedef vector<pii> vpii;

const int INF = 1e9;
const ll INFLL = 2e18;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 10;

const double EPS = 1E-9;
const double EPS_ANG = 1E-16;
const static double PI = 3.141592653589793;

int main(int argc, char ** argv) {
    int t, n;
    string p[10];

    cin >> t;
    while (t--) {
        int k = 0;
        map<string, int> f;

        cin >> n;
        for (int i=0; i<n; ++i)
            cin >> p[i], ++f[p[i]];

        for (int i=0; i<n; ++i) {
            if (f[p[i]] > 1) {
                --f[p[i]]; ++k;
                bool brk = false;
                for (char c='0'; c<='9' && !brk; ++c) {
                    for (int j=0; j<4; ++j) {
                        char tmp = p[i][j];
                        p[i][j] = c;
                        if (f[p[i]] == 0) { f[p[i]] = 1; brk = 1; break; }
                        p[i][j] = tmp;
                    }
                }
            }
        }

        cout << k << endl;
        for (int i=0; i<n; ++i)
            cout << p[i] << endl;
    }
    return 0;
}
