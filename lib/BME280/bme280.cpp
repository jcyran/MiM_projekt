#include "bme280.h"

void bme280Init(Adafruit_BME280& bme) {
    Wire.begin(BME280_I2C_SDA, BME280_I2C_SCL);

    bool status;
    status = bme.begin(0x76);

    if (!status) {
        Serial.println("Could not find a valid BME280 sensor, check wiring!");
        while (1) delay(10);
    }

    Serial.println("Sensor BME280 correctly initialized.");
}

void getSensorValues(Adafruit_BME280& bme, SensorValues& values) {
    values.temp = bme.readTemperature();
    values.humid = bme.readHumidity();
    values.press = bme.readPressure();
}
