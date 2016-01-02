#include <cstdio>
#include <cmath>
#include "Utils/Vector.hpp"

Vector const Vector::ZERO = Vector(0, 0);

template<typename T>
	Vector::Vector(const sf::Vector2<T> &vec) : x(vec.x), y(vec.y) {
}
Vector::Vector(const Vector &vector) : x(vector.x), y(vector.y) {
}
Vector::Vector(const float &x, const float &y) : x(x), y(y) {
}
Vector::~Vector() {
}

Vector& Vector::set(Vector &other) {
	operator=(other);
	return *this;
}
Vector& Vector::set(float x, float y) {
	this->x = x;
	this->y = y;
	return *this;
}
Vector& Vector::setX(float x) {
	this->x = x;
	return *this;
}
Vector& Vector::setX(const Vector &x) {
	this->x = x.x;
	return *this;
}
Vector& Vector::setY(float y) {
	this->y = y;
	return *this;
}
Vector& Vector::setY(const Vector &y) {
	this->y = y.y;
	return *this;
}
Vector& Vector::addX(float x) {
	this->x += x;
	return *this;
}
Vector& Vector::addX(const Vector &x) {
	this->x += x.x;
	return *this;
}
Vector& Vector::addY(float y) {
	this->y += y;
	return *this;
}
Vector& Vector::addY(const Vector &y) {
	this->y += y.y;
	return *this;
}

float Vector::length() const {
	return std::sqrtf(length2());
}
float Vector::length2() const {
	return x * x + y * y;
}

float Vector::distTo(const float &x, const float &y) const {
	return sqrtf(distTo2(x, y));
}
float Vector::distTo(const Vector &A) const {
	return sqrtf(distTo2(A));
}

float Vector::distTo2(const float &x, const float &y) const {
	return (this->x - x) * (this->x - x) + (this->y - y) * (this->y - y);
}
float Vector::distTo2(const Vector & A) const {
	return (x - A.x) * (x - A.x) + (y - A.y) * (y - A.y);
}

Vector& Vector::rotTo(float rad) {
	rotate(rad - angleX());
	return *this;
}

float Vector::angleX() const {
	return atan2f(y, x);
}
float Vector::angleTo(const float &x, const float &y) const {
	return atan2f(y - this->y, x - this->x);
}
float Vector::angleTo(const Vector &A) const {
	return atan2f(A.y - y, A.x - x);
}

Vector& Vector::normalize(float length) {
	float d = this->length();
	x /= d;
	y /= d;
	x *= length;
	y *= length;
	return *this;
}

Vector& Vector::rotate(float rad) {
	float tX = x;
	float tY = y;
	x = tX * cosf(rad) - tY * sinf(rad);
	y = tX * sinf(rad) + tY * cosf(rad);
	return *this;
}

Vector& Vector::rotate90() {
	float tmpX = x;
	x = y;
	y = tmpX;
	return *this;
}

void Vector::print(const std::string pre, const std::string sui) const {
#ifdef _WIN32
	std::printf("%s", pre.c_str());
	std::printf("X: %f; Y: %f ", x, y);
	std::printf("%s", sui.c_str());
	std::printf("\n");
#endif
}

void Vector::readFromString(const std::string &string) {
	x = std::stof(string.substr(0, string.find(';')));
	y = std::stof(string.substr(string.find(';') + 1));
}

void Vector::writetoString(std::string *string) {
	*string += std::to_string(x) + ';' + std::to_string(y);
}

Vector Vector::getDir() {
	return (Vector(*this).normalize());
}

bool Vector::intersect(const Vector &p0, const Vector &p1, const Vector &p2, const Vector &p3) {
	float A1 = p1.y - p0.y;
	float B1 = p0.x - p1.x;
	float C1 = A1 * p0.x + B1 * p0.y;
	float A2 = p3.y - p2.y;
	float B2 = p2.x - p3.x;
	float C2 = A2 * p2.x + B2 * p2.y;
	float denominator = A1 * B2 - A2 * B1;

	if(denominator == 0) {
		return false;
	}

	float intersectX = (B2 * C1 - B1 * C2) / denominator;
	float intersectY = (A1 * C2 - A2 * C1) / denominator;
	float rx0 = (intersectX - p0.x) / (p1.x - p0.x);
	float ry0 = (intersectY - p0.y) / (p1.y - p0.y);
	float rx1 = (intersectX - p2.x) / (p3.x - p2.x);
	float ry1 = (intersectY - p2.y) / (p3.y - p2.y);

	if(((rx0 >= 0 && rx0 <= 1) || (ry0 >= 0 && ry0 <= 1)) &&
		((rx1 >= 0 && rx1 <= 1) || (ry1 >= 0 && ry1 <= 1))) {
		return true;
	} else {
		return false;
	}
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

Vector::operator sf::Vector2f() const {
	return sf::Vector2f(x, y);
}

