#include <bits/stdc++.h>
using namespace std;

const int MAX = 100 + 10;

bool ok;
int f[10];

vector<int> unaryOperation (vector<int> v) {
    vector<int> t;
    int r = v.size();
    for (int i=0; i<r; ++i) {
        if (v[i] == '!') {
            int x = 0, j;
            for (j=i; j<r; ++j)
                if (v[j] == '!') ++x;
                else break;
            t.push_back(v[j]);
            while (x--)
                t.back() ^= 1;
            i = j;
        } else t.push_back(v[i]);
    }
    return t;
}

vector<int> andOrOperation (vector<int> v, int flag) {
    vector<int> t;
    int r = v.size();
    for (int i=0; i<r; ++i) {
        if (!flag && v[i] == '&') {
            t.back() = t.back() & v[i+1];
            ++i;
        } else if (flag && v[i] == '|') {
            t.back() = t.back() | v[i+1];
            ++i;
        } else t.push_back(v[i]);
    }
    return t;
}

vector<int> getValue (vector<int> v) {
    reverse (v.begin(), v.end());
    v = unaryOperation (v);
    v = andOrOperation (v, 0); // 0 for and operation
    v = andOrOperation (v, 1); // 1 for or operation
    return v;
}

int sol (string s) {
    int n;
    int a[s.size()+5];
    for (n=0; s[n]; ++n)
        a[n] = s[n]>='a' && s[n]<='z' ? f[s[n]-'a'] : s[n]; // copying string into array

    stack<int> stk;
    for (int i=0; i<=n; ++i) {
        if (i == n || a[i] == ')') {
            vector<int> v;
            while (stk.size() > 0) {
                if (stk.top() == '(') {
                    stk.pop(); break;
                }
                v.push_back(stk.top());
                stk.pop();
            }
            v = getValue(v);
            for (int c : v) stk.push(c);
        } else stk.push(a[i]);
    }
    return stk.top();
}

void dfs (string t, int pos, string s1, string s2) { // assigning 0/1 to distinct characters
    if (!ok) return;
    if (pos == t.size()) {
        if (sol(s1) != sol(s2))
            ok = false;
        return;
    }
    f[t[pos]-'a'] = 0;
    dfs (t, pos+1, s1, s2);
    f[t[pos]-'a'] = 1;
    dfs (t, pos+1, s1, s2);
}

string distinct (string s) { // taking distinct characters
    string t = "";
    for (int i=0; s[i]; ++i)
        if (!f[s[i]-'a'] && s[i] >= 'a' && s[i] <= 'z') {
            f[s[i]-'a'] = 1;
            t += s[i];
        }
    return t;
}

int main() {
    int test;
    string s1, s2;

    scanf("%d", &test);
    for (int Case=1; Case<=test; ++Case) {
        cin >> s1 >> s2;
        ok = true;
        for (int i=0; i<10; ++i) f[i] = 0;
        dfs (distinct(s1+s2), 0, s1, s2);
        if (ok)
            printf("Case %d: Equivalent\n", Case);
        else
            printf("Case %d: Not Equivalent\n", Case);
    }

    return 0;
}
