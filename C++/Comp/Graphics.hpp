#ifndef GRAPHICSHPP
#define GRAPHICSHPP

#include <SFML\Graphics.hpp>
#include <entityx\entityx.h>
#include "../Vector.hpp"

struct SpriteInfo {
	sf::Sprite sprite;
	sf::Color color;
	Vector off;
	Vector ori;
	float z;

	SpriteInfo() {}
	SpriteInfo(sf::Texture &sprite, const Vector &off = Vector::ZERO, const Vector &orig = Vector::ZERO, float z = 0.0f, sf::Color color = sf::Color(255, 255, 255, 255))
		: sprite(sprite), off(off), ori(orig), z(z), color(color) {}
};
struct TextInfo {
	sf::Color color;
	sf::Text text;
	Vector off;
	float z;
	
	TextInfo() {}
	TextInfo(const sf::Text &text, const Vector &off = Vector::ZERO, float z = 0.0f, sf::Color color = sf::Color::White)
		: text(text), off(off), z(z), color(color) {}
};
struct BoxInfo {
	sf::RectangleShape shape;
	sf::Color color;
	Vector off;
	Vector ori;
	float z;

	BoxInfo() {}
	BoxInfo(const sf::RectangleShape &shape, const Vector &off = Vector::ZERO, const Vector &ori = Vector::ZERO, float z = 0.f, const sf::Color &color = sf::Color::White)
		: shape(shape), off(off), ori(ori), z(z), color(color) {}
};

struct Graphics {
	std::map<std::string, SpriteInfo> sprites;
	std::map<std::string, TextInfo> texts;
	std::map<std::string, BoxInfo> boxes;

	////////////////////////////////////////////////////////////////////////
	/// entityx::Entity &e, const std::string &name, const SpriteInfo &sprite
	////////////////////////////////////////////////////////////////////////
	static void set(entityx::Entity &e, const std::string &name, const SpriteInfo &sprite) {
		if(!e.has_component<Graphics>()) e.assign<Graphics>();
		e.component<Graphics>()->sprites[name] = sprite;
	}
	static void set(entityx::Entity &e, const std::string &name, const TextInfo &sprite) {
		if(!e.has_component<Graphics>()) e.assign<Graphics>();
		e.component<Graphics>()->texts[name] = sprite;
	}
	static void set(entityx::Entity &e, const std::string &name, const BoxInfo &box) {
		if(!e.has_component<Graphics>()) e.assign<Graphics>();
		e.component<Graphics>()->boxes[name] = box;
	}
};

#endif