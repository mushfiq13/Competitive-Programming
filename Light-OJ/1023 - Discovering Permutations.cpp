#include <cstdio>
using namespace std;

int n, k;
int count[27];
char s[27], res[27];

void permute(int l, int f)
{
    if (!k) return;
    if (f == n) {
        res[f] = '\0';
        puts(res);
        k--;
        return;
    }

    int i;
    for (i=0; k && i<l; i++) {
        if(!count[i]) continue;
        res[f] = s[i];
        count[i]--;
        permute(l,f+1);
        count[i]++;
    }
}

int main ()
{
    int t, cs = 1;

    int i;
    for (i=0; i<26; i++) {
        count[i] = 1;
        s[i] = i+'A';
    }
    s[i] = '\0';

    scanf ("%d", &t);

    while (t--) {
        scanf ("%d %d", &n, &k);

        printf ("Case %d:\n", cs++);
        permute (n,0);
    }

    return 0;
}
