#include <iostream>
#include <stdlib.h>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <iterator>

#define HEART "H" // Copas
#define CLUB "C" // Paus
#define DIAMOND "D" // Ouro
#define SPADE "S" // Espada

using namespace std;

struct card {
    int value;
    string suit;
    bool is_turned;
	bool is_valid;
};

const string INVALID_CMD = "Comando inválido!";

vector <card> deck;
stack<card> stock;
stack<card> discard;

stack<card> fundation_heart;
stack<card> fundation_club;
stack<card> fundation_diamond;
stack<card> fundation_spade;

void assign_cards(string suit) {
	card c;
	for (int i = 0; i < 13; i++)  {
		c.suit = suit;
		c.value = (i+1);
		c.is_turned = false;
		deck.push_back(c);
	}		
}

void build_deck() {
	assign_cards(HEART); 
	assign_cards(CLUB);
	assign_cards(DIAMOND);
	assign_cards(SPADE);
}

void build_stock() {
	for (int i = 0; i < 24; i++) {
		stock.push(deck.data()[i]);
		deck.erase(deck.begin() + i);
	}	
}

void replace_stock() {
  for (int i = 0; i < discard.size(); i++) {
    card c = discard.top();
    discard.pop();
    stock.push(c);
  }
}

void acess_stock() {
	card c;
	if (!stock.empty()) {	
		c = stock.top();
		stock.pop();	
		discard.push(c);
	} else {
		if (!discard.empty()) {
		replace_stock();
		}
  	}	
}

void move_cards() {
		cout << "Escolha uma opcao de movimentacao:" << endl << endl;
		cout << "Opcao (1): mover do descarte para as pilhas." << endl;
		cout << "Opcao (2): mover do descarte para as fundacoes." << endl;
		cout << "Opcao (3): mover entre pilhas." << endl;
		cout << "Opcao (4): mover das pilhas para as fundacoes." << endl;
		cout << "Opcao (5): mover das fundacoes para as pilhas." << endl << endl;
		int opcao;
		
		cout << "Opcao: ";
		cin >>  opcao;
		cout << endl;
		
		if (opcao == 1) {
			// discard_to_stack();
		} else if(opcao == 2) {
			// discard_to_fundation();
		} else if (opcao == 3) {
			// stack_to_stack()
		} else if (opcao == 4) {
			// stack_to_fundation()
		} else if (opcao == 5) {
			// fundation_to_stack()
		}		 
}

void menu() {
	
	while(true) {
		cout << endl;	  
		cout << "       --1-- --2-- --3-- --4-- --5-- --6-- --7--" << endl;
		cout << "-----  [???] <=> Estoque                        " << endl;
		cout << "-----  [---] <=> Descarte           " << endl;
		cout << endl;
		cout << "--1--  [---] [---] [---] [---] [---] [---] [---]" << endl;
		cout << "--2--  [---] [---] [---] [---] [---] [---] [---]" << endl;
		cout << "--3--  [---] [---] [---] [---] [---] [---] [---]" << endl;
		cout << "--4--  [---] [---] [---] [---] [---] [---] [---]" << endl;
		cout << "--5--  [---] [---] [---] [---] [---] [---] [---]" << endl;
		cout << "--6--  [---] [---] [---] [---] [---] [---] [---]" << endl;
		cout << "--7--  [---] [---] [---] [---] [---] [---] [---]" << endl;
		cout << "--8--  [---] [---] [---] [---] [---] [---] [---]" << endl;
		cout << "--9--  [---] [---] [---] [---] [---] [---] [---]" << endl;
		cout << "--10-  [---] [---] [---] [---] [---] [---] [---]" << endl;
		cout << "--11-  [---] [---] [---] [---] [---] [---] [---]" << endl;
		cout << "--12-  [---] [---] [---] [---] [---] [---] [---]" << endl;
		cout << "--13-  [---] [---] [---] [---] [---] [---] [---]" << endl << endl;
		cout << "--14-  [---] [---] [---] [---] <=> Fundacoes    " << endl << endl;
		cout << "Escolha uma opcao:" << endl;
		cout << "Opcao (1): puxar uma carta do estoque." << endl;
		cout << "Opcao (2): mover uma carta." << endl;
		cout << "Opcao (3): sair do jogo." << endl << endl;
		int opcao;
		
		cout << "Opcao: ";
		cin >>  opcao;
		cout << endl;
		
		if (opcao == 1) {
			// access_stock();
		} else if(opcao == 2) {
			move_cards();
		} else if (opcao == 3) {
			cout << endl << "Jogo encerrado." << endl << endl;
			break;
		} else {
			cout << endl << "Opcao invalida" << endl << endl;
		}
	}

}

void run_game() {
   	menu();   
}

int main() {
	
	return 0;
}