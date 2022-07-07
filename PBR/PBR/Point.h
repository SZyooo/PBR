#pragma once
#include<iostream>
#include"Tool.h"
namespace PBR {
	template<typename T>
	class Point3;
	template<typename T>
	class Vector3;
	template<typename T>
	class Vector2;
	template<typename T>
	class Point2 {
	public:
		explicit Point2(const Point3<T>& p3);
		Point2() :x(0), y(0){}
		Point2(const T& xx, const T& yy) :x(xx), y(yy) {}
		template<typename T2> Point2(const Point2<T2>& p2):x((T)p2.x),y((T)p2.y){}
		template<typename T2> Point2(const Vector2<T2>& p2):x((T)p2.x),y((T)p2.y){}
		Point2(const Point2<T>& p2):x(p2.x),y(p2.y){}
		operator Vector2<T>() const {
			return Vector2<T>(x, y);
		}
		Point2& operator=(const Point2<T>& p2) {
			x = p2.x;
			y = p2.y;
			return *this;
		}
		friend std::ostream operator <<(std::ostream& os, const Point2<T>& p){
			os << "[" << p.x << "," << p.y << "]";
			return os;
		}
		const Point2<T> operator +(const Point2<T>& p) const {
			return Point2<T>(x + p.x,y+p.y);
		}
		const Point2<T> operator +(const Vector2<T>& v2) const {
			return Point2<T>(x+v2.x,y+v2.x);
		}
		Point2<T>& operator+=(const Point2<T>& p) {
			x += p.x;
			y += p.y;
			return *this;
		}
		Point2<T>& operator+=(const Vector2<T>& v) {
			x += v.x;
			y += v.y;
			return *this;
		}
		const Vector2<T> operator-(const Point2<T>& p)const {
			return Vector2<T>(x + p.x, y + p.y);
		}
		const Point2<T> operator-(const Vector2<T>& v) const{
			return Point2<T>(x - v.x, y - v.y);
		}
		Point2<T>& operator-=(const Vector2<T>& v) {
			x -= v.x;
			y -= v.y;
			return *this;
		}
		Point2<T>& operator-() {
			x = -x;
			y = -y;
			return *this;
		}
		const Point2<T> operator*(const T&v)const {
			return Point2<T>(x * v, y * v);
		}
		Point2<T>& operator*=(const T& v) {
			x *= v;
			y *= v;
			return *this;
		}
		const Point2<T> operator/(const T& v)const {
			if (IsZero(v)) {
				throw ZERODENOMINATORERROR;
			}
			double inv = 1.d / v;
			return (* this)* inv;
		}
		Point2<T>& operator/=(const T& v) {
			if (IsZero(v)) {
				throw ZERODENOMINATORERROR;
			}
			double inv = 1.d / v;
			x *= inv;
			y *= inv;
			return *this;
		}
		T operator[](size_t idx)const {
			if (idx < 0 || idx >= 2) {
				throw "Index out of Point2's range";
			}
			if (idx == 0)return x;
			return y;
		}
		T& operator[](size_t idx) {
			if (idx < 0 || idx >= 2) {
				throw "Index out of Point2's range";
			}
			if (idx == 0)return x;
			return y;
		}
		bool operator==(const Point2<T>& p2) {
			return x == p2.x && y == p2.y;
		}
		bool operator !=(const Point2<T>& p2) {
			return !(*this == p2);
		}

		T x, y;
	};

