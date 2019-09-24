#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[4];

    cin >> a[0] >> a[1] >> a[2] >> a[3];
    int sum = a[0]+a[1]+a[2]+a[3];

    bool yes = false;
    for (int i=0; !yes && i<4; ++i) {
        int taken = a[i];
        if (taken == (sum-taken)) yes = true;
        for (int j=i+1; !yes && j<4; ++j) {
            taken += a[j];
            if (taken == (sum-taken)) yes = true;
            for (int k=j+1; !yes && k<4; ++k) {
                taken += a[k];
                if (taken == (sum-taken)) yes = true;
                for (int l=k+1; !yes && l<4; ++l) {
                    taken += a[l];
                    if (taken == (sum-taken)) yes = true;
                    taken -= a[l];
                }
                taken -= a[k];
            }
            taken -= a[j];
        }
        taken -= a[i];
    }

    if (yes) puts("YES");
    else puts("NO");

    return 0;
}
