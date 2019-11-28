#include <bits/stdc++.h>
using namespace std;

vector<string> words[11];

int bfs (const string & s, const string & t) {
    int ssz = s.size();
    int wsz = words[ssz].size();
    queue<pair<string, int>> q;
    map<string, bool> used;

    q.push ({s, 0});
    used[s] = 1;
    while (!q.empty()) {
        string v = q.front().first;
        const int cur_d = q.front().second;
        q.pop();
        if (v == t) return cur_d;
        for (int i=0; i<wsz; ++i) {
            if (used[words[ssz][i]]) continue;
            int ham_dis = 0;
            for (int j=0; v[j] && ham_dis<2; ++j)
                if (words[ssz][i][j] != v[j])
                    ++ham_dis;
            if (ham_dis == 1){
                used[words[ssz][i]] = 1;
                q.push ({words[ssz][i], cur_d+1});
            }
        }
    }
}

int main() {
    static int test;
    static string s, a, b;

    scanf("%d", &test);
    while (test--) {
        for (int i=0; i<11; ++i) words[i].clear();
        while (cin >> s && s!="*") {
            words[s.size()].push_back (s);
        }

        cin.ignore();
        while (getline (cin, s) && s != "") {
            stringstream ss (s);
            ss >> a >> b;
            cout << s << " " << bfs (a, b) << endl;
        }

        if (test) puts("");
    }

    return 0;
}
