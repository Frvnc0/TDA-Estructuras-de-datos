// Aqui programo todo lo correspondiente al tda y sus funciones

// tarea: hacer el control sin recursividad
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "clase1.h"

// CSGO

struct punto *createPunto()
{
    struct punto *pt = (struct punto *)malloc(sizeof(struct punto)); // por que usar el puntero
    pt->x = 0;
    pt->y = 0;
    return pt;
}

void setPunto(struct punto *pt, float setX, float setY, char *opcion)
{

    if (strcmp(opcion, "x") == 0)
    {
        pt->x = setX;
    }

    else if (strcmp(opcion, "y") == 0)
    {
        pt->y = setY;
    }
}

int getPuntoY(struct punto *pt)
{
    int y = pt->x;
    return y;
}

int getPuntoX(struct punto *pt)
{
    int x = pt->y;
    return x;
}

int getQuadrant(struct punto *pt)
{
    if (pt->x > 0 && pt->y > 0)
    {
        return 1;
    }
    else if (pt->x < 0 && pt->y > 0)
    {
        return 2;
    }
    else if (pt->x < 0 && pt->y < 0)
    {
        return 3;
    }
    else if (pt->x < 0 && pt->y > 0)
    {
        return 4;
    }

    else
    {
        return 0;
    }
}

void printPt(struct punto *pt){
    printf("La coordenada x, corresponde a: %f", pt->x);
    printf("La coordenada y, corresponde a: %f", pt->y);
}

void movePt(struct punto *pt, float addX, float addY){
    pt->x = pt->x + addX; //!!!!
    pt->y = pt->y + addY; //!!!!
}

float distancePt(struct punto *pt1, struct punto *pt2){

    float distance = sqrt((pow(pt2->x-pt1->x,2))+(pow(pt2->y-pt1->y,2))); //!!! no existe la libreria
    return distance;
}

struct punto *pt_medio(struct punto *pt1, struct punto *pt2){
    struct punto *pt3 = (struct punto*)malloc(sizeof(struct punto*));
    pt3->x =(pt1->x+pt2->x)/2;
    pt3->y =(pt1->y+pt2->y)/2;
    return pt3;
}
