#include <particlesystem/Emitters/explosion_emitter.h>

namespace particlesystem {

ExplosionEmitter::ExplosionEmitter(glm::vec2 position) : m_position(position) {}

void ExplosionEmitter::emit(Particle& particle) const {
    particle.position = m_position;
    particle.velocity = glm::vec2((static_cast<float>(rand()) / RAND_MAX * 4.0f)-2,
                                  (static_cast<float>(rand()) / RAND_MAX * 4.0f)-2);
    particle.force = glm::vec2((static_cast<float>(rand()) / RAND_MAX * 4.0f)-2,
                                (static_cast<float>(rand()) / RAND_MAX * 4.0f)-2);

    particle.color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
    particle.mass = 1.0f;
    particle.size = 5.0f;
    //particle.lifetime = 10.0f;
    particle.lifetime = 10.0f + static_cast<float>(rand()) / RAND_MAX * 4.0f;
    particle.alive = true;
}

}  // namespace particlesystem