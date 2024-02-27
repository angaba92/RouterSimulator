//TRABAJO DE PROGRAMACION II
//ANDRES GARCIA-BAQUERO LEON

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "definiciones.h"
#include "funcion.h"

void libera_erronea(PAQUETE** lista)
{
  PAQUETE* l=*lista;
  PAQUETE* p=*lista;
  
  while(l->sig!=NULL)
  {
  p=p->sig;
    free(l->interfaz_origen);
    l->interfaz_origen=NULL;
    free(l);
  l=p;
  }
  free(l->interfaz_origen);
  l->interfaz_origen=NULL;
  free(l);

}

void liberaTodo(INTERFAZ ** lista)
{

INTERFAZ* l= *lista;
PAQUETE * p= NULL;
IP* pip= NULL;
INTERFAZ *f=*lista;
PAQUETE * ppaux= NULL;
IP* pipaux= NULL;
 
  while(l->sig!=NULL )
  {
  pip=l->psig;
  p=l->paqsig;
  pipaux=pip;
  ppaux=p;
    while(pip->sig!=NULL)
    {
    pipaux=pipaux->sig;
    free(pip);
    pip=pipaux;
    }
    free(pip);
    if(p!=NULL)
    { 
    while(p->sig!=NULL)
      {  
      ppaux=ppaux->sig;
      
      if(p->datos!=NULL)
      {
      free(p->datos);
      p->datos=NULL;
      }
    free(p->interfaz_origen);
	p->interfaz_origen=NULL;
      free(p);
      p=ppaux;
      }
        if(p->datos!=NULL)
        {
        free(p->datos);
        p->datos=NULL;
        }
	free(p->interfaz_origen);
	p->interfaz_origen=NULL;
    free(p);
    }
  f=l->sig;
  free(l->nombre);
  l->nombre=NULL;
  free(l);
  l=f;
  }
  
 
 if(l->sig==NULL)
{
  pip=l->psig;
  p=l->paqsig;
  pipaux=pip;
  ppaux=p;
    while(pip->sig!=NULL)
    {
    pipaux=pipaux->sig;
    free(pip);
    pip=pipaux;
    }
    free(pip);
    if(p!=NULL)
    {
    while(p->sig!=NULL)
      {  
      ppaux=ppaux->sig;
      free(p->datos);
      p->datos=NULL;
      free(p);
      p=ppaux;
      }
      free(p->interfaz_origen);
	p->interfaz_origen=NULL;
    free(p);
    
    }
    free(l->nombre);
    l->nombre=NULL;
    free(l);
    f=NULL;
    l=NULL;
    p= NULL;
    pip= NULL;
    ppaux= NULL;  
    pipaux= NULL;
}


}

void ImprimePaquetesErrorneos(FILE *psal, PAQUETE *f)
{
	
	PAQUETE* l=f;
	
	
		while(l!=NULL)
		{
		
																		
		fprintf(psal,"<!");
		fprintf(psal,"%s",l->interfaz_origen);
		fprintf(psal,"[[");
		fprintf(psal,"%d ",l->long_leida);
		fprintf(psal,"%d.%d.%d.%d ",l->direccion_origen[CERO],l->direccion_origen[UNO],l->direccion_origen[TRES-UNO],l->direccion_origen[TRES]);
		fprintf(psal,"%d.%d.%d.%d ",l->direccion_destino[CERO],l->direccion_destino[UNO],l->direccion_destino[TRES-UNO],l->direccion_destino[TRES]);
			if(l->datos!=NULL)
			{
			fprintf(psal,"%s",l->datos);
			
			}
		fprintf(psal,"]]");
		fprintf(psal,">");
		fprintf(psal,"\n");
			
		l=l->sig;
		}
		
}


