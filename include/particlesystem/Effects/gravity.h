#pragma once

#include "particlesystem/effect.h"
#include <glm/vec2.hpp>

namespace particlesystem {

class Gravity : public Effect {
public:
    Gravity(glm::vec2 center, float strength);

    glm::vec2 getForce(const Particle& particle) const override;

private:
    glm::vec2 m_center;
    float m_strength;
};

}  // namespace particlesystem