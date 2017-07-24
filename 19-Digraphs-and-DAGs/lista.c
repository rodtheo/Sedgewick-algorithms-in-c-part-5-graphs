#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

//Assinaturas das funÃ§Ãµes
// t_elemento* get_elemento(int v, int w);
// t_lista*    get_lista();
//
// int         esta_vazia(t_lista* lista);
// void        inserir_inicio(int valor, t_lista* lista);
// void        inserir_final(int valor, t_lista* lista);
// // void        inserir(int pos, int valor, t_lista* lista);
//
// void        remover_inicio(t_lista* lista);
// void        remover_final(t_lista* lista);
// void        remover(int pos, t_lista* lista);
//
// void        apagar_lista(t_lista* lista);
// void        imprime_lista(t_lista* lista);



//ImplementaÃ§Ãµes das FunÃ§Ãµes

//---------------------------------------------------------------
int tamanho_lista(t_lista* lista){
  t_elemento* ptr = lista->primeiro;
  int t = 0;
  if (ptr == NULL) return 0;

  while (ptr != NULL){
    t = t + 1;

    ptr = ptr->proximo;
  }

  return t;
}

//---------------------------------------------------------------
void imprime_lista(t_lista* lista){
    t_elemento* ptr = lista->primeiro;

    if(ptr == NULL){
        printf("Lista Vazia!\n");
        return;
    }

    while( ptr != NULL ){
        printf(" (%d -> %d) ", ptr->v, ptr->w);

        ptr = ptr->proximo;

    }//end while

    printf("NULL \n");

}//end imprime_lista()


// //---------------------------------------------------------------
// void inserir(int pos, int valor, t_lista* lista){
//
//     if(pos <= 0){
//         inserir_inicio(valor, lista);
//     }else{
//
//         t_elemento* atual = lista->primeiro;
//         int i = 0;
//
//         for(i = 0; i < (pos-1) && atual != NULL; i++ )
//             atual = atual->proximo;
//
//         if(atual == NULL || atual == lista->ultimo){
//             inserir_final(valor, lista);
//         }else{
//             t_elemento* elemento = get_elemento(valor);
//
//             elemento->proximo    = atual->proximo;
//             atual->proximo       = elemento;
//         }
//
//     }//end if pos
//
// }//end inserir()


//---------------------------------------------------------------
void inserir_inicio(int v, int w, t_lista* lista){

    t_elemento* elemento = get_elemento(v, w);
    elemento->proximo    = lista->primeiro;
    lista->primeiro      = elemento;

    //trata o caso da lista estar vazia inicialmente
    if(lista->ultimo == NULL){
        lista->ultimo    = lista->primeiro;
    }

}//end inserir_inicio()


//---------------------------------------------------------------
void inserir_final(int v, int w, t_lista* lista){
    t_elemento* elemento = get_elemento(v, w);

    if( esta_vazia(lista) ){
        lista->primeiro = elemento;
    }else{
        lista->ultimo->proximo = elemento;
    }

    lista->ultimo = elemento;

}//end inserir_final()


//---------------------------------------------------------------
t_lista* get_lista(){
    t_lista* ptr  = (t_lista *) malloc(sizeof(t_lista));

    ptr->primeiro = NULL;
    ptr->ultimo   = NULL;

    return ptr;
}//end get_lista()


//---------------------------------------------------------------
t_elemento* get_elemento(int v, int w){
    t_elemento* ptr = (t_elemento *) malloc(sizeof(t_elemento));

    ptr->v       = v;
    ptr->w       = w;
    ptr->proximo    = NULL;

    return ptr;
}//end get_elemento()


//---------------------------------------------------------------
int esta_vazia(t_lista* lista){
    return (lista->primeiro == NULL && lista->ultimo == NULL);
}//end esta_vazia();


//---------------------------------------------------------------
void apagar_lista(t_lista* lista){
    t_elemento* ptr = lista->primeiro;

    if(!esta_vazia(lista)){

        while( ptr != NULL ){
            lista->primeiro = lista->primeiro->proximo;

            free(ptr);

            ptr = lista->primeiro;
        }//end while

    }//end if

    free(lista);

}//end apagar_lista()



//---------------------------------------------------------------
// int main(){
//
//     t_lista*   pLista = get_lista();
//
//     inserir_final(0, 3, pLista);
//     inserir_final(0, 4, pLista);
//     inserir_final(0, 5, pLista);
//     inserir_final(1, 6, pLista);
//     inserir_final(2, 7, pLista);
//
//     imprime_lista(pLista);
//
//
    // if(esta_vazia(pLista))
    //     printf("Lista Vazia!\n");
    // else
    //     printf("Caso contrÃ¡rio.\n");
    //
    // apagar_lista(pLista);
//
//
//     return 0;
// }
