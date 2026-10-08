#pragma once

#include <vector>
#include <memory>

#include <glm/vec2.hpp>
#include <glm/vec4.hpp>

#include "particle.h"
#include "emitter.h"
#include "effect.h"

namespace particlesystem {

class ParticleSystem {
public:
    ParticleSystem(int numParticles);

    void update(float time, float speed);

    void addEmitter(std::unique_ptr<Emitter> emitter);
    void addEffect(std::unique_ptr<Effect> effect);

    const std::vector<glm::vec2>& getPosition() const;
    const std::vector<float>& getSize() const;
    const std::vector<glm::vec4>& getColor() const;

private:
    float m_lastTime{0.0f};

    std::vector<Particle> m_particles;
    std::vector<std::unique_ptr<Emitter>> m_emitters;
    std::vector<std::unique_ptr<Effect>> m_effects;

    // Arrayer for rendering
    std::vector<glm::vec2> m_positions;
    std::vector<float> m_sizes;
    std::vector<glm::vec4> m_colors;

    void respawnDeadParticles();
    void accumulateForces();
    void integrate(float dt);
    void updateLifetimes(float dt);
    void syncRenderData();
};

}  // namespace particlesystem