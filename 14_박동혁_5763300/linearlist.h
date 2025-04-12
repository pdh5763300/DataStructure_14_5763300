#pragma once

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MAX_DEGREE 100

typedef struct {
    int coef;  
    int expo;  
} Term;


typedef struct {
    Term data[MAX_DEGREE];  
    int size;               
} Polynomial;


void addTerm(Polynomial* poly, int coef, int expo);
Polynomial multiply(Polynomial a, Polynomial b);
void printPoly(Polynomial poly);
void printDebugOnly(Polynomial poly, int move);
void parsePolynomial(char* input, Polynomial* poly);
