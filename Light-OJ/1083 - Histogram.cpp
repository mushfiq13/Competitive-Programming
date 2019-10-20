#include <bits/stdc++.h>
using namespace std;

const int MAX = 30000 + 10;

int a[MAX];

int main() {
    int test, n;

    scanf("%d", &test);
    for (int Case = 1; Case <= test; ++Case) {
        scanf("%d", &n);
        for (int i=1; i<=n; ++i) {
            scanf("%d", &a[i]);
        }

        stack <int> s;
        int ans = 0;
        for (int i=1; i<=n+1; ++i) {
            int h = i <= n ? a[i] : 0;
            while (!s.empty() && a[s.top()] > h) {
                int top_id = s.top();
                s.pop();
                ans = max (ans, a[top_id] * (s.empty() ? i-1 : i-s.top()-1));
            }
            s.push(i);
        }

        printf("Case %d: %d\n", Case, ans);
    }

    return 0;
}
