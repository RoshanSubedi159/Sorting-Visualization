#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <Windows.h>
#include "Node.h"
#include "Button.h"

//Constant for Node Change Speed
#define SPEED (70)


bool check = false;


//Function to draw and display the all the Nodes
void renderNodes(Node *nodes[], int nodeCount, sf::RenderWindow &window)
{
	//Sorting Window Background Color
	window.clear(sf::Color(204,229,255));
	for (int i = 0; i < nodeCount; i++)
	{
		sf::RectangleShape *rectangle = nodes[i]->getShape();
		sf::Text* nodeValue = nodes[i]->getText();
		window.draw(*rectangle);
		window.draw(*nodeValue);
	}


	//Label Dispaly
	sf::Font fontl;
	fontl.loadFromFile("Arial.ttf");
	sf::Text messagel;
	messagel.setFont(fontl);
	if(check==true)
		messagel.setString("Label:	Orange = Unsorted Bar	Light Yelow = Current Bar	Blue = Sorted Bar	Green = Current Min. Bar");
	else
		messagel.setString("Label:	Orange = Unsorted Bar	Light Yelow = Current Bar	Blue = Sorted Bar	");
	messagel.setFillColor(sf::Color(0, 52, 102));
	messagel.setCharacterSize(30);
	messagel.setPosition(sf::Vector2f(10.f, window.getSize().y - 70.f));
	window.draw(messagel);


	window.display();
}


//Generates random numbers between 1-99
void GenerateNumbers(int* a, int nodeCount)
{
	srand(time(NULL));
	for (int i = 0; i < nodeCount; i++)
	{
		a[i]=rand() % 100;
	}
}


//Swaps the numbers indexed in the array
void swapNumbers(int* a, int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}


//Sorts the array using Bubble Sort Method

void BubbleSort(int *a,Node *nodes[],int nodeCount, sf::RenderWindow &window)
{

	// Color(0,102,204)		::Bluish == Sorted Node
	// Color(255,255,153)	::Yellowish == Current Node
	// Color(255,153,51)	::Orangish == Unsorted Node

	bool swapped;

	//Displays the array in initial form
	renderNodes(nodes, nodeCount, window);
	Sleep(SPEED);

	//Sorting Loop
	for (int i = 0; i < nodeCount; i++)
	{
		swapped = true;
		for (int j = 0; j < nodeCount - i - 1; j++)
		{
			//Shows nodes being compared
			nodes[j]->changeNodeColor(sf::Color(255,255,153));
			nodes[j + 1]->changeNodeColor(sf::Color(255,255,153));
			renderNodes(nodes, nodeCount, window);
			Sleep(SPEED);

			//Comparing the two nodes
			if (a[j] > a[j + 1])
			{
				swapped = false;
				swapNumbers(a, j, j + 1);
				nodes[j]->setNode(a[j]);
				nodes[j + 1]->setNode(a[j + 1]);
			}

			renderNodes(nodes, nodeCount, window);
			Sleep(SPEED);
			nodes[j]->changeNodeColor(sf::Color(255,153,51));
			nodes[j + 1]->changeNodeColor(sf::Color(255,153,51));
		}
		nodes[nodeCount - 1 - i]->changeNodeColor(sf::Color(255,153,51));

		//Changing the sorted nodes color
		if (swapped == true)
		{
			for (int i = 0; i < nodeCount; i++)
				nodes[i]->changeNodeColor(sf::Color(0,102,204));
			renderNodes(nodes, nodeCount, window);
			Sleep(SPEED);
			break;
		}
		nodes[nodeCount-i-1]->changeNodeColor(sf::Color(0,102,204));
		renderNodes(nodes, nodeCount, window);
	}

	for (int k = 0; k < nodeCount; k++)
		nodes[k]->changeNodeColor(sf::Color(0,102,204));
	renderNodes(nodes, nodeCount, window);
	Sleep(SPEED);


	//Dispalying message after sorting is completed
	sf::Font font;
	font.loadFromFile("Heaters.otf");
	sf::Text message;
	message.setFont(font);
	message.setString("The array is Sorted using BubbleSort.");
	message.setFillColor(sf::Color::Red);
	message.setCharacterSize(100);
	message.setPosition(sf::Vector2f(100,window.getSize().y*(3.f/4.f)));

	window.draw(message);
	window.display();
	Sleep(3000);
}


//Sorts the array using Insertion Sort Method

