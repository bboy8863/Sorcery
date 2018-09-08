#include "board.h"
#include "ascii_graphics.h"
#include <iostream>
#include "card.h"
#include "enchantment.h"
using namespace std;

Board::Board(Player * p1, Player * p2): p1{p1}, p2{p2}{}

void Board::display() {
	//top border
	cout << EXTERNAL_BORDER_CHAR_TOP_LEFT;
	const int topB = 165;
	for (int i = 0; i < topB; ++i) {
		cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
	}
	cout << EXTERNAL_BORDER_CHAR_TOP_RIGHT << endl;
	

	card_template_t ritTemp = p1->ritual ? 
	   p1->ritual->makeTemplate() : CARD_TEMPLATE_BORDER;//ritual
	card_template_t empty = CARD_TEMPLATE_EMPTY;
	card_template_t playerTemp = display_player_card(1,p1->name,p1->life,p1->magic);
	card_template_t grave = (p1->grave.empty())? 
	  CARD_TEMPLATE_BORDER: p1->grave.back()->makeTemplate();//grave
	
	// print ritual player card and grave for p1

	for (int i=0; i < 11; ++i) {
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN<< ritTemp[i] 
		  << empty[i] << playerTemp[i] << empty[i] << 
		  grave[i]<< EXTERNAL_BORDER_CHAR_UP_DOWN << endl;
	}
	
	
	vector <card_template_t> tm;//for the field
	int l = p1->field.size();
	for (int i = 0; i < 5; ++i) {
		if (i < l) {
			tm.emplace_back(p1->field[i]->makeTemplate());
		} else {
			tm.emplace_back(CARD_TEMPLATE_BORDER);
		}
	}
			
	const int templateSize=tm[0].size();
	for (int i = 0; i < templateSize; ++i) {
		cout<<EXTERNAL_BORDER_CHAR_UP_DOWN << tm[0][i]<< 
		  tm[1][i]<<tm[2][i]<<tm[3][i]<<tm[4][i]<< 
		  EXTERNAL_BORDER_CHAR_UP_DOWN <<endl;
	}
		
	for (auto &b : CENTRE_GRAPHIC) { cout << b << endl;}// center graphic
	
	tm.clear();
	l = p2->field.size();
	for (int i = 0; i < 5; ++i) {
                if (i < l) {
                        tm.emplace_back(p2->field[i]->makeTemplate());
                } else {
                        tm.emplace_back(CARD_TEMPLATE_BORDER);
                }
        }
        for (int i = 0; i < templateSize; ++i) {
                cout<<EXTERNAL_BORDER_CHAR_UP_DOWN << tm[0][i]<<
                  tm[1][i]<<tm[2][i]<<tm[3][i]<<tm[4][i]<<
                   EXTERNAL_BORDER_CHAR_UP_DOWN <<endl;
        }

	ritTemp = p2->ritual ?
           p2->ritual->makeTemplate() : CARD_TEMPLATE_BORDER;//ritual
        empty = CARD_TEMPLATE_EMPTY;
        playerTemp = display_player_card(2,p2->name,p2->life,p2->magic);
        grave = (p2->grave.empty())?
          CARD_TEMPLATE_BORDER: p2->grave.back()->makeTemplate();//grave

        // print ritual player card and grave for p2

        for (int i = 0; i < 11; ++i) {
                cout << EXTERNAL_BORDER_CHAR_UP_DOWN<< ritTemp[i]
                  << empty[i] << playerTemp[i] << empty[i] <<
                  grave[i]<< EXTERNAL_BORDER_CHAR_UP_DOWN << endl;
        }
	cout << EXTERNAL_BORDER_CHAR_BOTTOM_LEFT;
        for (int i = 0; i < topB; ++i) {
                cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
        }
        cout << EXTERNAL_BORDER_CHAR_BOTTOM_RIGHT << endl;



}

void Board::displayHand(Player * actp) {
	vector <card_template_t> tm;//for the field
        int l = actp->hand.size();
        for (int i = 0; i < 5; ++i) {
                if (i < l) {
                        tm.emplace_back(actp->hand[i]->makeTemplate());
                } else {
                        tm.emplace_back(CARD_TEMPLATE_BORDER);
                }
        }
	
	const int templateSize=tm[0].size();
	
	for (int i = 0; i < templateSize; ++i) {
                cout<< tm[0][i]<<
                  tm[1][i]<<tm[2][i]<<tm[3][i]<<tm[4][i]<<endl;
        }
}
	
	
void Board::inspectMinion(Player * actp, int i) {
	--i;
	vector <shared_ptr<Enchantment>> v = actp->field[i]->inspect(actp->field[i]);
	//minion card
	card_template_t t = actp->field[i]->makeTemplate();
	for (auto &b : t) {
        	cout << b << endl;
        }
	vector <card_template_t> tm;
	for (int i = 0; i < v.size();) {
		for (int j = 0; j < 5; ++j) {
			if (i < v.size()) {
                	        tm.emplace_back(v[i]->displaySelf());
	                } else {
        		        tm.emplace_back(CARD_TEMPLATE_EMPTY);
			}
			++i;
                }
		for (int c = 0; c < 11; ++c) {
			cout<< tm[0][c]<<
                  	tm[1][c]<<tm[2][c]<<tm[3][c]<<tm[4][c]<<endl;
			
		}
		tm.clear();
	}	
	
}	 




















