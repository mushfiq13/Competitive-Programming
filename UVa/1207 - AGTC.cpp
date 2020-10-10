#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int editDistance(string& A, string& B, int n, int m) {
    if (n == 0) return m;
    if (m == 0) return n;

    int &ret = dp[n-1][m-1];
    if (ret != -1) return ret;

    if (A[n-1] == B[m-1]) return ret = editDistance(A, B, n-1, m-1);

    return ret = 1 + min (editDistance(A, B, n-1, m),
                min (editDistance(A, B, n-1, m-1), editDistance(A, B, n, m-1))
                );
}

int main() {
    int n, m;
    string A, B;

    while (cin >> n >> A >> m >> B) {
        dp = vector<vector<int>> (n+1, vector<int> (m+1, -1));
        cout << editDistance(A, B, n, m) << endl;
    }

    return 0;
}
