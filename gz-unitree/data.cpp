#include "data.hpp"
#include <array>
#include <cmath>

std::array<double, 3> BodyAngularVelocityToEulerRates(
    double omega_x, double omega_y, double omega_z,
    double roll, double pitch)
{
    double sr = std::sin(roll);
    double cr = std::cos(roll);
    double tp = std::tan(pitch);
    double cp = std::cos(pitch);

    // Guard against division by zero (near pitch = ±90°)
    const double epsilon = 1e-6;
    if (std::abs(cp) < epsilon) {
        cp = (cp >= 0) ? epsilon : -epsilon;
    }

    // Angular velocity vector
    double omega[3] = {omega_x, omega_y, omega_z};

    // Compute Euler rates
    double roll_dot  = omega_x + sr * tp * omega_y + cr * tp * omega_z;
    double pitch_dot =         cr * omega_y         - sr * omega_z;
    double yaw_dot   =         sr / cp * omega_y    + cr / cp * omega_z;

    return {roll_dot, pitch_dot, yaw_dot};
}
