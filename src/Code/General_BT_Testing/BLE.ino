#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

// See the following for generating UUIDs:
// https://www.uuidgenerator.net/

#define SERVICE_UUID "da15d268-1779-4748-acc0-265c114418b1"
#define CHARACTERISTIC_UUID "971251a7-40d7-46db-81a6-945a5d5f4f23"
BLECharacteristic *pCharacteristic;

class MyCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
    String value = pCharacteristic->getValue();
    valorRebut(value);  // Call my function with the received value to isolate the entire BLE procedure in a single tab
  }
};

class MyServerCallbacks : public BLEServerCallbacks {
  void onDisconnect(BLEServer* pServer) {
    motorStart("ABCD", 0);
    activateSerial = false;
    digitalWrite(ledGpin, 0);
    digitalWrite(ledYpin, 0);
    digitalWrite(ledRpin, 1);
  }
};

void enviarBLE(String valor) {  // Sends a string via BLE
  pCharacteristic->setValue(valor);
  pCharacteristic->notify();
}

void setupBLE() { // Initiates the BLE server
  BLEDevice::init("DRONE");
  BLEServer *pServer = BLEDevice::createServer();

  BLEService *pService = pServer->createService(SERVICE_UUID);

  pCharacteristic =
    pService->createCharacteristic(CHARACTERISTIC_UUID,
                                   BLECharacteristic::PROPERTY_WRITE | BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);
  pCharacteristic->setCallbacks(new MyCallbacks());
  pService->start();

  BLEAdvertising *pAdvertising = pServer->getAdvertising();
  pAdvertising->start();
}

void valorRebut(String valorBT) {  // Callback function when a String is received via BLE
  // CONTROL COMANDS VIA BLE
  if (valorBT.charAt(0) == 'P') serialKp = valorBT.substring(1).toFloat(); // Modificates Kp value (i.e. P0.5)
  else if (valorBT.charAt(0) == 'I') serialKi = valorBT.substring(1).toFloat(); // Modificates Ki value (i.e. I0.1)
  else if (valorBT.charAt(0) == 'D') serialKd = valorBT.substring(1).toFloat(); // Modificates Kd value (i.e. D0.1)
  else if (valorBT.charAt(0) == 'V') motorStart("ABCD", valorBT.substring(1).toFloat()); // Start all motors at a given power (i.e. V40)
  else if (valorBT.charAt(0) == 'H') hoverPower = valorBT.substring(1).toFloat(); // Sets the hovering power when the stabilization PID is on (i.e. H60)
  else if (valorBT.charAt(0) == 'T') tolva.writeMicroseconds(valorBT.substring(1).toInt()); // Sets the speed of the hopper valve (1000 -> Full power CC; 1500 --> Stop; 2000 --> Full power CCW)
  else if (valorBT == "S") { // Enables the stabilization loop
    digitalWrite(ledGpin, 0);
    digitalWrite(ledYpin, 1);
    digitalWrite(ledRpin, 0);
    activateSerial = true;
    enviarBLE("INICIAT");
  } else if (valorBT == "s") { // Stops all motors and disables stabilization loop (PANIC COMMAND)
    motorStart("ABCD", 0);
    activateSerial = false;
    digitalWrite(ledGpin, 0);
    digitalWrite(ledYpin, 0);
    digitalWrite(ledRpin, 1);
    enviarBLE("STOP");
  }
  else if (valorBT == "p") enviarBLE(String(serialKp)); // Sends the Kp value to the BT device
  else if (valorBT == "i") enviarBLE(String(serialKi)); // Sends the Ki value to the BT device
  else if (valorBT == "d") enviarBLE(String(serialKd)); // Sends the Kd value to the BT device
}