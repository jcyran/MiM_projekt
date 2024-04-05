#pragma once

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define BME280_I2C_SDA 33
#define BME280_I2C_SCL 32

struct SensorValues {
    float temp, humid, press;
};

void bme280Init(Adafruit_BME280&);
void getSensorValues(Adafruit_BME280&, SensorValues&);
