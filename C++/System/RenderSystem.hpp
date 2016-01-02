#ifndef RENDERSYSTEMHPP
#define RENDERSYSTEMHPP

#include "Comp\Graphics.hpp"

class RenderSystem : public entityx::System<RenderSystem> {
private:
	std::vector<SpriteInfo> sprites;
	std::vector<TextInfo> texts;
	std::vector<BoxInfo> boxes;

	entityx::ComponentHandle<Graphics> graphics;

	sf::RenderWindow &window;
	sf::View &view;
	sf::Texture t;
public:
	RenderSystem(sf::RenderWindow &window, sf::View &view);
	~RenderSystem();

	void update(entityx::EntityManager &enm, entityx::EventManager &evm, entityx::TimeDelta delta);
};

#endif