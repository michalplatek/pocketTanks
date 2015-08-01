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
	sf::Text lifeLeft;
	sf::Text lifeRight;
	std::string playerString, angleString, powerString, lifeLeftString, lifeRightString;
	float angle = 0.0, player = 0.0, power = 0.0, lifeLeftFloat = 0.0, lifeRightFloat = 0.0;

	
	playerString = std::to_string(player);
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
	playerTurn.setCharacterSize(16); // in pixels, not points!
	playerTurn.setPosition(520.0, 630.0);
	playerTurn.setColor(sf::Color::Black);

	angleOfTheShoot.setFont(myCharacter);
	angleOfTheShoot.setString("Kat wystrzalu: " + angleString);
	angleOfTheShoot.setCharacterSize(14); // in pixels, not points!
	angleOfTheShoot.setPosition(520.0, 660.0);
	angleOfTheShoot.setColor(sf::Color::Black);

	powerOfTheShoot.setFont(myCharacter);
	powerOfTheShoot.setString("Moc wystrzalu: "+ powerString);
	powerOfTheShoot.setCharacterSize(14); // in pixels, not points!
	powerOfTheShoot.setPosition(520.0, 680.0);
	powerOfTheShoot.setColor(sf::Color::Black);

	lifeLeft.setFont(myCharacter);
	lifeLeft.setString("Zycie: " + lifeLeftString);
	lifeLeft.setCharacterSize(16); // in pixels, not points!
	lifeLeft.setPosition(15.0, 600.0);
	lifeLeft.setColor(sf::Color::Black);
	lifeLeft.setStyle(sf::Text::Bold);

	lifeRight.setFont(myCharacter);
	lifeRight.setString("Zycie: " + lifeRightString);
	lifeRight.setCharacterSize(16); // in pixels, not points!
	lifeRight.setPosition(920.0, 600.0);
	lifeRight.setColor(sf::Color::Black);
	lifeRight.setStyle(sf::Text::Bold);


			glColor3f(1.0f, 1.0f, 0.5f);
			glBegin(GL_QUADS);
			
			float guiField[8] = { -500.0, 0.0, 500.0, 0.0, 500.0, 20.0, -500.0, 20.0 };

			for (int i = 0.0; i < 4.0; i++){
				float posx = getConfig()->positionToPixel(guiField[i * 2]);
				float posy = getConfig()->positionToPixel(guiField[(i * 2) + 1]);

				glVertex2f(posx, posy);
			}

			glEnd();

			glColor3f(0.0f, 0.0f, 0.4f);
			glBegin(GL_QUADS);

			float horizontalLine[8] = { -500.0, 19.0, 500.0, 19.0, 500.0, 20.0, -500.0, 20.0 };

			for (int i = 0.0; i < 4.0; i++){
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
				for (int i = 0.0; i < 4.0; i++){
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
			window->draw(lifeRight);
			window->popGLStates();
}
		
	


