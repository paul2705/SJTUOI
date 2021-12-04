All: Part1 Test

    Part1: Part1.o Parklot.o Slot.o Ticket.o Van.o Vehicle.o System.o Sys.o
	g++ -o Part1 Part1.o Parklot.o Slot.o Ticket.o Van.o Vehicle.o System.o Sys.o

    Test: Test.o Triangle.o Figure.o
	g++ -o Test Test.o Triangle.o Figure.o -framework OpenGL \-framework GLUT

opt= -O2 -Werror -Wall -Wextra -Wconversion -Wvla -Wpedantic -std=c++11
hbj= Parklot.h Slot.h Ticket.h Van.h Vehicle.h System.h Sys.h
obj= Part1.o Parklot.o Slot.o Ticket.o Van.o Vehicle.o System.o Sys.o Test.o Triangle.o Figure.o

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

Figure.o: Figure.cpp Figure.h
	g++ -c Figure.cpp -framework OpenGL \-framework GLUT

Triangle.o: Triangle.cpp Triangle.h Figure.h
	g++ -c Triangle.cpp -framework OpenGL \-framework GLUT

Test.o: Test.cpp Figure.h Triangle.h
	g++ -c Test.cpp -framework OpenGL \-framework GLUT

.PHONY: clean
clean: 
	-del -f $(obj) Part1 Test
	-rm -f $(obj) Part1 Test
