#pragma once

#include "particlesystem/emitter.h"
#include <glm/vec2.hpp>

namespace particlesystem {

class ExplosionEmitter : public Emitter {
public:
    ExplosionEmitter(glm::vec2 position);
    void emit(Particle& particle) const override;

private:
    glm::vec2 m_position;
};

}  // namespace particlesystem