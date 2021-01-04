CC=gcc
AR=ar
OBJECTS_TXT=txtfind.o
OBJECTS_ISORT=isort.o
FLAGS= -Wall -g

all: isort txtfind
isort: $(OBJECTS_ISORT) isort.a
	$(CC) $(FLAGS) -o isort $(OBJECTS_ISORT) isort.a
txtfind: $(OBJECTS_TXT) txtfind.a 
	$(CC) $(FLAGS) -o txtfind $(OBJECTS_TXT) txtfind.a 
isort.a: $(OBJECTS_ISORT)
	$(AR) -rcs isort.a $(OBJECTS_ISORT)
txtfind.a: $(OBJECTS_TXT)
	$(AR) -rcs txtfind.a $(OBJECTS_TXT)
isort.o: isort.c 
	$(CC) $(FLAGS) -c isort.c
txtfind.o: txtfind.c 
	$(CC) $(FLAGS) -c txtfind.c 
clean:
	rm -f *.o *.a *.so isort txtfind