void ImprimeDatosRef(FILE *psal, PAQUETE* paquetes)
{
	PAQUETE* l=paquetes;
	
	
		while(l!=NULL)
		{
		if (l->error_autoreferencia==UNO)
		{																
		fprintf(psal,"<!");
		fprintf(psal,"%s",l->interfaz_origen);
		fprintf(psal,"[[");
		fprintf(psal,"%d ",l->long_leida);
		fprintf(psal,"%d.%d.%d.%d ",l->direccion_origen[CERO],l->direccion_origen[UNO],l->direccion_origen[TRES-UNO],l->direccion_origen[TRES]);
		fprintf(psal,"%d.%d.%d.%d ",l->direccion_destino[CERO],l->direccion_destino[UNO],l->direccion_destino[TRES-UNO],l->direccion_destino[TRES]);
			if(l->datos!=NULL)
			{
			fprintf(psal,"%s",l->datos);
			
			}
		fprintf(psal,"]]");
		fprintf(psal,">");
		fprintf(psal,"\n");
		
	
		}
	
		l=l->sig;
		}
}
void ImprimeDatosNoRef(FILE *psal,PAQUETE* paquetes)
{
	
	PAQUETE* l=paquetes;
	
	
	
	while(l!=NULL)
		{
			if (l->error_autoreferencia==CERO)
			{															
		fprintf(psal,"<!");
		fprintf(psal,"%s",l->interfaz_origen);
		fprintf(psal,"[[");
		fprintf(psal,"%d ",l->long_leida);
		fprintf(psal,"%d.%d.%d.%d ",l->direccion_origen[CERO],l->direccion_origen[UNO],l->direccion_origen[TRES-UNO],l->direccion_origen[TRES]);
		fprintf(psal,"%d.%d.%d.%d ",l->direccion_destino[CERO],l->direccion_destino[UNO],l->direccion_destino[TRES-UNO],l->direccion_destino[TRES]);
			if(l->datos!=NULL)
			{
			fprintf(psal,"%s",l->datos);
			
			}
		fprintf(psal,"]]");
		fprintf(psal,">");
		fprintf(psal,"\n");
		
	
		
			}
		l=l->sig;
		}
	
	
	
}

void ComparaDireccion(INTERFAZ** lista, int *error,FILE *p, IP* pip)
{
	int i=CERO;
	INTERFAZ *l=*lista;
	IP * dipip=l->psig;
	
	while(l!=NULL && i!=TRES)
	{
		while(dipip!=NULL && i<TRES)									//bucle recorriendo las interfaces
		{
		if(dipip->direccion[i]==pip->direccion[i])i++;					//comparo posicion a posicion y utilizo i como bandera
		
		else
			{
		i=CERO;															//si no es igual, paso a la siguiente direccion ip
		dipip=dipip->sig;
			}
			
		}
	if(i!=TRES)
		{
	l=l->sig;
	if (l!=NULL)dipip=l->psig;											//paso a la siguiente interfaz
		
		}
	else
	{
		*error=ERROR;
		fprintf(stderr,"Error 3: el fichero de configuración es incorrecto.\n");
		RecorrePuntero(p);
		
	}
	
	}
}


void RecorrePuntero (FILE *p)
{
	char c;
	c=fgetc(p);
	while(c!=EOF)
	{
		c=fgetc(p);
	}


}

NODO *CreaNodo (char i, int* error)
{
  NODO *p = NULL;

  p = (NODO *) malloc(sizeof(NODO));
  if (NULL != p)
    {
      p->v = i;
      p->sig = NULL;
    }
  else
    {
      *error=ERRORESERVA;
      fprintf(stderr,"Error 6: error de memoria.\n");						//ERROR 1 en reserva dinamica
    }
  return p;
}

void EnlazaInterfaz(INTERFAZ *pinter, INTERFAZ **ini)
{
  INTERFAZ*p=NULL;
	
  if(*ini==NULL)   														//LISTA VACIA
    {
      *ini=pinter;													
		(*ini)->sig=NULL;
    }
  else 
    {
		p=*ini;
      while(p->sig!=NULL)
	{
	  p=p->sig;															//enlazo detras del ultimo
	}
      p->sig=pinter;
      pinter->sig=NULL;
    }
	
}


