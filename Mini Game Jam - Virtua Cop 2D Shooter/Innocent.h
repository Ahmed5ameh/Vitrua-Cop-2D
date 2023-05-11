#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>

using namespace std;
using namespace sf;
class Innocent
{
public:
	float radius = 70, InnocentHitBoxRadius = 60;
	Vector2f position;
	CircleShape circle, InnocentHitBox;
	Texture InnocentTex, InnocentHitBoxTex;
	Clock clock;
	int alpha = 255;

	Innocent() {};
	Innocent(Vector2f x) {
		//Innocent himself
		position = x;
		InnocentTex.loadFromFile("innocent1.png");
		this->circle.setRadius(radius);
		this->circle.setTexture(&InnocentTex);
		this->circle.setFillColor(sf::Color(255, 255, 255, 255));	//Innocent is Green
		this->circle.setPosition(position);
		this->circle.setOrigin(radius, radius);

		//HitBox
		this->InnocentHitBox.setRadius(InnocentHitBoxRadius);
		this->InnocentHitBox.setFillColor(sf::Color(50, 50, 50, 0));	//HitBox is Red
		this->InnocentHitBox.setPosition(position);
		this->InnocentHitBox.setOrigin(InnocentHitBoxRadius, InnocentHitBoxRadius);
	}

	void DrawFun(sf::RenderWindow* window) {
		window->draw(this->circle);
		window->draw(this->InnocentHitBox);
	}

	void Move(float deltaX) {
		this->circle.move(deltaX, 0);
		this->InnocentHitBox.move(deltaX, 0);
	}
	bool isOverlapping(Vector2f &mousePosition, float mouseRadius) {
		float distance = 0, RHS = 0, LHS = 0;
		distance = ((mousePosition.y - this->InnocentHitBox.getPosition().y) * (mousePosition.y - this->InnocentHitBox.getPosition().y)) + ((mousePosition.x - this->InnocentHitBox.getPosition().x) * (mousePosition.x - this->InnocentHitBox.getPosition().x));
		RHS = ((this->InnocentHitBox.getRadius() + mouseRadius) * (this->InnocentHitBox.getRadius() + mouseRadius));
		if (distance <= RHS) {
			return 1;
		}
		else {
			return 0;
		}
	}
};

