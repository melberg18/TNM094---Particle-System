#pragma once

#include "particlesystem/effect.h"
#include <glm/vec2.hpp>

namespace particlesystem {

class Wind : public Effect {
public:
    Wind(glm::vec2 wind);

    glm::vec2 getForce(const Particle& particle) const override;

private:
    glm::vec2 m_wind;
};

}  // namespace particlesystem
