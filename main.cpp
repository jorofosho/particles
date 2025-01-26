#include <iostream>
#include <vector>
#include <cmath>
#include "classes.h"


int
main ()
{
    double duration = 0.0;
    World world;

    std::cout << "How long shall this run for in seconds?";
    std::cin >> duration;
 
    world.add_particle(Particle(1, 2, 3));
    world.add_particle(Particle(2, 10, -10));

    world.simulate(duration);

    return 0;
}