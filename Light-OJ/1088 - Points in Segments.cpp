#include <bits/stdc++.h>
using namespace std;

int BS(int *a, int n, int x, int f) {
	int id = -1;
	int lo = 1, hi = n;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (!f) {
			if (a[mid] < x) {
				lo = mid+1;
			}
			else {
				id = mid;
				hi = mid-1;
			}
		}
		else {
			if (a[mid] <= x) {
				id = mid;
				lo = mid+1;
			}
			else {			
				hi = mid-1;
			}
		}
	}
	return id;
}

int main() {
	int t, n, q;

	scanf("%d", &t);
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d %d", &n, &q);

		int a[n+1];
		for (int i=1; i<=n; ++i) {
			scanf("%d", &a[i]);
		}

		printf("Case %d:\n", cas);
		while (q--) {
			int A, B;
			scanf("%d %d", &A, &B);
			int l = BS(a, n, A, 0);
			int r = BS(a, n, B, 1);
			int ans = (l <= r && l != -1 && r != -1) ? r - l + 1 : 0;
			printf("%d\n", ans);
		}		
	}

	return 0;
}
/*
2

4 1
1 2 3 4
5 10

4 1
5 6 7 8
1 4
*/
