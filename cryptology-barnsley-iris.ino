/* Arduino library includes */

#include <Servo.h>
#include <Stepper.h>

/* Defines, typedefs, constants */

static const int SERVO_PIN = 2;
static const int MAGLOCK_PIN = 9;
static const int MOTOR_PIN_1 = 3;
static const int MOTOR_PIN_2 = 5;
static const int MOTOR_PIN_3 = 4;
static const int MOTOR_PIN_4 = 6;
static const int HOME_PIN = A0;
static const int TRIGGER_PIN = A1;

static const int SERVO_INITIAL_POSITION = 0;
static const int SERVO_OPEN_POSITION = 160;

static const int IRIS_SPEED = 10;
static const int STEPS_PER_REV = 4096;
static const int IRIS_CLOSE_POSITION = 2900;

/* Local Objects/Variables */
static Servo s_servo;
static Stepper s_stepper(STEPS_PER_REV, MOTOR_PIN_1, MOTOR_PIN_2, MOTOR_PIN_3, MOTOR_PIN_4);

/* Local Functions */

static bool iris_open()
{
	return digitalRead(HOME_PIN) == LOW;
}

static void open_iris()
{
	s_stepper.setSpeed(IRIS_SPEED);
	while (!iris_open())
	{
		s_stepper.step(1);
		delayMicroseconds(100);
	}
}

static void close_iris()
{
	s_stepper.step(-IRIS_CLOSE_POSITION);
}

void setup()
{
	Serial.begin(115200);
	pinMode(SERVO_PIN, OUTPUT);
	pinMode(MAGLOCK_PIN, OUTPUT);
	pinMode(MOTOR_PIN_1, OUTPUT);
	pinMode(MOTOR_PIN_2, OUTPUT);
	pinMode(MOTOR_PIN_3, OUTPUT);
	pinMode(MOTOR_PIN_4, OUTPUT);
	pinMode(HOME_PIN, INPUT_PULLUP);
	pinMode(TRIGGER_PIN, INPUT_PULLUP);

	s_servo.attach(SERVO_PIN);

	Serial.println("Moving servo to initial position");

	s_servo.write(SERVO_INITIAL_POSITION);

	Serial.println("Finding home position");

	open_iris();

	Serial.println("Closing iris");

	close_iris();

	Serial.println("Waiting for trigger");

	while(digitalRead(TRIGGER_PIN) != LOW) {}

	Serial.println("Opening servo");

	s_servo.write(SERVO_OPEN_POSITION);

	delay(100);

	Serial.println("Opening iris");

	open_iris();

	Serial.println("Iris open");
}

void loop()
{

}
