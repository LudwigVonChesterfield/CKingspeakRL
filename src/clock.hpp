#pragma once

#include <SDL2/SDL.h>

#define SECOND *1000
#define SECONDS *1000

class Clock{
public:
    Clock();

    bool should_tick();

    int dt();
    void tick();

private:
    int last;
    int current;

    int min_tick_delay = 0.01 SECONDS;
};
