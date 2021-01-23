#include "EnvironmentElement.h"

EnvironmentElement::EnvironmentElement(sf::Texture& texture, int width, int position) :
	m_texture(texture),
	m_width(width), 
	m_position(position),
	m_health(100)
{

}

void EnvironmentElement::animate(float deltaTime) {
	// TODO lorsque les elements seront cr��s en Animable
}

void EnvironmentElement::draw(sf::RenderWindow& window) const {
	sf::Sprite sprite;
	sprite.setTexture(m_texture);
	sprite.setTextureRect(sf::IntRect(0, 0, Map::TILE_WIDTH * m_width, m_texture.getSize().y));
	sprite.setPosition(Map::TILE_WIDTH*m_position, 0);
	sprite.setOrigin(Map::TILE_WIDTH / 2, 0);
	window.draw(sprite);
}

void EnvironmentElement::reset() {

}

void EnvironmentElement::remove() {

}

void EnvironmentElement::receiveDamages(int damages) {
	this->m_health -= damages;
	if (m_health < 0) {
		m_health = 0;
	}
}

