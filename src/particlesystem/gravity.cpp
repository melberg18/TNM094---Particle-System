#include <particlesystem/Effects/gravity.h>
#include <glm/geometric.hpp>   // length, normalize

namespace particlesystem {

Gravity::Gravity(glm::vec2 center, float strength) : m_center(center), m_strength(strength) {}

glm::vec2 Gravity::getForce(const Particle& particle) const {

    glm::vec2 direction = m_center - particle.position; //Berakna vector riktning till centrum
    float distance = glm::length(direction);

    /*if (distance < 0.001f) {
        return glm::vec2(0.0f, 0.0f);
    }*/

    glm::vec2 unitDirection = glm::normalize(direction);

    float forceMagnitude = m_strength * particle.mass / (distance * distance);

    return unitDirection * forceMagnitude;
}

}  // namespace particlesystem