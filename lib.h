#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct complexo Complexo;
void imprimirComplexoFormaPolar();
void imprimirComplexo(Complexo* x);
Complexo* criaComplexoFormaAlgebrica(float a, float b);
Complexo* criaComplexoFormaPolar(float a, float b);
void liberaComplexo(Complexo * z);
void formaAlgebrica(Complexo* z, float* a, float* b);
void formaPolar(Complexo* z, float* a, float* b);
int testeReal(Complexo* z);
int testeImaginario(Complexo* z);
int testeZero(Complexo* z);
Complexo* addComplexo(Complexo* z1, Complexo* z2);
Complexo* subComplexo(Complexo* z1, Complexo* z2);
Complexo* multComplexo(Complexo* z1, Complexo* z2);
Complexo* divComplexo(Complexo* z1, Complexo* z2);
Complexo* conjugadoComplexo(Complexo* z);
Complexo* potenciaComplexo(Complexo* z, int n);
Complexo* raizComplexo(Complexo* z, int n);

