/*
 * classes.cpp
 *
 * The implementation of the classes such as particles and the world.
 */

#include <iostream>
#include <vector>
#include <cmath>
#include "classes.h"

/*
 * G
 *
 * The gravitational constant
 */
const double G = 6.67430 * std::pow(10, -11);
const double TIME_STEP = 0.001;


/*
 * Particle
 *
 * Initialise a particle
 */
Particle::Particle(double _mass, double _x, double _y)
{
    x = _x;
    y = _y;
    mass = _mass;
    ax = 0;
    ay = 0;
    vx = 0;
    vy = 0;
}


/*
 * update
 *
 * Update the position and velocity of a particle over a given time period.
 *
 * Argument: dt
 *    The time period over which to update the position.
 */
void Particle::update(double dt)
{
    // Update position
    x += vx * dt + 0.5 * ax * dt * dt;
    y += vy * dt + 0.5 * ay * dt * dt;
    std::cout << "Updating position";
    std::cout << x << ", " << y;
    // Update velocity
    vx += ax * dt;
    vy += ay * dt;
}


/*
 * add_particle
 *
 * Adds a particle to the world.
 */
void World:: add_particle (const Particle& p)
{
    particles.push_back(p);
}


/*
 * apply_gravity
 *
 * Apply gravity to each particle.
 */
void World:: apply_gravity (void)
{
    /*
     * For each particle, its acceleration is modified by the mass of all
     * the other particles in the world.
     */
    for (auto& p : particles) {
        for (auto& p_other : particles) {
            if (&p != &p_other) {
//                std::cout << "Updating acceleration";
                p.ax -= (G * p_other.mass) / std::pow((p.x - p_other.x), 2);
                p.ay -= (G * p_other.mass) / std::pow((p.y - p_other.y), 2);
               // std::cout << p.ax << ", " << p.ay;
            }
        }
    }
}


/*
 * update_particles
 *
 * Increment the particle positions and velocities over a discrete time
 * period.
 *
 * Argument: dt
 *    The time period over which the particles should be updated.
 */
void World:: update_particles (double dt)
{
    for (auto& p : particles) {
        p.update(dt);
    }
}


/*
 * show_particles
 *
 * Display all the particles in the world
 */
void World::show_particles(void) const {
    for (const auto& p : particles) {
        std::cout << "Particle at (" << p.x << ", " << p.y << ")\n";
    }
    std::cout << "====================\n";
}


/*
 * simulate
 *
 * Simulate the behaviour of the particles over a given time period.
 *
 * Argument: run_time
 *    The time over which to run the simulation.
 */
void World::simulate (double run_time)
{
    double time_elapsed = 0.0;

    /*
     * For each time step:
     * 1. Calculate the force of gravity exerted on all the particles
     *    and update their accelerations.
     * 2. Then update their new positions and velocities after a small
     *    discrete time step.
     * 3. Render/save their positions.
     *
     * Repeat until we've run for the alloted time.
     */
    for (auto& p: particles) {
        std::cout << "Start position: " << p.x << ", " << p.y;
    }
    while (time_elapsed < run_time) {
        apply_gravity();
        update_particles(TIME_STEP);
        time_elapsed += TIME_STEP;
        show_particles();
    }
}
