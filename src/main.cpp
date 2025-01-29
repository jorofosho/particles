#include <iostream>
#include <vector>
#include <cmath>
#include "classes.h"

const double G = 1;

int
main ()
{
    double duration = 0.0;
    World world;
    Particle p1(1, 500, 250);
    Particle p2(625000, 500, 500);

    std::cout << "How long shall this run for in seconds?";
    std::cin >> duration;
 
    p2.vx = 0;
    p2.vy = 0;
    p1.vy = 0;
    p1.vx = sqrt(G * p2.mass / 250);

    world.add_particle(&p1);
    world.add_particle(&p2);

    return world.simulate(duration);
}