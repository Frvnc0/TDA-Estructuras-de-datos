// tarea: hacer el control sin recursividad
//Aqui se define el tda y sus operaciones con sus respectivas entradas
struct punto{
    float x;
    float y;
};

//CSGO


struct punto *createPunto();

void setPunto(struct punto *pt, float setX,  float setY, char *opcion);

int getPuntoY(struct punto *pt);

int getPuntoX(struct punto *pt);



int getQuadrant(struct punto *pt);

void printPt(struct punto *pt);

void movePt(struct punto *pt, float addX, float addY);

struct punto *pt_medio(struct punto *pt1, struct punto *pt2);


