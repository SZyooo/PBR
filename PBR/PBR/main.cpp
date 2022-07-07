#include"Point.h"
#include"Vector.h"


int main() {
	PBR::Point3i p1,p2(1,2,3);
	PBR::Vec3i v3 = p1 - p2;
	std::cout << PBR::Distance(p1, p2);

}