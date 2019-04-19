#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t;

    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;
        if ((a+b)/2%2 == 0)
            printf("Sadia will be happy.\n");
        else
            printf("Oops!\n");
    }

    return 0;
}
