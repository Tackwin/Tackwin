#include "Vector2.hpp"
#include <cstdio>
#include <cmath>

Vector2 const Vector2::ZERO = Vector2(0, 0);
Vector2::Vector2(const std::string &string) : x(0), y(0) {
	readFromString(string);
}
Vector2::Vector2(const Vector2 &vector) : x(vector.x), y(vector.y) {
}
Vector2::Vector2(const float &x, const float &y) : x(x), y(y) {
}
Vector2::~Vector2() {
}

Vector2& Vector2::set(Vector2 &other) {
	operator=(other);
	return *this;
}
Vector2& Vector2::set(float px, float py) {
	x = px;
	y = py;
	return *this;
}
Vector2& Vector2::setX(float px) {
	x = px;
	return *this;
}
Vector2& Vector2::setX(const Vector2 &v) {
	x = v.x;
	return *this;
}
Vector2& Vector2::setY(float py) {
	y = py;
	return *this;
}
Vector2& Vector2::setY(const Vector2 &v) {
	y = v.y;
	return *this;
}
Vector2& Vector2::addX(float px) {
	x += px;
	return *this;
}
Vector2& Vector2::addX(const Vector2 &v) {
	x += v.x;
	return *this;
}
Vector2& Vector2::addY(float py) {
	y += py;
	return *this;
}
Vector2& Vector2::addY(const Vector2 &v) {
	y += v.y;
	return *this;
}

float Vector2::length() const {
	return std::sqrtf(length2());
}
float Vector2::length2() const {
	return x * x + y * y;
}

float Vector2::distTo(const float &px, const float &py) const {
	return sqrtf(distTo2(px, py));
}
float Vector2::distTo(const Vector2 &A) const {
	return sqrtf(distTo2(A));
}

float Vector2::distTo2(const float &px, const float &py) const {
	return (px - x) * (px - x) + (py - y) * (py - y);
}
float Vector2::distTo2(const Vector2 & A) const {
	return (x - A.x) * (x - A.x) + (y - A.y) * (y - A.y);
}

Vector2& Vector2::rotTo(float rad) {
	rotate(rad - angleX());
	return *this;
}

float Vector2::angleX() const {
	return atan2f(y, x);
}
float Vector2::angleTo(const float &px, const float &py) const {
	return atan2f(py - y, px - x);
}
float Vector2::angleTo(const Vector2 &A) const {
	return atan2f(A.y - y, A.x - x);
}

Vector2& Vector2::normalize(float length) {
	float d = this->length();
	if(d == 0)
		return *this;
	x /= d;
	y /= d;
	x *= length;
	y *= length;
	return *this;
}

Vector2& Vector2::rotate(float rad) {
	float tX = x;
	float tY = y;
	x = tX * cosf(rad) - tY * sinf(rad);
	y = tX * sinf(rad) + tY * cosf(rad);
	return *this;
}

Vector2& Vector2::rotate90() {
	float tmpX = x;
	x = y;
	y = tmpX;
	return *this;
}

void Vector2::print(const std::string pre, const std::string sui) const {
	std::printf(pre.c_str());
	std::printf("X: %f; Y: %f ", x, y);
	std::printf(sui.c_str());
	std::printf("\n");
}

void Vector2::readFromString(const std::string &string) {
	x = std::stof(string.substr(0, string.find(';')));
	y = std::stof(string.substr(string.find(';') + 1));
}

void Vector2::writetoString(std::string *string) {
	*string += std::to_string(x) + ';' + std::to_string(y);
}

Vector2 Vector2::getNormalize() {
	return copy().normalize();
}

bool Vector2::intersect(const Vector2 &p0, const Vector2 &p1, const Vector2 &p2, const Vector2 &p3) {
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
