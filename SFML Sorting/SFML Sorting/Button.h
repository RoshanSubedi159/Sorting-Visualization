#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>

// BUTTON CLASS

class Button
{
private:

	//Requi::Red Private Variables

	sf::RenderWindow* window;
	sf::RectangleShape* buttonShape;
	sf::Font font;
	sf::Text* text;

public:

	//Constructor and Destructor
	Button(float x, float y, std::string text, sf::RenderWindow *window);
	~Button();

	//Button Functions
	sf::RectangleShape* getShape();
	sf::Text* getText();
	bool buttonPressed();
};
