#include "Node.h"

//Constructor Definition
Node::Node(float x, float y, float width, float height,
			float data)
{
	this->nodeShape = new sf::RectangleShape;
	this->nodeShape->setPosition(sf::Vector2f(x, y));
	this->nodeShape->setSize(sf::Vector2f(width, height*data));
	this->nodeShape->setOutlineColor(sf::Color(0, 76, 153));
	this->nodeShape->setOutlineThickness(2.0f);
	this->width = width;
	this->height = height;
	
	font.loadFromFile("Arial.ttf");
	this->text = new sf::Text;
	this->text->setFont(font);
	this->text->setString(std::to_string(int(data)));
	this->text->setFillColor(sf::Color::Black);
	this->text->setCharacterSize(35);
	
	this->text->setPosition
	(
		sf::Vector2f(this->nodeShape->getPosition().x+this->nodeShape->getGlobalBounds().width * (1.f / 4.f), 0.f)
	);

	this->nodeShape->setFillColor(sf::Color(255, 153, 51));
}

//Destructor Definition
Node::~Node()
{
	delete nodeShape;
}

// FUNCTION DEFINITIONS

//Returns sf::RectangleShape pointer
sf::RectangleShape *Node::getShape()
{
	return this->nodeShape;
}

//Reurns sf::Text pointer
sf::Text *Node::getText()
{
	return this->text;
}

//Returns sf::Vector2f for node position
sf::Vector2f Node::getNodePosition()
{
	return sf::Vector2f(this->nodeShape->getPosition());
}

//Changes node color
void Node::changeNodeColor(sf::Color color)
{
	this->nodeShape->setFillColor(color);
}

//Changes nodes value and height accordingly
void Node::setNode(int a)
{
	this->text->setString(std::to_string(a));
	this->nodeShape->setSize(sf::Vector2f(this->width, a*this->height));
}
