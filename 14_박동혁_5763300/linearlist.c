#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linearlist.h"


void addTerm(Polynomial* poly, int coef, int expo) {
    for (int i = 0; i < poly->size; i++) {
        if (poly->data[i].expo == expo) {
            poly->data[i].coef += coef;  
            return;
        }
    }
    poly->data[poly->size].coef = coef;   
    poly->data[poly->size].expo = expo;
    poly->size++;
}


void parsePolynomial(char* input, Polynomial* poly) {
    char buffer[256];
    strncpy_s(buffer, sizeof(buffer), input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    char* term;
    char* next_token;
    term = strtok_s(buffer, "+", &next_token); 

    while (term != NULL) {
        int coef = 0, expo = 0;

        if (strstr(term, "x") == NULL) {
            if (sscanf_s(term, "%d", &coef) != 1) {
                printf("오류: 잘못된 입력 형식! (%s)\n", term);
                return;
            }
            expo = 0;
        }
        else if (strstr(term, "^") == NULL) { 
            if (sscanf_s(term, "%dx", &coef) != 1) {
                printf("오류: 잘못된 입력 형식! (%s)\n", term);
                return;
            }
            expo = 1;
        }
        else {
           
            if (sscanf_s(term, "%dx^%d", &coef, &expo) != 2) {
                printf("오류: 잘못된 입력 형식! (%s)\n", term);
                return;
            }
        }

        addTerm(poly, coef, expo); 
        term = strtok_s(NULL, "+", &next_token); 
    }
}


Polynomial multiply(Polynomial a, Polynomial b) {
    Polynomial result = { .size = 0 };
    for (int i = 0; i < a.size; i++) {
        for (int j = 0; j < b.size; j++) {
            int newCoef = a.data[i].coef * b.data[j].coef;  
            int newExpo = a.data[i].expo + b.data[j].expo;  
            addTerm(&result, newCoef, newExpo);
        }
    }
    return result;
}


void printDebugOnly(Polynomial poly, int move) {
    printf("List: size = %d, last = %d, move = %d\n", poly.size, poly.size - 1, move);
    printf("P(x) = ");
    printPoly(poly);
}


void printPoly(Polynomial poly) {
    for (int i = 0; i < poly.size; i++) {
        printf("%dx^%d", poly.data[i].coef, poly.data[i].expo);
        if (i < poly.size - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}