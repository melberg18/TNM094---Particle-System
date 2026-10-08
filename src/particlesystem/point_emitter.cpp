#include <particlesystem/Emitters/point_emitter.h>

namespace particlesystem {

PointEmitter::PointEmitter(glm::vec2 position) : m_position(position) {}

void PointEmitter::emit(Particle& particle) const {
    particle.position = m_position;
    particle.velocity = glm::vec2(1.0f, 0.0f);
    particle.force = glm::vec2(1.0f, 0.0f);

    particle.color =
        glm::vec4(static_cast<float>(rand()) / RAND_MAX, static_cast<float>(rand()) / RAND_MAX,
                  static_cast<float>(rand()) / RAND_MAX, 1.0f);
    particle.mass = 1.0f;
    particle.size = 5.0f;
    //particle.lifetime = 5.0f;
    particle.lifetime = 3.0f + static_cast<float>(rand()) / RAND_MAX * 4.0f;
    particle.alive = true;
}

}  // namespace particlesystem