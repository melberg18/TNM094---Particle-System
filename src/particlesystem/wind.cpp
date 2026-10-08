#include <particlesystem/Effects/wind.h>

namespace particlesystem {

Wind::Wind(glm::vec2 wind) : m_wind(wind) {}

glm::vec2 Wind::getForce(const Particle& particle) const { return particle.mass * m_wind; }

}  // namespace particlesystem