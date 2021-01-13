#include "AnimableEntity.h"


AnimableEntity::AnimableEntity(sf::Texture &texture, vector<sf::Sprite> spriteSheet, float frameRate,
	int framePerCol, int framePerLig, int totalFrame) :
	m_texture(texture), m_spriteSheet(spriteSheet), m_frameRate(frameRate), m_framePerCol(framePerCol),
	m_framePerLig(framePerLig), m_totalFrame(totalFrame), m_currentFrame(0), m_elapsedTime(0.0f) {}

void AnimableEntity::animate(float deltaTime) {
	m_elapsedTime += deltaTime;
	if (m_totalFrame > 0) {
		m_currentFrame = ((int)(m_frameRate * m_elapsedTime)) % m_totalFrame;
	}
	else {
		m_currentFrame = 0;
	}
}

void AnimableEntity::draw(sf::RenderWindow& window) const {
	window.draw(m_spriteSheet[m_currentFrame]);
}
