Part1: Part1.o Parklot.o Slot.o Ticket.o Van.o Vehicle.o System.o Sys.o
	g++ -o Part1 Part1.o Parklot.o Slot.o Ticket.o Van.o Vehicle.o System.o Sys.o

opt= -O2 -Werror -Wall -Wextra -Wconversion -Wvla -Wpedantic -std=c++11
hbj= Parklot.h Slot.h Ticket.h Van.h Vehicle.h System.h Sys.h
obj= Part1.o Parklot.o Slot.o Ticket.o Van.o Vehicle.o System.o Sys.o

Ticket.o: Ticket.cpp Ticket.h
	g++ -c Ticket.cpp $(opt)

Slot.o: Slot.cpp Slot.h Vehicle.h
	g++ -c Slot.cpp $(opt)

Parklot.o: Parklot.cpp Parklot.h Slot.h Ticket.h
	g++ -c Parklot.cpp $(opt)

Vehicle.o: Vehicle.cpp Vehicle.h
	g++ -c Vehicle.cpp $(opt)

Van.o: Van.cpp Van.h Vehicle.h
	g++ -c Van.cpp $(opt)

System.o: System.cpp $(hbj)
	g++ -c System.cpp $(opt)

Part1.o: Part1.cpp $(hbj)
	g++ -c Part1.cpp $(opt)

Sys.o: Sys.cpp Sys.h
	g++ -c Sys.cpp $(opt)

.PHONY: clean
clean: 
	-del -f $(obj) Part1
	-rm -f $(obj) Part1
