#pragma once

#include "particle.h"


namespace particlesystem {

class Emitter {
public:
    virtual ~Emitter() = default;
    virtual void emit(Particle& particle) const = 0;
};

}  // namespace particlesystem