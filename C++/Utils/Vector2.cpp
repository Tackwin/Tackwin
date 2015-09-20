#include <SFML\System\Vector2.hpp>
#include <cstdio>
#include <cmath>
#include "Vector2.hpp"

Vector2::Vector2() : x(0), y(0) {
}
Vector2::Vector2(float x, float y) : x(x), y(y) {
}

Vector2::~Vector2() {
}

float Vector2::length() const {
	return std::sqrtf(length2());
}
float Vector2::length2() const {
	return x * x + y * y;
}

float Vector2::distTo(const float &x, const float &y) const {
	return sqrtf(distTo(x, y));
}
float Vector2::distTo(const Vector2 &A) const{
	return sqrtf(distTo(A));
}

float Vector2::distTo2(const float &x, const float &y) const {
	return (this->x - x) * (this->x - x) + (this->y - y) * (this->y - y);
}
float Vector2::distTo2(const Vector2 & A) const {
	return (x - A.x) * (x - A.x) + (y - A.y) * (y - A.y);
}

float Vector2::angleX() const {
	return atan2f(y, x);
}
float Vector2::angleTo(const float &x, const float &y) const {
	return atan2f(y, x) - atan2f(this->y, this->x);
}
float Vector2::angleTo(const Vector2 &A) const {
	return atan2f(A.y, A.x) - atan2f(y, x);
}

void Vector2::normalize(float length) {
	float d = this->length();
	x /= d;
	y /= d;
	x *= length;
	y *= length;
}

void Vector2::rotate(float rad) {
	x = x * cosf(rad) - y * sinf(rad);
	y = x * sinf(rad) + y * cosf(rad);
}

void Vector2::rotate90() {
	float tmpX = x;
	x = y;
	y = tmpX;
}

void Vector2::print(const std::string pre, const std::string sui) {
	std::printf(pre.c_str());
	std::printf("X: %f; Y: %f ", x, y);
	std::printf(sui.c_str());
	std::printf("\n");
}

Vector2& Vector2::operator=(const Vector2 &A) {
	x = A.x;
	y = A.y;
	return *this;
}

Vector2 Vector2::operator+(const Vector2 &A) const {
	return Vector2(x + A.x, y + A.y);
}
Vector2& Vector2::operator+=(const Vector2 &A) {
	x += A.x;
	y += A.y;
	return *this;
}
Vector2 Vector2::operator-(const Vector2 &A) const {
	return Vector2(x - A.x, y - A.y);
}
Vector2& Vector2::operator-=(const Vector2 &A) {
	x -= A.x;
	y -= A.y;
	return *this;
}
Vector2 Vector2::operator*(const Vector2 &A) const {
	return Vector2(x * A.x, y * A.y);
}
Vector2& Vector2::operator*=(const Vector2 &A) {
	x *= A.x;
	y *= A.y;
	return *this;
}
Vector2 Vector2::operator/(const Vector2 &A) const {
	return Vector2(x / A.x, y / A.y);
}
Vector2& Vector2::operator/=(const Vector2 &A) {
	x /= A.x;
	y /= A.y;
	return *this;
}
bool Vector2::operator==(const Vector2 &A) const {
	return x == A.x && y == A.y;
}
bool Vector2::operator!=(const Vector2 &A) const {
	return x != A.x || y != A.y;
}
bool Vector2::operator>(const Vector2 &A) const {
	return length2() > A.length2();
}
bool Vector2::operator>=(const Vector2 &A) const {
	return length2() >= A.length2();
}
bool Vector2::operator<(const Vector2 &A) const {
	return length2() < A.length2();
}
bool Vector2::operator<=(const Vector2 &A) const {
	return length2() <= A.length2();
}

Vector2::operator b2Vec2() {
	return b2Vec2(x, y);
}

Vector2::operator sf::Vector2f() {
	return sf::Vector2f(x, y);
}

