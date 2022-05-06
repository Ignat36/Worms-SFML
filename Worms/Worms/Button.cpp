#include "Button.h"

void Button::Show(sf::RenderWindow * window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
	sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
	
	window->draw( Rect.contains(mousePosF) ? CoveredButtonSprite : ButtonSprite);
}

Button::Button(int id, float pos_x, float pos_y, 
			   float width, float height, 
			   std::string ButtonFile, std::string CoveredButtonFile) 
				:
			   LayoutObject(id, pos_x, pos_y, width, height)
{
	LoadSprite(ButtonTexture, ButtonSprite, ButtonFile);
	LoadSprite(CoveredButtonTexture, CoveredButtonSprite, CoveredButtonFile);
	
	Position -= sf::Vector2f(ButtonTexture.getSize().x / 2, ButtonTexture.getSize().y / 2);
	Size = sf::Vector2f(ButtonTexture.getSize().x, ButtonTexture.getSize().y);
	Rect = sf::FloatRect(Position, Size);
	
	ButtonSprite.setPosition(Position);
	CoveredButtonSprite.setPosition(Position);
}
