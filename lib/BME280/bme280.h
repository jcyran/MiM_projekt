#ifndef BME280_H
#define BME280_H

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define BME280_I2C_SDA 33
#define BME280_I2C_SCL 32

Adafruit_BME280 bme;

float tempBME, humidBME, pressBME;

void bme280Init();
void getSensorValues();

#endif