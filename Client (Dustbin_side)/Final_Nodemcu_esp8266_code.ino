#include <ESP8266WiFi.h>
 
char* ssid = "GalaxyS8+";
char* password =  "dhruv1105";
 
const uint16_t port = 12345;
const char * host = "192.168.43.122";

//defines variables
const int trigPin = 4;
const int echoPin = 5;

long duration;
long distance;
 
void setup()
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("...");
  }
  
  Serial.print("WiFi connected with IP: ");
  Serial.println(WiFi.localIP());
   
  pinMode(trigPin, OUTPUT); //Sets the trigPin as an output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}
 
void loop()
{
    WiFiClient client;
    if (!client.connect(host, port)) {
      Serial.println("Connection to host failed");
      delay(1000);
      return;
    }
 
    Serial.println("Connected to server successful!"); 
    Serial.print("Hello from ESP8266_1"); 

    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    
    // Calculating the distance
    distance= duration*0.034/2;
    
    // Prints the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);
    //client.println("Distance: ");
    client.println(distance);
    //client.print("cm");
    
    Serial.println("Disconnecting...");
    client.stop(); 
    delay(1000);
}
