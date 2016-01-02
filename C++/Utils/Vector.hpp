#pragma once
#include <string>
#include <SFML\Graphics.hpp>
class Vector {
public:
	static const Vector ZERO;
public:
	float x = 0.f;
	float y = 0.f;

	Vector(const Vector &vector);
	template<typename T>
		Vector(const sf::Vector2<T> &vec);
	Vector(const float &x = 0.f, const float &y = 0.f);
	~Vector();

	inline Vector& get() { return *this; }

	Vector& set(Vector &other);
	Vector& set(float x, float y);
	Vector& setX(float x);
	Vector& setX(const Vector &x);
	Vector& setY(float y);
	Vector& setY(const Vector &y);
	Vector& addX(float x);
	Vector& addX(const Vector &x);
	Vector& addY(float y);
	Vector& addY(const Vector &x);

	float length() const;
	float length2() const;

	float distTo(const float &x, const float &y) const;
	float distTo(const Vector &A) const;
	float distTo2(const float &x, const float &y) const;
	float distTo2(const Vector &A) const;

	float angleX() const;
	float angleTo(const float &x, const float &y) const;
	float angleTo(const Vector &A) const;


	Vector getDir();

	Vector& normalize(float length = 1.f);

	Vector& rotate(float rad);
	Vector& rotTo(float rad);
	Vector& rotate90();

	void print(const std::string pre = "", const std::string sui = "") const;
	void readFromString(const std::string &string);
	void writetoString(std::string *string);

	Vector& operator=(const Vector &A);

	Vector operator+(const Vector &A) const;
	Vector& operator+=(const Vector &A);
	template<typename T>
	Vector operator+(const T &A) const;
	template<typename T>
	Vector& operator+=(const T &A);

	Vector operator-(const Vector &A) const;
	Vector& operator-=(const Vector &A);
	template<typename T>
	Vector operator-(const T &A) const;
	template<typename T>
	Vector& operator-=(const T &A);

	Vector operator*(const Vector &A) const;
	Vector& operator*=(const Vector &A);
	template<typename T>
	Vector operator*(const T &A) const;
	template<typename T>
	Vector& operator*=(const T &A);

	Vector operator/(const Vector &A) const;
	Vector& operator/=(const Vector &A);
	template<typename T>
	Vector operator/(const T &A) const;
	template<typename T>
	Vector& operator/=(const T &A);

	bool operator==(const Vector &A) const;
	bool operator!=(const Vector &A) const;
	bool operator>(const Vector &A) const;
	bool operator>=(const Vector &A) const;
	bool operator<(const Vector &A) const;
	bool operator<=(const Vector &A) const;

	operator sf::Vector2f() const;

public:
	inline static float det(const Vector &A, const Vector &B) {
		return A.x * B.y - A.y * B.x;
	}
	static bool intersect(const Vector &po, const Vector &p1, const Vector &p2, const Vector &p3);
	inline static bool equal(const Vector &a, const Vector &b, float eps = 0.1f) {
		return b.distTo2(a) < eps * eps;
	}
};

template<typename T>
inline Vector Vector::operator*(const T & A) const {
	return Vector(x * static_cast<const float>(A), y * static_cast<const float>(A));
}
template<typename T>
inline Vector& Vector::operator*=(const T & A) {
	x *= A;
	y *= A;
	return *this;
}

template<typename T>
inline Vector Vector::operator/(const T & A) const {
	return Vector(x / A, y / A);
}
template<typename T>
inline Vector& Vector::operator/=(const T & A) {
	x /= A;
	y /= A;
	return *this;
}

template<typename T>
inline Vector Vector::operator+(const T & A) const {
	return Vector(x + A, y + A);
}
template<typename T>
inline Vector& Vector::operator+=(const T & A) {
	x += A;
	y += A;
	return *this;
}

template<typename T>
inline Vector Vector::operator-(const T & A) const {
	return Vector(x - A, y - A);
}
template<typename T>
inline Vector& Vector::operator-=(const T & A) {
	x -= A;
	y -= A;
	return *this;
}