void InsertionSort(int* numbers, Node* nodes[], int nodeCount, sf::RenderWindow& window)
{
	// Color(0,102,204)		::Bluish == Sorted Node
	// Color(255,255,153)	::Yellowish == Current Node
	// Color(255,153,51)	::Orangish == Unsorted Node

	//Displaying Initial Array
	renderNodes(nodes, nodeCount, window);
	Sleep(SPEED);

	//Sorting Loop
	for(int i = 0 ; i < nodeCount ; i++ )
	{
		//Showing the selected node
		nodes[i]->changeNodeColor(sf::Color(255,255,153));
		renderNodes(nodes, nodeCount, window);
		Sleep(SPEED);

		for (int j = i; j > 0 ; j--)
		{
			if( numbers[j - 1] > numbers[j])
			{
				swapNumbers(numbers, j - 1, j);
				nodes[j]->setNode(numbers[j]);
				nodes[j - 1]->setNode(numbers[j - 1]);
				nodes[j - 1]->changeNodeColor(sf::Color(255,255,153));
				nodes[j]->changeNodeColor(sf::Color(0,102,204));
				renderNodes(nodes, nodeCount, window);
				Sleep(SPEED);
			}	
		}
		//Changing sorted node color
		for(int k = 0 ; k <= i ; k++ )
			nodes[k]->changeNodeColor(sf::Color(0,102,204));
		renderNodes(nodes, nodeCount, window);
		Sleep(SPEED);
	}
	//Changing the sorted node color
	for (int k = 0; k < nodeCount; k++)
		nodes[k]->changeNodeColor(sf::Color(0,102,204));
	renderNodes(nodes, nodeCount, window);


	//Displaying the message after the sorting is completed
	sf::Font font;
	font.loadFromFile("Heaters.otf");
	sf::Text message;
	message.setFont(font);
	message.setString("The array is Sorted using InsertionSort.");
	message.setFillColor(sf::Color::Red);
	message.setCharacterSize(100);
	message.setPosition(sf::Vector2f(100, window.getSize().y * (3.f / 4.f)));

	window.draw(message);
	window.display();
	Sleep(3000);
}


//Sorts the array using Selection Sort method

void SelectionSort(int* a, Node* nodes[], int nodeCount, sf::RenderWindow& window)
{
	// Color(0,102,204)		::Bluish == Sorted Node
	// Color(255,255,153)	::Yellowish == Current Node
	// Color(255,153,51)	::Orangish == Unsorted Node
	//Color(178,255,102) == Current Minimum
	
	

	//Displaying Initial Array
	renderNodes(nodes, nodeCount, window);

	Sleep(SPEED);

	
	//Sorting Loop
	for (int i = 0; i < nodeCount; i++)
	{
		int minIndex = i;
		int min = a[i];
		for (int j = i; j < nodeCount; j++)
		{
			//Changing Selected Node color
			nodes[j]->changeNodeColor(sf::Color(255,255,153));
			renderNodes(nodes, nodeCount, window);
			Sleep(SPEED);

			//Selecting the minimum node
			if (j == i)
			{
				nodes[j]->changeNodeColor(sf::Color(178, 255, 102));
				renderNodes(nodes, nodeCount, window);
				Sleep(SPEED);
			}
			else if (a[j] <= min)
			{
				nodes[minIndex]->changeNodeColor(sf::Color(255,153,51));
				renderNodes(nodes, nodeCount, window);
				Sleep(SPEED);
				minIndex = j;
				min = a[j];
				nodes[minIndex]->changeNodeColor(sf::Color(178, 255, 102));
				renderNodes(nodes, nodeCount, window);
				Sleep(SPEED);
			}
			else
			{
				nodes[j]->changeNodeColor(sf::Color(255,153,51));
				renderNodes(nodes, nodeCount, window);
			}
		}

		//Sorting the minimum node
		swapNumbers(a, i, minIndex);
		nodes[i]->setNode(a[i]);
		nodes[minIndex]->setNode(a[minIndex]);
		nodes[minIndex]->changeNodeColor(sf::Color(255,153,51));

		//Changing sorted node color
		nodes[i]->changeNodeColor(sf::Color(0,102,204));
		renderNodes(nodes, nodeCount, window);
	}

	//Changing sorted node color
	nodes[nodeCount - 1]->changeNodeColor(sf::Color(0,102,204));
	renderNodes(nodes, nodeCount, window);


	//Displaying message after the sorting is completed
	sf::Font font;
	font.loadFromFile("Heaters.otf");
	sf::Text message;
	message.setFont(font);
	message.setString("The array is Sorted using Selection Sort.");
	message.setFillColor(sf::Color::Red);
	message.setCharacterSize(100);
	message.setPosition(sf::Vector2f(100, window.getSize().y * (3.f / 4.f)));

	window.draw(message);
	window.display();
	Sleep(3000);
}