void EnlazaCaracter(NODO *pp, NODO **ini)
{
	
  NODO*p=NULL;
	
  if(*ini==NULL)   														//LISTA VACIA
    {
      *ini=pp;
		(*ini)->sig=NULL;		
    }
  else 
    {
      p=*ini;
      while(p->sig!=NULL)
	{
	  p=p->sig;															//enlazo detras del ultimo
	}
      p->sig=pp;
		pp->sig=NULL;
    }
	
}


void Borra (NODO **pp)
{
  NODO *paux = *pp;

  if (NULL != paux)
    {
      *pp = paux->sig; 
      free(paux);
    }
}


void BorraLista (NODO **pp)
{
  NODO *paux = NULL;
 
  while (NULL != *pp)
    {
      paux= *pp;
      *pp = (*pp)->sig;
      free(paux);
      
    }
	
}

char * CreaCadena(NODO** inilista, int* error)
{
  int i=0,j=0;
  NODO * p=*inilista;
  NODO * pant=NULL;
  char * cadena=NULL;
  while(p!=NULL)
    {
      pant=p;
      p=p->sig;															//cuento la longitud del nombre de la interfaz
      i++;
    }   
  cadena=(char*)calloc((i), sizeof(char));								//guardo memoria para la longitud contando el barra cero
  p=*inilista;
  if(cadena!=NULL)
    {	
      for(j=0;j<i;j++)
	{	
	  if(p!=NULL)
	    {
	      cadena[j]=p->v;												//copio el campo v en la cadena
	      p=p->sig;
	    }
	}
      cadena[i]='\0';
    }
  else
    {
      *error=ERRORESERVA;
      fprintf(stderr,"Error 6: error de memoria.\n");							//ERROR 1 en reserva dinamica
    }
	
  return cadena;
}	

INTERFAZ* CreaInterfaz(char* cadena, int* error)
{

  INTERFAZ* pinter=NULL;													//puntero para hacer reserva dinamica

  pinter=(INTERFAZ*)malloc(sizeof(INTERFAZ));

  if(pinter!=NULL)
    {	
      pinter->nombre=cadena;
      pinter->sig=NULL;
      pinter->psig=NULL;
      pinter->paqsig=NULL;
    }
  else
    {
      *error=ERRORESERVA;
      fprintf(stderr,"Error 6: error de memoria.\n");								//ERROR 1 en reserva dinamica
    }



  return pinter;
  
}
longitud CreaLongitudLeida(byte *tabla)
{
	
	longitud suma=0;
	suma=tabla[CERO]*UNO+tabla[UNO]*HEX+tabla[UNO+UNO]*HEX*HEX+tabla[TRES]*HEX*HEX*HEX;
	return suma;
}

void CreaDireccionOrigen(byte *tabla, byte* origen)
{
	int i,j;
	
	for(i=SIETE,j=0;i>=CUATRO;i--,j++)
	{
	origen[j]=tabla[i];
		
	}
	
	
	

}

 void CreaDireccionDestino(byte *tabla,byte *destino)
{
	int i,j;
	
	for(i=ONCE,j=0;i>=SIETE+1;i--,j++)
	{
	destino[j]=tabla[i];
		
	}
		
	
}


PAQUETE* CreaPaquete(char* cadena,longitud l_real, byte* tabla, int* error)
{
	
	PAQUETE* ppaq=NULL;													//puntero para hacer reserva dinamica
	longitud l_leida;													//unsigned int que recoje la longitud leida
														
	
	ppaq=(PAQUETE*)malloc(sizeof(PAQUETE));

  if(ppaq!=NULL)
    {	
		l_leida=CreaLongitudLeida(tabla);
		if(l_leida!=l_real)ppaq->error_longitud=CERO;					//compruebo si la longitud leida y la real son iguales
		else
		{
		ppaq->error_longitud=UNO;
		}
		CreaDireccionOrigen(tabla,ppaq->direccion_origen);				//guardo en cada campo los correspondientes datos
		CreaDireccionDestino(tabla,ppaq->direccion_destino);
		ppaq->interfaz_origen=cadena;
		cadena=NULL;
		ppaq->long_real=l_real;
		ppaq->sig=NULL;
		ppaq->long_leida=l_leida;
		
	if(l_real!=ONCE+1)
	{
		ppaq->datos=(byte*)calloc((l_real-12),sizeof(byte));
		if((ppaq->datos)!=NULL)
		{																//relleno el campo datos
		RellenaDatos(ppaq->datos,tabla,l_leida);
		
		}
		else
		{
			*error=ERRORESERVA;
			fprintf(stderr,"Error 6: error de memoria.\n");				//ERROR 1 en reserva dinamica
		}
	}
	else
	{
		ppaq->datos=NULL;
	}	
    
    }
  else
    {
      *error=ERRORESERVA;
      fprintf(stderr,"Error 6: error de memoria.\n");							//ERROR 1 en reserva dinamica
    }



  return ppaq;
}

