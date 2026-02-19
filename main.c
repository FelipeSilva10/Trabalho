#include <stdio.h>
#include <stdlib.h>
#include <abb.h>
#include <grafo.h>
#include <string.h>
#include <direct.h>

void printmenu(){

    printf("\n");
    printf("========================================\n");
    printf("            MENU PRINCIPAL\n");
    printf("========================================\n");
    printf("1 - Buscar local pelo nome\n");
    printf("2 - Listar locais em ordem alfabetica\n");
    printf("3 - Buscar menor rota entre dois locais\n");
    printf("4 - Exibir rotas diretas do grafo\n");
    printf("5 - Rota de menor custo passando por todos locais\n");
    printf("6 - Encerrar programa\n");
    printf("========================================\n");
    printf("Escolha uma opcao: ");
}

int main(){

    Grafo* g = criaGrafo(10000);
    No* abb = NULL;

    FILE *f = fopen("testecasos.txt", "r");
    if(!f) perror("erro: ");
    int cnt = 0;

    while(1){
        char a[100], b[100];
        int c;

        if(fscanf(f, "%99s %99s %d", a, b, &c) != 3) break;

        No* ax = NULL;
        No* bx = NULL;

        ax = buscar(abb, a);
        bx = buscar(abb, b);

        if(ax == NULL){
            abb = inserir(abb, a, cnt++);
            ax = buscar(abb, a);
        }
        if(bx == NULL){
            abb = inserir(abb, b, cnt++);
            bx = buscar(abb, b);

        }
        int ida;
        int idb;

        ida = ax->id;
        idb = bx->id;

        insereRua(g, ida, idb, c);


    }

    int loop = 1;

    while(loop){
        printmenu();
        int aux;
        scanf("%d", &aux);


        switch(aux){
        case 1:
            char nome[100];
            printf("Insira o nome do local:\n");
            scanf("%100s", nome);
            printf("\n");
            No* aux;

            aux = buscar(abb, nome);

            if(aux == NULL) printf("Nome invalido!\n");
            else printf("Id do local: %d\n", aux->id);

            break;
        case 2:
            ordem(abb);
            break;
        case 3:
            printf("Insira os nomes (2) dos locais: \n");
            char na[100], nb[100];
            scanf("%100s %100s", na, nb);
            printf("\n");

            No* ax = NULL;
            No* bx = NULL;

            ax = buscar(abb, na);
            bx = buscar(abb, nb);

            if(ax == NULL || bx == NULL){
                printf("ERRO! LOCAL INVALIDO!\n");
                break;
            }

            dijkstra(g, ax->id, bx->id);

            break;
        case 4:
            imprimeGrafo(g);
            break;
        case 5:
            mst(g);
            break;
        case 6:
            loop = 0;
            break;
        }
    }

    liberar(abb);
    liberaGrafo(g);

    return 0;
}
