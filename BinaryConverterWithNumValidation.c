#include <stdio.h>
#include <stdlib.h>

int main() {
    int binaryInput;
    int decimal = 0;
    int weight = 1;
    int rem;

    printf("Enter the binary number: ");
    scanf("%d", &binaryInput);

    int num = binaryInput;
    while (binaryInput != 0) {
        rem = binaryInput % 10;
        if (rem > 1) {
            printf("Invalid binary number!\n");
            return 1;
        }
        decimal += rem * weight;
        binaryInput /= 10;
        weight *= 2;
    }

    printf("Decimal equivalent of %d is: %d\n", num, decimal);
    return 0;
}
