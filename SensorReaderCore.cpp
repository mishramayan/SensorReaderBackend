#include "SensorFactory.h"
#include <vector>

int main() {
	//Create a factory to generate different types of sensors and ensure sensors are initialized
	std::vector<SensorReader*> sensors;

	sensors.push_back(SensorFactory::createSensor(ACCELEROMETER));
	sensors.push_back(SensorFactory::createSensor(GYROSCOPE));
	sensors.push_back(SensorFactory::createSensor(INCLINOMETER));
	sensors.push_back(SensorFactory::createSensor(MAGNETOMETER));

	//use the sensors
	for (SensorReader* sensor : sensors) {
		sensor->SensorCounter();
		sensor->readData();
		sensor->processData();
	}

	//Clean up allocated memory space
	for (SensorReader* sensor : sensors) {
		std::cout << "Deleting memory allocated for sensor: " << *&sensor << std::endl;
		delete sensor;
	}

	return 0;
}