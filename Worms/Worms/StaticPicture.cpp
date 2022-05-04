#include "StaticPicture.h"

void StaticPicture::Show(sf::RenderWindow * window)
{
	window->draw(Picture);
}

StaticPicture::StaticPicture(int id, float pos_x, float pos_y,
	float width, float height,
	std::string PictureFile)
	:
	LayoutObject(id, pos_x, pos_y, width, height)
{
	HidenFromUser = true;
	LoadSprite(Texture, Picture, PictureFile);
}