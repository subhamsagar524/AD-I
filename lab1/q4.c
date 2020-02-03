//This can be done with int and char only.

#include<stdio.h>

int main (void)
{
    char x = 'a';
    char y = 'b';

    x = x ^ y;
    y = x ^ y;
    x = x ^ y;

    printf("%c    %c", x, y);

    return 0;
}

