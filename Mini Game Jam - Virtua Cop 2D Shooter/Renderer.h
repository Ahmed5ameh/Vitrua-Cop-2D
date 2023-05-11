#pragma once
#include <SFML/Graphics.hpp>
#include <list>

using namespace sf;
using namespace std;

class Renderer
{
public:
	list<Drawable*> drawables;
	void AddDrawable(Drawable* drawable);
	void Render(RenderWindow* window);
};

