#pragma once
#include <SFML/System/Vector2.hpp>
#include <string>

struct Vector2 {

	static const Vector2 ZERO;
	static Vector2 createUnitVector(float a){return {cosf(a), sinf(a)}; }

	float x;
	float y;

	template<typename T>
	Vector2(const T& t);
	Vector2(const Vector2 &vector);
	Vector2(const std::string &string);
	Vector2(const float &x = 0, const float &y = 0);
	~Vector2();

	inline Vector2& copy() { return *this; }

	Vector2& set(Vector2 &other);
	Vector2& set(float x, float y);
	Vector2& setX(float x);
	Vector2& setX(const Vector2 &x);
	Vector2& setY(float y);
	Vector2& setY(const Vector2 &y);
	Vector2& addX(float x);
	Vector2& addX(const Vector2 &x);
	Vector2& addY(float y);
	Vector2& addY(const Vector2 &x);

	float length() const;
	float length2() const;

	float distTo(const float &x, const float &y) const;
	float distTo(const Vector2 &A) const;
	float distTo2(const float &x, const float &y) const;
	float distTo2(const Vector2 &A) const;

	float angleX() const;
	float angleTo(const float &x, const float &y) const;
	float angleTo(const Vector2 &A) const;

	Vector2 getNormalize();

	Vector2& normalize(float length = 1.f);

	Vector2& rotate(float rad);
	Vector2& rotTo(float rad);
	Vector2& rotate90();

	void print(const std::string pre = "", const std::string sui = "") const;
	void readFromString(const std::string &string);
	void writetoString(std::string *string);

	Vector2& operator=(const Vector2 &A);
	template<typename T>
	Vector2& operator=(const sf::Vector2<T> &A);

	Vector2 operator+(const Vector2 &A) const;
	Vector2& operator+=(const Vector2 &A);
	template<typename T>
	Vector2 operator+(const T &A) const;
	template<typename T>
	Vector2& operator+=(const T &A);

	Vector2 operator-(const Vector2 &A) const;
	Vector2& operator-=(const Vector2 &A);
	template<typename T>
	Vector2 operator-(const T &A) const;
	template<typename T>
	Vector2& operator-=(const T &A);

	template<typename T>
	Vector2 operator*(const T &A) const;
	template<typename T>
	Vector2& operator*=(const T &A);

	template<typename T>
	Vector2 operator/(const T &A) const;
	template<typename T>
	Vector2& operator/=(const T &A);

	bool operator==(const Vector2 &A) const;
	bool operator!=(const Vector2 &A) const;
	bool operator>(const Vector2 &A) const;
	bool operator>=(const Vector2 &A) const;
	bool operator<(const Vector2 &A) const;
	bool operator<=(const Vector2 &A) const;

	template<typename T>
	operator sf::Vector2<T>() const;

	inline static float det(const Vector2 &A, const Vector2 &B) {
		return A.x * B.y - A.y * B.x;
	}
	static bool intersect(const Vector2 &po, const Vector2 &p1, const Vector2 &p2, const Vector2 &p3);
	inline static bool equal(const Vector2 &a, const Vector2 &b, float eps = 0.1f) {//Test if two vector are within a range of e(exclusive)
		if(eps == 0)
			return a == b;
		return b.distTo2(a) < eps * eps;
	}
};

template<typename T>
Vector2::Vector2(const T& t) : x(t.x), y(t.y) { }

template<typename T>
inline Vector2::operator sf::Vector2<T>() const {
	return sf::Vector2<T>(static_cast<T>(x), static_cast<T>(y));
}

template<typename T>
inline Vector2& Vector2::operator=(const sf::Vector2<T> &A) {
	x = static_cast<float>(A.x);
	y = static_cast<float>(A.y);
	return *this;
}

template<typename T>
inline Vector2 Vector2::operator*(const T & A) const {
	return Vector2(x * static_cast<const float>(A), y * static_cast<const float>(A));
}
template<typename T>
inline Vector2& Vector2::operator*=(const T & A) {
	x *= A;
	y *= A;
	return *this;
}

template<typename T>
inline Vector2 Vector2::operator/(const T & A) const {
	return Vector2(x / A, y / A);
}
template<typename T>
inline Vector2& Vector2::operator/=(const T & A) {
	x /= A;
	y /= A;
	return *this;
}

template<typename T>
inline Vector2 Vector2::operator+(const T & A) const {
	return Vector2(x + A, y + A);
}
template<typename T>
inline Vector2& Vector2::operator+=(const T & A) {
	x += A;
	y += A;
	return *this;
}

template<typename T>
inline Vector2 Vector2::operator-(const T & A) const {
	return Vector2(x - A, y - A);
}
template<typename T>
inline Vector2& Vector2::operator-=(const T & A) {
	x -= A;
	y -= A;
	return *this;
}
