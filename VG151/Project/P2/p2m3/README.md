# Introduction

`Onecard` is a local game that almost simulates the popular card game `UNO`. The game `Onecard` have `n` players, `r` rounds and `d` decks of cards to be used. During each round, every player draws `c` cards initially, and ought to draw one card each turn but could be skipped by playing certain cards.



# Build

*   Download the file `p2m3`
*   This project requires 
    *   a `C complier` already defining one of the items listed following:
        *   `_WIN32`
        *   `__APPLE__`
        *   `__linux__`
        *   `__unix__` *(not recommended)*
    *    a `make` executiable item to run the code in the `makefile` file, like:
        *   terminal code `make` in `linux` or `apple`
        *   executiable item `mingw64-make.exe` in `windows`



# Get started

*   Locate the file `p2m3` at any path
*   Prompt `make` in terminal (linux or apple) or `mingw64-make` in command (windows)
*   Run the executiable file `onecard` to start the game
    *   If you run `onecard` in a terminal window, you could prompt more options to modify the upcoming game.
        *   `-h`|--help 
            *   print the help message
        *   `--log filename`
            *   write the logs in filename (default: onecard.log)
        *   `-n n`|--player-number=n 
            *   `n` players, n must be larger than 2 (default: 4)
        *   `-c c`|--initial-cards=c 
            *   deal `c` cards per player, `c` must be at least 2 (default: 5)
        *   `-d d`|--decks=d
            *   use `d` decks 52 cards each, `d` must be at least 2 (default: 2)
        *   `-r r`|--rounds=r 
            *   play `r` rounds, `r` must be at least 1 (default: 1)
        *   `-a`|--auto
            *   run in demo mode



# During the Game

*   You could simply follow the suggestions popped up whenever you need to make choices.



# Data Structure

![DataStructure](/Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/P2/p2m3/DataStructure.png)



