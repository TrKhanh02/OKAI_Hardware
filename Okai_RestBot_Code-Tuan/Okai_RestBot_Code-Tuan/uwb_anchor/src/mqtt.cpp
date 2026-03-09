// #include <ESP8266WiFi.h>
// #include <PubSubClient.h>
// #include <time.h>
// #include <TZ.h>
// #include <FS.h>
// #include <LittleFS.h>
// #include <CertStoreBearSSL.h>

// // ==== Cấu hình WiFi & MQTT ====
// const char* ssid = "OKAI";
// const char* password = "prv@101024";
// const char* mqtt_server = "95d28a1c55ec45fc89807d41cbc6c17f.s1.eu.hivemq.cloud";
// const char* mqtt_user = "hivemq.webclient.1755156037704";
// const char* mqtt_pass = "<.>,UDu1vIp0tyxF52YA";

// BearSSL::CertStore certStore;
// WiFiClientSecure espClient;
// PubSubClient *client;

// unsigned long lastMsg = 0;
// #define MSG_BUFFER_SIZE (500)
// char msg[MSG_BUFFER_SIZE];
// int value = 0;

// void setup_wifi() {
//   delay(10);
//   Serial.println();
//   Serial.printf("Connecting to %s\n", ssid);

//   WiFi.mode(WIFI_STA);
//   WiFi.begin(ssid, password);

//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }

//   Serial.println("\nWiFi connected");
//   Serial.print("IP address: ");
//   Serial.println(WiFi.localIP());
// }

// void setDateTime() {
//   configTime(TZ_Europe_Berlin, "pool.ntp.org", "time.nist.gov");

//   Serial.print("Waiting for NTP time sync: ");
//   time_t now = time(nullptr);
//   while (now < 8 * 3600 * 2) {
//     delay(100);
//     Serial.print(".");
//     now = time(nullptr);
//   }
//   Serial.println();

//   struct tm timeinfo;
//   gmtime_r(&now, &timeinfo);
//   Serial.printf("%s %s", tzname[0], asctime(&timeinfo));
// }

// void callback(char* topic, byte* payload, unsigned int length) {
//   Serial.print("Message arrived [");
//   Serial.print(topic);
//   Serial.print("] ");
//   for (int i = 0; i < length; i++) {
//     Serial.print((char)payload[i]);
//   }
//   Serial.println();
// }

// void reconnect() {
//   while (!client->connected()) {
//     Serial.print("Attempting MQTT connection...");
//     if (client->connect("ESP8266Client", mqtt_user, mqtt_pass)) {
//       Serial.println("connected");
//       client->subscribe("testTopic");
//     } else {
//       Serial.printf("failed, rc=%d try again in 5 seconds\n", client->state());
//       delay(5000);
//     }
//   }
// }

// void setup() {
//   Serial.begin(115200);
//   LittleFS.begin();
//   setup_wifi();
//   setDateTime();

//   int numCerts = certStore.initCertStore(LittleFS, PSTR("/certs.idx"), PSTR("/certs.ar"));
//   Serial.printf("Number of CA certs read: %d\n", numCerts);
//   if (numCerts == 0) {
//     Serial.printf("No certs found. Did you upload the LittleFS data?\n");
//     return;
//   }

//   BearSSL::WiFiClientSecure *bear = new BearSSL::WiFiClientSecure();
//   bear->setCertStore(&certStore);

//   client = new PubSubClient(*bear);
//   client->setServer(mqtt_server, 8883);
//   client->setCallback(callback);
// }

// void loop() {
//   if (!client->connected()) {
//     reconnect();
//   }
//   client->loop();

//   unsigned long now = millis();
//   if (now - lastMsg > 2000) {
//     lastMsg = now;
//     ++value;
//     snprintf(msg, MSG_BUFFER_SIZE, "hello world #%d", value);
//     Serial.printf("Publish message: %s\n", msg);
//     client->publish("testTopic", msg);
//   }
// }
