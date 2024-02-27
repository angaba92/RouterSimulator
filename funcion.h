//TRABAJO DE PROGRAMACION II
//ANDRES GARCIA-BAQUERO LEON
#ifndef FUNCION_H
#define FUNCION_H


//constantes
#define BLANCO ' '
#define TAM_MAX 1024
#define MAXDIR 255
#define ERROR  0
#define N	'\n'
#define R '\r'
#define T	'\t'
#define	CERO 0
#define ERRORESERVA 1
#define desplazamiento -1
#define CUATRO	4
#define SIETE 7
#define ONCE 11
#define UNO 1
#define TRES 3
#define	HEX	256
//declaracion de funciones
NODO *CreaNodo (char i, int* error);
void EnlazaInterfaz(INTERFAZ *pp, INTERFAZ **ini);
void EnlazaCaracter(NODO *pp, NODO **ini);
void Borra (NODO **pp);
void BorraLista (NODO** pp);
IP* CreaIP(int* direccion, int* error);
INTERFAZ* CreaInterfaz(char* cadena, int* error);
NODO *BuscaElemento (NODO *prim, int valor_buscado);
void Configuracion(FILE *p, INTERFAZ ** lista ,int * error);
char * CreaCadena(NODO** inilista, int* error);
void ComparaEnlazaInterfaz(INTERFAZ** lista,char* nombre_interfaz,int numero_interfaces,IP* pip,int *error);
void entrada (FILE*p, INTERFAZ **lista, int *error, PAQUETE**lista_erronea);
PAQUETE* CreaPaquete(char* cadena,longitud l_real,byte * tabla, int* error);
longitud CreaLongitudLeida(byte *tabla);
void CreaDireccionOrigen(byte *tabla, byte *origen);
int ContadorLeidosMal(PAQUETE **lista);
void CreaDireccionDestino(byte *tabla, byte *destino);
void RellenaDatos(byte * datos, byte *tabla,longitud leida);
void ComparaPaqueteInterfaz(PAQUETE *paquetes,INTERFAZ** lista, int *error, PAQUETE** lista_erronea);
void EnlazaPaquete(PAQUETE *paquetes,INTERFAZ **p, PAQUETE**lista_erronea);	
void ComparaNombrePaquete(PAQUETE *paquetes, INTERFAZ** p);
void salida(char* nombrefichero,INTERFAZ **lista, PAQUETE**lista_erronea);
void ComparaDireccion(INTERFAZ** lista, int *error,FILE *p,IP* pip);
int ContadorAutoref(INTERFAZ *lista);
void BuscaDireccionInterfaz(INTERFAZ **lista,int *error);
void RecorrePuntero (FILE *p);
int ContadorNoref(INTERFAZ *lista);
void ImprimeDatosRef (FILE *psal,PAQUETE* paquetes);
void ImprimeDatosNoRef (FILE *psal,PAQUETE* paquetes);
void ImprimePaquetesErrorneos(FILE *psal,PAQUETE* f);
void libera_erronea(PAQUETE** lista);
void liberaTodo(INTERFAZ ** lista);

#endif
