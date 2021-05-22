#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cliente.h"
#include "categoria.h"
#include "alquiler.h"
#include "juegos.h"
#include "utn.h"
#include "localidad.h"
#include "informes.h"
#include "harcodeo.h"

#define TAMC 1000
#define TAMA 1000
#define TAM_CAT 5
#define TAMJ 50
#define TAML 5


///DEJO LOS PROTOTIPOS DE ESTAS FUNCIONES Y ALGUNAS FUNCIONES ACA PORQUE ME APARECIA EL ERROR DEL INCLUDE RECURSIVO

/** \brief muestra los clientes que han pasado a tener isEmpty=1
 *
 * \param lista[] eCliente   array que recorre
 * \param tam int            tamanio del array
 * \return int              devuelve 1 si se realizo correctamente y 0 sino
 *
 */
int mostrarClientesDeBaja(eCliente lista[], int tam, eLocalidad localidades[], int tamL);

/** \brief permite realizar la baja logica de un cliente. Pasa el campo isEmpty del cliente seleccionado a 1.
 *
 * \param lista[] eCliente   array que recorre
 * \param tam int            tamanio del array
 * \return int                devuelve 1 si se realiza la baja y 0 sino
 *
 */
int bajaCliente(eCliente lista[], int tam, eLocalidad localidades[], int tamL);

/** \brief permite modificar los datos de un cliente existente. pide el codigo del cliente que se quiere modificar, y que campo de ese cliente. lo modifica y lo asigna a la estructura corresp.
 *
 * \param lista[] eCliente     array que recorre
 * \param tam int              tamanio del array
 * \return int                 devuelve 1 si se realiza la modificacion correctamente, 0 si no se modifica nada o hay un error de punteros null
 *
 */
int modificarCliente(eCliente lista[], int tam, eLocalidad localidades[], int tamL);

/** \brief imprime la informacion de un cliente
 *
 * \param unCliente eCliente      un elemento de la estructura que se muestra
 * param localidades   array de localidades para cargar la descripcion
 * tamL    tamanio array localidades
 * \return void
 *
 */
void mostrarCliente(eCliente unCliente, eLocalidad localidades[], int tamL);

/** \brief imprime una tabla con todos los clientes del array llamando a la funcion mostrarCliente();
 *
 * \param lista[] eCliente  array que recorre
 * \param tam int           tamanio del array
 * \return int     devuelve 1 si se ejecuto correctamente (puntero no es null y tam es mayor a 0)
 *
 */
int mostrarClientes(eCliente lista[], int tam, eLocalidad localidades[], int tamL);

int altaCliente(eCliente lista[], int tam, int* pCodigo, eLocalidad localidades[], int tamL);///devuelve 0 si no se puede y 1 si se puede

int cargarDescripcionLocalidad(int id, eLocalidad localidades[], int tamL, char descripcion[]);///puntero a descripcion para usarla en otra funcion

