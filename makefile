

GCC= gcc
WALL= -W -Wall 
PRINCIPAL = main
FUNCION = funcion

$(PRINCIPAL):	$(PRINCIPAL).o $(FUNCION).o
	$(GCC) $(WALL) -g -o $(PRINCIPAL) $(PRINCIPAL).o $(FUNCION).o

$(PRINCIPAL).o: $(PRINCIPAL).c definiciones.h
	$(GCC) $(WALL) -g -c $(PRINCIPAL).c

$(FUNCION).o:	$(FUNCION).c $(FUNCION).h
	$(GCC) $(WALL) -g -c $(FUNCION).c