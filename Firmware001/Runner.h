

#ifndef RUNNER_H
#define RUNNER_H

#define MAX_NUM_OSCS 8
#ifndef NULL
#    define NULL (0)
#endif

// these are the function pointers that point to the various parts of an oscillator

typedef void(*noteOnFn)(void *, int note);
typedef void(*noteOffFn)(void *);
typedef void(*ccFn)(void *);


// this needs to be called every frame
typedef void(*tickFn)(void *);




/**
 * Add an oscillator of any type, by providing the struct, the tick function, noteon, noteoff and cc function.
 * All functions are optional, just pass null in to a function if your object doesn't use it.
 */
void addObject(void *osc, tickFn tickFunction, tickFn, noteOnFn noteon, noteOffFn noteoff, ccFn ccFunction);

void doAllTicks();



#endif // RUNNER_H
