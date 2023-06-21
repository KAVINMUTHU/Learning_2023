#include <stdio.h>
#include <string.h>

// Structure to store sensor information
struct SensorInfo
{
    char sensorID[10];
    float temperature;
    int humidity;
    int lightIntensity;
};

// Function to parse and populate sensor data
void populateSensorData(const char *data, struct SensorInfo *sensor)
{
    char temp[10];
    sscanf(data, "S%[^-]-T:%f-H:%d-L:%d", sensor->sensorID, &(sensor->temperature), &(sensor->humidity), &(sensor->lightIntensity));
}

int main()
{
    const char *data = "S1-T:36.5-H:100-L:50";
    struct SensorInfo sensor;

    // Populate sensor data
    populateSensorData(data, &sensor);

    // Display sensor information
    printf("Sensor Info:\n");
    printf("Sensor ID: %s\n", sensor.sensorID);
    printf("Temperature: %.1f C\n", sensor.temperature);
    printf("Humidity: %d\n", sensor.humidity);
    printf("Light Intensity: %d%%\n", sensor.lightIntensity);

    return 0;
}
