#include <cstdio>
#include <string>
using namespace std;

int main()
{
    int n, a, b;
    char ch;

    scanf("%d %d %d", &n, &a, &b);

    int cont = 0, adj = 0;
    while (n-- && (a || b)) {
            scanf(" %c", &ch);
            if (ch == '.') {
                    if (adj == 1)
                            if (b)
                                    --b, ++cont, adj = 2;
                            else
                                    adj = 0;
                    else if (adj == 2)
                            if (a)
                                    --a, ++cont, adj = 1;
                            else
                                    adj = 0;
                    else
                            if (a >= b)
                                    --a, ++cont, adj = 1;
                            else if (b >= a)
                                    --b, ++cont, adj = 2;
                            else
                                    adj = 0;
            }
            else
                    adj = 0;
    }

    printf ("%d\n", cont);

    return 0;
}
