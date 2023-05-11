#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
class Enemy{
public:
	float radius = 70, enemyHitBoxRadius = 80;
	Vector2f position;
	CircleShape circle, enemyHitBox;
	Texture enemyTex, enemyHitBoxTex;
	Clock clock;
	int alpha = 255;
	int numOfRow;
	bool isEnemy = 0;

	Enemy() {}
	Enemy(Vector2f x, int numTexture, int _ ) {
		//Enemy himself
		position = x;
		this->isEnemy = _;

		//Enemies textures
		if (_ == 1) {
			switch (numTexture) {
			case 0:
				enemyTex.loadFromFile("enemy1.png");
				break;
			case 1:
				enemyTex.loadFromFile("enemy2.png");
				break;
			case 2:
				enemyTex.loadFromFile("enemy3.png");
				break;
			default:
				break;
			}
		}
		//Inncoents textures
		else {
			switch (numTexture) {
			case 0:
				enemyTex.loadFromFile("Innocent1.png");
				break;
			case 1:
				enemyTex.loadFromFile("Innocent2.png");
				break;
			case 2:
				enemyTex.loadFromFile("Innocent3.png");
				break;
			default:
				break;
			}

		}

		
		this->circle.setRadius(radius);
		this->circle.setTexture(&enemyTex);
		this->circle.setFillColor(sf::Color(255, 255, 255, 255));	//Enemy is Green
		this->circle.setPosition(position);
		this->circle.setOrigin(radius, radius);

		//HitBox
		this->enemyHitBoxTex.loadFromFile("circle.png");
		this->enemyHitBox.setRadius(enemyHitBoxRadius);
		this->enemyHitBox.setTexture(&enemyHitBoxTex);
		this->enemyHitBox.setFillColor(sf::Color(50, 50, 50, 0));	//HitBox is Red
		this->enemyHitBox.setPosition(position);
		this->enemyHitBox.setOrigin(enemyHitBoxRadius, enemyHitBoxRadius);
	}

	void DrawFun(sf::RenderWindow* window) {
		window->draw(this->circle);
		window->draw(this->enemyHitBox);
	}

	void Move(float deltaX) {
		if (this->numOfRow == 1) {
			this->circle.move(deltaX, 0);
			this->enemyHitBox.move(deltaX, 0);
		}
		else {
			this->circle.move(-deltaX, 0);
			this->enemyHitBox.move(-deltaX, 0);
		}

	}
	bool isOverlapping(Vector2f &mousePosition, float mouseRadius) {
		float distance = 0, RHS = 0, LHS = 0;
		distance = ((mousePosition.y - this->enemyHitBox.getPosition().y) * (mousePosition.y - this->enemyHitBox.getPosition().y)) + ((mousePosition.x - this->enemyHitBox.getPosition().x) * (mousePosition.x - this->enemyHitBox.getPosition().x));
		RHS = ((this->enemyHitBox.getRadius() + mouseRadius) * (this->enemyHitBox.getRadius() + mouseRadius));
		if (distance <= RHS ){
			return 1;
		}
		else {
			return 0;
		}
	}
};
