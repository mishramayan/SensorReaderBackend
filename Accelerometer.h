#pragma once
#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include "SensorReader.h"

class Accelerometer : public SensorReader {
public:
	void readData() override {
		std::cout << "Reading Accelerometer Data....\n";
	}

	void processData() override {
		std::cout << "Processing Accelerometer Data....\n";
	}
};

#endif ACCELEROMETE_H