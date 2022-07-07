#pragma once
#include <iostream>
#include "Tool.h"
namespace PBR {
	template<typename T> 
	class Vector2 {
	public:
		Vector2():x(0),y(0){}
		Vector2(const T&px,const T&py):x(px),y(py){}
		explicit Vector2( const Vector2<T>& v):x(v.x), y(v.y){}
		Vector2& operator=(const Vector2<T>& v){
			x = v.x;
			y = v.y;
			return *this;
		}
		friend std::ostream& operator<<(std::ostream& os , const Vector2& v){
			os <<"["<< v.x<<"," << v.y<<"]";
			return os;
		}
		Vector2 operator+(const Vector2<T>& v) const {
			return Vector2(x + v.x, y + v.y);
		}
		Vector2 operator+=(const Vector2<T>& v) {
			x += v.x;
			y += v.y;
			return *this;
		}
		Vector2 operator-(const Vector2<T>& v) const {
			return Vector2(x - v.x, y - v.y);
		}
		Vector2& operator-=(const Vector2<T>& v) {
			x -= v.x;
			y -= v.y;
			return *this;
		}
		bool operator==(const Vector2<T>& v) const {
			return x == v.x && y == v.y;
		}
		bool operator!=(const Vector2<T>& v)const {
			return !(*this == v);
		}
		Vector2 operator *(const T& val) const{
			return Vector2(x * val, y * val);
		}
		Vector2 operator /(const T& val)const {
			if (IsZero(val)) {
				throw "denominator cannot be zero";
			}
			T inv = 1.0f / val;
			return Vector2(x * inv,y * inv);
		}
		Vector2 operator /=(const T& val) {
			if (IsZero(val)) {
				throw ZERODENOMINATORERROR;
			}
			T inv = 1.0f / val;
			x = x * inv;
			y = y * inv;
			return *this;
		}
		Vector2 operator-() { return Vector2(-x,-y); }
		T operator[](size_t idx) const{
			if (idx < 0 || idx >= 2)
				throw "index out of vector2's range";
			return idx == 0 ? x : y;
		}
		T& operator[](size_t idx) {
			if (idx < 0 || idx >= 2)
				throw "index out of vector2's range";
			return idx == 0 ? x : y;
		}
		T LengthSquared() const { return x * x + y * y; }
		double Length() const { return std::sqrt(LengthSquared()); }
	public:
		T x, y;
	};
	template<typename T>
	class Vector3 {
	public:
		Vector3():x(0),y(0),z(0){}
		Vector3(const T&px,const T& py,const T&pz):x(px),y(py),z(pz){}
		Vector3(const Vector3<T>& v):x(v.x),y(v.y),z(v.z){}
		Vector3& operator=(const Vector3& v) {
			x = v.x;
			y = v.y;
			z = v.z;
			return *this;
		}
		friend std::ostream& operator<<(std::ostream& os, const Vector3<T>& v) {
			os << "[" << v.x << "," << v.y << "," << v.z << "]";
			return os;
		}
		Vector3 operator+(const Vector3& v) const {
			return Vector3(x + v.x, y + v.y, z + v.z);
		}
		Vector3 operator +=(const Vector3& v) {
			x += v.x;
			y += v.y;
			z += v.z;
			return *this;
		}
		Vector3 operator-(const Vector3& v) const{
			return Vector3(x - v.x, y - v.y, z - v.z);
		}
		Vector3 operator-() const {
			return Vector3(-x, -y, -z);
		}
		Vector3& operator-=(const Vector3&v) {
			x -= v.x;
			y -= v.y;
			z -= v.z;
			return *this;
		}
		Vector3 operator *(const Vector3& v) const {
			return Vector3(x * v.x, y * v.y, z * v.z);
		}
		Vector3 operator *=(const Vector3& v) {
			x *= v.x;
			y *= v.y;
			z *= v.z;
			return *this;
		}
		Vector3 operator/(const T& val) const{
			if (val == 0)
				throw ZERODENOMINATORERROR;
			T inv = 1.f / val;
			return Vector3(x * inv, y * inv, z * inv);
		}
		Vector3 operator/=(const T& val) {
			*this = *this / val;
			return *this;
		}
		bool operator ==(const Vector3& v) const {
			return x == v.x && y == v.y && z == v.z;
		}
		bool operator !=(const Vector3& v) const {
			return !(*this == v);
		}
		T operator[](size_t idx)const {
			if (idx < 0 || idx >= 3)
				throw "index out of vector3's range";
			if (idx == 0)
				return x;
			else if (idx == 1)
				return y;
			else
				return z;
		}
		T& operator[](size_t idx) {
			if (idx < 0 || idx >= 3)
				throw "index out of vector3's range";
			if (idx == 0)
				return x;
			else if (idx == 1)
				return y;
			else
				return z;
		}
		T LengthSquared() const {
			return x * x + y * y + z * z;
		}
		double Length()const  {
			return std::sqrt(LengthSquared());
		}
	public:
		T x, y, z;
	};
	template<typename T>
	T Dot(const Vector2<T>& v1, const Vector2<T>& v2) {
		return v1.x * v2.x + v1.y * v2.y;
	}
	template<typename T>
	T Dot(const Vector3<T>& v1, const Vector3<T>& v2) {
		return v1.x * v2.x + v1.y * v2.y + v2.x * v2.y;
	}
	template<typename T>
	Vector3<T> Cross(const Vector3<T>& v1, const Vector3<T>& v2) {
		return Vector3<T>(
			v1.y * v2.z - v1.z * v2.y,
			v1.z * v2.x - v1.x * v2.z,
			v1.x * v2.y - v1.y * v2.x
			);
	}
	template<typename T>
	Vector2<T> Normalize(const Vector2<T>& v) {
		T len = v.Length();
		return v / len;
	}
	template<typename T>
	Vector3<T> Normalize(const Vector3<T>& v) {
		T len = v.Length();
		return v / len;
	}
	template<typename T>
	T MinComponent(const Vector3<T>& v) {
		return std::min(v.x,std::min(v.y,v.z));
	}
	template<typename T>
	T MinComponent(const Vector2<T>& v) {
		return std::min(v.x, v.y);
	}
	template<typename T>
	T MaxComponent(const Vector3<T>& v) {
		return std::max(v.x, std::max(v.y, v.z));
	}
	template<typename T>
	T MaxComponent(const Vector2<T>& v) {
		return std::min(v.x,v.y);
	}
	template<typename T>
	size_t MinDimension(Vector2<T>& v) {
		return v.x > v.y ? 1 : 0;
	}
	template<typename T>
	size_t MinDimension(Vector3<T>& v) {
		size_t idx = v.x > v.y ? 1 : 0;
		return v[idx] > v.z ? 2 : idx;
	}
	template<typename T>
	size_t MaxDimension(Vector2<T>& v) {
		return v.x < v.y ? 1 : 0;
	}
	template<typename T>
	size_t MaxDimension(Vector3<T>& v) {
		size_t idx = v.x < v.y ? 1 : 0;
		return v[idx] < v.z ? 2 : idx;
	}
	template<typename T>
	Vector2<T> Min(const Vector2<T>& v1, const Vector2<T>& v2) {
		return Vector2<T>(std::min(v1.x,v2.x),std::min(v1.y,v2.y));
	}
	template<typename T>
	Vector3<T> Max(const Vector3<T>& v1, const Vector3<T>& v2) {
		return Vector3<T>(std::min(v1.x,v2.x),std::min(v1.y,v2.y),std::min(v1.z,v2.z));
	}
	template<typename T>
	Vector3<T> Permute(Vector3<T>& v, size_t nx, size_t ny, size_t nz) {
		return Vector3<T>(v[nx],v[ny],v[nz]);
	}
	template<typename T>
	void CoordinateSystem(const Vector3<T>& norm, Vector3<T>& recv_second_dim, Vector3<T>& recv_third_dim) {
		if (norm.x > norm.y) {
			recv_second_dim.x = -norm.z;
			recv_second_dim.y = 0;
			recv_second_dim.z = norm.x;
			recv_second_dim = Normalize(recv_second_dim);
		}
		else {
			recv_second_dim.x = 0;
			recv_second_dim.y = -norm.z;
			recv_second_dim.z = norm.y;
			recv_second_dim = Normalize(recv_second_dim);
		}
		recv_third_dim = Cross(norm, recv_second_dim);
	}
	typedef Vector2<float> Vec2f;
	typedef Vector3<float> Vec3f;
	typedef Vector2<int> Vec2i;
	typedef Vector3<int> Vec3i;
}