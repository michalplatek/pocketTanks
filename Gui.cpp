#include <GL/freeglut.h>
#include "Gui.h"
#include <string>

#include<SFML/Graphics/Text.hpp>


Gui::Gui(Config* config, sf::RenderWindow *window) : Renderable(config), window(window)
{
}

Gui::~Gui()
{
}

void Gui::passGame(Game* game){
	this->game = game;
}
void Gui::render()
{

	sf::Font myCharacter;
	myCharacter.loadFromFile("arial.ttf");
	sf::Text title;
	sf::Text playerTurn;
	sf::Text angleOfTheShoot;
	sf::Text powerOfTheShoot;
	sf::Text lifeLeft, controlLeft, upDownLeft, leftRightLeft, attackLeft, shellLeft;
	sf::Text lifeRight, controlRight, upDownRight, leftRightRight, attackRight, shellRight;
	std::string playerString, angleString, powerString, shellString;
	std::string lifeLeftString, lifeRightString;
	float angle = 0.0, power = 0.0;
	sf::Event e;

	//if the turn is divided by 2, then player 2 is playing 
	if (game->getTurn() % 2 == 0) {
		playerString = " ZIELONEGO";
		angle = (game->getTank(1)->getBarrelAngle() - 3.141593) * (-1);
		power = game->shellVelocity;
	}
	else {
		playerString = " NIEBIESKIEGO";
		angle = game->getTank(0)->getBarrelAngle();
		power = game->shellVelocity;
	}


	angleString = std::to_string(angle);
	powerString = std::to_string(power);
	lifeLeftString = std::to_string(game->getTank(0)->healthPoints);
	lifeRightString = std::to_string(game->getTank(1)->healthPoints);

	title.setFont(myCharacter);
	title.setString("Pocket Tanks");
	title.setCharacterSize(20); // in pixels, not points!
	title.setPosition(580.0, 600.0);
	title.setColor(sf::Color::Black);
	title.setStyle(sf::Text::Bold | sf::Text::Underlined);

	playerTurn.setFont(myCharacter);
	playerTurn.setString("Kolej gracza: " + playerString);
	playerTurn.setCharacterSize(14); // in pixels, not points!
	playerTurn.setPosition(520.0, 630.0);
	playerTurn.setColor(sf::Color::Black);

	angleOfTheShoot.setFont(myCharacter);
	angleOfTheShoot.setString("Kat wystrzalu: " + angleString);
	angleOfTheShoot.setCharacterSize(14); // in pixels, not points!
	angleOfTheShoot.setPosition(520.0, 650.0);
	angleOfTheShoot.setColor(sf::Color::Black);

	powerOfTheShoot.setFont(myCharacter);
	powerOfTheShoot.setString("Moc wystrzalu: "+ powerString);
	powerOfTheShoot.setCharacterSize(14); // in pixels, not points!
	powerOfTheShoot.setPosition(520.0, 670.0);
	powerOfTheShoot.setColor(sf::Color::Black);

	controlLeft.setFont(myCharacter);
	controlLeft.setString("<------------------Sterowanie------------------->");
	controlLeft.setCharacterSize(14); // in pixels, not points!
	controlLeft.setPosition(470.0, 690.0);
	controlLeft.setColor(sf::Color::Black);
	controlLeft.setStyle(sf::Text::Bold);

	lifeLeft.setFont(myCharacter);
	lifeLeft.setString("Zycie: " + lifeLeftString);
	lifeLeft.setCharacterSize(16); // in pixels, not points!
	lifeLeft.setPosition(15.0, 600.0);
	lifeLeft.setColor(sf::Color::Black);
	lifeLeft.setStyle(sf::Text::Bold);

	upDownLeft.setFont(myCharacter);
	upDownLeft.setString("Gora / dol : W / S");
	upDownLeft.setCharacterSize(16); // in pixels, not points!
	upDownLeft.setPosition(15.0, 630.0);
	upDownLeft.setColor(sf::Color::Black);

	leftRightLeft.setFont(myCharacter);
	leftRightLeft.setString("Lewo / prawo : A / D");
	leftRightLeft.setCharacterSize(16); // in pixels, not points!
	leftRightLeft.setPosition(15.0, 650.0);
	leftRightLeft.setColor(sf::Color::Black);

	attackLeft.setFont(myCharacter);
	attackLeft.setString("Atak : Spacja");
	attackLeft.setCharacterSize(16); // in pixels, not points!
	attackLeft.setPosition(15.0, 670.0);
	attackLeft.setColor(sf::Color::Black);

	shellLeft.setFont(myCharacter);
	shellLeft.setString("AP / HE / SH : 1 / 2 / 3");
	shellLeft.setCharacterSize(16); // in pixels, not points!
	shellLeft.setPosition(15.0, 690.0);
	shellLeft.setColor(sf::Color::Black);

	lifeRight.setFont(myCharacter);
	lifeRight.setString("Zycie: " + lifeRightString);
	lifeRight.setCharacterSize(16); // in pixels, not points!
	lifeRight.setPosition(920.0, 600.0);
	lifeRight.setColor(sf::Color::Black);
	lifeRight.setStyle(sf::Text::Bold);

	upDownRight.setFont(myCharacter);
	upDownRight.setString("Gora / dol : Up / Down");
	upDownRight.setCharacterSize(16); // in pixels, not points!
	upDownRight.setPosition(920.0, 630.0);
	upDownRight.setColor(sf::Color::Black);

	leftRightRight.setFont(myCharacter);
	leftRightRight.setString("Lewo / prawo : Left / Right");
	leftRightRight.setCharacterSize(16); // in pixels, not points!
	leftRightRight.setPosition(920.0, 650.0);
	leftRightRight.setColor(sf::Color::Black);

	attackRight.setFont(myCharacter);
	attackRight.setString("Atak : Enter");
	attackRight.setCharacterSize(16); // in pixels, not points!
	attackRight.setPosition(920.0, 670.0);
	attackRight.setColor(sf::Color::Black);
	
	shellRight.setFont(myCharacter);
	shellRight.setString("AP / HE / SH : 8 / 9 / 0");
	shellRight.setCharacterSize(16); // in pixels, not points!
	shellRight.setPosition(920.0, 690.0);
	shellRight.setColor(sf::Color::Black);

			glColor3f(1.0f, 1.0f, 0.5f);
			glBegin(GL_QUADS);
			
			float guiField[8] = { -500.0, 0.0, 500.0, 0.0, 500.0, 20.0, -500.0, 20.0 };

			for (int i = 0; i < 4; i++){
				float posx = getConfig()->positionToPixel(guiField[i * 2]);
				float posy = getConfig()->positionToPixel(guiField[(i * 2) + 1]);

				glVertex2f(posx, posy);
			}

			glEnd();

			glColor3f(0.0f, 0.0f, 0.4f);
			glBegin(GL_QUADS);

			float horizontalLine[8] = { -500.0, 19.0, 500.0, 19.0, 500.0, 20.0, -500.0, 20.0 };

			for (int i = 0; i < 4; i++){
				float posx = getConfig()->positionToPixel(horizontalLine[i * 2]);
				float posy = getConfig()->positionToPixel(horizontalLine[(i * 2) + 1]);

				glVertex2f(posx, posy);
			}

			glEnd();

			glColor3f(0.0f, 0.0f, 0.4f);
			glBegin(GL_QUADS);

			float verticalLine[3][8] = { { 59.0, 0.0, 59.0, 19.0, 60.0, 19.0, 60.0, 0.0 },
										{ 140.0, 0.0, 140.0, 19.0, 141.0, 19.0, 141.0, 0.0 } };
			for (int j = 0; j < 2; j++){
				for (int i = 0; i < 4; i++){
					float posx = getConfig()->positionToPixel(verticalLine[j][i * 2]);
					float posy = getConfig()->positionToPixel(verticalLine[j][(i * 2) + 1]);

					glVertex2f(posx, posy);
				}
			}

			glEnd();

			window->pushGLStates();
			window->draw(title);
			window->draw(playerTurn);
			window->draw(angleOfTheShoot);
			window->draw(powerOfTheShoot);
			window->draw(lifeLeft);
			window->draw(controlLeft);
			window->draw(upDownLeft);
			window->draw(leftRightLeft);
			window->draw(attackLeft);
			window->draw(shellLeft);
			window->draw(lifeRight);
			window->draw(controlRight);
			window->draw(upDownRight);
			window->draw(leftRightRight);
			window->draw(attackRight);
			window->draw(shellRight);
			window->popGLStates();
}
		
	


