#include"WestWorld.h"

WestWorld::WestWorld(){}

WestWorld::~WestWorld(){}

void WestWorld::createMiner()
{
	// O minerador inicia o seu dia em casa, descansado, sem sede e sem nada no bolso...
	miner.currentLocation	= house;
	miner.qtdGoldCarried	= 0;
	miner.levelThirst		= 0;
	miner.levelTiredness	= 0;
	miner.qtdMoneyInBank	= 0;

	miner.currentState = restingAtHome;
}

void WestWorld::showMessage(std::string message)
{
	WinApp::getInstance()->addMensageToList(message);
}

void WestWorld::init()
{
	createMiner();
}

void WestWorld::update()
{
	// Maquina de estados do minerador
	switch (miner.currentState)
	{
	case restingAtHome:
		// ENTER do estado
		if (miner.currentLocation != house)
		{
			showMessage("Indo para casa!");
			miner.currentLocation = house;
			break;
		}

		// UPDATE do estado
		// Se o nimerador não estiver cansado ele volta ao trabalho
		if (miner.levelTiredness <= maxTiredness) 
		{
			showMessage("Estou bem descansado, Hora de procurar por mais ouro!");
			miner.currentState = excavatingAtMine;

			//EXIT do estado
			//O minerador said de casa para o trabalho e não vai voltar enquando não conseguir o ouro necessário
			miner.qtdMoneyInBank = 0;
			showMessage("Saindo de casa");
		}
		// Se estiver cansado, ele dorme
		else 
		{
			miner.levelTiredness -= 1;
			showMessage("ZZZZZ (dormindo)...");
		}

		break;
	case excavatingAtMine:
		// ENTER do estado
		if (miner.currentLocation != goldMine)
		{
			showMessage("Andando para a mina de ouro.");
			miner.currentLocation = goldMine;
			break;
		}

		// UPDATE do estado
		// O minerador acha uma pepita
		miner.qtdGoldCarried += 1;
		// Aumenta o cansaço do minerador
		miner.levelTiredness += 1;

		showMessage("Consegui uma pepita de ouro!");

		// Se o mineiro estiver com o bolso cheio, ele vai o ouro no banco
		if (miner.qtdGoldCarried >= maxNuggets) 
		{
			miner.currentState = depositingGoldAtBank;

			//EXIT do estado
			showMessage("Deixando a mina!");
			break;
		}

		// Se estiver com sede, ele vai para o bar beber
		if (miner.levelThirst >= maxThirst)
		{
			miner.currentState = drinkingAtBar;

			//EXIT do estado
			showMessage("Deixando a mina!");
			break;
		}

		break;
	case depositingGoldAtBank:
		// ENTER do estado
		if (miner.currentLocation != bank)
		{
			showMessage("Indo para o banco");
			miner.currentLocation = bank;
			break;
		}

		// UPDATE do estado
		// Deposita o ouro na conta
		miner.qtdMoneyInBank += miner.qtdGoldCarried;
		// Tira o ouro da carteira
		miner.qtdGoldCarried = 0;

		showMessage("Depositando o ouro. Agora tenho na conta: " + std::to_string(miner.qtdMoneyInBank));

		// Se atingiu a quantidade de ouro coletado necessária
		if (miner.qtdMoneyInBank >= neededMoney)
		{
			showMessage("Ok, depositado! Já consegui o suficiente por hora, vou voltar para casa e descansar com minha esposa!");
			miner.currentState = restingAtHome;

			// EXIT do estado
			showMessage("Saindo do banco!");
		}
		// Se não atingiu a quantidade de ouro necessária
		else
		{
			miner.currentState = excavatingAtMine;

			// EXIT do estado
			showMessage("Saindo do banco!");
		}

		break;
	case drinkingAtBar:
		// ENTER do estado
		if (miner.currentLocation != saloon)
		{
			showMessage("Caramba, estou com sede, vou para o bar!");
			miner.currentLocation = saloon;
			break;
		}

		// UPDATE do estado
		if (miner.levelThirst >= maxThirst)
		{
			miner.levelThirst = 0;
			miner.qtdMoneyInBank -= 2;
			showMessage("Ahhhh, delicia de bebida!");
		}
		else
		{
			showMessage("Não tenho mais sede.");
			miner.currentState = excavatingAtMine;

			// EXIT do estado
			showMessage("Chega de bar por hoje!");
		}

		break;
	}
	// Fim da maquina de estados do minerador
}