	template<typename T>
	class Point3 {
	public:
		Point3(const T&px,const T&py,const T&pz)
			:x(px),y(py),z(pz){}
		Point3()
			:x(0),y(0),z(0){}
		template<typename U> Point3(const Point3<U>& p)
			:x((T)p.x),y((T)p.y),z((T)p.z){}
		Point3(const Point3<T>& p)
			:x(p.x),y(p.y),z(p.z){}
		operator Vector3<T>() const {
			return Vector3<T>(x, y, z);
		}
		Point3& operator=(const Point3<T>& p3) {
			x = p3.x;
			y = p3.y;
			z = p3.z;
			return *this;
		}
		friend std::ostream& operator<<(std::ostream& os, const Point3<T>& p) {
			os << "[" << p.x << "," << p.y << "," << p.z << "]";
			return os;
		}
		const Point3 operator+(const Point3<T>& p) const { return Point3<T>(x + p.x, y + p.y, z + p.z); }
		const Point3 operator+(const Vector3<T>& v)const { return Point3<T>(x + v.x, y + v.y, z + v.z); }
		Point3& operator+=(const Point3<T>& p) { *this = *this + p; return *this; }
		Point3& operator+=(const Vector3<T>& v) { *this = *this + v; return *this; }
		const Vector3<T> operator-(const Point3<T>& p)const { return Vector3<T>(x - p.x, y - p.y, z - p.z); }
		const Point3<T> operator-(const Vector3<T>& v)const { return Point3<T>(x - v.x, y - v.y, z - v.z); }
		Point3& operator-=(const Vector3<T>& v) { *this = *this - v; return *this; }
		const Point3 operator*(const T&v)const { return Point3<T>(x*v, y*v, z *v); }
		Point3& operator*=(const T& v) { *this = *this * v; return *this; }
		const Point3 operator/(const T& v)const 
		{
			if (IsZero(v)) throw ZERODENOMINATORERROR; double inv = 1 / v; return Point3<T>(x * inv, y * inv, z * inv);
		}
		Point3& operator/=(const T& v) { *this = *this / v; return *this; }
		Point3& operator-() { x = -x; y = -y; z = -z; return *this; }
		T operator[](size_t idx)const {
			if (idx < 0 || idx >= 3)
				throw "Index out of Point3's range";
			if (idx == 0) return x;
			else if (idx == 1)return y;
			else return z;
		}
		T& operator[](size_t idx) {
			if (idx < 0 || idx >= 3)
				throw "Index out of Point3's range";
			if (idx == 0) return x;
			else if (idx == 1)return y;
			else return z;
		}
		bool operator ==(const Point3<T>& p) { return x == p.x && y == p.y && z == p.z; }
		bool operator !=(const Point3<T>& p) { return !(*this == p); }

		T x, y, z;
	};

	template<typename T>
	Point2<T>::Point2(const Point3<T>& p3):x(p3.x),y(p3.y) {}

	template<typename T> double Distance(const Point2<T>& p1, const Point2<T>& p2) { return (p1 - p2).Length(); }
	template<typename T> double DistanceSquared(const Point2<T>& p1, const Point2<T>& p2) { return (p1 - p2).LengthSquared(); }
	template<typename T> double Distance(const Point3<T>& p1, const Point3<T>& p2) { return (p1 - p2).Length(); }
	template<typename T> double DistanceSquared(const Point3<T>& p1, const Point3<T>& p2) { return (p1 - p2).LengthSquared(); }
	template<typename T> Point2<T> Lerp(float t, const Point2<T>& p1, const Point2<T>& p2) { return (1 - t) * p1 + t * p2; }
	template<typename T> Point3<T> Lerp(float t, const Point3<T>& p1, const Point3<T>& p2) { return (1 - t) * p1 + t * p2; }
	template<typename T> Point2<T> Floor(const Point2<T>& p) { return Point2<T>(std::floor(p.x), std::floor(p.y)); }
	template<typename T> Point3<T> Floor(const Point3<T>& p) { return Point3<T>(std::floor(p.x), std::floor(p.y), std::floor(p.z)); }
	template<typename T> Point2<T> Ceil(const Point2<T>& p) { return Point2<T>(std::ceil(p.x), std::ceil(p.y)); }
	template<typename T> Point3<T> Ceil(const Point3<T>& p) { return Point3<T>(std::ceil(p.x), std::ceil(p.y), std::ceil(p.z)); }
	template<typename T> Point2<T> Abs(const Point2<T>& p) { return Point2<T>(std::abs(p.x), std::abs(p.y)); }
	template<typename T> Point3<T> Abs(const Point3<T>& p) { return Point3<T>(std::abs(p.x), std::abs(p.y), std::abs(p.z)); }
	template<typename T> Point2<T> Permute(const Point2<T>& p, size_t x, size_t y) { return Point2<T>(p[x], p[y]); }
	template<typename T> Point3<T> Permute(const Point3<T>& p, size_t x, size_t y, size_t z) { return Point3<T>(p[x], p[y], p[z]); }
	typedef Point2<float> Point2f;
	typedef Point2<int> Point2i;
	typedef Point3<float> Point3f;
	typedef Point3<int> Point3i;
}




