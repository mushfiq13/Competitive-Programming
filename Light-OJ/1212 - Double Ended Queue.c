#include <stdio.h>
#include <string.h>

typedef struct {
    short top;
    short data[10];
} stack;

void pushLeft (stack *s, short item, short n)
{
    if (s->top == n) {
        puts ("The queue is full");
    } else {
        int i;
        for (i = s->top; i > 0; i--) {
            s->data[i] = s->data[i-1];
        }
        s->data[0] = item;
        printf ("Pushed in left: %hd\n", item);
        s->top++;
    }
}

void pushRight (stack *s, short item, short n)
{
    if (s->top == n) {
        puts ("The queue is full");
    } else {
        s->data[s->top] = item;
        printf ("Pushed in right: %hd\n", item);
        s->top++;
    }
}

void popLeft (stack *s)
{
    if (s->top == 0) {
        puts ("The queue is empty");
    } else {
        printf ("Popped from left: %hd\n", s->data[0]);
        s->top--;
        int i;
        for (i = 0; i < s->top; i++) {
            s->data[i] = s->data[i+1];
        }
    }
}

void popRight (stack *s)
{
    if (s->top == 0) {
        puts ("The queue is empty");
    } else {
        s->top--;
        printf ("Popped from right: %hd\n", s->data[s->top]);
    }
}

int main ()
{
    stack push;
    short t, n, m, item, cs = 1;
    char s[15];

    scanf ("%hd", &t);

    while (t--) {
            scanf ("%hd %hd", &n, &m);

            push.top = 0;

            printf ("Case %d:\n", cs++);
            while (m--) {
                    scanf (" %s", s);
                    if (strcmp(s, "pushLeft") == 0) {
                            scanf ("%hd", &item);
                            pushLeft (&push, item, n);
                    }
                    else if (strcmp(s, "pushRight") == 0) {
                            scanf ("%hd", &item);
                            pushRight (&push, item, n);
                    }
                    else if (strcmp(s, "popLeft") == 0){
                            popLeft (&push);
                    }
                    else {
                        popRight (&push);
                    }
            }
    }

    return 0;
}
