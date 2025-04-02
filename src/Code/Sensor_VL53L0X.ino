#include <VL53L0X.h> 
#include <Wire.h>

VL53L0X sensor; 

int startTime = millis(); 
int mInterval = 100; 

void setup() {
    Serial.begin(9600);
    
    Wire.begin(); 
    Wire.setClock(400000); 

    sensor.setTimeout(500); 
    
    if (!sensor.init()) {
        Serial.println("VL53L0X no responde, verifica el cableado.");
    } else {
        sensor.setSignalRateLimit(0.1);
        sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
        sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);
        sensor.setMeasurementTimingBudget(40000); 
        sensor.startContinuous(50);
    }   
}

void loop() {
    if ((millis() - startTime) > mInterval) {
        int distancia = sensor.readRangeContinuousMillimeters();
        
        // Detecta errores en la medición
        if (sensor.timeoutOccurred()) {
            Serial.println("Error: Tiempo de espera excedido");
        } else {
            Serial.print("Distancia: ");
            Serial.print(distancia);
            Serial.println(" mm");
        }
        
        startTime = millis();
    }
}
