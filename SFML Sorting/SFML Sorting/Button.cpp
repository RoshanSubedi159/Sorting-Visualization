#include "Button.h"

//Constructor Definition
Button::Button(float x, float y, std::string text, sf::RenderWindow *window)
{
	this->window = window;


	this->buttonShape = new sf::RectangleShape;
	this->buttonShape->setPosition(sf::Vector2f(x, y));
	this->buttonShape->setSize(sf::Vector2f(350.f, 100.f));

	font.loadFromFile("Heaters.otf");
	this->text = new sf::Text;
	this->text->setFont(font);
	this->text->setString(text);
	this->text->setFillColor(sf::Color::Red);
	this->text->setCharacterSize(88);

	this->text->setPosition
	(
		this->buttonShape->getPosition().x + (this->buttonShape->getGlobalBounds().width / 2.f) - this->text->getGlobalBounds().width / 2.f,
		this->buttonShape->getPosition().y + (this->buttonShape->getGlobalBounds().height / 2.f) - (this->text->getGlobalBounds().height / 2.f) - 25.0f
	);
}

//Destructor
Button::~Button()
{
}

//Finction Definitions

// Returns sf::RectangleShape pointer
sf::RectangleShape* Button::getShape()
{
	return this->buttonShape;
}

//Returns sf::Text pointer
sf::Text* Button::getText()
{
	return this->text;
}

//Function related to button press
//Returns true when the button in pressed
bool Button::buttonPressed()
{
	//Button Idle Color
	this->text->setFillColor(sf::Color::Red);
	if (this->buttonShape->getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*window))))
	{
		//Button Hover Color
		this->text->setFillColor(sf::Color::Green);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			//Button Pressed Color
			this->text->setFillColor(sf::Color::Color(128,0,128));
			window->draw(*text);
			window->display();
			Sleep(100);
			return true;
		}
	}
	return false;
}
