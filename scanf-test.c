#include "stdio.h"

//little test coded by cucuzacu to test the newly implemented scanf
int main()
{
    char name[32];
    long age;
    long hex_val;
    char secret[10];

    const char* input_str = "Alice 25 0xdead";
    int count = sscanf(input_str, "%s %d %x", name, &age, &hex_val);
    
    printf("Test 1 (sscanf):\n");
    printf("  Parsed %d items\n", count);
    printf("  Name: %s, Age: %d, Hex: %x\n", name, age, hex_val);
    printf("--------------------------\n");

    const char* id_str = "ID: 42";
    long id_num = 0;
    sscanf(id_str, "ID: %d", &id_num);
    printf("Test 2 (Literal Match):\n");
    printf("  ID found: %d (Expected 42)\n", id_num);
    printf("--------------------------\n");

    printf("Test 3 (Interactive):\n");
    printf("Enter your first name and a lucky number: ");
    
    scanf("%s %d", name, &age);
    printf("  Hello %s, your lucky number is %d.\n", name, age);
    printf("--------------------------\n");

    printf("Type a single character: ");
    char c;
    scanf(" %c", &c);
    printf("  You typed: %c\n", c);

    return 0;
}