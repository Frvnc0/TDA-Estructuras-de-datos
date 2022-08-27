#include <stdio.h>
#include <stdlib.h>

struct info{
    int dato;
    int nivel;
    int visitado;
    char predecesor;
};

struct node{

    struct info *info;
    struct node *leftSon;
    struct node *rightSon;


};



struct info* createInfo(int input){

    struct info *infoReturn = (struct info*)malloc(sizeof(struct info));
    infoReturn->dato = input;
    infoReturn->visitado = 0;

    return infoReturn;


}


struct node* createTree(int dato){

    struct node *tree = (struct node*)malloc(sizeof(struct node));
    tree->info = createInfo(dato);
    tree->leftSon = NULL;
    tree->rightSon = NULL;
    return tree;

};



// el paso clave en esta recursion, corresponde a poder utilizar la variable aux para poder llamar la recursion
// en varias ocasiones
//busca un elemento en el arbol -> null si no lo encuentra, -> direccion del elemento si lo encuentra
struct node *searchInTree(struct node *tree, int searchInput ){

    if(tree->info->dato == searchInput){
        return tree;
    }

    else
    {
        struct node *aux = NULL;
        
        if(tree->leftSon != NULL){
            aux = searchInTree(tree->leftSon, searchInput);
        }

        if(aux != NULL && aux->info->dato == searchInput){
            return aux;
        }

        else
        {
            if(tree->rightSon != NULL){
                aux = searchInTree(tree->rightSon, searchInput);
            }
            if(aux != NULL && aux->info->dato == searchInput){
                return aux;
            }
        }

        return aux;
    }
}


// inserta un nodo -> 1 si la insercion fue exitosa -> -0 si la insercion no fue exitosa
void insert(struct node *T,int father, int x){

    struct node *searched = searchInTree(T,father); // se busca el nodo padre

    if (searched == NULL){
        printf("No se ha encontrado al padre del nodo");
    }
    else
    {
        if(searched->leftSon == NULL){
            searched->leftSon = createTree(x);
        }
        else
        {
            searched->rightSon = createTree(x);
        }
        
    }
    
};

int *leerArchivo(char *nombreArchivo, int *quantifyOfnodes)
{

    FILE *fp = fopen("tree.txt", "r");

    fscanf(fp, "%d", quantifyOfnodes); // se obtiene la cantidad de iteraciones que se deben realizar

    int *arrRepresentationReturn = (int *)malloc(sizeof(int)); // se reserva el espacio para el array que sera retornado
    int stop = *quantifyOfnodes;
    int aux;

    for (int i = 0; i < stop; i++) // ! posible bug
    {
        fscanf(fp, "%d", &arrRepresentationReturn[i]);
    }

    return arrRepresentationReturn;
}



int main(){

    int quantifyOfNodes = 0;
    int *arrRepresentation = leerArchivo("tree.txt", &quantifyOfNodes);

    printf("%d", arrRepresentation[6]);


}