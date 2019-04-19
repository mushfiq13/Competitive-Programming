#include <cstdio>
#include <string>
using namespace std;

int main()
{
    char s[100005];

    scanf (" %s", s);

    int mx = 0, ans = 0, mp[10] = {};
    for (int i=0; s[i]; ++i) {
        ++mp[s[i]-'0'];
        if (mp[s[i]-'0'] > mx) {
            mx = mp[s[i]-'0'];
            ans = s[i] - '0';
        }
    }

    printf ("%d\n", ans);

    return 0;
}
