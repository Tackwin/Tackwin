#include "Utils/ResMng.hpp"
#include <assert.h>
#include <SFML\Audio.hpp>
#include <SFML\Graphics.hpp>
#include <windows.h>

std::map<sf::String, sf::SoundBuffer> ResMng::sounds;
std::map<sf::String, sf::Texture> ResMng::textures;
std::map<sf::String, sf::Shader> ResMng::shaders;
std::map<sf::String, sf::Image> ResMng::images;
std::map<sf::String, sf::Font> ResMng::fonts;

ResMng::ResMng() {
}

ResMng::~ResMng() {
}

void ResMng::loadAll() {
	getFont(RES_FONT);
	getShader(RES_BASE_SHADER);
	getImage(RES_LEVEL_TGA);
	getSound(RES_SOUND_SHOTGUN);
	getTexture(RES_BLOODSPLASH);
	getTexture(RES_BODY_PLAYER);
	getTexture(RES_ARMS_PLAYER);
	getTexture(RES_FEET_PLAYER);
	getTexture(RES_FIRETORCH);
	getTexture(RES_PARTICULE);
	getTexture(RES_GUNPOINT);
	getTexture(RES_ENNEMIE);
	getTexture(RES_PLAYER);
	getTexture(RES_BULLET);
	getTexture(RES_WEAPON);
	getTexture(RES_LEVEL);
	getTexture(RES_BLOOD);
}

sf::Texture& ResMng::getTexture(const sf::String &path) {
	auto loc = textures.find(path);
	if(loc != textures.end())
		return textures[path];
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED);
	printf("Loaging Texture: ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	printf("%s\n", path.toAnsiString().c_str());
	sf::Texture texture;
	assert(texture.loadFromFile(path));
	textures.emplace(path, texture);
	return textures[path];
}
sf::Shader& ResMng::getShader(const sf::String &path) {
	auto loc = shaders.find(path);
	if(loc != shaders.end())
		return shaders[path];
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED);
	printf("Loaging Shader :\n");
	printf("          --vert : ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	printf("%s\n", (path + ".vert").toAnsiString().c_str());
	assert(shaders[path].loadFromFile(path + ".vert", sf::Shader::Vertex));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED);
	printf("          --frag : ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	printf("%s\n", (path + ".frag").toAnsiString().c_str());
	assert(shaders[path].loadFromFile(path + ".frag", sf::Shader::Fragment));
	return shaders[path];
}
sf::Image& ResMng::getImage(const sf::String &path) {
	auto loc = images.find(path);
	if(loc != images.end())
		return images[path];
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED);
	printf("Loaging Image  : ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	printf("%s\n", path.toAnsiString().c_str());
	sf::Image image;
	assert(image.loadFromFile(path));
	images.emplace(path, image);
	return images[path];
}
sf::SoundBuffer& ResMng::getSound(const sf::String &path) {
	auto loc = sounds.find(path);
	if(loc != sounds.end())
		return sounds[path];
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED);
	printf("Loaging Sound  : ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	printf("%s\n", path.toAnsiString().c_str());
	sf::SoundBuffer buffer;
	buffer.loadFromFile(path);
	sounds.emplace(path, buffer);
	return sounds[path];
}
sf::Font& ResMng::getFont(const sf::String &path) {
	auto loc = fonts.find(path);
	if(loc != fonts.end())
		return fonts[path];
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED);
	printf("Loaging Font   : ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	printf("%s\n", path.toAnsiString().c_str());
	sf::Font font = sf::Font();
	font.loadFromFile(path);
	fonts.emplace(path, font);
	return fonts[path];
}
