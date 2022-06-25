#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
#include <assert.h>
#define MAX 50



struct pilha
{
    char palavra;
    float vet[MAX];
};


Pilha* cria_vetor (void)
{
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->palavra = 0; /* inicializa com zero elementos */
    return p;
}


void push_vetor (Pilha* p, char v)
{
    if (p->palavra == MAX)   /* capacidade esgotada */
    {
        printf("Capacidade da pilha estourou.\n");
        exit(1); /* aborta programa */
    }
    /* insere elemento na próxima posição livre */
    p->vet[p->palavra] = v;
    p->palavra++;
}


char pop_vetor (Pilha* p)
{
    float v;
    if (vazia_Vetor(p))
    {
        printf("Pilha vazia.\n");
        exit(1); /* aborta programa */
    }
    /* retira elemento do topo */
    v = p->vet[p->palavra-1];
    p->palavra--;
    return v;
}
int vazia_Vetor (Pilha* p)
{
    return (p->palavra == 0);
}


void libera_vetor (Pilha* p)
{
    free(p);
}

/* imprime: versão com vetor */
void imprime_Vetor (Pilha* p)
{
    int i;
    for (i=p->palavra-1; i>=0; i--)
        printf("%f\n",p->vet[i]);
        printf("%c\n",p->vet[i]);
}






/*
##################################################################################################################
*/

struct vetordin{
    int n;
    int nmax;
    float *v;
};

VetorDin*vd_cria(void)
{
    VetorDin*vd =(VetorDin*) malloc (sizeof(VetorDin));
    vd->n =0;
    vd -> nmax =4;
    vd -> v =(float *) malloc(vd -> nmax* sizeof(float));
    return vd;
}

static void realoca(VetorDin *vd)
{
    vd ->nmax *= 2;
    vd ->v = (float*)realloc(vd->v , vd ->nmax*sizeof(float));
}

void vd_insere(VetorDin * vd , float x)
{
    if(vd->n == vd-> nmax){

        realoca(vd);
    }
    vd ->v[vd ->n++] = x;
}

int vd_tam(VetorDin * vd)
{
    return vd-> n;
}

float vd_acessa(VetorDin *vd , int i)
{
    assert(i>=0 && i<vd->n);
    return vd->v[i];
}

void vd_libera(VetorDin *vd)
{
    free(vd->v);
    free(vd);
}



VetorDin* le_valores(char *arquivo)
{
    FILE * f = fopen(arquivo ,"rt");
    if(f== NULL){
        return NULL;
    }
    VetorDin *vd =vd_cria();
    float x;
    while (fscanf("f ,% f ",& x)==1){
        vd_insere(vd,x);
    }
    fclose(f);
    return vd;
}



/*
void vInit(Vetor *v){
	v->tamanhoAtual = 0;
	v->capacidade = CAPACIDADE_INICIAL;

	v->p = malloc(sizeof(int) * (v->capacidade));
	if((v->p) == NULL) return;
}

void vInsere(Vetor *v, int valor){
	vDobraCapacidade(v);
	(v->p)[v->tamanhoAtual++] = valor;
}

void vDobraCapacidade(Vetor *v){
	if((v->tamanhoAtual) == (v->capacidade)){
		v->capacidade *= 2;
		v->p = realloc(v->p, sizeof(int) * v->capacidade);
	}
}
*/
