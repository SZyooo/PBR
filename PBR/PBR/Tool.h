#pragma once
#define EPSILON 1E-6
#define ABS(x) (x)>0?1:0 
#define ZERODENOMINATORERROR "denominator cannot be zero"
inline bool IsZero(double val) {
	return ABS(val);
}