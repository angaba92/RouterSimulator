//TRABAJO DE PROGRAMACION II
//ANDRES GARCIA-BAQUERO LEON
#include <stdio.h>
#include <stdlib.h>
#include "definiciones.h"
#include "funcion.h"

int main(int argc, char** argv)
{
	FILE* fich=NULL;
	INTERFAZ*lista=NULL;
	int error;
	FILE *p=NULL;
	PAQUETE *lista_erronea=NULL;
	
  if(argc!=CUATRO)fprintf(stderr,"Error 1: argumentos incorrectos.\n");
  
  else
    
    {
      fich=fopen(argv[UNO],"r");
      if(!fich)fprintf(stderr,"Error 2: el fichero de configuración no se puede leer.\n");
      else
	{
	  Configuracion(fich,&lista,&error);
	  fclose(fich);
	  if(error==ERROR);
	  else if(error==ERRORESERVA);
	  
	  else
	 { 
		p=fopen(argv[TRES-UNO],"r");
		if(!p)fprintf(stderr,"Error 4: el fichero de entrada no se puede leer.\n");
		else
	{
	  entrada(p,&lista,&error,&lista_erronea);
	  
	  fclose(p);
	  salida(argv[TRES],&lista,&lista_erronea);
	  
	  
	}
	}		
			
		
	}
		
    }

  return CERO;

}
