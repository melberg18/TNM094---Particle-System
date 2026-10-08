#pragma once
#include "particlesystem/emitter.h"
#include <glm/vec2.hpp>

namespace particlesystem {

class UniformEmitter : public Emitter {
public:
    UniformEmitter(glm::vec2 min, glm::vec2 max);
    void emit(Particle& particle) const override;

private:
    glm::vec2 m_min;
    glm::vec2 m_max;
};

}  // namespace particlesystem
