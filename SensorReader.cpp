#include "SensorReader.h"

HRESULT SensorReader::initialize() {
	//Step 1: Initialize the Sensor API
	HRESULT bSuccess = CoInitialize(0);

	if (FAILED(bSuccess)) {
		std::cerr << "CoInitialize failed with error code 0x" << std::hex << bSuccess << std::endl;
		return bSuccess;
	}

	//Step 2: Enumerate sensors and count them
	HRESULT hr = CoCreateInstance(CLSID_SensorManager, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pSensorManager));
	return hr;
}

ULONG SensorReader::getSensorsCount() {
	ULONG totalSensors = 0;
	HRESULT hr = pSensorManager->GetSensorsByCategory(SENSOR_CATEGORY_ALL, &pSensorCollection);
	hr = pSensorCollection->GetCount(&totalSensors);

	return totalSensors;
}
