
#include <SFML\System\Vector2.hpp>
#include <cstdio>
#include <cmath>
#include "Vector.hpp"


Vector::Vector() : x(0), y(0) {
}
template<typename T>
Vector::Vector(sf::Vector2<T>& A) : x(static_cast<float>(A.x)), y(static_cast<float>(y)) {
}
Vector::Vector(std::string &string) : x(0), y(0) {
	readFromString(string);
}
Vector::Vector(float x, float y) : x(x), y(y) {
}

Vector::~Vector() {
}

float Vector::length() const {
	return std::sqrtf(length2());
}
float Vector::length2() const {
	return x * x + y * y;
}

float Vector::distTo(const float &x, const float &y) const {
	return sqrtf(distTo(x, y));
}
float Vector::distTo(const Vector &A) const{
	return sqrtf(distTo(A));
}

float Vector::distTo2(const float &x, const float &y) const {
	return (this->x - x) * (this->x - x) + (this->y - y) * (this->y - y);
}
float Vector::distTo2(const Vector & A) const {
	return (x - A.x) * (x - A.x) + (y - A.y) * (y - A.y);
}

float Vector::angleX() const {
	return atan2f(y, x);
}
float Vector::angleTo(const float &x, const float &y) const {
	return atan2f(y, x) - atan2f(this->y, this->x);
}
float Vector::angleTo(const Vector &A) const {
	return atan2f(A.y, A.x) - atan2f(y, x);
}

void Vector::normalize(float length) {
	float d = this->length();
	x /= d;
	y /= d;
	x *= length;
	y *= length;
}

void Vector::rotate(float rad) {
	x = x * cosf(rad) - y * sinf(rad);
	y = x * sinf(rad) + y * cosf(rad);
}

void Vector::rotate90() {
	float tmpX = x;
	x = y;
	y = tmpX;
}

void Vector::print(const std::string pre, const std::string sui) {
	std::printf(pre.c_str());
	std::printf("X: %f; Y: %f ", x, y);
	std::printf(sui.c_str());
	std::printf("\n");
}

void Vector::readFromString(std::string &string) {
	x = std::stof(string.substr(0, string.find(';')));
	y = std::stof(string.substr(string.find(';') + 1));
}

void Vector::writetoString(std::string *string) {
	*string += std::to_string(x) + ';' + std::to_string(y) + '\n';
}

Vector& Vector::operator=(const Vector &A) {
	x = A.x;
	y = A.y;
	return *this;
}

Vector Vector::operator+(const Vector &A) const {
	return Vector(x + A.x, y + A.y);
}
Vector& Vector::operator+=(const Vector &A) {
	x += A.x;
	y += A.y;
	return *this;
}
Vector Vector::operator-(const Vector &A) const {
	return Vector(x - A.x, y - A.y);
}
Vector& Vector::operator-=(const Vector &A) {
	x -= A.x;
	y -= A.y;
	return *this;
}
Vector Vector::operator*(const Vector &A) const {
	return Vector(x * A.x, y * A.y);
}
Vector& Vector::operator*=(const Vector &A) {
	x *= A.x;
	y *= A.y;
	return *this;
}
Vector Vector::operator/(const Vector &A) const {
	return Vector(x / A.x, y / A.y);
}
Vector& Vector::operator/=(const Vector &A) {
	x /= A.x;
	y /= A.y;
	return *this;
}
bool Vector::operator==(const Vector &A) const {
	return x == A.x && y == A.y;
}
bool Vector::operator!=(const Vector &A) const {
	return x != A.x || y != A.y;
}
bool Vector::operator>(const Vector &A) const {
	return length2() > A.length2();
}
bool Vector::operator>=(const Vector &A) const {
	return length2() >= A.length2();
}
bool Vector::operator<(const Vector &A) const {
	return length2() < A.length2();
}
bool Vector::operator<=(const Vector &A) const {
	return length2() <= A.length2();
}

Vector::operator b2Vec2() {
	return b2Vec2(x, y);
}

Vector::operator sf::Vector2f() {
	return sf::Vector2f(x, y);
}

template<typename T>
Vector::operator sf::Vector2<T>() {
	return sf::Vector2<T>(static_cast<T>(x), static_cast<T>(y));
}