int mostrarAlquileresPorCliente(eAlquileres alquileres[], int tamA, eCliente lista[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat, eLocalidad localidades[], int tamL);

/** \brief permite ingresar un nuevo alquiler. Lo almacena en el indice que devuelve buscarLibreAlquileres y luego de cargar los datos cambia su estado de isEmpty a 0 para ocuparlo
 *
 * \param alquileres[] eAlquileres    array que recorre para cargar un nuevo alquiler
 * \param tamA int                    tamanio del array
 * \param lista[] eCliente            array de clientes para poder mostrarlos
 * \param tam int                      tamanio del array clientes
 * \param categorias[] eCategoria       array categorias para poder mostrar su descripcion
 * \param tamC int                      tamanio del array
 * \param juegos[] eJuego               array juegos para poder mostrarlos
 * \param tamJ int                      tamanio del array juegos
 * \param pIdAlquiler int*              puntero al codigo del alquiler (autoincremental)
 * \return int                          devuelve 1 si se realizo el alta correctamente y 0 sino
 *
 */
int altaAlquiler(eAlquileres alquileres[], int tamA, eCliente lista[], int tam, eCategoria categorias[], int tamCat, eJuego juegos[], int tamJ, int* pIdAlquiler, eLocalidad localidades[], int tamL);

/** \brief da de baja alquileres de los clientes que han sido dados de baja. pregunta, muestra a los clientes dados de baja y si el usuario confirma los da de baja a los alquileres
 *
 * \param alquileres[] eAlquileres     array que recorre para dar de baja los alquileres
 * \param tamA int                     tamanio del array
 * \param lista[] eCliente             array de clientes para poder mostrar los dados de baja
 * \param tam int                       tamanio del array
 * \return int                          devuelve 1 si se ejecuto correctamente y 0 sino
 *
 */
int bajaAlquilerDelCliente(eAlquileres alquileres[], int tamA, eCliente lista[], int tam, eLocalidad localidades[], int tamL);


///MAIN////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    int opcionMenuPrincipal;
    int opcionInformes;
    int opcionClientes;
    int opcionAlquileres;
    char seguir = 's';
    int nextCodigo=100;//arranca de este valor
    int nextIdAlquiler=5000;
    int nextCodigoJuego=1;

    ///clientes
    eCliente clientes[TAMC];

    inicializarClientes(clientes, TAMC);

    harcodearClientes(clientes, TAMC, 10, &nextCodigo);

    ///alquileres
    eAlquileres alquileres[TAMA];

    inicializarAlquileres(alquileres, TAMA);

    harcodearAlquileres(alquileres, TAMA, 10, &nextIdAlquiler);

    ///juegos

    eJuego juegos[TAMJ];

    inicializarJuegos(juegos, TAMJ);

    harcodearJuegos(juegos, TAMJ, 10, &nextCodigoJuego);


    eCategoria categorias[TAM_CAT] = {
        {500, "Mesa"},
        {501, "Azar"},
        {502, "Estrategia"},
        {503, "Salon"},
        {504, "Magia"}
        };

    eLocalidad localidades[TAML] = {{1, "Avellaneda"}, {2, "Lanus"}, {3, "Gerli"}, {4, "Temperley"}, {5, "Quilmes"}};

    while(seguir=='s')
    {
        menu();
        utn_getNumero(&opcionMenuPrincipal, "Ingrese una opcion: ", "Error. Opcion invalida.\n", 1, 20, 3);
        switch(opcionMenuPrincipal)
        {
        case 1:
            ///clientes
            menuClientes();
            utn_getNumero(&opcionClientes, "Ingrese una opcion: ", "Error. Opcion invalida.\n", 1, 20, 3);
            switch(opcionClientes)
            {
            case 1:
                if(altaCliente(clientes, TAMC, &nextCodigo, localidades, TAML))
                {
                    printf("Alta exitosa\n");
                }
                else
                {
                    printf("Hubo un problema al dar de alta");
                }
                break;
            case 2:
                //baja
                if(bajaCliente(clientes, TAMC, localidades, TAML))
                {
                    printf("Baja exitosa\n");
                    bajaAlquilerDelCliente(alquileres, TAMA, clientes, TAMC, localidades, TAML);
                }
                else
                {
                    printf("Hubo un problema al dar de baja\n");
                }
                break;
            case 3:
                //modificacion
                printf("modificar empleado");
                if(modificarCliente(clientes, TAMC, localidades, TAML))
                {
                    printf("Modificacion exitosa\n");
                }
                else
                {
                    printf("Hubo un problema al modificar el cliente\n");
                }
                break;
            case 4:
                //listar
                ordenarClientes(clientes, TAMC, 1);
                mostrarClientes(clientes, TAMC, localidades, TAML);
                break;
            }
            break;
        case 2:
            ///alquileres
            menuAlquileres();
            utn_getNumero(&opcionAlquileres, "Ingrese una opcion: ", "Error. Opcion invalida.\n", 1, 20, 3);
            switch(opcionAlquileres)
            {
            case 1:
                ///nuevo alquiler
                if(altaAlquiler(alquileres, TAMA, clientes, TAMC, categorias, TAM_CAT, juegos, TAMJ, &nextIdAlquiler, localidades, TAML))
                {
                    printf("Alta exitosa\n");
                }
                else
                {
                    printf("Hubo un problema al dar de alta\n");
                }
                break;

            case 2:
                //baja alquiler
                if(bajaAlquiler(alquileres, TAMA, clientes, TAMC, juegos, TAMJ, categorias, TAM_CAT))
                {
                    printf("Cancelacion realizada con exito.\n");
                }
                else
                {
                    printf("Hubo un problema al cancelar el alquiler\n");
                }
                break;
            case 3:
                ///listar alquileres
                mostrarAlquileres(alquileres, TAMA, clientes, TAMC, categorias, TAM_CAT, juegos, TAMJ);
                break;
            }//fin alquileres
            break;
        case 3:
            ///juegos
            mostrarJuegos(juegos, TAMJ, categorias, TAM_CAT);

            break;
        case 4:
            //informes
            menuInformes();
            utn_getNumero(&opcionInformes, "Ingrese una opcion: ", "Error\n", 1, 20, 3);
            switch(opcionInformes)
            {
            case 1:
                mostrarAlquileresPorCliente(alquileres, TAMA, clientes, TAMC, juegos, TAMJ, categorias, TAM_CAT, localidades, TAML);
                break;
            case 2:
                gastoCliente(alquileres, TAMA, clientes, TAMC, juegos, TAMJ, categorias, TAM_CAT);
                break;
            case 3:
                mostrarJuegosMesa(alquileres, TAMA, clientes, TAMC, juegos, TAMJ, categorias, TAM_CAT);
                break;
            case 4:
                juegoMasAlquiladoPorHombres(alquileres, TAMA, clientes, TAMC, juegos, TAMJ, categorias, TAM_CAT);
                break;
            case 5:
                juegosAlquiladosPorMujeres(alquileres, TAMA, clientes, TAMC, juegos, TAMJ, categorias, TAM_CAT);
                break;
            case 6:
                telClientesPorFecha(alquileres, TAMA, clientes, TAMC, juegos, TAMJ, categorias, TAM_CAT);
                break;
            case 7:
                clientesDeAvellaneda(alquileres, TAMA, clientes, TAMC, juegos, TAMJ, categorias, TAM_CAT, localidades, TAML);
                break;
            case 8:
                localidadMasClientes(alquileres, TAMA, clientes, TAMC, juegos, TAMJ, categorias, TAM_CAT, localidades, TAML);
                break;
            case 9:
                clientesQueAlquilaronJuego(alquileres, TAMA, clientes, TAMC, juegos, TAMJ, categorias, TAM_CAT, localidades, TAML);
                break;
            case 10:
                recaudacionPorFecha(alquileres, TAMA, clientes, TAMC, juegos, TAMJ, categorias, TAM_CAT, localidades, TAML);
                break;
            }
            break;
        case 10:
            seguir='n';

            break;
        }

        printf("Desea seleccionar otra opcion?: ");
        fflush(stdin);
        scanf("%c", &seguir);

        system("pause");

    }



    return 0;
}



