#include <stdio.h>
#include <stdlib.h>

int main()
{
    int binary;
    int weight;
    int decimal;
    int rem;
    int num;

    printf("Enter the binary number: ");
    scanf("%d",&binary);
    decimal = 0;
    weight = 1;
    num = binary;

    while(binary!=0)
    {
        rem = binary % 10;
        decimal = decimal + rem*weight;
        binary = binary / 10;
        weight = weight*2;
    }
    printf("Decimal equivalent of the binary number %d is: %d", num, decimal );

    return 0;
}
