#include <bits/stdc++.h>
using namespace std;

bool isPrime (int n) {
    for (int i=2; i*i<=n; ++i)
        if (n%i == 0) return 0;
    return 1;
}

int bfs (int s, int t) {
    if (s == t) return 0;
    queue<int> q;
    vector<bool> used(t+10);
    vector<int> d(t+10);

    q.push(s);
    used[s] = 1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i=2; i < v; ++i) {
            if (v%i == 0 && isPrime(i)) {
                int to = v + i;
                if (to <= t && !used[to]) {
                    used[to] = 1;
                    q.push(to);
                    d[to] = d[v] + 1;
                }
            }
        }
    }

    return d[t]==0 ? -1 : d[t];
}

int main() {
    int test, s, t;

    scanf("%d", &test);
    for (int Case=1; Case<=test; ++Case) {
        scanf("%d %d", &s, &t);
        printf("Case %d: %d\n", Case, bfs(s, t));
    }

    return 0;
}