int bajaCliente(eCliente lista[], int tam, eLocalidad localidades[], int tamL)
{
    int todoOk=0;
    int indice;//para guardar la ubicacion
    int codigo;
    char confirma;

    system("cls");
    printf("       Baja de clientes\n");

    mostrarClientes(lista, tam, localidades, tamL);

    utn_getNumero(&codigo, "Ingrese el codigo del cliente que desea dar de baja: ", "Error, codigo invalido. \n", 100, 1100, 3);

    indice=buscarCliente(lista, tam, codigo);

    if(indice==-1)
    {
        printf("No existe un cliente con el codigo %d", codigo);
    }
    else
    {
        mostrarCliente(lista[indice], localidades, tamL);

        printf("Confirma la baja del cliente %d?: ", codigo);
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma=='s')
        {
            lista[indice].isEmpty=1;

            todoOk=1;
        }
        else
        {
            printf("Baja cancelada por el usuario\n");
        }
    }
    return todoOk;
}

int modificarCliente(eCliente lista[], int tam, eLocalidad localidades[], int tamL)
{
    int todoOk=0;
    int indice;//para guardar la ubicacion
    int codigo;
    int opcion;
    char nuevoNombre[51];
    char nuevoApellido[51];
    char nuevoTelefono[21];
    char confirma='s';
    int flagNombre=0;
    int flagApellido=0;
    int flagTelefono=0;


    system("cls");
    printf("       Modificacion de clientes\n");

    mostrarClientes(lista, tam, localidades, tamL);

    utn_getNumero(&codigo, "Ingrese el codigo del cliente que desea modificar: ", "Error, codigo invalido. \n", 100, 1100, 3);

    indice=buscarCliente(lista, tam, codigo);

    if(indice==-1)
    {
        printf("No existe un cliente con el codigo %d", codigo);
    }
    else
    {
        mostrarCliente(lista[indice], localidades, tamL);

        printf("1. Modificar nombre\n");
        printf("2. Modificar apellido\n");
        printf("3. Modificar telefono\n");

        utn_getNumero(&opcion, "Ingrese el campo que desea modificar: ", "Error.\n", 1, 3, 3);
        switch(opcion)
        {
            case 1:
                utn_getStringNombre(nuevoNombre, "Ingrese el nuevo nombre: ", "Error.\n", 51, 3);
                flagNombre=1;

                break;
            case 2:
                utn_getStringNombre(nuevoApellido, "Ingrese el nuevo apellido: ", "Error.\n", 51, 3);
                flagApellido=1;

                break;
            case 3:
                utn_getTelefono(nuevoTelefono, "Ingrese el nuevo telefono: ", "Error, telefono invalido.\n", 21, 3);
                flagTelefono=1;

                break;

        }

        printf("Confirma la modificacion del cliente? (s para aceptar) ");
        scanf("%c", &confirma);
        if(confirma=='s')
        {
            if(flagNombre==1)
            {
                strcpy(lista[indice].nombre,nuevoNombre);
                printf("Nombre actualizado\n");
            }
            if(flagApellido==1)
            {
                strcpy(lista[indice].apellido,nuevoApellido);
                printf("Apellido actualizado\n");
            }
            if(flagTelefono==1)
            {
                strcpy(lista[indice].telefono,nuevoTelefono);
                printf("Telefono actualizado\n");
            }
            todoOk=1;
        }
        else
        {
            printf("Modificacion cancelada por el usuario.\n");
            todoOk=0;
        }


    }


    return todoOk;
}

int bajaAlquilerDelCliente(eAlquileres alquileres[], int tamA, eCliente lista[], int tam, eLocalidad localidades[], int tamL)
{
    int codigoCliente;
    char respuesta;
    int todoOk=0;

    if(alquileres!=NULL && tamA>0 && lista!=NULL && tam>0)
    {
        printf("Desea cancelar los alquileres de un cliente dado de baja?: ");
        fflush(stdin);
        scanf("%c", &respuesta);


        if(respuesta=='s')
        {
            printf("\n Clientes dados de baja\n");
            mostrarClientesDeBaja(lista, tam, localidades, tamL);
            utn_getNumero(&codigoCliente, "Ingrese el codigo del cliente: ", "Error\n", 100, 1100, 3);

            for(int i=0; i<tamA; i++)
            {
                if(alquileres[i].codigoCliente==codigoCliente)
                {
                    alquileres[i].isEmpty==1;
                }
            }
            printf("Alquileres del cliente codigo %d cancelados\n", codigoCliente);
        }
        else
        {
            printf("No se daran de baja los alquileres del cliente codigo %d\n", codigoCliente);
        }

        todoOk=1;
    }


    return todoOk;
}
