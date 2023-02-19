#include <Arduino.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
 
void setup() {
 
  Serial.begin(115200);                 //Serial connection
  WiFi.begin("HUAWEI GR5 2017", "RMVC@982583152");   //WiFi connection
 
  while (WiFi.status() != WL_CONNECTED) {  //Wait for the WiFI connection completion
 
    delay(500);
    Serial.println("Waiting for connection");
 
  }
 
}
 
void loop() {
 
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
 
    HTTPClient http;    //Declare object of class HTTPClient
    
    http.begin("http://jsonplaceholder.typicode.com/users");      //Specify request destination
     //http.begin("https://wandering-water-6831.fly.dev/predict");  
 
    //int httpCode = http.POST("Message from ESP8266");   //Send the request
     http.addHeader("Content-Type", "application/json");
    
    //int httpResponseCode = http.POST("{\"api_key\":\"tPmAT5Ab3j7F9\",\"sensor\":\"BME280\",\"value1\":\"24.25\",\"value2\":\"49.54\",\"value3\":\"1005.14\"}");
    int httpResponseCode = http.POST("{\"device_id\":\"QEIZrUmZGUuzBqRnw0jZ\",\"data reading\":{\"i\":0.9900436818128375,\"time\":1676362048419,\"v\":0.5681495890359043}}");

    String payload = http.getString();                  //Get the response payload
 
    //Serial.println(httpCode);   //Print HTTP return code
    Serial.println(httpResponseCode);
    Serial.println(payload);    //Print request response payload
 
    http.end();  //Close connection
 
  } else {
 
    Serial.println("Error in WiFi connection");
 
  }
 
  delay(30000);  //Send a request every 30 seconds
 
}