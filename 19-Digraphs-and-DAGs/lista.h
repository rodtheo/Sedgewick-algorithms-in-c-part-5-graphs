#ifndef __LISTA_H__
#define __LISTA_H__

typedef struct elemento{
    int v;
    int w;
    struct elemento* proximo;
} t_elemento;

typedef struct{
    t_elemento* primeiro;
    t_elemento* ultimo;
} t_lista;


t_elemento* get_elemento(int v, int w);
t_lista*    get_lista();

int         esta_vazia(t_lista* lista);
void        inserir_inicio(int v, int w, t_lista* lista);
void        inserir_final(int v, int w, t_lista* lista);
// void        inserir(int pos, int valor, t_lista* lista);

void        remover_inicio(t_lista* lista);
void        remover_final(t_lista* lista);
void        remover(int pos, t_lista* lista);

void        apagar_lista(t_lista* lista);
void        imprime_lista(t_lista* lista);

int tamanho_lista(t_lista* lista);

#endif
