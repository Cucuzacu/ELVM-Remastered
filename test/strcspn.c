#include <stdio.h>
#include <string.h>

int main(void) 
{
    char line[] = "username:password";

    int len = (int)strcspn(line, ":");

    line[len] = '\0';

    printf("Username = %s\n", line);
    printf("Password = %s\n", line + len + 1);

    return 0;
}
