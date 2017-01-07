#include "Field.h"

Field::Field(TextureCache* _textureCache, const sf::Vector2f& position) : textureCache(_textureCache)
{
	sprite.setTexture(_textureCache->get("emptyField"));
	sprite.setPosition(position);
	type = ft::FieldTypes::EMPTY;
}

bool Field::isHover(const sf::RenderWindow &window)
{
	return static_cast<sf::IntRect>(sprite.getGlobalBounds())
		.contains(sf::Mouse::getPosition(window));
}

void Field::setFieldType(const ft::FieldTypes& _fieldType)
{
	type = _fieldType;
	if (_fieldType == ft::FieldTypes::CIRCLE)
		sprite.setTexture(textureCache->get("circleField"));
	else if (_fieldType == ft::FieldTypes::CROSS)
		sprite.setTexture(textureCache->get("crossField"));
}
