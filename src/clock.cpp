#include "clock.hpp"

Clock::Clock(){
    last = 0;
    current = 0;
}

bool Clock::should_tick(){
    return SDL_GetTicks() - current > min_tick_delay;
}

int Clock::dt(){
    return current - last;
}

void Clock::tick(){
    last = current;
    current = SDL_GetTicks();
}
