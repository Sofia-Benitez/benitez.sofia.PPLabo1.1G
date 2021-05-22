#ifndef LOCALIDAD_H_INCLUDED
#define LOCALIDAD_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[30];
}eLocalidad;

#endif // LOCALIDAD_H_INCLUDED

/** \brief funcion que imprime una localidad
 *
 * \param unaLocalidad eLocalidad
 * \param tamL int
 * \return void
 *
 */
void mostrarLocalidad(eLocalidad unaLocalidad, int tamL);


/** \brief funcion que recorre un array de localidades e imprime
 *
 * \param localidades[] eLocalidad
 * \param tamL int
 * \return void
 *
 */
void mostrarLocalidades(eLocalidad localidades[], int tamL);


/** \brief carga la descripcion de la localidad en un puntero para utilizarla en otra funcion
 *
 * \param id int
 * \param localidades[] eLocalidad
 * \param tamL int
 * \param descripcion[] char
 * \return int
 *
 */
int cargarDescripcionLocalidad(int id, eLocalidad localidades[], int tamL, char descripcion[]);///puntero a descripcion para usarla en otra funcion


///int localidadMasClientes(eAlquileres alquileres[], int tamA, eCliente lista[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat, eLocalidad localidades[], int tamL);

///int clientesDeAvellaneda(eAlquileres alquileres[], int tamA, eCliente lista[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat, eLocalidad localidades[], int tamL)

