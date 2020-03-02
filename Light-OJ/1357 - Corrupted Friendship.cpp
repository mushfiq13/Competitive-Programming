#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5 + 10;

vector<int> adj[MAX];

void dfs(const int v, ll& ans, int& cnt, const int n) {
    ++cnt;
    for (auto to: adj[v]) {
        dfs(to, ans, cnt, n);
    }
    ans += n-cnt;
}

int main() {
    static int test, n, x, y;

    scanf("%d", &test);
    for (int Case=1; Case<=test; ++Case) {
        scanf("%d", &n);
        for (int i=1; i<=n; ++i)
            adj[i].clear();

        for (int i=1; i<n; ++i) {
            scanf("%d %d", &x, &y);
            adj[x].push_back(y);
        }

        ll ans = 0;
        int cnt = 0;
        dfs(1, ans, cnt, n);

        printf("Case %d: %d %lld\n", Case, n-1, ans);
    }

    return 0;
}
