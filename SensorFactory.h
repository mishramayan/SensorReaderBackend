#pragma once
#ifndef SENSORFACTORY_H
#define SENSORFACTORY_H

#include "SensorReader.h"
#include "Accelerometer.h"
#include "Gyroscope.h"
#include "Inclinometer.h"
#include "Magnetometer.h"

enum SensorType {
	ACCELEROMETER,
	GYROSCOPE,
	INCLINOMETER,
	MAGNETOMETER
};

class SensorFactory {
public:
	static SensorReader* createSensor(SensorType type) {

		SensorReader* sensor = nullptr;

		//Perform initializtion before creating sensors
		switch (type) {
			case ACCELEROMETER:
				return new Accelerometer();
			case GYROSCOPE:
				return new Gyroscope();
			case INCLINOMETER:
				return new Inclinometer();
			case MAGNETOMETER:
				return new Magnetometer();
			default:
				return nullptr;
		}
	}
};

#endif SENSORFACTORY_H


