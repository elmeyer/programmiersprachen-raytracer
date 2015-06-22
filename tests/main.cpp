#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "sphere.hpp"
#include "box.hpp"

TEST_CASE("Sphere default construction", "[constructor]") {
        Sphere s{};
        glm::vec3 c{0.0, 0.0, 0.0};
        REQUIRE(s.getRadius() == 0.0);
        REQUIRE(s.getCenter() == c);
        REQUIRE(s.getColor().r == 0.0);
        REQUIRE(s.getColor().g == 0.0);
        REQUIRE(s.getColor().b == 0.0);
        REQUIRE(s.getName() == "");
}

TEST_CASE("Sphere construction", "[constructor]") {
        glm::vec3 c{1.0, 1.0, 1.0};
        Sphere s{c, 5.0, "Sphere", Color{1.0, 1.0, 1.0}};
        REQUIRE(s.getRadius() == 5.0);
        REQUIRE(s.getCenter() == c);
        REQUIRE(s.getColor().r == 1.0);
        REQUIRE(s.getColor().g == 1.0);
        REQUIRE(s.getColor().b == 1.0);
        REQUIRE(s.getName() == "Sphere");
}

/*
TEST_CASE("Sphere move construction", "[constructor]") {
        Sphere s1{5.0};
        Sphere s2(std::move(s1));
        glm::vec3 c{0.0, 0.0, 0.0};
        REQUIRE(s2.getRadius() == 5.0);
        REQUIRE(s2.getCenter() == c);
        REQUIRE(s1.getRadius() == 0.0);
        REQUIRE(s1.getCenter() == c);
}
*/
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
        REQUIRE(b.getColor().r == 0.0);
        REQUIRE(b.getColor().g == 0.0);
        REQUIRE(b.getColor().b == 0.0);
        REQUIRE(b.getName() == "");
}

TEST_CASE("Box construction", "[constructor]") {
        glm::vec3 min{1.0, 1.0, 1.0};
        glm::vec3 max{5.0, 5.0, 5.0};
        Box b{min, max, "Box", Color{1.0, 1.0, 1.0}};
        REQUIRE(b.getMin() == min);
        REQUIRE(b.getMax() == max);
        REQUIRE(b.getColor().r == 1.0);
        REQUIRE(b.getColor().g == 1.0);
        REQUIRE(b.getColor().b == 1.0);
        REQUIRE(b.getName() == "Box");
}
/*
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
*/
TEST_CASE("Box area calculation", "[area]") {
        glm::vec3 min{1.0, 1.0, 1.0};
        glm::vec3 max{5.0, 5.0, 5.0};
        Box b{min, max};
        REQUIRE(b.area() == Approx(96.0));
}

TEST_CASE("Box volume calculation", "[volume]") {
        glm::vec3 min{1.0, 1.0, 1.0};
        glm::vec3 max{5.0, 5.0, 5.0};
        Box b{min, max};
        REQUIRE(b.volume() == Approx(64.0));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
