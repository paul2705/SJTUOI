# OneCard

This is the project 2 for course `ENGR1510J` by Yiming Xiang(ID `521370910032`). This project is a card game based on a popular card game "Uno".

## Supporting OS

- Windows (Only tested on windows 7 and 10)
- Mac OS
- Linux

The game on all the platform is the same, so please feel free to have your own OS play this game!

## Build

You have to ensure that you have installed `gcc`, `make` and `cmake`(version>=3.5).

In the root directory of the project, run:

```
cmake ./
make
./onecard
```

If you want to add parameters, please put your parameters after `./onecard`.

## Usage

### Parameters

```
-h|--help                print this help message	
--log filename           write the logs in filename (default: onecard.log)
-n n|--player-number=n   n players, n must be larger than 2 (default: 4)
-c c|--initial-cards=c   deal c cards per player, c must be at least 2 (default: 5)
-d d|--decks=d           use d decks 52 cards each, d must be at least 2 (default: 2)
-r r|--rounds=r          play r rounds, r must be at least 1 (default: 1)
-a|--auto                run in demo mode
```

### Reminders

Once the game starts, you can see `Please let Player * play`, and you should give the console to Player \*, he should press `Enter` button to continue. After he played(if he can't play any card, the game will pass him and show that the next player should play), the game will then show `Please let Player * play`, and you should let another Player \* play.

## Rules

This OneCard game is a little bit different from normal ones. After one player plays an attack card(2 or 3), the next player can play any skill card to defend it no matter which suit it is and which type of skill it has. Also when you are under no attack and you want to draw a card(for you don't have a choice), if the new card is valid to play, the game will ask you if you want to play the new card.

### Penalty calculating method

- Skilled card: add 20
- Normal card: add the card number

## Program structure

There are 5 .c file in my program, I design their functions as follows:

- main.c: Initialize and start the big loop
- game.c: deal with global things like `get card names`, `clear screen`...
- cards.c: deal with cards like `shuffle`, `draw cards`, `insert and delete cards`...
- player.c: deal with players and their input, like `getplayer`, `print possible cards`...
- round.c: deal with rounds, like judging whether the game ends

## TO-DO

I should use a clearer program structure to design my project. Current one is not so clear because some of the functions are not easy to understand and don't have a clear goal.