void RellenaDatos(byte * datos, byte *tabla,longitud leida )
{

	longitud  i=0;
	int j=0;
	for(i=ONCE+1,j=0;i<leida;i++,j++)
	{
	datos[j]=tabla[i];
	}


}

IP* CreaIP(int* direccion, int* error)
{

  IP* pip=NULL;															//puntero para hacer reserva dinamica
  int i;
  pip=(IP*)malloc(sizeof(IP));

  if(pip!=NULL)
    {	
      for(i=0;i<4;i++)
	{
	  pip->direccion[i]=direccion[i];									//copio dirip en el nodo tipo  IP, para su posterior enlace
		
	}
      pip->sig=NULL;
    }
	
  else
    {
      *error=ERRORESERVA;
      fprintf(stderr,"Error 6: error de memoria.\n");					//ERROR 1 en reserva dinamica
    }



  return pip;
	
}

void ComparaEnlazaInterfaz(INTERFAZ** lista,char* nombre_interfaz,int numero_interfaces,IP* pip, int *error)
{

  int i=0;
  INTERFAZ *l=*lista;
  IP * r=NULL;
  

  while(i<numero_interfaces && strcmp(nombre_interfaz,l->nombre)!=CERO  )
    {
																		//mientras q no sean iguales y el contador no sea el numero de nodos entro
      l=l->sig;
      i++;
    }
  if(l==NULL)
	{
  fprintf(stderr,"Error 3: el fichero de configuración es incorrecto.\n");
  
  *error=ERROR;	
  
  	}
  else
   {
	if(l->psig==NULL)
		{
      l->psig=pip;														//enlazo si lo ha encontrado
		}
    else
    {
		r=l->psig;
		while(r->sig!=NULL)
		{
		r=r->sig;
		}
		r->sig=pip;														//enlazo aqui si tiene mas de una direccion
	}
   }
    
    
}

void EnlazaPaquete(PAQUETE *paquetes,INTERFAZ **p, PAQUETE**lista_erronea)
{
	
	
	PAQUETE*f=NULL;
	
	if(paquetes->error_longitud==CERO)
	{
	if(*lista_erronea==NULL)
		{
		
		*lista_erronea=paquetes;										//lista de paquetes erroneos
		}
		else
		{
		f=*lista_erronea;
		while(f->sig!=NULL)
			{
			f=f->sig;
			}
		f->sig=paquetes;
		}	
			
	}
	else
	{
	
	
		if((*p)->paqsig==NULL)   												//LISTA VACIA
		{
			(*p)->paqsig=paquetes;
			((*p)->paqsig)->sig=NULL;		
		}
		else 
		{
			f=(*p)->paqsig;
			while(f->sig!=NULL)
			{
			f=f->sig;															//enlazo detras del ultimo
			}
				
			f->sig=paquetes;
			paquetes->sig=NULL;
			
				
		}
			
			
	
	
	}
	
}

int ContadorAutoref(INTERFAZ *lista)
{
	
	int contador=0;
	INTERFAZ *p=lista;
	PAQUETE *f=NULL;
	
	
	
	    f=p->paqsig;
		while(f!=NULL)													//bucle recorriendo las interfaces
		{
		  if(f->error_autoreferencia==UNO)
            contador++;						                          	//comparo el campo de autoreferencia 
		                                                                //si no es igual, paso a la siguiente direccion ip
		  f=f->sig;
		}
		
	
	return contador;
}

