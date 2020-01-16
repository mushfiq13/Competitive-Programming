#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
vector<int> adj[100 + 10];

map<int, string> pp1;
map<string, int> pp2;

void topSort(const int n) {
    priority_queue<int> pq;
    vector<int> indegree (n+1);

    for (int i=1; i<=n; ++i)
        for (int to: adj[i])
            ++indegree[to];

    for (int i=1; i<=n; ++i)
        if (indegree[i] == 0)
            pq.push(-i);

    ans.clear();
    while (!pq.empty()) {
        int v = -pq.top();
        pq.pop();
        ans.push_back(v);
        for (int to: adj[v]) {
            --indegree[to];
            if (indegree[to] == 0)
                pq.push(-to);
        }
    }
}

int main() {
    int n, m;

    for (int Case=1; ~scanf("%d", &n); ++Case) {
        pp1.clear();
        pp2.clear();

        for (int i=1; i<=n; ++i) {
            string s;
            cin >> s;
            pp1[i] = s;
            pp2[s] = i;
            adj[i].clear();
        }

        scanf("%d", &m);
        while (m--) {
            string b1, b2;
            cin >> b1 >> b2;
            adj[pp2[b1]].push_back(pp2[b2]);
        }

        topSort(n);

        printf("Case #%d: Dilbert should drink beverages in this order:", Case);
        for (int v: ans)
            printf(" %s", pp1[v].c_str());
        printf(".\n\n");
    }

    return 0;
}
