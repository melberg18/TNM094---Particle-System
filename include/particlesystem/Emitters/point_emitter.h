#pragma once

#include "particlesystem/emitter.h"
#include <glm/vec2.hpp>

namespace particlesystem {

class PointEmitter : public Emitter {
public:
    PointEmitter(glm::vec2 position);
    void emit(Particle& particle) const override;

private:
    glm::vec2 m_position;
};

}  // namespace particlesystem