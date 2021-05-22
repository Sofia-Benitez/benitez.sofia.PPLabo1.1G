#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "informes.h"
#include "alquiler.h"
#include "juegos.h"
#include "categoria.h"
#include "utn.h"

void menuInformes(void)
{
    system("cls");

    printf("Informes\n");
    printf("1. Alquileres por cliente\n");
    printf("2. Gasto de un cliente\n");
    printf("3. Juegos de mesa\n");
    printf("4. Juego mas alquilado por hombres\n");
    printf("5. Juegos alquilados por mujeres\n");
    printf("6. Telefono de clientes que alquilaron en una fecha en particular \n");
    printf("7. Clientes de Avellaneda\n");
    printf("8. Localidades con mas clientes\n");
    printf("9. Clientes que alquilaron juego\n");
    printf("10. Recaudacion por fecha\n");
}

int mostrarJuegosMesa(eAlquileres alquileres[], int tamA, eCliente lista[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat)
{
    int todoOk=0;
    int mesa=500;

    if(alquileres!=NULL && tamA>0 && lista!=NULL && tam>0 && juegos!=NULL && tamJ>0 && categorias!=NULL && tamCat>0)
    {
        printf("\n**********Juegos de mesa ***********\n");

        for(int i=0; i<tamJ; i++)
        {
            if(juegos[i].idCategoria==500)
            {
                mostrarJuego(juegos[i], tamCat, categorias);
                todoOk=1;
            }
        }

        return todoOk;
    }
}

int gastoCliente(eAlquileres alquileres[], int tamA, eCliente lista[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat)
{
    float gastoCliente=0;///acumulador
    int codigo;
    int flag=0;
    int todoOk=0;

    mostrarClientes(lista, tam);
    utn_getNumero(&codigo, "Ingrese el codigo del empleado: ", "Error\n", 100, 1100, 3);

    if(alquileres!=NULL && tamA>0 && lista!=NULL && tam>0 && juegos!=NULL && tamJ>0 && categorias!=NULL && tamCat>0){
        for(int j=0; j<tamA; j++)
        {
            if(alquileres[j].codigoCliente==codigo && alquileres[j].isEmpty==0)
            {
                for(int i=0; i<tamJ; i++)
                {
                    if(juegos[i].codigo==alquileres[j].codigoJuego)///busco el juego que alquilo el cliente
                    {
                        gastoCliente+=juegos[i].importe;
                        flag=1;
                    }
                }
            }
        }

    if(!flag)
    {
        printf("No hay alquileres de ese cliente\n");
    }
    else
    {
        printf("El total de gastos del cliente %d es %.2f: ", codigo, gastoCliente);
    }
    todoOk=1;
    }

    return todoOk;
}

int juegoMasAlquiladoPorHombres(eAlquileres alquileres[], int tamA, eCliente lista[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat)
{
    int contadorJuego[tamJ];//contador por cada juego para ver cual es el mas alquilado
    int mayor;
    int flag=1;
    int todoOk=0;

    for(int i=0; i<tamJ;i++)//inicializo contadores
    {
        contadorJuego[i]=0;
    }

    if(alquileres!=NULL && tamA>0 && lista!=NULL && tam>0 && juegos!=NULL && tamJ>0 && categorias!=NULL && tamCat>0){

    for(int i=0; i<tamJ;i++)
    {
        for(int j=0; j<tamA; j++)
        {
            if(alquileres[j].isEmpty==0 && alquileres[j].codigoJuego==juegos[i].codigo)
            {
                for(int h=0; h<tam; h++)
                {
                    if(alquileres[j].codigoCliente==lista[h].codigo && lista[h].sexo=='m')
                    {
                        (contadorJuego[i])++;
                    }
                }

            }
        }
    }

    for(int i=0; i<tamJ;i++)
    {
        if(flag || contadorJuego[i]>mayor)
        {
            mayor=contadorJuego[i];
            flag=0;
        }
    }
    printf("Juegos mas alquilados por hombres: \n");
    for(int i=0; i<tamJ;i++)
    {
        if(contadorJuego[i]==mayor)
        {
            printf("%s\n", juegos[i].descripcion);
        }
    }
    todoOk=1;
    }
    return todoOk;
}


int juegosAlquiladosPorMujeres(eAlquileres alquileres[], int tamA, eCliente lista[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat)
{

    int flag=1;
    int todoOk=0;


    if(alquileres!=NULL && tamA>0 && lista!=NULL && tam>0 && juegos!=NULL && tamJ>0 && categorias!=NULL && tamCat>0){
        printf("\nJuegos alquilados por mujeres\n");
        for(int i=0; i<tamJ;i++)
        {
            for(int j=0; j<tamA; j++)
            {
                if(alquileres[j].isEmpty==0 && alquileres[j].codigoJuego==juegos[i].codigo)
                {
                    for(int h=0; h<tam; h++)
                    {
                        if(alquileres[j].codigoCliente==lista[h].codigo && lista[h].sexo=='f')
                        {
                            mostrarJuego(juegos[i], tamCat, categorias);
                        }
                    }

                }
            }
        }
        todoOk=1;
    }

    return todoOk;
}


int telClientesPorFecha(eAlquileres alquileres[], int tamA, eCliente lista[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat)
{
    int todoOk=0;
    int dia;
    int mes;
    int anio;
    int flag=0;
    if(alquileres!=NULL && tamA>0 && lista!=NULL && tam>0 && juegos!=NULL && tamJ>0 && categorias!=NULL && tamCat>0){

        printf("Ingrese fecha de alquiler que desea buscar dd/mm/aaaa: ");
        scanf("%d/%d/%d", &dia, &mes, &anio);

        for(int i=0; i<tamA; i++)///recorro los alquileres
        {
            if(alquileres[i].fechaAlquiler.dia==dia && alquileres[i].fechaAlquiler.mes == mes && alquileres[i].fechaAlquiler.anio == anio)
            {
                for(int j=0; j<tam; j++)//recorro los clientes
                {
                    if(alquileres[i].codigoCliente==lista[j].codigo)
                    {

                        printf("Cliente: %s  Tel:  %s\n", lista[j].nombre, lista[j].telefono);
                        flag=1;
                    }
                }
            }
        }

        if(!flag)
        {
            printf("Ningun cliente alquilo esta fecha\n");
        }







        todoOk=1;
    }
    return todoOk;
}



int clientesQueAlquilaronJuego(eAlquileres alquileres[], int tamA, eCliente lista[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat)
{
    int juego;
    int todoOk=0;

    if(alquileres!=NULL && tamA>0 && lista!=NULL && tam>0 && juegos!=NULL && tamJ>0 && categorias!=NULL && tamCat>0){

        mostrarJuegos(juegos, tamJ, categorias, tamCat);
        utn_getNumero(&juego, "Ingrese el codigo del juego: ", "error\n", 1, 20, 3);


            for(int j=0; j<tamA; j++)
            {
                if(alquileres[j].codigoJuego==juego)
                {
                    printf("Clientes que alquilaron el juego\n");
                    for(int i=0; i<tam; i++)
                    {
                        if(alquileres[j].codigoCliente==lista[i].codigo)
                        {
                            printf("%s\n", lista[i].nombre);
                            todoOk=1;
                        }
                    }
                }
            }


        }
    return todoOk;
}

int recaudacionPorFecha(eAlquileres alquileres[], int tamA, eCliente lista[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat)
{
    int todoOk=0;
    float total;
    int dia;
    int mes;
    int anio;
    int flag=0;
    if(alquileres!=NULL && tamA>0 && lista!=NULL && tam>0 && juegos!=NULL && tamJ>0 && categorias!=NULL && tamCat>0){

        printf("Ingrese fecha de alquiler que desea buscar dd/mm/aaaa: ");
        scanf("%d/%d/%d", &dia, &mes, &anio);

        for(int i=0; i<tamA; i++)///recorro los alquileres
        {
            if(alquileres[i].fechaAlquiler.dia==dia && alquileres[i].fechaAlquiler.mes == mes && alquileres[i].fechaAlquiler.anio == anio)
            {
                for(int j=0; j<tamJ; j++)///recorro juegos
                {
                    if(alquileres[i].codigoJuego==juegos[j].codigo)
                    {
                        total+=juegos[j].importe;
                        flag=1;
                    }
                }

            }
        }

        if(!flag)
        {
            printf("Ningun cliente alquilo esta fecha\n");
        }
        else
        {
            printf("Total recaudacion de la fecha: %f\n", total);
        }

        todoOk=1;
    }
    return todoOk;
}















///informes de practica


int clientesMasAlquileres(eAlquileres alquileres[], int tamA, eCliente lista[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat)
{
    int todoOk=0;
    int contadorAlquileres[tam];///alquileres por empleados
    int mayor;
    int flag=1;

    for(int i=0; i<tam; i++)///inicializo los contadores de cada empleado
    {
        contadorAlquileres[i]=0;
    }

    if(alquileres!=NULL && tamA>0 && lista!=NULL && tam>0 && juegos!=NULL && tamJ>0 && categorias!=NULL && tamCat>0)
    {
            for(int i=0; i<tam; i++)///recorro clientes
            {
                for(int j=0; j<tamA; j++)///recorro alquileres
                {
                    if(alquileres[j].isEmpty==0 && alquileres[j].codigoCliente==lista[i].codigo)///si el codigo de cliente del alquiler coincide con el codigo del cliente que recorro
                    {
                        contadorAlquileres[i]++;
                        todoOk=1;
                    }
                }
            }

      for(int i=0; i<tam; i++)
      {
          if(flag || contadorAlquileres[i]>mayor)
          {
              mayor=contadorAlquileres[i];
              flag=0;
          }
      }

      for(int i=0; i<tam; i++)
      {
          if(contadorAlquileres[i]==mayor)
          {
              printf("%s\n", lista[i].nombre);
          }

      }


    }

    return todoOk;
}





void categoriaMasJuegos(eAlquileres alquileres[], int tamA, eCliente lista[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat)
{
    int contador[tamCat];
    int mayor;
    int flag=1;

    for(int i=0; i<tamCat;i++)//inicializo contadores
    {
        contador[i]=0;
    }

    for(int i=0; i<tamCat;i++)
    {
        for(int j=0; j<tamJ; j++)
        {
            if(juegos[j].idCategoria==categorias[i].id)
            {
                (contador[i])++;
            }
        }
    }

    for(int i=0; i<tamCat;i++)
    {
        if(flag || contador[i]>mayor)
        {
            mayor=contador[i];
            flag=0;
        }
    }
    printf("Categorias con mas juegos: \n");
    for(int i=0; i<tamCat;i++)
    {
        if(contador[i]==mayor)
        {
            printf("%s\n", categorias[i].descripcion);
        }
    }
}

void actualizarPrecioPorCategoria(eAlquileres alquileres[], int tamA, eCliente lista[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat)
{
    float precio;
    float nuevoPrecio;
    int categoria;
    int porcentajeDescuento;

    mostrarCategorias(categorias, tamCat);
    printf("Seleccione la categoria: ");
    scanf("%d", &categoria);

    printf("Ingrese el porcentaje de descuento: ");
    scanf("%d", &porcentajeDescuento);

    for(int i=0; i<tamJ; i++)
    {
        if(juegos[i].idCategoria==categoria)
        {
            precio=juegos[i].importe;
            nuevoPrecio=  precio- precio * porcentajeDescuento/100;
            juegos[i].importe=nuevoPrecio;
        }
    }

    printf("Precios actualizados\n");
    for(int i=0; i<tamJ; i++)
    {
        if(juegos[i].idCategoria==categoria)
        {
            mostrarJuego(juegos[i], tamCat, categorias);
        }
    }
}

void categoriaPreferidaCliente(eAlquileres alquileres[], int tamA, eCliente lista[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat)
{
    int contadorCat[tamCat]; ///contador por categoria para ver cual es la mas elegida por un cliente
    int codigo;
    int mayor;
    int flag=1;

    for(int i=0; i<tamCat;i++)//inicializo contadores
    {
        contadorCat[i]=0;
    }


    mostrarClientes(lista, tam);
    utn_getNumero(&codigo, "Ingrese el codigo del empleado: ", "Error\n", 100, 1100, 3);

    for(int i=0; i<tamA; i++)///recorro los alquileres
    {
        if(alquileres[i].codigoCliente==codigo)//alquileres del empleado
        {
            for(int j=0; j<tamJ; j++)//recorro los juegos
            {
                if(alquileres[i].codigoJuego==juegos[j].codigo)//encuentro el juego que alquilo
                {
                    for(int k=0; k<tamCat; k++)//recorro las categorias
                    {
                        if(juegos[j].idCategoria==categorias[k].id)//busco la categoria del juego que alquilo
                        {
                            contadorCat[k]++;
                        }
                    }
                }
            }
        }
    }

    for(int i=0; i<tamCat;i++)
    {
        if(flag || contadorCat[i]>mayor)
        {
            mayor=contadorCat[i];
            flag=0;
        }
    }
    printf("Categorias preferidas del cliente: \n");
    for(int i=0; i<tamCat;i++)
    {
        if(contadorCat[i]==mayor)
        {
            printf("%s\n", categorias[i].descripcion);
        }
    }
}
