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
Odpowiada za wy�wietlanie obiekt�w �wiata gry i tworzenie okna programu.
*/
class View
{
	Config* config;
public:
	/**
	Konstruktor klasy widoku.
	@param config Obiekt przechowuj�cy konfiguracj� rozgrywki.
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
	Inicjuje macierz projekcji okna. Ustawia wy�wietlanie do warto�ci domy�lnych.
	*/
	void viewportSetup();
	/**
	Resetuje macierze projekcji w oknie renderingu. Ustawia wy�wietlanie do warto�ci domy�lnych.
	*/
	void viewportReset();
	/**
	Przygotowuje bibliotek� OpenGL do rysowania na pocz�tku ka�dego cyklu p�tli gry.
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
	@param tank obiekt czo�gu
	*/
	void render(Tank* tank);
	/**
	Renderuje obiekt typu Barrel.
	@param barrel obiekt lufy czo�gu
	*/
	void render(Barrel* barrel);
	/**
	Renderuje ko�a czo�gu.
	@param wheels wektor obiekt�w typu Wheel (k� czo�gu)
	*/
	void render(std::vector<Wheel*> wheels);
	/**
	Renderuje obiekt typu World.
	@param world obiekt �wiata
	*/
	void render(World* world);
	/**
	Renderuje obiekt typu Shell.
	@param shell obiekt �wiata gry
	*/
	void render(Shell* shell);
	/**
	Renderuje GUI aplikacji (obiekt typu Gui)
	@param gui obiekt gui aplikacji
	*/
	void render(Gui* gui);

	/**
	Renderuje obiekt renderowalny w jego pozycji przeliczonej z uk�adu �wiata gry na wsp�rz�dne ekranu.
	@param renderable obiekt dziedzicz�cy po klasie Renderable (obiekt renderowalny)
	*/
	void renderAtBodyPosition(Renderable* renderable);

};

#endif