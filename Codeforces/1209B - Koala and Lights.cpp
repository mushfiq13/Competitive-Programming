#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
const int MAX = 101;

string l[MAX];
int a[MAX], b[MAX];

int main() {
    int n;
    string s;

    cin >> n >> s;
    for (int i=0; i < n; ++i)
        cin >> a[i] >> b[i];

    int ans = 0;
    for (int i=0; i<n; ++i) {
        l[i] = s[i];
        int t = s[i]-'0';
        int id = 1;
        ans += t;
        while (b[i] <= MAX*MAX) {
            for (int j=id; j<b[i]; ++j, ++id)
                l[i] += t + '0';
            t ^= 1;
            b[i] += a[i];
        }
    }

    for (int i=1; i<MAX*MAX; ++i) {
        int cnt = 0;
        bool rep = true;
        for (int j=0; j<n; ++j) {
            if (l[j][i] == '\0') n = 0;
            else
                cnt += l[j][i] - '0';
        }
        if (n) ans = max (ans, cnt);
    }

    cout << ans << endl;
    return 0;
}
