#include <iostream>
#include <vector>
#include <cmath>


/*
 * G
 *
 * The gravitational constant
 */
const double G = 6.67430 * (10 ^ -11)
const double TIME_STEP = 0.001

class Particle {
public:
    double x, y;
    double vx, vy;
    double ax, ay;
    double mass;

    Particle (double mass, double x, double y)
        : x(x), y(y), vx(vx), vy(vy), ax(ax), ay(ay), mass(mass) {}

    void
    update (double dt)
    {
        // Update position
        x += vx * dt + 0.5 * ax * dt * dt;
        y += vy * dt + 0.5 * ay * dt * dt;

        // Update velocity
        vx += ax * dt;
        vy += ay * dt;
    }
}


class World {

private:
    uint32_t num_particles;
    uint32_t simulate time;
    uint32_t dt;
    std::vector<Particle> particles;

public:
    /*
     * add_particle
     *
     * Add a particle to the world.
     *
     * Argument: p
     *    The particle to add
     */
    void
    add_particle (const Particle& p)
    {
        particles.push_back(p);
    }

    /*
     * apply_gravity
     *
     * Apply gravity to each particle.
     */
    void
    apply_gravity (void)
    {
        /*
         * For each particle, its acceleration is modified by the mass of all
         * the other particles in the world.
         */
        for (auto& p : particles) {
            for (auto& p_other : particles) {
                if (p != p_other) {
                    p.ax -= (G * p_other.mass) / (p.x - p_other.x) ^ 2;
                    p.ay -= (G * p_other.mass) / (p.y - p_other.y) ^ 2;
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
    void
    update_particles (double dt)
    {
        for (auto& p : particles) {
            p.update(dt)
        }
    }

    /*
     * show_particles
     *
     * Display all the particles in the world
     */
    void
    show_particles(void) const {
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
    void
    simulate (double run_time)
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
        while (time_elapsed < run_time) {
            apply_gravity();
            update_particles(TIME_STEP);
            time_elapsed += TIME_STEP;
        }
    }
}