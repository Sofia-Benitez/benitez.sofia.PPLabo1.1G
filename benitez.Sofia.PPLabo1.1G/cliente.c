#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cliente.h"
#include "localidad.h"
#include "alquiler.h"
#include "utn.h"


//menu
void menu(void)
{

    system("cls");

    printf("Alquiler de juegos\n");
    printf("1. CLIENTES\n");
    printf("2. ALQUILERES\n");
    printf("3. JUEGOS (mostrar) \n");
    printf("4. INFORMES\n");
    printf("5. --------\n");
    printf("6. ---------- \n");
    printf("10. Salir\n");



}

void menuClientes(void)
{
    system("cls");

    printf("CLIENTES\n");
    printf("1. Alta \n");
    printf("2. Baja\n");
    printf("3. Modificacion \n");
    printf("4. Listar\n");
    printf("5. --------\n");
    printf("6. ---------- \n");
    printf("10. Salir\n");
}

///clientes

int inicializarClientes(eCliente lista[], int tam)
{
    int todoOk=0;
    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)//recorro el array para inicializar
        {
               lista[i].isEmpty=1;
        }
        todoOk=1;
    }
    return todoOk;
}



int buscarCliente(eCliente lista[], int tam, int codigo)
{
    int indice=-1;///si no lo encunetra devuelve -1 que es imposible como indice

    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(!lista[i].isEmpty && lista[i].codigo == codigo)//si no es 1, es decir si esta ocupado && si el indice es igual al legajo que me pasan
            {
                indice=i;///guardo en la variable indice le indice de la estructura que coincide
                break;///si no rompe me devuelve el indice de la ultima estructura vacia y yo necesito el primero.
            }
        }
    }

    return indice;

}


int buscarLibre(eCliente lista[], int tam)
{
    int indice=-1;

    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty)//si es 1
            {
                indice=i;
                break;
            }
        }

    }

    return indice;
}








int ordenarClientes(eCliente lista[], int tam, int criterio)
{
    int todoOk=0;//si no se puede ordenar
    eCliente auxCliente;//auxiliar de lo que voy a ordenar

    if(lista!=NULL && tam>0)
    {
        if(criterio==1)
        {

            for(int i=0; i<tam-1; i++)
            {
                for(int j=i+1; j<tam; j++)
                {
                    if(strcmp(lista[i].apellido, lista[j].apellido)>0)
                    {
                        auxCliente=lista[i];
                        lista[i]=lista[j];
                        lista[j]=auxCliente;
                    }
                }
            }

        }
        //else



    }

    todoOk=1;


    return todoOk;
}


int cargarNombreCliente(int codigo, eCliente lista[], int tam, char nombre[])
{
    int todoOk=0;

    if(lista!=NULL && tam>0 && nombre!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].codigo==codigo && !lista[i].isEmpty)
            {
                strcpy(nombre, lista[i].nombre);///cargo la cadena que me pasan en la funcion
                todoOk=1;
                break;///ya consegui la descripcion correspondiente
            }
        }
    }

    return todoOk;
}


int mostrarClientesDeBaja(eCliente lista[], int tam, eLocalidad localidades[], int tamL)
{
    int flag=1;
    int todoOk=0;

    if(lista!=NULL && tam>0)
    {
        printf("\n                                        ******Lista de clientes******\n");
        printf("Codigo            Apellido                 Nombre                 Sexo                  Telefono        Localidad\n");
        printf("----------------------------------------------------------------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty==1 && lista[i].codigo>=100 && lista[i].codigo<=1100 && utn_esSoloLetras(lista[i].nombre) && (lista[i].sexo=='f' ||lista[i].sexo=='m'||lista[i].sexo=='o'))///muestra los que estan en el indice que estan ocupados
            {
                mostrarCliente(lista[i], localidades, tamL);
                flag=0;
            }
        }
        if(flag)
        {
            printf("\n\n                                      No hay clientes en la lista\n");
        }
        printf("\n\n");
        todoOk=1;
    }


    return todoOk;
}

