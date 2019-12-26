#include <bits/stdc++.h>
using namespace std;

int main() {
    static int test, n;
    string s;

    scanf("%d", &test);
    for (int Case=1; Case<=test; ++Case) {
        scanf("%d", &n);
        cin >> s;
        printf("Case %d: ", Case);
        if (s == "Alice") {
            if ((n-1)%3)
                puts("Alice");
            else
                puts("Bob");
        } else {
            if (n%3 == 0)
                puts("Alice");
            else
                puts("Bob");
        }
    }

    return 0;
}
