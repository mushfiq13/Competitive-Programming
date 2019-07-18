#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cin >> n;

    if (n%4 == 1)
        puts("0 A");
    else if (n%4 == 3)
        puts("2 A");
    else if (n%4 == 2)
        puts("1 B");
    else
        puts("1 A");

    return 0;
}
