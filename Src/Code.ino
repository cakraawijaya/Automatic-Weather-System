#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <DHT.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

const char* mqtt_server = "broker.emqx.io";

const char* TOPIC_DISTANCE = "YOUR_TOPIC_LEVEL1/distance";
const char* TOPIC_TEMP = "YOUR_TOPIC_LEVEL1/temperature";
const char* TOPIC_HUMID = "YOUR_TOPIC_LEVEL1/humidity";
const char* TOPIC_JSON = "YOUR_TOPIC_LEVEL1/aws";

int intervalPengiriman = 5; // detik

#define Echo 12
#define Trigger 14

#define DHTPIN 27
#define DHTTYPE DHT11

float temperature;
float humidity;
float distanceCM;

char bufferTemp[10];
char bufferHum[10];
char bufferDistance[10];

unsigned long prevMillis = 0;

WiFiClient espClient;
PubSubClient mqtt(espClient);
DHT dht(DHTPIN, DHTTYPE);

void setup_wifi() {

  delay(10);

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Terhubung");
  Serial.print("IP Address : ");
  Serial.println(WiFi.localIP());

}

void callback(char* topic, byte* payload, unsigned int length) {
  // Tidak digunakan
}

void reconnect() {

  while (!mqtt.connected()) {

    Serial.print("Attempting MQTT connection...");

    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);

    if (mqtt.connect(clientId.c_str())) {

      Serial.println("Connected!");

    } else {

      Serial.print("Failed, rc=");
      Serial.print(mqtt.state());
      Serial.println(" Retry in 5 seconds");

      delay(5000);

    }

  }

}

float readDistance() {

  digitalWrite(Trigger, LOW);
  delayMicroseconds(2);

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);

  digitalWrite(Trigger, LOW);

  long duration = pulseIn(Echo, HIGH, 30000);

  if (duration == 0) {
    return -1;
  }

  return duration * 0.0343 / 2;

}

void publish_data() {

  dtostrf(temperature, 4, 1, bufferTemp);
  mqtt.publish(TOPIC_TEMP, bufferTemp);

  dtostrf(humidity, 4, 1, bufferHum);
  mqtt.publish(TOPIC_HUMID, bufferHum);

  dtostrf(distanceCM, 4, 1, bufferDistance);
  mqtt.publish(TOPIC_DISTANCE, bufferDistance);

}

void publish_json() {

  JsonDocument doc;

  doc["temperature"] = temperature;
  doc["humidity"] = humidity;
  doc["distance"] = distanceCM;

  char jsonBuffer[256];

  serializeJson(doc, jsonBuffer);

  mqtt.publish(TOPIC_JSON, jsonBuffer);

}

void setup() {

  Serial.begin(115200);

  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);

  setup_wifi();

  dht.begin();

  mqtt.setServer(mqtt_server, 1883);
  mqtt.setCallback(callback);

}

void loop() {

  if (!mqtt.connected()) {
    reconnect();
  }

  mqtt.loop();

  if (millis() - prevMillis >= intervalPengiriman * 1000) {

    prevMillis = millis();

    temperature = dht.readTemperature();
    humidity = dht.readHumidity();
    distanceCM = readDistance();

    Serial.println("========== DATA SENSOR ==========");

    if (!isnan(temperature))
      Serial.println("Temperature : " + String(temperature) + " °C");
    else
      Serial.println("Temperature : Error");

    if (!isnan(humidity))
      Serial.println("Humidity    : " + String(humidity) + " %");
    else
      Serial.println("Humidity    : Error");

    if (distanceCM >= 0)
      Serial.println("Distance    : " + String(distanceCM) + " cm");
    else
      Serial.println("Distance    : Out of Range");

    Serial.println();

    if (!isnan(temperature) && !isnan(humidity)) {

      publish_data();
      publish_json();

    }

  }

  delay(5);

}
