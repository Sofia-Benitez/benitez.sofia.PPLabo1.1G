#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "localidad.h"
#include "alquiler.h"
#include "cliente.h"


void mostrarLocalidad(eLocalidad unaLocalidad, int tamL)
{
    printf("%d               %s   \n", unaLocalidad.id, unaLocalidad.descripcion);
}

void mostrarLocalidades(eLocalidad localidades[], int tamL)
{
    if(localidades!=NULL && tamL>0)
    {
        printf("\n                       ******Localidades******\n");
        printf("           ID            Descripcion      \n");
        for(int i=0; i<tamL; i++)
        {
           mostrarLocalidad(localidades[i], tamL);
        }
    }
}

int cargarDescripcionLocalidad(int id, eLocalidad localidades[], int tamL, char descripcion[])///puntero a descripcion para usarla en otra funcion
{
    int todoOk=0;

    if(id>=1 &&  id<=10 && localidades!=NULL && tamL>0 && descripcion!=NULL)
    {
        for(int i=0; i<tamL; i++)
        {
            if(localidades[i].id==id)
            {
                strcpy(descripcion, localidades[i].descripcion);///cargo la cadena que me pasan en la funcion
                todoOk=1;
                break;///ya consegui la descripcion correspondiente
            }
        }
    }

    return todoOk;
}

///INFORMES DE LOCALIDAD
int localidadMasClientes(eAlquileres alquileres[], int tamA, eCliente lista[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat, eLocalidad localidades[], int tamL)
{
    int contador[tamL];
    int mayor;
    int flag=1;
    int todoOk=0;

    for(int i=0; i<tamL; i++)//inicializo contadores
    {
        contador[i]=0;
    }

    if(localidades!=NULL && tamL >0 && alquileres!=NULL && tamA>0 && lista!=NULL && tam>0 && juegos!=NULL && tamJ>0 && categorias!=NULL && tamCat>0){
    for(int i=0; i<tamL;i++)///recorro localidades
    {
        for(int j=0; j<tam; j++)///recorro clientes
        {
            if(localidades[i].id==lista[j].idLocalidad)
            {
                contador[i]++;
            }
        }
    }

    for(int i=0; i<tamL;i++)
    {
        if(flag || contador[i]>mayor)
        {
            mayor=contador[i];
            flag=0;
        }
    }
    printf("Localidades con mas clientes: \n");
    for(int i=0; i<tamL;i++)
    {
        if(contador[i]==mayor)
        {
            printf("%s\n", localidades[i].descripcion);
        }
    }
    todoOk=1;
    }
    return todoOk;
}


int clientesDeAvellaneda(eAlquileres alquileres[], int tamA, eCliente lista[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat, eLocalidad localidades[], int tamL)
{
    int todoOk=0;
    int avellaneda=1;
    if(localidades!=NULL && tamL >0 && alquileres!=NULL && tamA>0 && lista!=NULL && tam>0 && juegos!=NULL && tamJ>0 && categorias!=NULL && tamCat>0){

    for(int i=0; i<tam; i++)//recorro clientes
    {

            if(lista[i].idLocalidad==avellaneda && lista[i].isEmpty==0)
            {
                mostrarCliente(lista[i], localidades, tamL);
            }

    }


     todoOk=1;
    }

    return todoOk;
}


