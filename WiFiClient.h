#include <ESP8266WiFi.h>

const char* ssid     = "YOURSSID";
const char* password = "YOURPASSWORD";
const char* host = "YOURHOSTNAME";

struct httpResp {
  bool status;
  int result;
};

bool wifiSetup() {
  WiFi.begin(ssid, password);
  int i=0;
  while (WiFi.status() != WL_CONNECTED && i<300) {
    delay(50);
    i++;
  }
  return WiFi.status() == WL_CONNECTED;
}


httpResp wifiGetData() {
  httpResp response;
  response.status = false;
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    return response;
  }

  client.print(String("GET / HTTP/1.1\r\nHost: ") + host + "\r\nConnection: close\r\n\r\n");
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return response;
    }
  }
  String line;
  while(client.available()){
    line = client.readStringUntil('\r');
  }
  if(line.substring(1,3) == String("Ok")) {
      response.status = true;
      response.result = 0;
      if(line.substring(3,4).length()) {
        response.result = line.charAt(3) - 48;
      }
  }
  return response;  
}
