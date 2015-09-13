#ifndef _VIEW_H_
#define _VIEW_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window/Context.hpp>
#include <GL/freeglut.h>
#include "Config.h"
#include "Game.h"
#include "Gui.h"
/**
Klasa: Widok
Odpowiada za wyœwietlanie obiektów œwiata gry i tworzenie okna programu.
*/
class View
{
	Config* config;
public:
	/**
	Konstruktor klasy widoku.
	@param config Obiekt przechowuj¹cy konfiguracjê rozgrywki.
	*/
	View(Config* config);
	/**
	Bezparametrowy konstruktor klasy widoku
	*/
	~View();
	
	sf::RenderWindow* window;
	/**
	Zwraca okno do renderowania gry.
	@return okno do renderingu gry
	*/
	sf::RenderWindow* getWindow();
	/**
	Inicjuje macierz projekcji okna. Ustawia wyœwietlanie do wartoœci domyœlnych.
	*/
	void viewportSetup();
	/**
	Resetuje macierze projekcji w oknie renderingu. Ustawia wyœwietlanie do wartoœci domyœlnych.
	*/
	void viewportReset();
	/**
	Przygotowuje bibliotekê OpenGL do rysowania na pocz¹tku ka¿dego cyklu pêtli gry.
	*/
	void prepare();
	
	/**
	Renderuje testowy obraz w oknie renderingu.
	*/
	void renderTest();
	/**
	Renderuje obiekt typu Game.
	@param game obiekt gry.
	*/
	void render(Game* game);
	/**
	Renderuje obiekt typu Tank.
	@param tank obiekt czo³gu
	*/
	void render(Tank* tank);
	/**
	Renderuje obiekt typu Barrel.
	@param barrel obiekt lufy czo³gu
	*/
	void render(Barrel* barrel);
	/**
	Renderuje ko³a czo³gu.
	@param wheels wektor obiektów typu Wheel (kó³ czo³gu)
	*/
	void render(std::vector<Wheel*> wheels);
	/**
	Renderuje obiekt typu World.
	@param world obiekt œwiata
	*/
	void render(World* world);
	/**
	Renderuje obiekt typu Shell.
	@param shell obiekt œwiata gry
	*/
	void render(Shell* shell);
	/**
	Renderuje GUI aplikacji (obiekt typu Gui)
	@param gui obiekt gui aplikacji
	*/
	void render(Gui* gui);

	/**
	Renderuje obiekt renderowalny w jego pozycji przeliczonej z uk³adu œwiata gry na wspó³rzêdne ekranu.
	@param renderable obiekt dziedzicz¹cy po klasie Renderable (obiekt renderowalny)
	*/
	void renderAtBodyPosition(Renderable* renderable);

};

#endif