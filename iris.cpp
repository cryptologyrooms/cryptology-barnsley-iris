#include <Arduino.h>
#include <Stepper.h>

#include "iris.h"

#if defined(IRIS_HOMED_WHEN_CLOSED)

void iris_home(Stepper& stepper)
{
	iris_close(stepper);
}

bool iris_is_closed()
{
	return digitalRead(IRIS_HOME_PIN) == LOW;	
}

void iris_close(Stepper& stepper)
{
	stepper.setSpeed(IRIS_SPEED);
	while (!iris_is_closed())
	{
		stepper.step(1);
		delayMicroseconds(100);
	}
}

void iris_open(Stepper& stepper)
{
	stepper.step(-IRIS_OPEN_POSITION);
}

#endif

#if defined(IRIS_HOMED_WHEN_OPEN)

void iris_home(Stepper& stepper)
{
	iris_open(stepper);
}

bool iris_is_open()
{
	return digitalRead(IRIS_HOME_PIN) == LOW;
}

void iris_open(Stepper& stepper)
{
	stepper.setSpeed(IRIS_SPEED);
	while (!iris_is_open())
	{
		stepper.step(1);
		delayMicroseconds(100);
	}
}

void iris_close(Stepper& stepper)
{
	stepper.step(-IRIS_CLOSE_POSITION);
}
#endif
