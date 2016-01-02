#include "Comp\Position.hpp"
#include "RenderSystem.hpp"
#include "Comp\Physics.hpp"
#include "ResMng.hpp"
#include "Game.hpp"

RenderSystem::RenderSystem(sf::RenderWindow &window, sf::View &view) : window(window), view(view) {
}

RenderSystem::~RenderSystem() {
}

bool compareSprite(const SpriteInfo &A, const SpriteInfo &B) {
	return A.z < B.z;
}
bool compareText(const TextInfo &A, const TextInfo &B) {
	return A.z < B.z;
}
bool compareBox(const BoxInfo &A, const BoxInfo &B) {
	return A.z < B.z;
}

void RenderSystem::update(entityx::EntityManager &enm, entityx::EventManager &evm, entityx::TimeDelta delta) {
	sprites.clear();
	texts.clear();
	boxes.clear();

	for(auto E : enm.entities_with_components<Graphics>(graphics)) {
		for(auto &S : graphics->sprites) {
			sf::Sprite &sprite = S.second.sprite;
			Vector p = S.second.off;
			if(E.has_component<Physics>()) {
				sprite.setRotation(180 * E.component<Physics>()->radians / 3.14159f);
			} if(E.has_component<Position>()) {
				p += E.component<Position>()->get();
			}
			sprite.setOrigin(S.second.ori);
			sprite.setColor(S.second.color);
			sprite.setPosition(p);
			sprites.push_back(S.second);
		}
		for(auto &T : graphics->texts) {
			sf::Text &t = T.second.text;
			Vector p = T.second.off;
			if(E.has_component<Physics>()) {
				t.setOrigin(E.component<Physics>()->origin);
			} if(E.has_component<Position>()) {
				p += E.component<Position>()->get();
			}
			t.setPosition(p);
			t.setColor(T.second.color);
			texts.push_back(T.second);
		}
		for(auto &B : graphics->boxes){
			sf::RectangleShape &s = B.second.shape;
			Vector p = B.second.off;
			s.setOrigin(B.second.ori);
			s.setFillColor(B.second.color);
			if(E.has_component<Position>()){
				p += E.component<Position>()->get();
			}
			s.setPosition(p);
			boxes.push_back(B.second);
		}
	}
	std::sort(sprites.begin(), sprites.end(), compareSprite);
	std::sort(texts.begin(), texts.end(), compareText);
	std::sort(boxes.begin(), boxes.end(), compareBox);

	window.setView(view);
	window.clear();
	for(auto &B : boxes)
		window.draw(B.shape);
	for(auto &S : sprites)
		window.draw(S.sprite);
	for(auto &T : texts)
		window.draw(T.text);
	window.display();
}
