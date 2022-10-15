#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3 {
public:

	//default constructor assumes all values are zeros in vector 
	vec3() : e{0,0,0} {}

	//constructor where we can pass values 
	vec3(double e0, double e1, double e2) : e{e0,e1,e2} {}

	//methods for retrieving each indidivual component of the vector
	double x() const { return e[0];}
	double y() const { return e[1];}
	double z() const { return e[2];}

	//overload the - operator for make every component its opposite in terms of sign
	//add the indexing operator for fast retrieval of values
	vec3 operator-() const {return vec3(-e[0], -e[1], e[2]);}
	double operator[](int i ) const {return e[i];}
	double& operator[](int i ){return e[i];}

	// overload +=, *= , /= for adding and multiplying vectors component wise
	vec3& operator +=(const vec3 &v) {
		e[0] += v.e[0];
		e[1] += v.e[1];
		e[2] += v.e[2];
		return *this;
	}

	vec3& operator *=(const double t){
		e[0] *= t;
		e[1] *= t;
		e[2] *= t;
		return *this;
	}

	//utilize already existing multiplication overloading
	vec3& operator /=(const double t) {
		return *this *= 1/t;
	}

	double length() const {
		return sqrt(length_squared());
	}

	double length_squared() const {
		return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
	}

public:
	double e[3];
};

//type aliases for vec3
using point3 = vec3; //3d point
using color = vec3; //rgb color



//vec3 utility functions

//overloading the << operator to have it print out the contents of a vector
inline std::ostream& operator<<(std::ostream &out, const vec3 &v) {
	return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

//overloading basic mathematical operators for performing operations on vectors
inline vec3 operator+(const vec3 &u, const vec3 &v) {
	return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3 &u, const vec3 &v) {
	return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3 &u, const vec3 &v) {
	return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator*(double t, const vec3 &v) {
	return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vec3 operator*(const vec3 &v, double t) {
	return t * v;
}

inline vec3 operator/(vec3 v, double t) {
	return (1/t) * v;
}

inline double dot(const vec3 &u, const vec3 &v) {
	return u.e[0] * v.e[0] 
		 + u.e[1] * v.e[1]
		 + u.e[2] * v.e[2];
}

inline vec3 cross(const vec3 &u, const vec3 &v) {
	return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
	           u.e[2] * v.e[0] - u.e[0] * v.e[2],
	           u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(vec3 v) {
	return v / v.length();
}

#endif