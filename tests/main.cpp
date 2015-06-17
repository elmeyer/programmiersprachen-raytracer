#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "sphere.hpp"
#include "box.hpp"

TEST_CASE("Sphere default construction", "[constructor]") {
        Sphere s{};
        glm::vec3 c{0.0, 0.0, 0.0};
        REQUIRE(s.getRadius() == 0.0);
        REQUIRE(s.getCenter() == c);
}

TEST_CASE("Sphere construction", "[constructor]") {
        glm::vec3 c{1.0, 1.0, 1.0};
        Sphere s{c, 5.0};
        REQUIRE(s.getRadius() == 5.0);
        REQUIRE(s.getCenter() == c);
}

TEST_CASE("Sphere radius-only construction", "[constructor]") {
        Sphere s{5.0};
        glm::vec3 c{0.0, 0.0, 0.0};
        REQUIRE(s.getRadius() == 5.0);
        REQUIRE(s.getCenter() == c);
}

TEST_CASE("Sphere copy construction", "[constructor]") {
        Sphere s1{5.0};
        Sphere s2(s1);
        REQUIRE(s2.getRadius() == s1.getRadius());
        REQUIRE(s2.getCenter() == s1.getCenter());
}

TEST_CASE("Sphere move construction", "[constructor]") {
        Sphere s1{5.0};
        Sphere s2(std::move(s1));
        glm::vec3 c{0.0, 0.0, 0.0};
        REQUIRE(s2.getRadius() == 5.0);
        REQUIRE(s2.getCenter() == c);
        REQUIRE(s1.getRadius() == 0.0);
        REQUIRE(s1.getCenter() == c);
}

TEST_CASE("Sphere area calculation", "[area]") {
        Sphere s{1.0};
        REQUIRE(s.area() == Approx(12.566370614359173));
}

TEST_CASE("Sphere volume calculation", "[volume]") {
        Sphere s{1.0};
        REQUIRE(s.volume() == Approx(4.188790204786391));
}

TEST_CASE("Box default construction", "[constructor]") {
        Box b{};
        glm::vec3 p{0.0, 0.0, 0.0};
        REQUIRE(b.getMin() == p);
        REQUIRE(b.getMax() == p);
}

TEST_CASE("Box construction", "[constructor]") {
        glm::vec3 min{1.0, 1.0, 1.0};
        glm::vec3 max{5.0, 5.0, 5.0};
        Box b{min, max};
        REQUIRE(b.getMin() == min);
        REQUIRE(b.getMax() == max);
}

TEST_CASE("Box copy construction", "[constructor]") {
        glm::vec3 min{1.0, 1.0, 1.0};
        glm::vec3 max{5.0, 5.0, 5.0};
        Box b1{min, max};
        Box b2(b1);
        REQUIRE(b2.getMin() == b1.getMin());
        REQUIRE(b2.getMax() == b2.getMax());       
}

TEST_CASE("Box move construction", "[constructor]") {
        glm::vec3 min{1.0, 1.0, 1.0};
        glm::vec3 max{5.0, 5.0, 5.0};
        Box b1{min, max};
        Box b2(std::move(b1));
        REQUIRE(b2.getMin() == min);
        REQUIRE(b2.getMax() == max);
        glm::vec3 p{0.0, 0.0, 0.0};
        REQUIRE(b1.getMin() == p);
        REQUIRE(b1.getMax() == p);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
