#include "Level.h"
#include "Framework/Input.h"
#include <string>
using namespace std;


Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font\n";
	}

	textX.setFont(font);
	textX.setCharacterSize(24);
	textX.setFillColor(sf::Color::Red);
	textX.setPosition(0, 0);

	textY.setFont(font);
	textY.setCharacterSize(24);
	textY.setFillColor(sf::Color::Red);
	textY.setPosition(60, 0);
}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{

	if (input->isKeyDown(sf::Keyboard::W))
	{
		input->setKeyUp(sf::Keyboard::W);
		std::cout << "W\n";
	}

	if (input->isKeyDown(sf::Keyboard::J) && input->isKeyDown(sf::Keyboard::K) && input->isKeyDown(sf::Keyboard::L))
	{
		std::cout << "J, K AND L PRESSED.\n";
		input->setKeyUp(sf::Keyboard::J);
		input->setKeyUp(sf::Keyboard::K);
		input->setKeyUp(sf::Keyboard::L);
	}

	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		input->setKeyUp(sf::Keyboard::Escape);
		window->close();
	}
	int x = input->getMouseX();
	int y = input->getMouseY();

	string strX = std::to_string(x);
	string strY = std::to_string(y);
	textX.setString(strX);
	textY.setString(strY);



}

// Update game objects
void Level::update()
{

}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(textX);
	window->draw(textY);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}