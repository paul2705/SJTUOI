#
# add your files to the _SRC lines. other lines shoudl remain untouched
#

CCC = g++
CCFLAGS = -Werror -pedantic -Wall -Wextra -Wvla -std=c++17
LIBS = -lglut -lGL 
PMS_SRC = Part1.cpp Parklot.cpp Slot.cpp Ticket.cpp Van.cpp Vehicle.cpp System.cpp Sys.cpp Car.cpp Triangle.cpp Figure.cpp Trapezium.cpp Quad.cpp Circle.cpp Group.cpp Line.cpp Semicircle.cpp Teleported.cpp Spacecraft.cpp UFO.cpp
PMS = pms
IPA_SRC = Test.cpp Triangle.cpp Figure.cpp Trapezium.cpp Quad.cpp Circle.cpp Semicircle.cpp Line.cpp Group.cpp Car.cpp Vehicle.cpp Teleported.cpp Spacecraft.cpp UFO.cpp Ticket.cpp Sys.cpp System.cpp Parklot.cpp Slot.cpp
IPA = ipa

#
# do not modify anything below
#

.PHONY: clean

all: pms ipa

pms: 
	$(CCC) $(CCFLAGS) -o $(PMS) $(PMS_SRC) $(LIBS)

ipa:
	$(CCC) $(CCFLAGS) -o $(IPA) $(IPA_SRC) $(LIBS)

clean: 
	$(RM) *.o *.a *~ $(PMS) $(IPA)