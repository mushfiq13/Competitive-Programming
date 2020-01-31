#include <bits/stdc++.h>
using namespace std;

map<string, bool> pp;
string let = "zabcdefghijklmnopqrstuvwxyza";

int bfs(string s, string t) {
    if (pp[s] || pp[t]) return -1;

    int ans = int(1e9);
    queue<pair<string,int>> q;

    q.push({s,0});
    while (!q.empty()) {
        string v = q.front().first;
        int d = q.front().second;
        q.pop();
        if (v == t) return d;
        string to = v;
        for (int i=0; i<3; ++i) {
            int pos = to[i]-'a' + 1;
            to[i] = let[pos-1];
            if (!pp[to]) {
                q.push({to, d+1});
                pp[to] = 1;
            }
            to[i] = let[pos+1];
            if (!pp[to]) {
                q.push({to, d+1});
                pp[to] = 1;
            }
            to[i] = v[i];
        }
    }

    return 0;
}

int main(int argc, int ** argv) {
    static int test, n;
    static char a[4], b[4], word[4];
    string x1, x2, x3;

    word[3] = '\0';
    scanf("%d", &test);
    for (int Case=1; Case<=test; ++Case) {
        scanf(" %s %s", &a, &b);
        scanf("%d", &n);

        pp.clear();
        while (n--) {
            cin >> x1 >> x2 >> x3;
            for (char c1: x1) {
                word[0] = c1;
                for (char c2: x2) {
                    word[1] = c2;
                    for (char c3: x3) {
                        word[2] = c3;
                        pp[word] = 1;
                    }
                }
            }
        }

        printf("Case %d: %d\n", Case, bfs(a,b));
    }

    return 0;
}
