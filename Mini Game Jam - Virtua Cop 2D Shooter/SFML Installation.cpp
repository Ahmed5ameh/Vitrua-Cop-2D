#include <iostream>
#include <SFML/Graphics.hpp>
#include <string.h>
#include <list>
#include "Renderer.h"
#include "Enemy.h"
#include "Innocent.h"
#include <time.h>
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

using namespace std;

int main()
{
	srand(time(NULL));
	//sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!", sf::Style::Fullscreen);
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
	window.setMouseCursorVisible(false);
	float mouseRadius = 25;
	float time = 0, deltaTime = 0, currentTime = 0, speed = 150, deltaX = 0;
	float counter = 0;
	sf::Clock clock;
	sf::CircleShape	mouse(mouseRadius);
	Texture mouseTex, bgTexture, fgTexture, gameOverTexture;
	sf::Sprite background, foreground, gameOver;
	mouseTex.loadFromFile("scope.png");
	mouse.setTexture(&mouseTex);
	mouse.setOrigin(mouseRadius, mouseRadius);

	if (!bgTexture.loadFromFile("background2.png")) {
		return 1;
	}
	background.setTexture(bgTexture);
	
	if (!fgTexture.loadFromFile("forground.png")) {
		return 1;
	}
	foreground.setTexture(fgTexture);

	if (!gameOverTexture.loadFromFile("game_over.png")) {
		return 1;
	}
	gameOver.setTexture(gameOverTexture);

	vector<Enemy> Enemies;
	//Row = 1 Enemies
	Enemy e0(sf::Vector2f(0, 415), rand() % 3, rand() % 2);
	Enemy e1(sf::Vector2f(250, 415), rand() % 3, rand() % 2);
	Enemy e2(sf::Vector2f(500, 415), rand() % 3, rand() % 2);
	Enemy e3(sf::Vector2f(700, 415), rand() % 3, rand() % 2);
	Enemy e4(sf::Vector2f(950, 415), rand() % 3, rand() % 2);
	Enemy e5(sf::Vector2f(1200, 415), rand() % 3, rand() % 2);
	Enemy e6(sf::Vector2f(1450, 415), rand() % 3, rand() % 2);
	Enemy e7(sf::Vector2f(1700, 415), rand() % 3, rand() % 2);
	Enemy e8(sf::Vector2f(2150, 415), rand() % 3, rand() % 2);
	//Row = 2 Enemies
	Enemy e9(sf::Vector2f(2150, 675), rand() % 3, rand() % 2);
	Enemy e10(sf::Vector2f(1700, 675), rand() % 3,rand() % 2);
	Enemy e11(sf::Vector2f(1450, 675), rand() % 3,rand() % 2);
	Enemy e12(sf::Vector2f(1200, 675), rand() % 3,rand() % 2);
	Enemy e13(sf::Vector2f(950, 675), rand() % 3, rand() % 2);
	Enemy e14(sf::Vector2f(700, 675), rand() % 3, rand() % 2);
	Enemy e15(sf::Vector2f(500, 675), rand() % 3, rand() % 2);
	Enemy e16(sf::Vector2f(250, 675), rand() % 3, rand() % 2);
	Enemy e17(sf::Vector2f(0, 675), rand() % 3, rand() % 2);
	e0.numOfRow = 1;
	e1.numOfRow = 1;
	e2.numOfRow = 1;
	e3.numOfRow = 1;
	e4.numOfRow = 1;
	e5.numOfRow = 1;
	e6.numOfRow = 1;
	e7.numOfRow = 1;
	e8.numOfRow = 1;
	e9.numOfRow = 2;
	e10.numOfRow = 2;
	e11.numOfRow = 2;
	e12.numOfRow = 2;
	e13.numOfRow = 2;
	e14.numOfRow = 2;
	e15.numOfRow = 2;
	e16.numOfRow = 2;
	e17.numOfRow = 2;
	Enemies.push_back(e0);
	Enemies.push_back(e1);
	Enemies.push_back(e2);
	Enemies.push_back(e3);
	Enemies.push_back(e4);
	Enemies.push_back(e5);
	Enemies.push_back(e6);
	Enemies.push_back(e7);
	Enemies.push_back(e8);
	Enemies.push_back(e9);
	Enemies.push_back(e10);
	Enemies.push_back(e11);
	Enemies.push_back(e12);
	Enemies.push_back(e13);
	Enemies.push_back(e14);
	Enemies.push_back(e15);
	Enemies.push_back(e16);
	Enemies.push_back(e17);

	while (window.isOpen())
	{
		currentTime = clock.getElapsedTime().asSeconds();
		deltaTime = currentTime - time;
		time = currentTime;
		deltaX = deltaTime * speed;
		Vector2f mousePosition;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (event.type == sf::Event::MouseMoved){
			mousePosition = (sf::Vector2f)sf::Mouse::getPosition(window);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.close();
		}
		
		mouse.setPosition(mousePosition);
		window.clear();
		window.draw(background);
		/*Draw Enemies here (Between clear & display)*/
		for (int i = 0; i < Enemies.size(); i++) {
			Enemies[i].Move(deltaX);
			Enemies[i].DrawFun(&window);
			switch (Enemies[i].numOfRow){
			case 1:
				if (Enemies[i].circle.getPosition().x + deltaX <= WINDOW_WIDTH + Enemies[i].circle.getRadius()) {
					Enemies[i].circle.setPosition(Enemies[i].circle.getPosition().x + deltaX, Enemies[i].circle.getPosition().y);
					Enemies[i].enemyHitBox.setPosition(Enemies[i].enemyHitBox.getPosition().x + deltaX, Enemies[i].enemyHitBox.getPosition().y);
			    }
			    else {
					clock.restart();
					time = 0;
					Enemies[i].circle.setPosition(sf::Vector2f(-250, 415));
					Enemies[i].enemyHitBox.setPosition(sf::Vector2f(-250, 415));
					Enemies[i].alpha = 255;
					Enemies[i].circle.setFillColor(sf::Color(255, 255, 255, Enemies[i].alpha));
					//Enemies[i].enemyHitBox.setFillColor(sf::Color(255, 255, 255, Enemies[i].alpha));
			    }
				break;
			case 2:
				if (Enemies[i].circle.getPosition().x - deltaX >= -Enemies[i].circle.getRadius()) {
					Enemies[i].circle.setPosition(Enemies[i].circle.getPosition().x - deltaX, Enemies[i].circle.getPosition().y);
					Enemies[i].enemyHitBox.setPosition(Enemies[i].enemyHitBox.getPosition().x - deltaX, Enemies[i].enemyHitBox.getPosition().y);
				}
				else {
					clock.restart();
					time = 0;
					Enemies[i].circle.setPosition(sf::Vector2f(2170, 675));
					Enemies[i].enemyHitBox.setPosition(sf::Vector2f(2170, 675));
					Enemies[i].alpha = 255;
					Enemies[i].circle.setFillColor(sf::Color(255, 255, 255, Enemies[i].alpha));
					//Enemies[i].enemyHitBox.setFillColor(sf::Color(255, 255, 255, Enemies[i].alpha));
				}
				break;
			default:
				break;
			}
			
			mousePosition = (sf::Vector2f)sf::Mouse::getPosition(window);

			if (Enemies[i].isOverlapping(mousePosition, mouseRadius) &&
				Enemies[i].clock.getElapsedTime().asSeconds() > 0.275 && Enemies[i].alpha != 0 && Enemies[i].isEnemy == 1) {
				Enemies[i].enemyHitBox.setFillColor(sf::Color(255, 255, 255, Enemies[i].alpha));
			}
			else {
				Enemies[i].enemyHitBox.setFillColor(sf::Color(255, 255, 255, 0));
			}

			if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
				event.key.code == sf::Mouse::Left && Enemies[i].isOverlapping(mousePosition, mouseRadius) &&
				Enemies[i].clock.getElapsedTime().asSeconds() > 0.275 && Enemies[i].alpha != 0 && Enemies[i].isEnemy == 1) {
				Enemies[i].alpha = 0;
				Enemies[i].circle.setFillColor(sf::Color(255, 255, 255, Enemies[i].alpha));
				Enemies[i].enemyHitBox.setFillColor(sf::Color(255, 255, 255, Enemies[i].alpha));
				//KILL ENEMY
				//cout << counter++ << endl;
				Enemies[i].clock.restart();
			}
			if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
				event.key.code == sf::Mouse::Left && Enemies[i].isOverlapping(mousePosition, mouseRadius) &&
				Enemies[i].clock.getElapsedTime().asSeconds() > 0.275 && Enemies[i].alpha != 0 && Enemies[i].isEnemy == 0) {
				//cout << "GAME OVER" << endl;
				window.draw(gameOver);
			}
			Enemies[i].DrawFun(&window);
			
		}	
		window.draw(foreground);
		window.draw(mouse);
		window.display();
	}
	return 0;
}
