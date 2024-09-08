#pragma once
#ifndef INCLINOMETER_H
#define INCLINOMETER_H

#include "SensorReader.h"

class Inclinometer : public SensorReader {
public:
	void readData() override {
		std::cout << "Reading Inclinometer Data....\n";
	}

	void processData() override {
		std::cout << "Processing Inclinometer Data....\n";
	}
};

#endif INCLINOMETER_H