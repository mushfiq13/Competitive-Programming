#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a == b)
        puts("infinity");
    else {
        int n = a - b, Count = 0;
        for (long long i=1; i*i<= n; ++i) {
            if (n%i == 0) {
                if (a%i == b) ++Count ;
                if (i*i != n && a%(n/i) == b) ++Count;
            }
        }
        printf("%d\n", Count);
    }
    return 0;
}
