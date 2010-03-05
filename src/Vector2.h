#ifndef _VECTOR2_H
#define _VECTOR2_H

#include <cmath>
#include <iosfwd>

template<class T>
class Vector2
{
	public:
		Vector2()
		{
			set(T(), T());
		}
		
		Vector2(T new_x, T new_y)
		{
			set(new_x, new_y);
		}
		
		Vector2(T value)
		{
			set(value, value);
		}

		void set(T new_x, T new_y)
		{
			x() = new_x;
			y() = new_y;
		}

		T& x(){return _c[0];}
		T& y(){return _c[1];}
		T x() const{return _c[0];}
		T y() const{return _c[1];}

		void operator=(T value)
		{
			set(value, value);
		}

		void operator+=(const Vector2& other)
		{
			set(x() + other.x(), y() + other.y());
		}
		void operator-=(const Vector2& other)
		{
			set(x() - other.x(), y() - other.y());
		}
		void operator*=(T factor)
		{
			set(x() * factor, y() * factor);
		}
		void operator/=(T factor)
		{
			set(x() / factor, y() / factor);
		}
		
		T lengthSquared() const
		{
			return x()*x() + y()*y();
		}
		T length() const
		{
			return std::sqrt(lengthSquared());
		}
		void normalize()
		{
			operator/=(length());
		}
		void invert()
		{
			x() = -x();
			y() = -y();
		}
		
		operator const T*() const
		{
			return _c;
		}
		
		template <class U>
		Vector2<U> convert() const
		{
			return Vector2<U>(static_cast<U>(x()), static_cast<U>(y()));
		}
		
		private:
			T _c[2];
};

template<class T>
inline const Vector2<T> operator+(const Vector2<T>& one, const Vector2<T>& two)
{
	return Vector2<T>(one.x() + two.x(), one.y() + two.y());
}
template<class T>
inline const Vector2<T> operator-(const Vector2<T>& one, const Vector2<T>& two)
{
	 return Vector2<T>(one.x() - two.x(), one.y() - two.y());
}
template<class T>
inline const Vector2<T> operator-(const Vector2<T>& one)
{
	return Vector2<T>(-one.x(), -one.y());
}
template<class T>
inline const Vector2<T> operator*(const Vector2<T>& one, T factor)
{
	return Vector2<T>(one.x() * factor, one.y() * factor);
}
template<class T>
inline const Vector2<T> operator*(T factor, const Vector2<T>& one)
{
	return Vector2<T>(one.x() * factor, one.y() * factor);
}
template<class T>
inline const Vector2<T> operator/(const Vector2<T>& one, T factor)
{
	return Vector2<T>(one.x() / factor, one.y() / factor);
}

template<class T>
inline T operator*(const Vector2<T>& one, const Vector2<T>& two){ //dotproduct
	return one.x() * two.x() + one.y() * two.y();
}

template<class T>
inline bool operator==(const Vector2<T>& one, const Vector2<T>& two)
{
	return one.x() == two.x() && one.y() == two.y();
}
template<class T>
inline bool operator!=(const Vector2<T>& one, const Vector2<T>& two)
{
	return !(one == two);
}
/*
template<class T>
std::ostream& operator<<(std::ostream& os, const Vector2<T>& vec)
{
	os << '(' << vec.x() << ',' << ' ' << vec.y() << ')';
	return os;
}
*/
typedef Vector2<float> Vector2f;
typedef Vector2<int> Vector2i;
typedef Vector2<size_t> Vector2u;

#endif //_VECTOR2_H
