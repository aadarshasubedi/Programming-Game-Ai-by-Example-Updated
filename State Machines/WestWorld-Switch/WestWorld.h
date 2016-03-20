#pragma once
#include "Test.h"
#include <iostream>
#include <string>

const int neededMoney = 5;	// Quantidade de ouro que o minerador precisa ter para poder ir para casa descançar.
const int maxNuggets = 3;	// Quantidade maxima de pepitas que o minerador pode carregar.
const int maxThirst = 5;	// Quando passa esse valor o minerador está com sede.
const int maxTiredness = 5; // Quando passa esse valor o minerador está com sono.

enum location
{
	house,		// Casa do minerador
	goldMine,	// Mina de ouro
	bank,		// Banco
	saloon		// Bar
};

enum state
{
	restingAtHome,			// Vai dormir e descansar em casa
	excavatingAtMine,		// Vai para mina escavar em busca de ouro
	depositingGoldAtBank,	// Vai no banco e deposita o ouro
	drinkingAtBar			// Vai para o bar beber
};

struct Miner
{
	state		currentState;		// Estado atual dentre as opções possiveis
	location	currentLocation;	// Local atual dentre as opções possiveis
	int			qtdGoldCarried;		// Quanto ouro o minerador tem em seu bolso
	int			qtdMoneyInBank;		// Quanto dinheiro o minerador tem no banco
	int			levelThirst;		// Quanto maior o valor, mais sede o minerador tem
	int			levelTiredness;		// Quando maior o valor, mais cansado o minerador está
};


class WestWorld
{
private:
	Miner miner;

	void createMiner();
	void showMessage(std::string message);

public:
	WestWorld();
	~WestWorld();

	void init();
	void update();
	
};