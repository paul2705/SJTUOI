# Parking lot simulation

Author: Pgroup24

Course: VG101 2020 Fall

Language: C++

***

### General description:

1. Use the CMakelists.txt to compile;
2. After running, enter an **even** number of slots (**>=12**) in the standard input area;  (user interface)
3. For part 1, each ticket will be printed at constant interval, so please be patient until the whole process ends;
4. For part 2, each function is controlled within 50 lines and each class is allocated  in proper order; (bonus 1)
5. For part 2, a flag is added on the car which moves up and down constantly; (bonus 2)  
6. For part 2, complex drawing involved, a teleporter is consisted of size-changing polygon. (bonus 3)
7. For part 2, a singleton is implemented which avoids constantly constructing and destroying objects; (bonus 4)
8. For part 2, each vehicle follows a complex but smooth trajectory which avoids overlapping with slot verge lines.
9. For part 2, the animation won't stop automatically; 

extra advance:
1. For part 1, each vehicle will cry if it has to enter the queuing line;
2. For part 1, each vehicle has its own plate whose length is related to its car type;
3. For part 2, each vehicle can automatically speed up or slow down when it is leaving or stopping, which makes their move more nature. (**We believe it deserves a bonus!**)

***

### Documents

- README.md
- Changelog.md
- Project3
  - CMakeLists.txt
  - part1.c
  - part2.c
  - vehicle.c
  - vehicle.h
  - coloredFig.c
  - coloredFig.h
  - parkingLot.c
  - parkingLot.h

***

### Task allocation

Mai Xu: Regular Parking lot; README; CHANGELOG; Hierarchy Diagram; basic class and structures of shape and parking lot; 

Qi Ling: Regular Parking lot;  Singleton; basic structures for vehicles and parking lot; calculation of traces and respective movement.

Haomiao Xu: Most part of drawings of the vehicles;

Fan Hu: Most part of calculation of traces.