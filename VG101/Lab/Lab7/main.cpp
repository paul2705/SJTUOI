#include <iostream>
#include <string>
#include <chrono>
#include "lab7.h"
#include<vector>


using namespace std;
vector<int> my,opp;

#define REITER vector<int>::reverse_iterator
/**
 * The main function, you do not need to change this.
 * All inputs and outputs are taken care of here.
 * @return
 */
int main(int argc, char *argv[]) {
    if (argc == 2 && string(argv[1]) == "-r") {
        // Race mode, used by server to compete with each other
        Game &game = *getMyGame();
        Brain &brain = *getMyBrain();

        int myX, myY, oppX, oppY;
        cin >> myX >> myY;
        cin >> oppX >> oppY;

        int myD, oppD;
        cin >> myD >> oppD;

        game.initialize(myX, myY, oppX, oppY, Direction(myD), Direction(oppD));
        brain.initialize();

        Turn turn_status=T_Cont;

        do {
            Move m = brain.judge();
            cout << int(m) << endl;

            int oppMove;
            cin >> oppMove;

            game.move(Tank_A, m);
            game.move(Tank_B, Move(oppMove));
        } while ((turn_status = game.turn()) == T_Cont);

        switch (turn_status) {
            case T_A_Win:
                cout << "Tank A Wins" << endl;
                system("Pause");
                break;
            case T_B_Win:
                cout << "Tank B Wins" << endl;
                system("Pause");
                break;
            case T_Draw:
                cout << "Draw" << endl;
                system("Pause");
                break;
            case T_Cont:
                cout << "Something Wrong Happened" << endl;
                break;
        }
    } else {
        Game &game = *getMyGame();
        Brain &brain = *getMyBrain();

        int myX, myY, oppX, oppY;
        cin >> myX >> myY; 
        cin >> oppX >> oppY; 

        int myD, oppD;
        cin >> myD >> oppD;
        game.initialize(myX, myY, oppX, oppY, Direction(myD), Direction(oppD));
        brain.initialize();

        Turn turn_status=T_Cont;

        do {
            Move m = brain.judge();
            cout<<int(m)<<endl;
            
            game.GetMap();
            cerr << game.draw();
            auto start = chrono::steady_clock::now();
            while (chrono::duration<double>(chrono::steady_clock::now() - start).count() < 0.2);

            int myMove;
            cin >> myMove; my.push_back(myMove);

            int oppMove;
            cin >> oppMove; opp.push_back(oppMove);

            game.move(Tank_A, Move(m));
            game.move(Tank_B, Move(oppMove));
        } while ((turn_status = game.turn()) == T_Cont);

        switch (turn_status) {
            case T_A_Win:
                cout << "Tank A Wins" << endl;
                system("Pause");
                break;
            case T_B_Win:
                cout << "Tank B Wins" << endl;
                system("Pause");
                break;
            case T_Draw:
                cout << "Draw" << endl;
                system("Pause");
                break;
            case T_Cont:
                cout << "Something Wrong Happened" << endl;
                break;
        }
        /*for (REITER myit=my.rbegin(),oppit=opp.rbegin();myit!=my.rend();myit++,oppit++){
            cerr << game.draw();
            cerr<<endl;
            auto start = chrono::steady_clock::now();
            while (chrono::duration<double>(chrono::steady_clock::now() - start).count() < 0.2);

            game.DTurn();
            game.Dmove(Tank_A, Move(*myit));
            game.Dmove(Tank_B, Move(*oppit));
        }*/
    }
    return 0;
}

