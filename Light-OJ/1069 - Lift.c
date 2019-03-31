#include <stdio.h>

int main ()
{
    int t, pos1, pos2;
    int lift_move_sec;
    int Case = 0;

    scanf ("%d", &t);

    while (t--){
            scanf ("%d %d", &pos1, &pos2);
            lift_move_sec = (pos1 > pos2) ? ((pos1-pos2)*4) + (pos1*4) : pos2*4;
            printf ("Case %d: %d\n", ++Case, lift_move_sec + 19);
    }

    return 0;
}
