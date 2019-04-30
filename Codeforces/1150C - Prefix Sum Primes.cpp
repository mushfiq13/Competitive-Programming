#include <bits/stdc++.h>
using namespace std;

#define MAX 200000

int main()
{
    int n, ar[3] = {};

    cin >> n;
    for (int i=0; i<n; ++i) {
        int x;
        cin >> x;
        ar[x]++;
    }

    if (ar[1] && ar[2]) {
        printf("2 1");
        ar[1]-- ;
        ar[2]-- ;
    }
    else if (ar[1]) {
        printf("1");
        ar[1]-- ;
    }
    else if (ar[2]) {
        printf("2");
        ar[2]-- ;
    }

    for (; ar[2] > 0; ar[2]--)
        printf(" 2");
    for (; ar[1] > 0; ar[1]--)
        printf(" 1");
    puts("");

    return 0;
}
