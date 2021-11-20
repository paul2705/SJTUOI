# Onecard

Author: Mai Xu

Course: VG101 2020 Fall

Language: C

***

### Introductions

1. What is ONECARD?

   - One Card is a game played by n persons over a pre-decided number of rounds r, much like uno. A total of d decks of Poker cards, excluding Jokers, are shuffled and c cards are offered to each player. As the game starts each player, following the defined order, plays cards **either following the rank or the suit** defined by the previous card (Notice that each player can play up to **two cards**). Any played cards directly goes into the discard pile, and anyone who is unable to play should **draw a card** from the top of the stock pile. As soon as a player has discarded all his cards the game stops and the player wins this round. At the end of the r rounds the final score of each player is determined by summing up of all his penalties. The person with highest score wins.

2. How to play ONECARD?

   - General Rules: 

     •Attack:
     – Cards with rank 2: the next player draws two cards from the stock pile;
     – Cards with rank 3: the next player draws three cards from the stock pile;
     • Defense:
     – Cards with rank 7: cancel an attack, i.e. do not draw any card if a 2 or a 3 was played before;
     • Direction:
     – Queen cards: reverse the playing order from counter-clockwise to clockwise or clockwise to counterclockwise;
     – Jack cards: skip the next player;

   - Tips:

     - Each player can play up to two cards, with cards' special effect accumulated. For example, if you play Heart 2 as well as Heart 3, the next player will have to draw 5 cards if he doesn't have respective defense cards. Also if you play Spades Queen along with Spades 3, you will redirect your attack to the previous player. Other magical combinations include double Jack, where you can directly jump the next three player, or double Queen, which literally has no effect at all.  Notice that if you play cards with rank 2 or 3 in the first round, you will enter attack mode and regular cards with same suit cannot be played in the second round. 
     - You can always choose to jump your round and draw a card instead.

***

### General description:

1. To compile, please input command `gcc main.c card.c player.c action.c display.c -o onecard `.
2. After compiling, enter manual mode by simply input `onecard` in your terminal. To enter auto mode, input `onecard -a` or `onecard --auto`.
3. The parameters in the project can only be adjusted through terminal. Note that the game will perform in default parameters if no adjustment is applied. Refer to `onecard -h` or `onecard --help` for detailed information. 
4. Details of the game process are dumped into a log file called "onecard.log". Feel free to personalize the file name through command `onecard --log`.
5. Of course you can always enter the game by simply double click 'onecard.exe'.

***

### Documents

- README.md
- Changelog.md
- Project2
  - CMakeLists.txt
  - main.c
  - card.c
  - card.h
  - player.c
  - player.h
  - display.c
  - display.h
  - action.c
  - action.h
- onecard.exe

***

### How it works

- Functions and Structures used:

  1.  card.c and card.h

     - `struct CARD`: Define a structure for a card with properties rank and suit;

     - `initial_card`: Generate random DECK piles of cards;
     - `randomize`:  Randomize an array of CARD.

  2.  player.c and player.h

     - `struct PLAYER`: Define a structure for a players with properties id, score, card, length and two pointers, one pointing to the previous player, one pointing to the next;
     - `initlist`: Generate a chain array for USER players with DEFAULT cards and respective id, score, etc;
     - `sequence`: Decide the sequence of the players;
     - `deal`: Deal respective cards to each player;
     - `free_player`: Free memory used.

  3. display.c and display.h

     - `welcome`: Print welcome message;
     - `status`: Show status for human player;
     - `display`: Display the information of a card;
     - `show_status`: Show status of each player in auto mode.
     - `show_action1`: Show action of each player in  the first round;
     - `show_action2`: Show action of each player in  the second round;
     - `win`: Show the winning status;
     - `scoreboard`: Print the result of the game in each round;
     - ascii art:
       - `asciiart`: Draw a set of cards in ascii art;
       - `asciiart_demo`: Draw a single card in ascii art.
     
  4. action.c and action.h

     - `initialize`: Scan values of variables from command line;
     - `play`: Judge and play a card, a.k.a removing a certain card from the player's card pile;
     - `effect`: Show effect passed on the next player;
     - `pass`: Move to the next player;
     - `take`: Take one card from the original card pile to the player's card pile;
     - `sort`: Sort cards in a pre-decided sequence;
     - `discard`: Return the played cards to the original pile then shuffle.


***

