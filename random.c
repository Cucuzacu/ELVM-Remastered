#include <stdio.h>
#include <random.h>

int main()
{
    int i, seed;
    printf("Enter seed: ");
    scanf("%d", &seed);
    setseed(seed);
    for (i = 0; i < 5; i++) printf("rand[%d] = %d\n", i, rand());
}