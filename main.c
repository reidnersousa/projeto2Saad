#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "lista.h"

//estrutura autorreferenciad
//sctackNode  =pilhaNode

/*****************8888
*               Não funciona
***************************/

/*
void imprime(lista *array, int *erro){
    for (int i = 0; i < lista_tamanho(array); i++){
        printf("%d ", lista_busca_ind(array, i, erro));
    }
    printf("[Tamanho: %d -> Capacidade: %d]\n", lista_tamanho(array), lista_capacidade(array));
}

*/
int main ()
{
    Pilha*pilha;

    pilha=cria_vetor();
    push_vetor(pilha,'a');
    imprime_Vetor(pilha);
    printf("Fim da execução \n");


    VetorDin*vet;
    vet=vd_cria();
    vd_insere(vet,12);
    printf("%d",vd_tam(vet));
    vd_libera(vet);

    return 0;// indica conclusão bem-sucedida
}





