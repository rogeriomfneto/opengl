#include <iostream>

#define GLM_SWIZZLE
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

void Constructors() {
	std::cout << std::endl;

	glm::vec2 Point0{ 10.0f, 10.0};
	glm::vec3 Point1{ 10.0f, 0.0f, 0.0f };
	glm::vec4 Point2{ 10.0f, 10.0f, 0.0f, 0.0f };
	glm::ivec2 Point3{ 3, 4 };
	glm::bvec3 Point4{ false, true, false };
	glm::dvec2 Point5{ 10.0, 10.0 };
	glm::vec3 Point6{ Point0, 1.0f };
	glm::vec2 Point7{ Point2 };

	std::cout << "Point0: " << glm::to_string(Point0) << std::endl;
	std::cout << "Point1: " << glm::to_string(Point1) << std::endl;
	std::cout << "Point2: " << glm::to_string(Point2) << std::endl;
	std::cout << "Point3: " << glm::to_string(Point3) << std::endl;
	std::cout << "Point4: " << glm::to_string(Point4) << std::endl;
	std::cout << "Point5: " << glm::to_string(Point5) << std::endl;
	std::cout << "Point6: " << glm::to_string(Point6) << std::endl;
	std::cout << "Point7: " << glm::to_string(Point7) << std::endl;

}

void Components() {
	std::cout << std::endl;

	glm::vec3 P{ 1, 2, 3 };

	std::cout << "x: " << P.x << " y: " << P.y << " z: " << P.z << std::endl;
	std::cout << "r: " << P.r << " g: " << P.g << " b: " << P.b << std::endl;
	std::cout << "0: " << P[0] << " 1: " << P[1] << " 2: " << P[2] << std::endl;
}

void Swizzle() {
	std::cout << std::endl;

	glm::vec4 P{ 1, 2, 3, 4 };

	glm::vec3 Q = P.xxx;
	glm::vec3 R = P.xyx;
	glm::vec4 T = P.xyzw;
	glm::vec4 Y = P.xzzw;

	std::cout << glm::to_string(Y) << std::endl;
}

void Operations() {
	glm::vec3 P0{ 10.0f, 10.f, 0.0f };
	glm::vec3 P1{ 10.0f, 10.f, 10.0f };

	glm::vec3 R;

	R = P0 + P1;
	std::cout << glm::to_string(R) << std::endl;

	R = P0 - P1;
	std::cout << glm::to_string(R) << std::endl;

	R = P0 * 5.0f;
	std::cout << glm::to_string(R) << std::endl;

	R = P0 * P1;
	std::cout << glm::to_string(R) << std::endl;

	float L = glm::length(P0);
	std::cout << L << std::endl;

	glm::vec3 Norm = glm::normalize(P0);
	std::cout << glm::to_string(Norm) << std::endl;

	float Dot = glm::dot(P0, P1);
	std::cout << Dot << std::endl;

	glm::vec3 Cross = glm::cross(P0, P1);
	std::cout << glm::to_string(Cross) << std::endl;

	float Distance = glm::distance(P0, P1);
	std::cout << Distance << std::endl;

	glm::vec3 Refract = glm::refract(P0, Norm, 1.0f);
	std::cout << glm::to_string(Refract) << std::endl;

	glm::vec3 Reflect = glm::reflect(P0, Norm);
	std::cout << glm::to_string(Reflect) << std::endl;
}

//int main() {
//	Constructors();
//	Components();
//	Swizzle();
//	Operations();
//
//	return 0;
//}