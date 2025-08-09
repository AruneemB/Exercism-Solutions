#include "space_age.h"

namespace space_age {

constexpr double space_age::earth_year_seconds;
constexpr double space_age::mercury_orbit;
constexpr double space_age::venus_orbit;
constexpr double space_age::earth_orbit;
constexpr double space_age::mars_orbit;
constexpr double space_age::jupiter_orbit;
constexpr double space_age::saturn_orbit;
constexpr double space_age::uranus_orbit;
constexpr double space_age::neptune_orbit;

space_age::space_age(double seconds) : seconds_(seconds) {}

double space_age::seconds() const {
    return seconds_;
}

double space_age::on_earth() const {
    return seconds_ / earth_year_seconds;
}

double space_age::on_mercury() const {
    return on_earth() / mercury_orbit;
}

double space_age::on_venus() const {
    return on_earth() / venus_orbit;
}

double space_age::on_mars() const {
    return on_earth() / mars_orbit;
}

double space_age::on_jupiter() const {
    return on_earth() / jupiter_orbit;
}

double space_age::on_saturn() const {
    return on_earth() / saturn_orbit;
}

double space_age::on_uranus() const {
    return on_earth() / uranus_orbit;
}

double space_age::on_neptune() const {
    return on_earth() / neptune_orbit;
}

}  // namespace space_age
