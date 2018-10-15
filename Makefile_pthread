all : pthread_create

pthread_create: main.o
	g++ -g -o pthread_create main.o -lpthread

main.o:
	g++ -g -c -o main.o main.cpp

clean:
	rm -f pthread_create
	rm -f *.o


