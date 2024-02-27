//TRABAJO DE PROGRAMACION II
//ANDRES GARCIA-BAQUERO LEON	
#ifndef DEFINICIONES_H
#define DEFINICIONES_H

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
//nuevos tipos
typedef unsigned char byte;

typedef unsigned int longitud;

typedef struct paquete
{
  char * interfaz_origen;
  longitud long_real;
  longitud long_leida;
  byte direccion_origen[CUATRO];
  byte direccion_destino[CUATRO];
  byte *datos;
  int	error_longitud;	
  int error_autoreferencia;
  struct paquete *sig;

}PAQUETE;

typedef struct ip
{
  struct ip *sig;
  int direccion[4];
}IP;


typedef struct interfaz
{
  struct interfaz *sig;
  struct ip *psig;
  struct paquete *paqsig;
  char * nombre;
}INTERFAZ;


typedef struct nodo
{
  struct nodo *sig;
  char 	v;
}NODO;

#endif
