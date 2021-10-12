Main: Main.o Game.o Card.o Pile.o User.o Operation.o
	gcc -o Main Main.o Game.o Card.o Pile.o User.o Operation.o

obj= Game.h Operation.h User.h Pile.h Card.h

Main.o: Main.c $(obj)
	gcc -c Main.c

Game.o: Game.c $(obj)
	gcc -c Game.c

Card.o: Card.c Card.h
	gcc -c Card.c 

Pile.o: Pile.c Pile.h Card.h
	gcc -c Pile.c

User.o: User.c User.h Pile.h Card.h
	gcc -c User.c

Operation.o: Operation.c Operation.h Pile.h Card.h User.h Game.h
	gcc -c Operation.c
