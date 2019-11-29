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

int par[27], Size[27];

int find_set(int v) {
    return par[v] = v == par[v] ? v : find_set(par[v]);
}

void union_sets(int a, int b) {
    int u = find_set(a);
    int v = find_set(b);
    if (u != v) {
        if (Size[v] > Size[u])
            swap(u, v);
        par[v] = u;
        Size[u] += Size[v];
    }
}

int main(int argc, char ** argv) {
    static int n, f[27] = {};
    string pass;

    for (int i=0; i<27; ++i) par[i] = i, Size[i] = 1;

    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> pass;
        for (int i=1; pass[i]; ++i) {
            f[pass[i]-'a'] = 1;
            union_sets(pass[i]-'a', pass[i-1]-'a');
        }
        f[pass[0]-'a'] = 1;
    }

    int ans = 0;
    for (int i=0; i<27; ++i)
        if (f[i] && find_set(i) == i)
            ++ans;

    cout << ans << endl;

    return 0;
}
