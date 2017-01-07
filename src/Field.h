#pragma once

#include <SFML/Graphics.hpp>

#include "Enums.h"
#include "TextureCache.h"

class Field: public sf::Transformable, public sf::Drawable
{
public:
	ft::FieldTypes type;

	Field() { type = ft::FieldTypes::EMPTY; }
	Field(TextureCache* _textureCache, const sf::Vector2f& position);

	bool isHover(const sf::RenderWindow &window);

	void setTextureCache(TextureCache* _textureCache) {
		textureCache = _textureCache;
	}
	void setFieldType(const ft::FieldTypes& _fieldType);
private:
	sf::Sprite sprite;
	TextureCache* textureCache;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		states.transform *= getTransform();
		target.draw(sprite, states);
	}
};