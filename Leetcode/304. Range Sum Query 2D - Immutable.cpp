class NumMatrix {
public:
    vector<vector<int>> S;

    NumMatrix(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return;
        int n = mat.size();
        int m = mat[0].size();

        S.clear();
        S.resize(n+1);
        for (int i=0; i<=n; ++i)
            S[i].resize(m+1);

        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=m; ++j) {
                S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + mat[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        ++row1; ++col1; ++row2; ++col2;
        return S[row2][col2] - S[row1-1][col2] - S[row2][col1-1] + S[row1-1][col1-1];
    }
};
