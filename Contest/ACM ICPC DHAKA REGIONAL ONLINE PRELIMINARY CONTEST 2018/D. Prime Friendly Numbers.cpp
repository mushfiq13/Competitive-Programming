#include <bits/stdc++.h>
using namespace std;

#define IOS    ios_base::sync_with_stdio(0); cin.tie(0)

typedef long long ll;

typedef pair<int, int> pii;
typedef pair<int, bool> pib;

typedef vector<int> vi;
typedef vector<pii> vpii;

const int INF = 1e9 + 99;
const ll INFLL = 2e18;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int fx[8] = {+0, +0, +1, -1, +1, +1, -1, -1};
int fy[8] = {+1, -1, +0, +0, +1, -1, +1, -1};

ll pr;
string dig{"##23355777"};

long long mulMod(long long a, long long b, long long mod) {
    long long res = 0;
    while (b) {
        if(b & 1)
            res = (res + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return res;
}

long long powerMod(long long a, long long b, long long mod) {
    long long res = 1;
    while (b) {
        if (b & 1)
            res = mulMod(res, a, mod);  // res = res * a % mod
        a = mulMod(a, a, mod);          // a = a * a % mod
        b >>= 1;
    }
    return res;
}

bool checkComposite(long long n, long long a, long long d, int r) {
    long long x = powerMod(a, d, n);
    if (x == 1 || x == n-1) return false;

    for (int i=1; i<r; ++i) {
        x = mulMod(x, x, n);
        if (x == n-1) return false;
    }
    return true;
}

bool millerRabin(long long n, int iter = 5) {
    if (n < 2)    return false;

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 83, 89, 97}) {
        if (n == a)      return true;
        if (n % a == 0)  return false;
    }

    int r = 0;
    long long d = n-1;
    while ((d & 1) == 0) {
        d >>= 1;
        ++r;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (checkComposite(n, a, d, r))
            return false;
    }

    return true;
}

ll stringToInt(const string& s) {
    ll n = 0;
    for (char c : s)
        n = n * 10 + c - '0';
    return n;
}

// get greater number less than s with allowable digits
void F(string& s) {
    int r = s.size();
    bool upd = false;
    for (int i = r-1; i >= 0; --i) {
        if (s[i]-1 >= '2') {
            s[i] = dig[s[i]-1-'0'];
            while (++i < r) s[i] = '7';
            upd = true;
            break;
        }
    }

    if (!upd) {
        s.clear();
        for (int i=0; i<r-1; ++i) s += '7';
    }

    ll n = stringToInt(s);
    if (millerRabin(n)) pr = n;
}

bool valid(char c) {
    return (c == '7' || c == '5' || c == '3' || c == '2');
}

void rearrangeDigits(string& s) {
    // set allowable digits
    for (int i=0; i<s.size(); ++i) {
        if (valid(s[i])) continue;
        if (s[i] < '2') {
            while (--i>=0 && s[i] == '2');
            if (i >= 0) --s[i];
            else {
                s = string(s.size()-1, '7');
                break;
            }
        }
        s[i] = dig[s[i]-'0'];
        while (++i < s.size()) s[i] = '7';
        break;
    }
}

int main() {
    int t;

    cin >> t;
    for (int casei = 1; casei <= t; ++casei) {
        string s;
        cin >> s;

        rearrangeDigits(s);
        pr = -1;
        if (millerRabin(stringToInt(s))) pr = stringToInt(s);
        while (pr == -1) {
            F(s);
        }

        printf("Case %d: %lld\n", casei, pr);
    }

    return 0;
}
