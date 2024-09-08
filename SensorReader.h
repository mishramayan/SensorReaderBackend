#pragma once
#ifndef SENSORREADER_H
# define SENSORREADER_H

#include <iostream>
#include <initguid.h>
#include <windows.h>
#include <conio.h>
#include <sensors.h>
#include <SensorsApi.h>
#include <PortableDevice.h>

#pragma comment(lib, "Sensorsapi.lib")
#pragma comment(lib, "PortableDeviceGuids.lib")

class SensorReader {
public:
	virtual void readData() = 0;
	virtual void processData() = 0;

	// Common initialization method (static so it's called only once for all sensors)
	SensorReader() {
		HRESULT hr =  initialize();
		if (FAILED(hr)) {
			isInitialized = false;
		}
		else {
			isInitialized = true;
			std::cout << "Sensors initialized successfully!" << std::endl;
		}
	}

	ULONG SensorCounter(){
		ULONG sensorCount = getSensorsCount();
		if (sensorCount) {
			std::cout << "Total Number of Sensors : " << sensorCount << std::endl;
		}
		else {
			std::cout << "Failed counting number of Sensors!" << std::endl;
		}

		return sensorCount;
	}

	virtual ~SensorReader() = default;

private:
	bool isInitialized;
	ULONG sensorCount;
	ISensorManager* pSensorManager = NULL;
	ISensorCollection* pSensorCollection = NULL;
	SENSOR_ID gSensor_id;

	ISensor* gIsensor;
	IPortableDeviceKeyCollection* gIpDataFields = nullptr;

	unsigned long gLightLevel;

	HRESULT initialize();
	ULONG getSensorsCount();
};



#endif SENSORREADER_H
