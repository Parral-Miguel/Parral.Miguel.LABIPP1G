#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

struct //estructura mascota
{
    int id;
    char nombre [20];
    char sexo;
    int isEmpty;
} typedef eCliente;

#endif // CLIENTE_H_INCLUDED

int inicializarCliente (eCliente* clientes, int tam); //inicializa lista
/*int buscarEspacioLibreCliente (eCliente* clientes, int tam);*/
int listarClientes(eCliente* clientes, int tam); //lista todos
void listarCliente(eCliente* clientes, int tam, int indice);
/*int altaCliente(eCliente* clientes, int tam, int id);  //alta de servicio
int bajaCliente (eCliente* clientes, int tam);  //da de baja mascota
int buscarPorIdCliente (eCliente* clientes, int tam, int id); //busca servicio por id
int buscarVacioCliente(eCliente* clientes, int tam); //busca si servicio esta vacio
*/
