onecard: Main.o Sys.o Game.o UIScreen.o Card.o Pile.o User.o Operation.o
	gcc -o onecard Main.o Sys.o Game.o UIScreen.o Card.o Pile.o User.o Operation.o -O2 -O2 -Werror -Wall -Wextra -Wconversion -Wvla -Wpedantic -std=c11

opt= -O2 -Werror -Wall -Wextra -Wconversion -Wvla -Wpedantic -D _FORTIFY_SOURCE -std=c11
hbj= Sys.h Game.h UIScreen.h Operation.h User.h Pile.h Card.h
obj= Main.o Sys.o Game.o UIScreen.o Card.o Pile.o User.o Operation.o

Main.o: Main.c $(hbj)
	gcc -c Main.c $(opt)

Sys.o: Sys.c $(hbj)
	gcc -c Sys.c $(opt)

Game.o: Game.c $(hbj)
	gcc -c Game.c $(opt)

UIScreen.o: UIScreen.c $(hbj)
	gcc -c UIScreen.c $(opt)

Card.o: Card.c Card.h
	gcc -c Card.c $(opt)

Pile.o: Pile.c Pile.h Card.h
	gcc -c Pile.c $(opt)

User.o: User.c User.h Pile.h Card.h Operation.h Game.h
	gcc -c User.c $(opt)

Operation.o: Operation.c Operation.h Pile.h Card.h User.h Game.h
	gcc -c Operation.c $(opt)

.PHONY: clean
clean: 
	-del -f $(obj) onecard
	-rm -f $(obj) onecard
