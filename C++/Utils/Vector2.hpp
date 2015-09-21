#pragma once
#include <string>
#include <Box2D\Common\b2Math.h>
#include <SFML\System\Vector2.hpp>

class Vector2 {
public:
	float x;
	float y;

	Vector2();
	Vector2(float x = 0, float y = 0);
	~Vector2();

	float length() const;
	float length2() const;

	float distTo(const float &x, const float &y) const;
	float distTo(const Vector2 &A) const;
	float distTo2(const float &x, const float &y) const;
	float distTo2(const Vector2 &A) const;

	float angleX() const;
	float angleTo(const float &x, const float &y) const;
	float angleTo(const Vector2 &A) const;

	void normalize(float length = 1.f);
	
	void rotate(float rad);
	void rotate90();
	
	void print(const std::string pre = "", const std::string sui = "");

	Vector2& operator=(const Vector2 &A);

	Vector2 operator+(const Vector2 &A) const;
	Vector2& operator+=(const Vector2 &A);

	Vector2 operator-(const Vector2 &A) const;
	Vector2& operator-=(const Vector2 &A);

	Vector2 operator*(const Vector2 &A) const;
	Vector2& operator*=(const Vector2 &A);
	
	Vector2 operator/(const Vector2 &A) const;
	Vector2& operator/=(const Vector2 &A);

	bool operator==(const Vector2 &A) const;
	bool operator!=(const Vector2 &A) const;
	bool operator>(const Vector2 &A) const;
	bool operator>=(const Vector2 &A) const;
	bool operator<(const Vector2 &A) const;
	bool operator<=(const Vector2 &A) const;

	operator sf::Vector2f();
	operator b2Vec2();
};

