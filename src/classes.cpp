/*
 * classes.cpp
 *
 * The implementation of the classes such as particles and the world.
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "classes.h"

/*
 * G
 *
 * The gravitational constant
 */
const double G = 1;
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

    // Update velocity
    vx += ax * dt;
    vy += ay * dt;
}


/*
 * add_particle
 *
 * Adds a particle to the world.
 */
void World:: add_particle (Particle *p)
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
    double distance = 0.0;

    for (auto p : particles) {
        for (auto p_other : particles) {
            if (p != p_other) {
                distance = std::sqrt(std::pow((p->x - p_other->x), 2) + std::pow((p->y - p_other->y), 2));
                p->ax = -((G * p_other->mass) / std::pow(distance, 3)) * (p->x - p_other->x);
                p->ay = -((G * p_other->mass) / std::pow(distance, 3)) * (p->y - p_other->y);
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
    for (auto p : particles) {
        p->update(dt);
    }
}


/*
 * show_particles
 *
 * Display all the particles in the world
 */
void World::show_particles(sf::RenderWindow *window) const {
    sf::VertexArray points(sf::PrimitiveType::Points, 2);
    int i = 0;

    //window->clear();

    for (auto p: particles) {
        points[i].position = sf::Vector2f(p->x, p->y);
        i++;
    }

    window->draw(points);
    window->display();
}


/*
 * simulate
 *
 * Simulate the behaviour of the particles over a given time period.
 *
 * Argument: run_time
 *    The time over which to run the simulation.
 */
int World::simulate (double run_time)
{
    double           time_elapsed = 0.0;
    sf::RenderWindow window(sf::VideoMode({1000, 1000}), "SFML works!");
    sf::Event        event;

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
    while (time_elapsed < run_time && window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        apply_gravity();
        update_particles(TIME_STEP);
        time_elapsed += TIME_STEP;
        show_particles(&window);
    }

    return 0;
}
