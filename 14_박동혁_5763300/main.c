#include <stdio.h>
#include <string.h>
#include "linearlist.h"

int main() {
    Polynomial poly1 = { .size = 0 };  
    Polynomial poly2 = { .size = 0 }; 
    Polynomial result;
    int move = 2;  

    char input[256];

    
    printf("ù ��° ���׽��� �Է��ϼ��� (��: 3x^2+4x+1):\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; 
    parsePolynomial(input, &poly1);

    
    printf("\n�� ��° ���׽��� �Է��ϼ��� (��: 2x^2+5x+3):\n");
    fgets(input, sizeof(input), stdin); 
    input[strcspn(input, "\n")] = '\0';
    parsePolynomial(input, &poly2);

   
    printf("\n[���� ���]\n");
    result = multiply(poly1, poly2);
    printDebugOnly(result, move);

    return 0;
}


