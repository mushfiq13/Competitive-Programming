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

int BS (int l, int h, int& k, int& g, const int n) {
    int ans = -1;
    while (l <= h) {
        int m = (l + h) >> 1;
        int v = n / m;
        if (v < g) {
            k = m, ans = v;
            h = m-1;
        } else
            l = m+1;
    }
    g = ans;
    return ans;
}

int main(int argc, char ** argv) {
    static int t, n;

    cin >> t;
    while (t--) {
        cin >> n;
        int k = 1, g = n;
        vector<int> ans;
        ans.push_back(n);

        while (k <= n) {
            ans.push_back (BS(k+1, n+1, k, g, n));
        }

        sort(all(ans));

        cout << ans.size() << endl;
        for (int i=0; i<ans.size(); ++i) {
            if (i) putchar(' ');
            cout << ans[i];
        }
        puts("");
    }

    return 0;
}
