struct matrix{

    char** elements;
    int rows;
    int columns;

};


struct matriz *createMatrix(int rowsInput, int columnsInput){

    struct matrix *matrixReturn = (struct matrix*)malloc(sizeof(struct matrix));
    
    matrixReturn->columns = columnsInput;
    matrixReturn->rows = rowsInput;
    matrixReturn->elements = (char**)malloc(sizeof(char*));

    

    


    return matrixReturn;



}