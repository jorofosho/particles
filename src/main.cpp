#include <iostream>
#include <vector>
#include <cmath>
#include "classes.h"


int
main ()
{
    double duration = 0.0;
    World world;
    Particle p1(1, 50, 50);
    Particle p2(20000, 100, 100);

    std::cout << "How long shall this run for in seconds?";
    std::cin >> duration;
 
    world.add_particle(&p1);
    world.add_particle(&p2);

    return world.simulate(duration);
}