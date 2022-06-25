#include<stdio.h>




typedef struct pilha Pilha;


Pilha* cria_vetor (void);

char pop_vetor (Pilha* p);

/*
#########################################

*/


typedef struct vetordin VetorDin;

VetorDin*vd_cria(void);

void vd_insere(VetorDin *vd , float x);

int vd_tam(VetorDin *vd);

float vd_acessa( VetorDin*vd , int i);

void vd_libera(VetorDin *vd);

VetorDin* le_valores(char *arquivo);

