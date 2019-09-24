#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int MAX = 1e6 + 10;

vi pi (MAX);

void prefix_function (string P) {
    int now;
    pi[0] = now = -1;
    int n = (int) P.length();
    for (int i=1; i<n; ++i) {
        while (now > -1 && P[i] != P[now+1])
            now = pi[now];
        if (P[i] == P[now+1]) ++now;
        else now = -1;
        pi[i] = now;
    }
}

vi count (string T, string P) {
    int now = -1;
    vi ans;
    int n = (int) T.length();
    int m = (int) P.length();
    for (int i=0; i<n; ++i) {
        while (now > -1 && T[i] != P[now+1])
            now = pi[now];
        if (T[i] == P[now+1]) ++now;
        else now = -1;
        if (now+1 == m) {
            ans.push_back(i-m+2);
            now = pi[now];
        }
    }
    return ans;
}

int main() {
    int t;
    string T, P;

    scanf("%d", &t);
    for (int cs=0; cs<t; ++cs) {
        if (cs) puts("");
        cin >> T >> P;
        prefix_function (P);
        vi ans = count (T, P);
        int n = ans.size();
        if (n == 0) puts("Not Found");
        else {
            printf("%d\n", n);
            for (int i=0; i<n; ++i) {
                if (i) putchar(' ');
                printf("%d", ans[i]);
            }
            puts("");
        }
    }

    return 0;
}
