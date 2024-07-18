#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 /*Antonio Pedro Alves Fernandes 554056
   Erik do Santos Soares 555175
   Kauã Soares Dantas 553654
 */
int main(){
Complexo* x1 = criaComplexoFormaAlgebrica(8, 0.3);
Complexo* x2 = criaComplexoFormaPolar(2, 5);
float real, imag;
formaAlgebrica(x1, &real, &imag);
printf("numero real: %.2f, numero imaginario %.2f\n", real, imag);
formaPolar(x2, &real, &imag);
printf("numero real %.2f, numero imaginaria: %.2f\n", real, imag);
printf("\nverificacao do real numero x1 %d", testeReal(x1));
printf("\nverificacao do real numero x2 %d", testeReal(x2));
printf("\nverificacao do imaginario numero x1 %d", testeImaginario(x1));
printf("\nverificacao do imaginario numero x2 %d", testeImaginario(x2));
printf("\nverificacao do zero numero x1 %d\n", testeZero(x1));
printf("\nx1 + x2 =:");
imprimirComplexo(addComplexo(x1, x2));
printf("\n x1 - x2=:");
imprimirComplexo(subComplexo(x1, x2));
printf("\n x1 * x2=:");
imprimirComplexo(multComplexo(x1, x2));
printf("\nx1 / x2=:");
imprimirComplexo(divComplexo(x1, x2));
printf("\nConjugado complexo x1:");
imprimirComplexo(conjugadoComplexo(x1));
printf("\npotencia complexo x1 ao quadrad=:");
imprimirComplexo(potenciaComplexo(x1, 2));
imprimirComplexo(raizComplexo(x1, 3));
liberaComplexo(x1);
liberaComplexo(x2);
}
