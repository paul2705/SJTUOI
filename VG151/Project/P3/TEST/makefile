All: Test

    Test: Test.o Quad.o Figure.o
	g++ -o Test Test.o Quad.o Figure.o -framework OpenGL \-framework GLUT

opt= -Werror -pedantic -Wall -Wextra -Wvla -std=c++17
hbj= 
obj= Test.o Quad.o Figure.o

Figure.o: Figure.cpp Figure.h
	g++ -c Figure.cpp -framework OpenGL \-framework GLUT

Quad.o: Trapezium.cpp Quad.h Figure.h
	g++ -c Quad.cpp -framework OpenGL \-framework GLUT

Test.o: Test.cpp Figure.h Quad.h
	g++ -c Test.cpp -framework OpenGL \-framework GLUT

.PHONY: clean
clean: 
	-del -f $(obj) Test
	-rm -f $(obj) Test
