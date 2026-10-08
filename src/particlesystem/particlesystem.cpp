#include <particlesystem/particlesystem.h>
#include <fmt/format.h>

namespace particlesystem {

ParticleSystem::ParticleSystem(int numParticles) {
    
    m_particles.resize(numParticles);
    m_positions.resize(numParticles);
    m_sizes.resize(numParticles);
    m_colors.resize(numParticles);

}

void ParticleSystem::respawnDeadParticles() {
    for(auto& particle : m_particles) {

        if(!particle.alive) {

            if(!m_emitters.empty()) {

                m_emitters[0]->emit(particle);
            }
        }
    }
}

void ParticleSystem::accumulateForces() {
    for(auto& particle : m_particles) {

        if(!particle.alive) {
            continue;
        }

        particle.force = glm::vec2(0.0f, 0.0f);

        for(auto& effect : m_effects) {

            particle.force += effect->getForce(particle);

        } 
    }
}

void ParticleSystem::updateLifetimes(float dt) {
    for (auto& particle : m_particles) {
        if (!particle.alive) {
            continue;
        }        

        particle.lifetime -= dt;

        if (particle.lifetime <= 0.0f) {
            particle.alive = false;
        }
    }
}


void ParticleSystem::integrate(float dt) {
    for (auto& particle : m_particles) {
        if (!particle.alive) {
            continue;
        }

        glm::vec2 acceleration = particle.force / particle.mass;

        particle.velocity += acceleration * dt;
        particle.position += particle.velocity * dt;
    }
}


void ParticleSystem::syncRenderData() {
    for (size_t i = 0; i < m_particles.size(); i++) {
        m_positions[i] = m_particles[i].position;
        m_sizes[i] = m_particles[i].size;
        m_colors[i] = m_particles[i].color;
    }
}


void ParticleSystem::update(float time, float speed) {
    float dt = (time - m_lastTime) * speed;
    m_lastTime = time;

    static int frameCount = 0;
    if (frameCount++ % 60 == 0) {
        fmt::print("[{}][{}][Line {}] dt={:.4f}, particles={}\n",
            __FILE__, __FUNCTION__, __LINE__, dt, m_particles.size());
    }

    respawnDeadParticles();
    accumulateForces();
    integrate(dt);
    updateLifetimes(dt);
    syncRenderData();
}


void ParticleSystem::addEmitter(std::unique_ptr<Emitter> emitter) {
    m_emitters.push_back(std::move(emitter));
}

void ParticleSystem::addEffect(std::unique_ptr<Effect> effect) {
    m_effects.push_back(std::move(effect));
}


const std::vector<glm::vec2>& ParticleSystem::getPosition() const { return m_positions; }

const std::vector<float>& ParticleSystem::getSize() const { return m_sizes; }

const std::vector<glm::vec4>& ParticleSystem::getColor() const { return m_colors; }



}