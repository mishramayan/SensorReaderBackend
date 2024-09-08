#pragma once
#ifndef MAGNETOMETER_H
#define MAGNETOMETER_H

#include "SensorReader.h"

class Magnetometer : public SensorReader {
public:
	void readData() override {
		std::cout << "Reading Magnetometer Data....\n";
	}

	void processData() override {
		std::cout << "Processing Magnetometer Data....\n";
	}
};

#endif MAGNETOMETER_H