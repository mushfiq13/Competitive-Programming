//============================================================================
// Name        : Battleship.cpp
// Author      : Mushfiqur Rahman
//============================================================================

#include <bits/stdc++.h>
using namespace std;

const int MAX = 100 + 10;

string s[MAX];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i=0; i<n; ++i)
		cin >> s[i];
	int ans = 0, x = 0, y = 0;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			if (s[i][j] == '#') continue;
			int cnt = 0, cnt2 = 0, l = j;
			while (l-1>=0 && l-1+k-1 >= j && s[i][l-1] == '.') --l;
			while (l < n && l < j+k && s[i][l] == '.') {++l; ++cnt2;}
			if (cnt2/k) cnt = cnt2-k+1;
			cnt2 = 0, l = i;
			while (l-1>=0 && l-1+k-1 >= i && s[l-1][j] == '.') --l;
			while (l < n && l < i+k && s[l][j] == '.') {++l; ++cnt2;}
			if (cnt2/k) cnt += cnt2-k+1;
			if (cnt > ans) {ans = cnt; x = i; y = j;}
		}
	}
	cout << x+1 << " " << y+1 << endl;
	return 0;
}
