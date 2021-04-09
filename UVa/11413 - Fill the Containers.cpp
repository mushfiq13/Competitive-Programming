#include <bits/stdc++.h>
using namespace std;

bool check(int *a, int n, int m, int x) {
	int merg = n - m;
	int container = 0, sum = 0;
	for (int i=1; i<=n; ++i) {		
		if (!sum) {
			sum += a[i];
			++container;
		}
		else {
			if (merg && sum + a[i] <= x) {
				--merg;
				sum += a[i];
			}
			else {
				sum = a[i];
				++container;
			}
		}
		if (sum > x) return false;
	}

	return (container <= m);
}

int main() {
	int n, m;
	
	while (scanf("%d %d", &n, &m) == 2) {
		int a[n+1];
		for (int i=1; i<=n; ++i) {
			scanf("%d", &a[i]);
		}

		if (n <= m) {
			printf("%d\n", *max_element(a+1, a+n+1));
			continue;
		}

		int lo = 1, hi = (int)1e9 + 1;
		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			if (check(a, n, m, mid)) hi = mid;
			else lo = mid + 1;
		}

		printf("%d\n", lo);
	}

	return 0;
}
/*
1
10 4
14 12 41 2 46 8 48 1 1 54
*/