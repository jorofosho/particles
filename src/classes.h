/*
 * classes.h
 *
 * Definitions of the classes.
 */

#include <vector>

#ifndef CLASSES_H
#define CLASSES_H

class Particle {
public:
    double x, y;
    double vx, vy;
    double ax, ay;
    double mass;

    Particle (double _mass, double _x, double _y);
    void update(double dt);
};



class World {

private:
    std::vector<Particle *> particles;

public:
    void add_particle(Particle *p);

    void apply_gravity(void);

    void update_particles(double dt);

    void show_particles(void) const;

    int simulate(double run_time);
};


#endif