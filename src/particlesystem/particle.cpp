#pragma once

#include <glm/vec2.hpp>
#include <glm/vec4.hpp>

namespace particlesystem {

struct Particle {
    
    glm::vec2 position{0.0f, 0.0f};
    glm::vec2 velocity{0.0f, 0.0f};
    glm::vec2 force{0.0f, 0.0f};

    glm::vec4 color{1.0f, 1.0f, 1.0f, 1.0f};

    float mass{1.0f};
    float size{5.0f};
    float lifetime{0.0f};

    bool alive{false};
};

}  // namespace particlesystem