int ContadorLeidosMal(PAQUETE **lista)
{
	int contador=0;
	
	PAQUETE *f=*lista;
	
  
		while(f!=NULL)													//bucle recorriendo las interfaces
		{
		  
            contador++;						                          	//comparo el campo de autoreferencia 
		                                                                //si no es igual, paso al siguiente paquete
		  f=f->sig;
		}
		
	
	return contador;	
		
}

int ContadorNoref(INTERFAZ *lista)
{
	
	int contador=0;
	INTERFAZ *p=lista;
	PAQUETE *f=NULL;
	
	
	
	    f=p->paqsig;
		while(f!=NULL)													//bucle recorriendo las interfaces
		{
		  if(f->error_autoreferencia==CERO)
            contador++;						                          	//comparo el campo de autoreferencia 
		                                                                //si no es igual, paso a la siguiente direccion ip
		  f=f->sig;
		}
		
	
	return contador;
}

void ComparaPaqueteInterfaz(PAQUETE *paquetes,INTERFAZ** lista, int *error, PAQUETE** lista_erronea)
{
	int  i=0;
	INTERFAZ *p=*lista;
	IP *f=p->psig;
	INTERFAZ *e=*lista;
	PAQUETE *l=NULL;
	*error=CERO;
	
	while(p!=NULL && i!=TRES)
	{
		while(f!=NULL && i<TRES)										//bucle recorriendo las interfaces
		{
		if(paquetes->direccion_destino[i]==f->direccion[i])i++;			//comparo posicion a posicion y utilizo i como bandera
		
		else
			{
		i=CERO;															//si no es igual, paso a la siguiente direccion ip
		f=f->sig;
			}
			
		}
	if(i!=TRES)
		{
	p=p->sig;
	if (p!=NULL)f=p->psig;												//paso a la siguiente interfaz
		
		}
		
	
	}
	if(p!=NULL)
	{
	EnlazaPaquete(paquetes,&p,lista_erronea);
	ComparaNombrePaquete(paquetes,&p);	
	}
	else
	{
	
	if(e->paqsig==NULL)
		{
		
		e->paqsig=paquetes;
		(e->paqsig)->sig=NULL;											//lista de paquetes vacia
		}
	else
		{
		l=e->paqsig;
      while((l->sig)!=NULL)
	{
	  l=l->sig;															//enlazo detras del ultimo
	}
		l->sig=paquetes;
		paquetes->sig=NULL;
		}
	}	
	
}

void BuscaDireccionInterfaz(INTERFAZ **lista,int *error)
{
	IP *pip=NULL;
	INTERFAZ* l=*lista;
	int flag=UNO;
	pip=l->psig;
	
	while(l!=NULL && flag==UNO)
	{
			if(pip==NULL)
			{
			*error=ERROR;
			fprintf(stderr,"Error 3: el fichero de configuración es incorrecto.\n");
			flag=CERO;
			}
		
		else 
		{
			if(l!=NULL)
			{
			l=l->sig;
			
			if(l!=NULL)pip=l->psig;
			}
			
		}
	}
	
	
}

void ComparaNombrePaquete(PAQUETE *paquetes, INTERFAZ** p)
{
	
	if(strcmp(paquetes->interfaz_origen,(*p)->nombre)==CERO)			//comparo el nombre de la interfaz y del paquete
	{
		paquetes->error_autoreferencia=CERO;								//si coinciden autoreferencia vale uno, sino cero
		
	}
	else
	{
		paquetes->error_autoreferencia=UNO;
	}
	


	
}
	



