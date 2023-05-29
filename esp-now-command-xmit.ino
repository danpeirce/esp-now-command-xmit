/*
  ESP-NOW Demo - Transmit
  esp-now-demo-xmit.ino
  Sends data to Responder
  
  DroneBot Workshop 2022
  https://dronebotworkshop.com
*/

// Include Libraries
#include <esp_now.h>
#include <WiFi.h>

// Variables for test data
bool bool_value = true;

// on breadboard MAC Address: 84:F7:03:F7:82:8E
//in box MAC Address: 70:04:1D:FB:33:F6
// MAC Address of responder - edit as required
uint8_t broadcastAddress[] = {0x70, 0x04, 0x1D, 0xFB, 0x33, 0xF6};

// Define a data structure
typedef struct struct_message {
  char a[11];
  bool d;
} struct_message;

// Create a structured object
struct_message myData;

// Peer info
esp_now_peer_info_t peerInfo;

// Callback function called when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void setup() {
  
  // Set up Serial Monitor
  Serial.begin(115200);
 
  // Set ESP32 as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Initilize ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Register the send callback
  esp_now_register_send_cb(OnDataSent);
  
  // Register peer
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  
  // Add peer        
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
}

void loop() {

  if (Serial.available()) {
    
    // Invert the boolean value
    bool_value = !bool_value;
    
    // Format structured data
    strcpy(myData.a, "  PHYS1600");
    myData.d = bool_value;
    
    myData.a[0] = Serial.read();
    Serial.print("\n\t>> ");
    Serial.write(myData.a[0]);
    Serial.println(" <<\n");
    // Send message via ESP-NOW
    esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
    
    if (result == ESP_OK) {
      Serial.println("Sending confirmed");
    }
    else {
      Serial.println("Sending error");
    }
    //delay(2000);
  }
}
