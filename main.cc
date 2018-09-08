#include "ascii_graphics.h"
#include <iostream>
#include <string>
#include <vector>
#include "player.h"
#include "sstream"
#include <fstream>
#include "board.h"
#include "gameover.h"
using namespace std;

void printHelp() {
  cout <<"help -- Display this message."<< endl 
  << "end -- End the current player's turn."
  << "quit -- End the game." << endl
  << "attack minion other-minion -- Orders minion to attack other-minion." << endl
  << "attack minion -- Orders minion to attack the opponent." << endl
  << "play card [target-player target-card] -- Play card, optionally targeting target-card owned by target-player." <<  endl 
  << "use minion [target-player target-card] -- Use minion's special ability, optionally targeting target-card owned by target-player." 
  << "inspect minion -- View a minion's card and all enchantments on that minion." << endl 
  << "hand -- Describe all cards in your hand." << endl
  << "board -- Describe all cards on the board." << endl;
}

int main(int argc, char * argv[]) {
  istream * is = &cin;
  ifstream fs;
  bool test_mode = false;
  string d1 = "default.deck";
  string d2 = "default.deck";
  const string init = "-init";
  const string deck1= "-deck1";
  const string deck2 = "-deck2";
  const string testing = "-testing";
  for (int x = 0; x < argc; ++x) {
    if (argv[x] == init) {
      fs = ifstream{argv[++x]};
      is = &fs;
    }
    else if (argv[x] == deck1) {
      d1 = argv[++x];
    }
    else if (argv[x] == deck2) {
      d2 = argv[++x];
    } 
    else if (argv[x] == testing) {
      test_mode = true;
    }
  }

  ifstream deckFile1{d1};
  ifstream deckFile2{d2};

  string cmd;
  int i,j;
  string s;
  cout << "Player 1: ";
  *is >> s;

  Player p1{s, 1, test_mode};
  cout << "Player 2: ";
  *is >> s;
  Player p2{s, 2, test_mode};

  p1.setEm(&p2,deckFile1); // sets decks and opponent
  cout << "Enter START to continue: " << endl;
  *is >> s;
  p2.setEm(&p1,deckFile2);
  
  Player * actp = &p1; // who's turn is it 

  Board b{&p1, &p2};	
  //b.display();
  try {
   while (true) {
    if ((*is).eof()) { is = &cin;}
    getline(*is, s); 
    istringstream iss{s};
    iss >> cmd;
    if (cmd ==  "help") {
        printHelp();
        continue;
    } else if(cmd ==  "end") {
	actp->endTurn();
        actp =  (actp == &p1)? &p2 : &p1;
	actp->startTurn();
    } else if (cmd == "quit") {
        cout << "quited" << endl;
	break;
    } else if (cmd == "draw" && test_mode) {
	actp->draw();
    } else if (cmd ==  "discard" && test_mode) {
        iss >> i;
        actp->discard(i); 
      } else if (cmd ==  "attack") { 
        if (iss >> i >> j) {
	  actp->att(i,j);
      } else {
          iss.clear();
	  actp->att(i);
      }
    } else if (cmd == "play") {
	int t; char k;
        if (iss >> i >> j >> t) {
	  actp->playCard(i,j,t);
	} else { 
	  iss.clear();
	  if (iss >> k) {
	    actp->playCard(i,j,k);
	  } else {
	    actp->playCard(i);
	  }
	} 
    } else if (cmd == "use") { 
        int t; char k;
        if (iss >> i >> j >> t) {
          actp->useCard(i,j,t);
        } else {
          iss.clear();
          if (iss >> k) {//no such card in game 
          } else {
            actp->useCard(i);
          }
        }
    } else if (cmd == "describe") {
	iss >> i;
	b.inspectMinion(actp,i);
	continue;
    } else if (cmd ==  "hand") { 
	b.displayHand(actp);
	continue;
    } else if(cmd ==  "board") {
    }
  b.display();
  }
 }
 catch(Gameover & go) {
  cout <<go.getName() << " has won!" << endl;
 }
}
    
	
	
	
	

