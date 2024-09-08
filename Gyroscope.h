#pragma once
#ifndef GYROSCOPE_H
#define GYROSCOPE_H

#include "SensorReader.h"

class Gyroscope : public SensorReader {
public:
	void readData() override {
		std::cout << "Reading Gyroscope Data....\n";
	}

	void processData() override {
		std::cout << "Processing Gyroscope Data....\n";
	}
};

#endif GYROSCOPE_H