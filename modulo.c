#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

      struct complexo{// struct criadora de complexo
            float a;
            float b;
        };
        void imprimirComplexo(Complexo* x){// funcao para printar complexos
            printf(" %.2f + %.2fi\n", x->a, x->b);
        }
         Complexo* criaComplexoFormaAlgebrica(float a, float b){     //funcao criadora de um numero complexo na forma algebrica.
                Complexo* numeroComplexo;       //Tipo complexo criado.
                    numeroComplexo = (Complexo*) malloc(sizeof(Complexo));      //Alocando dinamicaemente a mamoria para o numero complexo.
                        numeroComplexo->a = a;      //Coleta a parte real do complexo
                            numeroComplexo->b = b;      //Recebe a parte imaginaria do número complexo
                                return numeroComplexo;      // printa o numero complexo criado.
        }
     Complexo* criaComplexoFormaPolar(float a, float b){         //coletador que cria complexo de forma polar
            float b_radianos = b * M_PI / 180.0;                    //coletando forma imaginaria multiplicada pelo valor de PI e dividida por 180.0
             Complexo* numeroComplexo;                               //Tipo complexo criado
                 numeroComplexo = (Complexo*) malloc(sizeof(Complexo));  //Alocando a memoria para o numero
                     numeroComplexo->a = a;                                  //coletando parte real
                        numeroComplexo->b = b_radianos;                           //coletando parte imaginaria
                             return numeroComplexo;                                      //Retorna o numero complexo criado
        }
     void liberaComplexo(Complexo *z){//liberador de espaço de arq do complexo
               free(z);
             }

        void formaAlgebrica(Complexo* z, float* a, float* b) { // printa parte real e imaginaria do complexo z
                        *a = z->a;
                            *b = z->b;
        }
        void formaPolar(Complexo *z, float *a, float *b)
        {
            *a = sqrt(z->a * z->a + z->b * z->b);   //Calcula o modulo do complexo
                    *b = atan2(z->b, z->a);  //Calcula o argumento (b) do complexo em radianos
        }
        int testeReal(Complexo* z) {
            //Verifica se a parte imaginaria está igual a zero
            if (z->b == 0) {
                return 1; //Retorna 1 caso imaginario = igual a zero
            } else {
                return 0; //Retorna 0 caso contrario
            }
        }
        int testeImaginario(Complexo* z) {
            if (z->a == 0) {  //Verifica se a parte real = 0
                return 1; //Retorna 1 se a parte real  = 0
            } else {
                return 0; //Retorna 0 caso nao seja
            }
        }
        int testeZero(Complexo* z) {
            // olha se imaginario e real sao 0
            if (z->a == 0 && z->b == 0) {
                return 1;
            } else {
                return 0;
            }
        }
        Complexo* addComplexo(Complexo* z1, Complexo* z2) { //funcao que soma 2 complexos
            Complexo* resultado = criaComplexoFormaAlgebrica(z1->a + z2->a, z1->b + z2->b); //recebe a soma  de dois complexos
            return resultado;
        }

        Complexo* subComplexo(Complexo* z1, Complexo* z2) {     //subtrai complexos
            Complexo* resultado = criaComplexoFormaAlgebrica(z1->a - z2->a, z1->b - z2->b);//complexo recebe a subtracao de duas partes
            return resultado;
        }

        Complexo* multComplexo(Complexo* z1, Complexo* z2) {    //multiplicador de complexos apartir dos parametros que a funcao recebe
            return criaComplexoFormaAlgebrica(z1->a * z2->a - z1->b * z2->b,
                 z1->a * z2->b + z1->b * z2->a);
        }

        Complexo* divComplexo(Complexo* z1, Complexo* z2) {     //divisor de complexos
            float divisor = z2->a* z2->a + z2->b * z2->b;       // define o divisor
                if (divisor == 0) {             //if divisao == 0 "erro, impossível"
                     printf("nao e possivel dividir por 0\n");
            }
            return criaComplexoFormaAlgebrica((z1->a * z2->a + z1->b * z2->b) / divisor,
                (z1->b * z2->a - z1->a * z2->b) / divisor); // a divisao ocorre pelos parametros
        }

        Complexo* conjugadoComplexo(Complexo* z) {      //conjugado complexo.
            Complexo* conjugado = (Complexo*)malloc(sizeof(Complexo));//Um complexo aloca o espaço e verifica se foi alocado
            if (conjugado == NULL) {
                printf("nao alocou memoria\n");
                exit(1);
            }
             conjugado->a = z->a;
                conjugado->b = -z->b;
                     return conjugado;
        }

        Complexo* potenciaComplexo(Complexo* z, int n) {        //printa  numero complexo elevado a um numero int
            Complexo* resultado = (Complexo*)malloc(sizeof(Complexo));
                if (resultado == NULL) {
                    printf("memoria nao alocada\n");
                         exit(1);
            }
                             resultado->a = 1;
                                 resultado->b = 0;
            float modulo = sqrt(z->a * z->a + z->b * z->b);
                float modulo2 = pow(modulo, n);
                     float argumento = atan2(z->b, z->a);
                         float argumento2 = argumento * n;
                             resultado->a = modulo2 * cos(argumento2);
                                resultado->b = modulo2 * sin(argumento2);
            return resultado;
        }
        Complexo* raizComplexo(Complexo* z, int n) {
            Complexo* raizes = (Complexo*)malloc(n * sizeof(Complexo));
                 if (raizes == NULL) {
                     printf("memoria nao alocada\n");
                         exit(1);
            }
                            float modulo = sqrt(z->a * z->a + z->b * z->b);
                                 float argumento = atan2(z->b, z->a);
            for (int k = 0; k < n; k++) {
                  float argumento2 = (argumento + 2 * 3.14 * k) / n;
                     raizes[k].a = pow(modulo, 1.0 / n) * cos(argumento2);
                         raizes[k].b = pow(modulo, 1.0 / n) * sin(argumento2);
                             printf("z%d = %.2f(cos(%.2f) + sen(%.2f)i)\n", k, raizes[k].a, atan2(raizes[k].b, raizes[k].a), atan2(raizes[k].b, raizes[k].a));
            }
            return raizes;
        }

