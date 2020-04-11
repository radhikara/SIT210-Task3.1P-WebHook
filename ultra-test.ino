// This #include statement was automatically added by the Particle IDE.
#include <HC_SR04.h>

double distance = 0.0;
bool beam_status = false;

int trigPin = D8;
int echoPin = D7;

HC_SR04 rangefinder = HC_SR04(trigPin, echoPin);

void setup() 
{
    Spark.variable("distance", &distance, DOUBLE);
}

void loop() 
{
    distance = rangefinder.getDistanceCM();
    String dist_str = String(distance);
    Particle.publish("distance", dist_str, PRIVATE);
    delay(100);
}
