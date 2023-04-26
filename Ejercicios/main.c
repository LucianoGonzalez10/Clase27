#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

Pila cargarPila (Pila a, Pila * b, Pila * c);
int main()
{
    int validos=0, punto = 0, i = 0, dimension = 100;
    int arreglo[dimension] ;
    Pila a;
    Pila b;
    Pila c;
    inicpila(&a);
    inicpila(&b);
    inicpila(&c);

    printf("Ingrese el ejercicio a ejecutar");
    scanf("%d", &punto);

    switch (punto)
    {
    case 1:
        a = cargarPila(a, &b, &c);
        mostrar(&a);
        mostrar(&b);
        mostrar(&c);
        break;

    case 2:

        cargarC(&c);
        mostrar(&c);

        i = buscarElementoC(&c);
        printf("La cantidad de veces que el elemento se encuentra en Pila C es: %i", i);
        break;

    case 3:
        cargarC(&c);
        validos=pasarElementos(&c, arreglo, dimension);
        int i = 0;
        while(i<validos){
            printf("El numero del arreglo es: %i \n", arreglo[i]);
            i++;
        }
        break;
    }

    return 0;
}
void cargarC(Pila * c)
{
    char confirm = 's';

    while(confirm == 's')
    {
        leer(c);

        printf("Desea seguir cargando elementos?");
        fflush(stdin);
        scanf("%c", &confirm);
    }
}

int buscarElementoC(Pila * c)
{
    Pila aux;
    inicpila(&aux);
    int buscar, i = 0;
    printf("Ingrese el dato a buscar en la Pila C");
    scanf("%i", &buscar);

    while(!pilavacia(c))
    {
        if(tope(c) == buscar)
        {
            i++;
            apilar(&aux, desapilar(c));
        }
        else
        {
            apilar(&aux, desapilar(c));
        }
    }

    return i;
}
Pila cargarPila (Pila a, Pila * b, Pila * c)
{
    char confirm = 's';
    int dato;

    printf("Desea seguir cargando elementos?");
    fflush(stdin);
    scanf("%c", &confirm);

    while(confirm == 's')
    {
        printf("Ingrese el elemento a cargar en la pila");
        scanf("%d", &dato);

        printf("Desea seguir cargando elementos?");
        fflush(stdin);
        scanf("%c", &confirm);

        if((dato % 3 == 0) && (dato % 2 != 0))
        {
            apilar(&a, dato);
        }
        else if((dato % 3 == 0) && (dato % 2 == 0))
        {
            apilar(b, dato);
        }

        else
        {
            apilar(c, dato);
        }
    }
    return a;
}

int pasarElementos(Pila * c, int arreglo[], int dimension)
{
    int i=0;
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(c))
    {
        if((tope(c) >= 5) && (tope(c)<=50))
        {
            arreglo[i] = desapilar(c);
            i++;
        }
        else
        {
            apilar(&aux, desapilar(c));
        }
    }
    return i;
}
