#pragma once

#include "particle.h"
#include <glm/vec2.hpp>

namespace particlesystem {

class Effect {
public:
    virtual ~Effect() = default;
    //virtual void apply(Particle& particle, float dt) = 0;

    virtual glm::vec2 getForce(const Particle& particle) const = 0;
};

}  // namespace particlesystem