void Configuracion(FILE *p, INTERFAZ ** lista ,int * error)
{
  int i=CERO, puntuacion;													//contador generico
  NODO* ini=NULL;
  NODO* pp=NULL;
  IP* pip=NULL;
  INTERFAZ* pinterfaz=NULL;
  char * cadena=NULL;													//puntero a char que recoje la cadena del nombre
  int num_inter;														//numero de interfaces
  char caracter,car1;													//caracter leido del nombre de la interfaz
  int dirip[CUATRO];													//cadena q recoje la direccion leida
  int contador_interfaces=CERO;
  if(fscanf(p,"%d",&num_inter)!=UNO)									//leo el numero de interfaces 	
    {
      *error=ERROR;
      fprintf(stderr,"Error 3: el fichero de configuración es incorrecto.\n");
     
    }
  else
    {  
      while(!feof(p))													//obvio los espacios, tabulaciones  y retornos de carro
	  {	
	    caracter=fgetc(p);
	  	
	    while((caracter!=N && caracter!=R))
	    {
			puntuacion=isspace(caracter);
	      
	      while(puntuacion!=CERO)
		{
		  caracter=fgetc(p);	
			puntuacion=isspace(caracter);
		}
	      
	      fseek(p, desplazamiento , SEEK_CUR);							//retraso el puntero para que apunte al principio del nombre de la interfaz
	      while (isspace(caracter)==CERO)
																		//en este bucle, leo caracteres y creo el nombre de su interfaz correspondiente
		{										
		  caracter=fgetc(p);
			
		  if(isspace(caracter)==CERO)
		    {
		      pp=CreaNodo(caracter,error);
		      EnlazaCaracter(pp, &ini);									//creo el nodo con la letra y enlazo
		    }
			
		}
	       
	      cadena=CreaCadena(&ini,error);								//paso los nodos a cadena
	      BorraLista(&ini);												//libero
	      pinterfaz=CreaInterfaz(cadena,error);							//creo la interfaz	
	      EnlazaInterfaz(pinterfaz,lista);								//enlazo la interfaz
	      contador_interfaces++;										//cada vez que creo una, se incrementa en 1
			cadena=NULL;												//libero el puntero para utilizarlo posteriormente
	    }
	
		
      if(contador_interfaces!=num_inter)
	  {
	   *error=ERROR;													//compruebo si las interfacez coinciden con el numero leido
	    fprintf(stderr,"Error 3: el fichero de configuración es incorrecto.\n");
	    
		RecorrePuntero(p);
	  }
      else 
	  {
		
		
			while(fscanf(p,"%d.%d.%d.%d",&(dirip[i]),&(dirip[i+1]),&(dirip[i+2]),&(dirip[i+3]))==4)	//leo la direccion ip
		 	{   
				if(fgetc(p)=='.')RecorrePuntero(p);
				
	         else if(dirip[i+TRES]!=CERO || dirip[CERO]>MAXDIR)
				{
              *error=ERROR;
              fprintf(stderr,"Error 3: el fichero de configuración es incorrecto.\n");
																							//compruebo que es correcta
				RecorrePuntero(p);
				}	
	         else
		     {
		 
			  pip=CreaIP(dirip,error);									//creo el nodo ip
			  car1=fgetc(p); 
		      while((car1!=N && car1!=R))
	          {
			    puntuacion=isspace(car1);
	      
	            while(puntuacion!=CERO)
		        {																//ignora blanco y retornos de carro
		         car1=fgetc(p);	
			     puntuacion=isspace(car1);
		        }
	      
	            fseek(p, desplazamiento , SEEK_CUR);							//retraso el puntero para que apunte al principio del nombre de la interfaz
	            while (isspace(car1)==CERO)
																		//en este bucle, leo caracteres y creo el nombre de su interfaz correspondiente
		        {										
		          car1=fgetc(p);
			
		          if(isspace(car1)==CERO)
		          {
		           pp=CreaNodo(car1,error);
		           EnlazaCaracter(pp, &ini);									//creo el nodo con la letra y enlazo
		          }
			
		        }
	       
	            cadena=CreaCadena(&ini,error);							//paso los nodos a cadena
	            BorraLista(&ini);										//libero
				ComparaDireccion(lista,error,p,pip);					//compruebo si estan repetidas
	            ComparaEnlazaInterfaz(lista,cadena,contador_interfaces,pip, error);	//comparo los nombres de las dos interfaces,si son iguales, le meto la direccion ip a esa interfaz
	            free(cadena);
				cadena=NULL;
	    		if(*error==ERROR)RecorrePuntero(p);
		      }			
						
	         }
		    }
		    
	  }

				}
				
	}if(*error!=ERROR)BuscaDireccionInterfaz(lista,error);
	

}
	


