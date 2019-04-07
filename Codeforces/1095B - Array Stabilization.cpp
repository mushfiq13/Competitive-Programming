#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n, a[100000];

    cin >> n;
    for (int i=0; i<n; ++i)
            cin >> a[i];

    sort (a, a+n);

    int ans = a[n-2]-a[0] >  a[n-1]-a[1]
            ? a[n-1]-a[1] : a[n-2]-a[0];
    cout << ans << endl;

    return 0;
}
