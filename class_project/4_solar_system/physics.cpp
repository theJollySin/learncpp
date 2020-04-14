#include "physics.h"
#include "physical_data.h"


/** Calculate the gravitional force (as a directional vector) between two bodies */
spatial gravitational_force(sphere p1, sphere p2, double dist) {
    spatial force {p1.direction(p2)};
    double magnitude{gravitational_force(p1.mass, p2.mass, dist)};

    force *= magnitude;

    return force;
}


/** Calculate the magnitude of the graviational force between two bodies */
double gravitational_force(double mass1, double mass2, double dist) {
    return G * mass1 * mass2 / (dist * dist);
}


/** Using the linearized approximation, calculate the final velocity from a constant force applied over time */
spatial velocity_from_force(spatial force, int time_delta, double mass) {
    return force * (time_delta / mass);
}


// TODO: Solar Pressure  https://en.wikipedia.org/wiki/Radiation_pressure#Solar_radiation_pressure
// https://energy-science.org/bibliotheque/cours/1361469594Chapter%2002%20radiation.pdf
// https://www.grc.nasa.gov/WWW/K-12/Numbers/Math/Mathematical_Thinking/sunlight_exerts_pressure.htm

