- # README for Project1

  ### Contributor： Mai Xu

  ### Directory

  - Overview

  - How to use

  - Ex.2

  - Notice

  - Bug section

  - Afterthought

    ------

  #### Overview

  For this project, I created three functions and three scripts, namely 'initialize.m', 'plate.m' , 'crossroad.m', and 'p1.m', 'traffic_light.m', 'move.m'.

  - The 'initialize' function initializes all the required parameters and provides user with three game modes.
  - The 'plate' function randomly generates a plate for each car.
  - The 'crossroad' function plots the crossroad.
  - The 'traffic_light' script controls the alternation of red, yellow and green light.
  - The 'move' script contains everything concerning car movement.

  To start the game, you have to run the 'p1' script which includes all the functions and scripts above and generates the animation. Here let me briefly explain the whole process with a simple algorithm.

  ##### Algorithm. (Project 1)

  ------

  Input: 'Road width' w ; 'Red light duration' r ; 'Orange light duration' o; 'Green light duration' g; 'Possibility of breaking traffic rules' p; 'Total number of cars' number; 'Frame per second' fps;

  Output: An animation;

  1. The user either manually input all parameters by themselves (suggested values are provided in Notice) or choose automatic mode and select difficulty level rated from 1 to 3, with 1 the most easy one. ;
  2. The system randomly generates car plates, colors, lengths and widths and store them into multiple cell arrays.
  3. Then the cars are distributed into four directions and the system calculates its initial coordinates.
  4. The main loop starts here. First we plot the crossroad and traffic lights. The traffic lights alternate its color by the time interval set by the user.
  5. Then plot the cars. Each car moves forward by 1/fps unit.
  6. Judge if any of the cars reaches the crossroad and encounters a red light. If so, stop. However, there is a possibility that it might ignore and move forward anyway.
  7. Judge if any of the cars crash into each other, if so, jump out of the loop and the game ends with the user losing the game. If not, continue.
  8. Judge if all of the cars have passed the crossroad safely, if so, jump out of the loop and the game ends with the user winning the game. If not, continue.
  9. Pause for 1/fps second.
  10. Erase all figure and go back to step 4.
  11. Display the plates of the cars that breaks the traffic rule.

  ------

  #### How to use

  The user inputs "automatic" to enter automatic mode and enter 1, 2 or 3 to select three difficulty levels. The user inputs 'manual' and define all parameters by themselves.

  #### Ex.2

  ##### Algorithm. (Random permutations.a)

  ------

  Input: a set of elements s; integer l ; function set

  Output: their permutations perm

  1. The user input a a set of elements and an integer l ;
  2. If l equals 1, perm equals s;
  3. If l exceeds 1, for i = length(perm(s,l-1)), for j = 1:length(j), set(s,n) = [perm(s,n-1),s(j)]
  4. Output perm

  ##### Algorithm. (Random permutations.b)

  ------

  Input: a set of elements; integer l ; function plates

  Output: a random subset of all the permutations containing n elements.

  1. The user input a set of elements and an integer l.
  2. Here let l be 0, n be 5. If l equals five, add a random alphabet character to the plate.
  3. If l is less than 5, let i be l+1, add a random number or alphabet character on the left of plate.
  4. Let plate be plates(i,plate).
  5. Output plate.

  #### Notice

  - The user should input integers if he/she choose to decide parameters manually.
  - Input car numbers should be less than 20 in order to prevent slow animation.
  - Road width should be less than 5 to make the animation clear and easy to read.
  - Traffic light intervals for red and green are suggested to be higher than 20 if the user wants to win this game.
  - Default fps is 6.

  #### Bug Section

  I haven't discovered any bug during operation. However, there are some potential problems. The whole animation gets a bit slow when both the number of cars (higher than 15) and fps (higher than 6) are set at a high level. Besides, there is a chance in a million that two car plates might be the same, however the chances are too little that we may as well just ignore it. In fact, the player is more likely to lose in this game if the number of cars goes up.

  #### Afterthought

  - Self learning is really helpful.
  - When encountering long lines of repeated code, it's wise to put them in one line in order to make debug process easier.
  - To make the main script more concise, separate them into several functions and scripts.
  - Cell array is a useful way to store data.
  - Make calculations as simple as possible, or the whole animation would get so slow that you might want to smash your computer.