#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED


/*Cliente:
• Código (autoincremental)
• Nombre (máximo 51 caracteres) Validar
• Apellido(máximo 51 caracteres)Validar
• Sexo Validar
• Teléfono (máximo 21 caracteres) Validar*/

typedef struct{

    int codigo;
    char nombre[51];
    char apellido[51];
    char sexo;
    char telefono[21];
    int idLocalidad;
    int isEmpty;
}eCliente;


#endif // CLIENTE_H_INCLUDED

/** \brief imprime el menu de opciones del ABM
 *
 * \param void
 * \return void
 *
 */
void menu(void);

/** \brief imprime el menu de ABM de clientes
 *
 * \param void
 * \return void
 *
 */
void menuClientes(void);


/** \brief asigna un 1 a todos los clientes indicando que estan vacios
 *
 * \param lista[] eCliente   array que recorre
 * \param tam int            tamanio del array
 * \return int devuelve 1 si se inicializaron correctamente
 *
 */
int inicializarClientes(eCliente lista[], int tam);








/** \brief busca el indice de un cliente segun su codigo
 *
 * \param lista[] eCliente   array que recorre
 * \param tam int            tamanio del array
 * \param codigo int         codigo que se pasa por parametro del cliente a buscar
 * \return int    devuelve el indice
 *
 */
int buscarCliente(eCliente lista[], int tam, int codigo);




/** \brief busca en el array la primera posicion vacia en el campo isEmpty
 *
 * \param lista[] eCliente    array que recorre
 * \param tam int               tamanio del array
 * \return int   delvulve el indice de la primera posicion vacia
 *
 */
int buscarLibre(eCliente lista[], int tam);




/** \brief permite ingresar un nuevo dato del tipo eCliente, le asigna un indice que estaba vacio, pide los datos en un auxiliar y luego los asigna a la estructura clientes
 *
 * \param lista[] eCliente    array que recorre
 * \param tam int             tamanio del array
 * \param pCodigo int*        puntero a la direccion de memoria del codigo del cliente (autoincremental)
 * \return int                devuelve 1 si se pudo realizar correctamente y 0 sino
 *
 */
///int altaCliente(eCliente lista[], int tam, int* pCodigo);




/** \brief ordena los clientes segun distintos criterios
 *
 * \param lista[] eCliente
 * \param tam int
 * \param criterio int    criterio de ordenamiento pasado por parametros
 * \return int            devuelve 1 si se realizo correctamente y 0 sino
 *
 */
int ordenarClientes(eCliente lista[], int tam, int criterio);


/** \brief carga los nombres de los clientes en un array para que sean utilizados en otra funcion
 *
 * \param codigo int    codigo del cliente del que se quiere obtener su nombre
 * \param lista[] eCliente    array de eCliente
 * \param tam int
 * \param nombre[] char        puntero al array nombre para ser utilizado en otra funcion
 * \return int                 devuelve 1 si se realizo correctamente y 0 sino
 *
 */
int cargarNombreCliente(int codigo, eCliente lista[], int tam, char nombre[]);





