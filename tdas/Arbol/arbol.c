#include <stdlib.h>
#include <stdio.h>


//? Como son los recorridos en arboles???
//https://www.youtube.com/watch?v=95CgVIsOxLA


typedef struct info{
    int valor;

}Info;

struct nodo{

    //todo: ajustar el dato o el info a dato puntero
    int dato;
//    struct info *datoPuntero;
    struct nodo *leftSon;
    struct nodo *rightSon;

};

// otra forma de representar el arbol
struct arbol{
    struct nodo *raiz;
};


struct nodo* crearNodo(int dato){

    struct nodo *nodoReturn = (struct nodo*)malloc(sizeof(struct nodo)); // se reserva espacio para el nodo
    nodoReturn->dato = dato;
    nodoReturn->leftSon  = NULL;
    nodoReturn->rightSon = NULL;
    return nodoReturn;

}


struct nodo *insertarHijoIzquierdo(struct nodo *arbol , int hijoIzquierdo){
 
    if(arbol->leftSon == NULL){
        arbol->leftSon = crearNodo(hijoIzquierdo);
        return arbol;
    }

    else{
        insertarHijoIzquierdo(arbol->leftSon,hijoIzquierdo);
    }
    
}

int isLeaf(struct nodo *nodeToVerif){
    
    //se verifica que el nodo no tenga hijos
    if(nodeToVerif->leftSon == NULL && nodeToVerif->rightSon == NULL){
        return 1;
    }
    else{
        return 0;
    }

}

//TODO: RECORRIDOS 
// creo que esto corresponde a un recorrido en preorden

void preOrden( struct nodo *arbol ){

    if(arbol == NULL){
        return;
    }
    if(isLeaf(arbol)){
        printf("%d,", arbol->dato);
    }
    else
    {
        printf("%d", arbol->dato); //  se imprime la raiz
        preOrden(arbol->leftSon);
        preOrden(arbol->rightSon);
    }
}


void inOrden(struct nodo *arbol){

    if(arbol == NULL){  // verificacion de que el arbol sea nulo
        return;
    }

    if(isLeaf(arbol) == 1){
        printf("%d,", arbol->dato);
    }

    else{

        inOrden(arbol->leftSon);
        printf("%d,", arbol->dato);
        inOrden(arbol->rightSon);

    }


}


void postOrden(struct nodo *arbol){

    if (arbol == NULL)
    {
        return;     
    }
    
    if (isLeaf(arbol))
    {
        printf("%d", arbol->dato);
    }
    else
    {
        postOrden(arbol->leftSon);
        postOrden(arbol->rightSon);
        printf("%d",arbol->dato);
    }
    

}


//todo: metodos de insercion 

// CONTROL DE QUE EL ARBOL NO SEA NULO SE REALIZA EN EL MAIN, acuerdo con la profe

void insertarHijoOrdenado(struct nodo *arbol, int datoInput){

    if (datoInput <= arbol->dato){ // se compara si es que es menor que la raiz

        if(arbol->leftSon == NULL){
            arbol->leftSon = crearNodo(datoInput);
        }
        else
        {
            insertarHijoOrdenado(arbol->leftSon, datoInput);
        }
    }

    else{

        if(arbol->rightSon == NULL){
            arbol->rightSon = crearNodo (datoInput);
        }
        else{
            insertarHijoOrdenado(arbol->rightSon,datoInput);
        }
    }

}

void insertaHijoDerecho(struct nodo *arbol, int dato){

    if(arbol->rightSon == NULL){
        crearNodo(dato);
    }

    else{
        insertaHijoDerecho(arbol->rightSon,dato);
    }

}


struct nodo *buscar(struct nodo *arbol, int search){

    struct nodo *nodoRetorno;

    if(search <= arbol->dato){

        if(arbol->leftSon->dato== search){
            nodoRetorno =arbol->leftSon;
        }
        else
        {
            buscar(arbol->leftSon, search);
        }
        
    }
    else
    {
        if (arbol->rightSon->dato == search)
        {
            nodoRetorno = arbol->rightSon;
        }
        else{

            buscar(arbol->rightSon,search);
        }
        
    };


    if(nodoRetorno == NULL){
        return NULL;
    }
    else
    {
        return nodoRetorno;
    }
    
}


//todo: height
int tree_height(struct nodo* root) {
    // Get the height of the tree
    if (!root)
        return 0;
    else {
        // Find the height of both subtrees
        // and use the larger one
        int left_height = tree_height(root->leftSon);
        int right_height = tree_height(root->rightSon);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}

//todo: determinacion de nivel
int alturaArbol(struct nodo *arbol){
    
    // ! Cuidado con la comprobacion, se me olvido hacer este caso como una comprobación
    if(!arbol){
        return 0;
    }
/* 
    if(isLeaf(arbol)){
        printf("a");
        return 1;
    }

 */
    if (alturaArbol(arbol->leftSon) >= alturaArbol(arbol->rightSon))
    {
        printf("b");
        return 1 + alturaArbol(arbol->leftSon);
    }
    else
    {
        printf("c");
        return 1 + alturaArbol(arbol->rightSon);
    }
    
}



int determinaNivel(struct nodo *arbol ){

    if( isLeaf(arbol) == 1){
    
        printf("a");   
        printf("%d", arbol->dato);
        return  1;
    
    }

    int alturaIzquierda = determinaNivel(arbol->leftSon);
    int alturaDerecha = determinaNivel(arbol->rightSon);

    if ( alturaIzquierda >= alturaDerecha)
    {
        
        printf("b");   
        return determinaNivel(arbol->leftSon) + 1;
        
    }

    else
    {
        printf("c");   
        return determinaNivel(arbol->rightSon) + 1;
    
    }
    
}

//
int mayorPeso(struct nodo *tree, int dato){

    

}


int main(){

    struct nodo *arbol = crearNodo(4);
 /* 
    insertarHijoIzquierdo(arbol,5);
    insertarHijoIzquierdo(arbol,6);
 */


    printf("hola");
    printf("\n");
    
    insertarHijoOrdenado(arbol,3);
    insertarHijoOrdenado(arbol,5);
    insertarHijoOrdenado(arbol,6);
    insertarHijoOrdenado(arbol,1);

    
    /* 

    insertarHijoOrdenado(arbol,6);
    insertarHijoOrdenado(arbol,7);
    insertarHijoOrdenado(arbol,5);
    insertarHijoOrdenado(arbol,9);
    insertarHijoOrdenado(arbol,13);
    insertarHijoOrdenado(arbol,3);
    
    */


    printf("preORden\n");
    preOrden(arbol);// impresionPreOrden del grafo 
    printf("\n");

    printf("inORden\n");
    inOrden(arbol);
    printf("\n");
    // impresion Inorden del grafo // notar que la impresion en InOrden, en el grafo ordenado,
    // corresponde a la impresion ordenada del grafo, en caso de que el grafo este ordenado

    printf("postOrden\n");
    postOrden(arbol);
    printf("\n");
/* 
    printf("%d", arbol->rightSon->leftSon->dato);

    printf("%d", arbol->leftSon->dato);

 */

/* 
    struct nodo *nodoBuscado = buscar(arbol,6); 

    printf("El dato del elemento buscado corresponde a: %d", nodoBuscado->dato);

 */
   // printf("%d", isLeaf(arbol));
    printf("El nivel mas alto del ABO, corresponde a : %d", tree_height(arbol));    

    printf("El nivel mas alto del ABO2, corresponde a : %d", alturaArbol(arbol));    

    printf("hola");





}


