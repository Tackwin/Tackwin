#pragma once
#include <map>
#define RES_FONT "Res/Font/F25_Bank_Printer.ttf"
#define RES_PLAYER "Res/player.png"
#define RES_BODY_PLAYER "Res/body.png"
#define RES_FEET_PLAYER "Res/feet.png"
#define RES_ARMS_PLAYER "Res/arms.png"
#define RES_ENNEMIE "Res/ennemie.png"
#define RES_LEVEL "Res/level.png"
#define RES_LEVEL_TGA "Res/level.tga"
#define RES_BULLET "Res/bullet.png"
#define RES_GUNPOINT "Res/gunpoint.png"
#define RES_WEAPON "Res/weapons.png"
#define RES_BLOOD "Res/blood.png"
#define RES_PARTICULE "Res/particule.png"
#define RES_BASE_SHADER "Shader/baseShader"
#define RES_FIRETORCH "Res/fireTorch.png"
#define RES_BLOODSPLASH "Res/bloodSplash.png"
#define RES_SOUND_SHOTGUN "Res/Sound/shotgun.ogg"

namespace sf {
	class Texture;
	class String;
	class Shader;
	class Image;
	class Font;
	class SoundBuffer;
};

class ResMng {
private:
	ResMng();
	~ResMng();

	static std::map<sf::String, sf::SoundBuffer> sounds;
	static std::map<sf::String, sf::Texture> textures;
	static std::map<sf::String, sf::Shader> shaders;
	static std::map<sf::String, sf::Image> images;
	static std::map<sf::String, sf::Font> fonts;
public:
	static sf::SoundBuffer& getSound(const sf::String &path);
	static sf::Texture& getTexture(const sf::String &path);
	static sf::Shader& getShader(const sf::String &path);
	static sf::Image& getImage(const sf::String &path);
	static sf::Font& getFont(const sf::String &path);
	static void loadAll();
};

