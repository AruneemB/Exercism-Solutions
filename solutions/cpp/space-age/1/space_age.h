#pragma once

namespace space_age {

class space_age {
  private:
    double seconds_;

    static constexpr double earth_year_seconds = 31557600.0;
    static constexpr double mercury_orbit = 0.2408467;
    static constexpr double venus_orbit = 0.61519726;
    static constexpr double earth_orbit = 1.0;
    static constexpr double mars_orbit = 1.8808158;
    static constexpr double jupiter_orbit = 11.862615;
    static constexpr double saturn_orbit = 29.447498;
    static constexpr double uranus_orbit = 84.016846;
    static constexpr double neptune_orbit = 164.79132;

  public:
    explicit space_age(double seconds);

    double seconds() const;
    double on_earth() const;
    double on_mercury() const;
    double on_venus() const;
    double on_mars() const;
    double on_jupiter() const;
    double on_saturn() const;
    double on_uranus() const;
    double on_neptune() const;
};

}  // namespace space_age
