#pragma once

#include <glm/vec2.hpp>
#include <glm/vec4.hpp>

namespace particlesystem {

struct Particle {
    glm::vec2 position;
    glm::vec2 velocity;
    glm::vec2 force;

    glm::vec4 color;

    float mass;
    float size;
    float lifetime;

    bool alive;
};

}  // namespace particlesystem