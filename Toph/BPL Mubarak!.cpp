#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    int t;
    string s;

    cin >> t;

    while (t--) {
        cin >> s;

        int cont = 0;
        for (int i=0; s[i]; ++i)
            if (s[i] != 'N' && s[i] != 'W' && s[i] != 'D')
                ++cont;

        if (cont < 6)
                if (cont > 1)
                    printf("%d BALLS\n", cont);
                else
                    printf("1 BALL\n");
        else {
                if (cont/6 > 1)
                    printf("%d OVERS", cont/6);
                else
                    printf("1 OVER");
                if (cont - cont/6*6 > 1)
                    printf(" %d BALLS", cont - cont/6*6);
                else if (cont%6)
                    printf(" 1 BALL");
                puts("");
        }
    }

    return 0;
}