int mostrarAlquileresPorCliente(eAlquileres alquileres[], int tamA, eCliente lista[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat, eLocalidad localidades[], int tamL)
{
    int todoOk=0;
    int codigoCliente;

    if(alquileres!=NULL && tamA>0 && lista!=NULL && tam>0 && juegos!=NULL && tamJ>0 && categorias!=NULL && tamCat>0)
    {
        printf("\nAlquileres por cliente\n");
        mostrarClientes(lista, tam, localidades, tamL);

        utn_getNumero(&codigoCliente, "Seleccione el codigo del cliente: ", "Error.\n", 100,1100,3);
        while(buscarCliente(lista, tam, codigoCliente)==-1)
        {
             utn_getNumero(&codigoCliente, "Codigo invalido. Seleccione el codigo del cliente: ", "Error.\n", 100,1100,3);
        }

        for(int i=0; i<tamA; i++)
        {
            if(codigoCliente==alquileres[i].codigoCliente)
            {
                mostrarAlquiler(alquileres[i], tamA, lista, tam, categorias, tamCat, juegos, tamJ);
                todoOk=1;
            }
        }

        return todoOk;
    }

}


int altaCliente(eCliente lista[], int tam, int* pCodigo, eLocalidad localidades[], int tamL)///devuelve 0 si no se puede y 1 si se puede
{
    int todoOk=0;
    int indice;



    eCliente nuevoCliente;  ///auxiliar


    if(lista!=NULL && tam>0 && pCodigo!=NULL)
    {
        system("cls");
        printf("Alta de cliente\n\n");
        printf("Codigo: %d\n", *pCodigo);
        indice=buscarLibre(lista, tam);
        if(indice==-1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {

            nuevoCliente.codigo= *pCodigo; ///traigo el codigo

            utn_getStringNombre(nuevoCliente.nombre, "Ingrese el nombre del cliente: ", "Error, ingrese un nombre valido.\n", 51, 3);

            utn_getStringNombre(nuevoCliente.apellido, "Ingrese el apellido del cliente: ", "Error, ingrese un apellido valido.\n", 51, 3);

            utn_getGenero(&nuevoCliente.sexo, "Ingrese el genero: ");

            utn_getTelefono(nuevoCliente.telefono, "Ingrese el telefono: ", "Error, telefono invalido.\n", 21, 3);

            mostrarLocalidades(localidades, tamL);
            utn_getNumero(&nuevoCliente.idLocalidad, "Ingrese el codigo de la localidad: ", "Error\n", 1, 10, 3);
            nuevoCliente.isEmpty=0;///ahora es una estructura cargada

            lista[indice]=nuevoCliente;

            ///actualizo el proximo cod
            *pCodigo=(*pCodigo)+1;


             todoOk=1;
        }

    }

    return todoOk;
}


void mostrarCliente(eCliente unCliente, eLocalidad localidades[], int tamL)
{
    char descripcionLocalidad[20];

    cargarDescripcionLocalidad(unCliente.idLocalidad, localidades, tamL, descripcionLocalidad);

        printf("%d            %10s            %10s             %c             %10s             %10s     \n",
           unCliente.codigo,
           unCliente.apellido,
           unCliente.nombre,
           unCliente.sexo,
           unCliente.telefono,
           descripcionLocalidad
           );



}

int mostrarClientes(eCliente lista[], int tam, eLocalidad localidades[], int tamL)
{
    int flag=1;
    int todoOk=0;

    if(lista!=NULL && tam>0, localidades!=NULL && tamL>0)
    {
        printf("\n                                        ******Lista de clientes******\n");
        printf("Codigo            Apellido                 Nombre         Sexo               Telefono                Localidad\n");
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty==0)///muestra los que estan en el indice que estan ocupados
            {
                mostrarCliente(lista[i], localidades, tamL);
                flag=0;
            }
        }
        if(flag)
        {
            printf("\n\n                                      No hay clientes en la lista\n");
        }
        printf("\n\n");
        todoOk=1;
    }


    return todoOk;
}

