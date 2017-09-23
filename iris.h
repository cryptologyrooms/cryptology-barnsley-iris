#ifndef _IRIS_H_
#define _IRIS_H_

//#define IRIS_HOMED_WHEN_OPEN
#define IRIS_HOMED_WHEN_CLOSED

#if defined(IRIS_HOMED_WHEN_OPEN) && defined (IRIS_HOMED_WHEN_CLOSED)
#error "Only one of IRIS_HOMED_WHEN_OPEN, IRIS_HOMED_WHEN_CLOSED should be defined"
#elif !defined(IRIS_HOMED_WHEN_OPEN) && !defined (IRIS_HOMED_WHEN_CLOSED)
#error "Exactly one of IRIS_HOMED_WHEN_OPEN, IRIS_HOMED_WHEN_CLOSED should be defined"
#endif

static const int IRIS_HOME_PIN = A0;
static const int IRIS_SPEED = 10;
static const int IRIS_CLOSE_POSITION = 3100;
static const int IRIS_OPEN_POSITION = 3100;

void iris_home(Stepper& stepper);
bool iris_is_open();
bool iris_is_closed();
void iris_close(Stepper& stepper);
void iris_open(Stepper& stepper);

#endif