//Function to render the sorting window

void sortingWindow(std::string title,int a)
{

	//Required variables
	const int nodeCount = 25 ;
	Node* nodes[nodeCount];
	int numbers[nodeCount];

	//Generating an array of random numbers
	GenerateNumbers(numbers, nodeCount);


	//Rendering the window to display sorting animation
	sf::RenderWindow window(sf::VideoMode(1620, 920), title, sf::Style::Titlebar);
	window.setFramerateLimit(60);

	//node width and height per single value
	float node_width = ((window.getSize().x) / (nodeCount));
	float node_height = ((window.getSize().y-100.f) / 100.f);


	//Creating all the nodes as bars
	nodes[0] = new Node(0.0f, 0.0f, node_width, node_height, (float)numbers[0]);
	for (int i = 1; i < nodeCount; ++i)
	{
		sf::Vector2f pos = nodes[i - 1]->getNodePosition();
		nodes[i] = new Node(pos.x + node_width, 0.0f, node_width, node_height, (float)numbers[i]);
	}


	// loop till the window is open
	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			//Deciding whish sorting algorithm to apply and closing the window after the sorting is completed
			if (a == 1)
			{
				check = false;
				BubbleSort(numbers, nodes, nodeCount, window);
				window.close();
			}
			else if (a == 2)
			{
				check = false;
				InsertionSort(numbers, nodes, nodeCount, window);
				window.close();
			}
			else if (a == 3)
			{
				check = true;
				SelectionSort(numbers, nodes, nodeCount, window);
				window.close();
			}
		}
	}

	//Deleting all the nodes created
	for (int i = 0; i < nodeCount; i++)
	{
		delete nodes[i];
	}
}


// MAIN FUNCTION

int main()
{
	//Rendering Main Window
	sf::RenderWindow win(sf::VideoMode(1280,720), "Main Window", sf::Style::Default);


	//Texture for Main window
	sf::RectangleShape photo;
	photo.setSize(sf::Vector2f(980, 720));
	photo.setPosition(sf::Vector2f(-100, 0));
	sf::Texture texture;
	texture.loadFromFile("sorting_image.png");
	photo.setTexture(&texture);

	//Declaring the required buttons
	Button* btn[4];

	//Bubble Sort Button
	btn[0] = new Button(photo.getGlobalBounds().width-100.f,100.f, "Bubble Sort",&win);
	sf::RectangleShape* button1 = btn[0]->getShape();
	sf::Text* text1 = btn[0]->getText();
	
	//Insertion Sort Button
	btn[1] = new Button(photo.getGlobalBounds().width - 100.f, button1->getPosition().y + button1->getGlobalBounds().height, "Insertion Sort",&win);
	sf::RectangleShape* button2 = btn[1]->getShape();
	sf::Text* text2 = btn[1]->getText();

	//Selection Sort Button
	btn[2] = new Button(photo.getGlobalBounds().width - 100.f, button2->getPosition().y + button2->getGlobalBounds().height, "Selection Sort", &win);
	sf::RectangleShape* button3 = btn[2]->getShape();
	sf::Text* text3 = btn[2]->getText();

	//Exit Button
	btn[3] = new Button(photo.getGlobalBounds().width - 100.f, button3->getPosition().y + button3->getGlobalBounds().height, "EXIT", &win);
	sf::RectangleShape* button4 = btn[3]->getShape();
	sf::Text* text4 = btn[3]->getText();

	//Loop till the window is open
	while (win.isOpen())
	{
		//Event in the window
		sf::Event evnt;
		while (win.pollEvent(evnt))
		{
			//Window CLose Condition
			if (evnt.type == sf::Event::Closed)
				win.close();

			//Button Pressed Conditions
			if (btn[0]->buttonPressed())
			{
				sortingWindow("BubbleSort", 1);
			}
			else if (btn[1]->buttonPressed())
			{
				sortingWindow("InsertionSort", 2);
			}
			else if (btn[2]->buttonPressed())
			{
				sortingWindow("SelectionSort", 3);
			}
			else if (btn[3]->buttonPressed())
			{
				win.close();
			}
		}

		//Drwaing all the entities
		win.clear(sf::Color::White);
		win.draw(photo);
		win.draw(*button1);
		win.draw(*button2);
		win.draw(*button3);
		win.draw(*button4);
		win.draw(*text1);
		win.draw(*text2);
		win.draw(*text3);
		win.draw(*text4);

		//Displaying the window
		win.display();
	}
	return 0;
}

