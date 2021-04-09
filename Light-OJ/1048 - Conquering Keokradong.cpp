#include <bits/stdc++.h>
using namespace std;

int ans[1001];
int pref[1001];

bool check(int *a, int n, int k, int x) {
	if (*max_element(a+1, a+n+1) > x) return false;

	int sum = 0, cnt = 0, merg = n - k;
	for (int i=1; i<=n; ++i) {
		if (sum+a[i] <= x && (!sum || merg)) {
			merg -= (sum > 0);
			sum += a[i];			
		}
		else {
			ans[++cnt] = sum;
			sum = a[i];
		}		
	}	
	ans[++cnt] = sum;
	
	return (cnt <= k);
}

int main() {
	int t, n, k;

	scanf("%d", &t);
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d %d", &n, &k);

		++n; ++k;

		int a[n+1];
		for (int i=1; i<=n; ++i) {
			scanf("%d", &a[i]);
		}

		int lo = 1, hi = (int)1e7;
		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			if (check(a, n, k, mid)) hi = mid;
			else lo = mid+1;
		}

		printf("Case %d: %d\n", cas, lo);
		check(a, n, k, lo);
		for (int i = 1; i <= k; ++i) {
			printf("%d\n", ans[i]);
		}
	}

	return 0;
}
/*

*/