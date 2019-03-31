#include <stdio.h>
#include <string.h>

int main ()
{
    int n, i, top, mx, cs = 1;
    char s[100];

    scanf ("%d ", &n);

    while (n--) {
            printf ("Case %d:\n", cs++);

            char stack[100][50] = {};
            strcpy (stack[0], "http://www.lightoj.com/");

            top = mx = 0;
            while (gets(s)) {
                    if (s[0] == 'Q')
                        break;
                    if (s[0] == 'V') {
                            top++;
                            mx = top;
                            for (i = 6; s[i] != '\0'; i++){
                                stack[top][i-6] = s[i];
                            }
                            stack[top][i-6] = '\0';
                            puts(stack[top]);
                    } else if (s[0] == 'B') {
                            top--;
                            if (top < 0) {
                                puts("Ignored");
                                top++;
                            } else {
                                puts(stack[top]);
                            }
                    } else if (s[0] == 'F') {
                            top++;
                            if (top > mx) {
                                puts("Ignored");
                                top--;
                            } else {
                                puts(stack[top]);
                            }
                    }
            }
    }

    return 0;
}
