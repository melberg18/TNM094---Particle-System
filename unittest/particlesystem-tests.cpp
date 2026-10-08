#include <catch2/catch_all.hpp>
#include <glm/glm.hpp>

#include <particlesystem/particlesystem.h>
#include <particlesystem/Emitters/uniform_emitter.h>

/* Unit tests using the catch2 framework
 * Homepage: https://github.com/catchorg/Catch2
 * Tutorial: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md
 * Docs: https://github.com/catchorg/Catch2/blob/devel/docs/Readme.md
 


 */



TEST_CASE("UniformEmitter spawnar partiklar innanför gränserna", "[uniform_emitter]") {
    glm::vec2 minBound{-1.0f, -1.0f};
    glm::vec2 maxBound{1.0f, 1.0f};
    particlesystem::UniformEmitter emitter{minBound, maxBound};
    particlesystem::Particle p{};
    emitter.emit(p);
    REQUIRE(p.position.x >= minBound.x);
    REQUIRE(p.position.x <= maxBound.x);
    REQUIRE(p.position.y >= minBound.y);
    REQUIRE(p.position.y <= maxBound.y);
}

TEST_CASE("UniformEmitter ger positiv lifetime", "[uniform_emitter]") {
    particlesystem::UniformEmitter emitter{glm::vec2(-1.0f, -1.0f), glm::vec2(1.0f, 1.0f)};
    particlesystem::Particle p{};
    emitter.emit(p);
    REQUIRE(p.lifetime > 0.0f);
}


TEST_CASE("ParticleSystem always contains 1000 particles", "[particlesystem]") {
    const int numParticles = 1000;
    particlesystem::ParticleSystem system{numParticles};

    REQUIRE(system.getPosition().size() == numParticles);
    REQUIRE(system.getSize().size() == numParticles);
    REQUIRE(system.getColor().size() == numParticles);
}