void entrada (FILE*p, INTERFAZ **lista, int *error, PAQUETE**lista_erronea)
{
  int i=0;
  NODO* pn=NULL;
  NODO*inin=NULL;
  char* cadena1;
  char car2;
  PAQUETE* paquetes=NULL;
  byte octetos[TAM_MAX];
  longitud i_long;
	
	
	fread(&car2,sizeof(char),UNO,p);										//lectura previa del <
	while(!feof(p)||(int)error==(int)ERRORESERVA)									//bucle hasta fin de fichero
    {
      	
	  fread(&car2,sizeof(char),UNO,p);										//leo el !
	  while(car2!='[' || (int)error==(int)ERRORESERVA)							//bucle hasta que termine de leer el nombre
	    {																//creo el nodo con la letra y enlazo
	    
	    
	      car2=fgetc(p);
	      if(car2!='[')
			{
	      pn=CreaNodo(car2,error);
	      EnlazaCaracter(pn, &inin);
			}
					
	    }
		cadena1=CreaCadena(&inin,error);								//paso los nodos a cadena
		
		BorraLista(&inin);												//libero
		fread(&car2,sizeof(char),UNO,p);									//leo el [
		
	  while((car2!=N && car2!=R))	
	    {
	      for(i=CERO;(octetos[i-UNO]!='>')&&(i<TAM_MAX) ;i++)				//voy guardando en octetos todos los campos del fichero 
		{
			car2=octetos[i];
			fread(&octetos[i],sizeof(byte),UNO,p);
			
		}
			fread(&car2,sizeof(byte),UNO,p);
	      i_long=i-TRES;
			
	    }
	 
		paquetes=CreaPaquete(cadena1,i_long,octetos,error);	//creo el paquete con su nombre y longitud real
		
		cadena1=NULL;	  
		ComparaPaqueteInterfaz(paquetes,lista,error,lista_erronea);
	  
		fread(&car2,sizeof(char),UNO,p);									//lectura previa del <
	}
       
}
	
void salida(char* nombre_fichero,INTERFAZ **lista, PAQUETE** lista_erronea)
{
	
	FILE* psal=NULL;
	int autoref=0,noref=0,leidos_mal=0;
	INTERFAZ *p=*lista;
	PAQUETE* f=*lista_erronea;
	
	psal=fopen(nombre_fichero,"w");
	if(psal==NULL)fprintf(stderr,"Error 5: el fichero de salida no se puede abrir.\n");
	else
	{
		while(p!=NULL)													//bucle recorriendo la lista
		{
			autoref=ContadorAutoref(p);
			fprintf(psal,"numero de paquetes reenviados por la interfaz %s: %d\n", p->nombre, autoref);
			
				if(autoref!=CERO)
				{
				ImprimeDatosRef(psal,p->paqsig);
				
				}
			noref=ContadorNoref(p);
			fprintf(psal,"\n");	
			fprintf(psal,"numero de paquetes no reenviados por la interfaz %s: %d\n", p->nombre, noref);
			
			if(noref!=CERO)
				{
				ImprimeDatosNoRef(psal,p->paqsig);
				
				}
			p=p->sig;
			fprintf(psal,"\n");
		}
		p=*lista;														//sino lo pongo violacion de segmento
		leidos_mal=ContadorLeidosMal(lista_erronea);
		fprintf(psal,"numero de paquetes erroneos que llegan al Sistema de Reenvio: %d\n", leidos_mal);
		ImprimePaquetesErrorneos(psal,f);
		fprintf(psal,"\n");
		liberaTodo(lista);
		if(f!=NULL)
		libera_erronea(lista_erronea);
		
	}





}
