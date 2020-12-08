#pragma once
#include <SFML/Graphics.hpp>
#include <string>

//NODE CLASS

class Node
{
private:
	//Private Node Variables
	sf::RectangleShape *nodeShape;
	sf::Font font;
	sf::Text *text;
	float width;
	float height;
	sf::Color color;

public:

	//Constructor and Destructor
	Node(float x, float y, float width, float height, float data);
	~Node();

	//Node Functions
	sf::RectangleShape *getShape();
	sf::Text *getText();
	sf::Vector2f getNodePosition();
	void changeNodeColor(sf::Color color);
	void setNode(int a);
};

