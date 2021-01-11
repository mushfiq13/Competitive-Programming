#include <bits/stdc++.h>
using namespace std;

int timer, place;
vector<char> used;
vector<int> time_in, low;
vector<vector<int>> g;

void dfs(int v, int p = -1) {
    used[v] = 1;
    time_in[v] = low[v] = ++timer;
    int subTree = 0;
    char found = 0;
    for (int to : g[v]) {
        if (p == to) continue;
        if (!used[to]) {
            dfs(to, v);
            ++subTree;
            low[v] = min(low[v], low[to]);
            if (time_in[v] <= low[to] && p != -1)
                found = 1;
        } else {
            low[v] = min(low[v], time_in[to]);
        }
    }

    place += (found == 1);
    if (p == -1 && subTree > 1)
        ++place;
}

void findCutVetices(int n) {
    timer = place = 0;
    used.assign(n+1, 0);
    time_in.assign(n+1, -1);
    low.assign(n+1, -1);

    for (int i=1; i<=n; ++i) {
        if (!used[i])
            dfs(i);
    }
}

int main() {
    int n, a, b;
    string s, dig;
    stringstream ss;

    while (cin >> n) {
        if (!n) break;

        g = vector<vector<int>> (n+1, vector<int>());

        cin.ignore();
        while (getline(cin, s)) {
            if (s[0] == '0') break;
            a = -1, ss.clear();
            ss << s;
            while (ss >> dig) {
                if (a == -1) a = stoi(dig);
                else {
                    b = stoi(dig);
                    g[a].push_back(b);
                    g[b].push_back(a);
                }
            }
        }

        findCutVetices(n);
        cout << place << endl;
    }

    return 0;
}
