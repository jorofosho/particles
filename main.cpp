#include <iostream>
#include <vector>
#include <cmath>
#include "classes.h"


int
main ()
{
    double duration = 0.0;
    World world;
    Particle p1(1, 2, 3);
    Particle p2(2, 10, -10);

    std::cout << "How long shall this run for in seconds?";
    std::cin >> duration;
 
    world.add_particle(&p1);
    world.add_particle(&p2);

    world.simulate(duration);

    return 0;
}