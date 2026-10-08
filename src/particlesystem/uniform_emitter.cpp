#include <particlesystem/Emitters/uniform_emitter.h>
#include <cstdlib>

namespace particlesystem {

UniformEmitter::UniformEmitter(glm::vec2 min, glm::vec2 max) : m_min(min), m_max(max) {}

void UniformEmitter::emit(Particle& particle) const {
    auto randRange = [](float min, float max) {
        return min + static_cast<float>(rand()) / RAND_MAX * (max - min);
    };

    particle.position = glm::vec2(randRange(m_min.x, m_max.x), randRange(m_min.y, m_max.y));
    particle.velocity = glm::vec2(0.0f, 0.0f);
    particle.force    = glm::vec2(0.0f, 0.0f);
    particle.color    = glm::vec4(
        static_cast<float>(rand()) / RAND_MAX,
        static_cast<float>(rand()) / RAND_MAX,
        static_cast<float>(rand()) / RAND_MAX,
        1.0f);
    particle.mass     = 1.0f;
    particle.size     = 5.0f;
    particle.lifetime = 3.0f + static_cast<float>(rand()) / RAND_MAX * 4.0f;
    particle.alive    = true;
}

}  // namespace particlesystem
