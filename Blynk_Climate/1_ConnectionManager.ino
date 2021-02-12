char auth[] = "nG2m27dGxppSe48hUjcDRQQDDkkOrmw0";
char ssid[] = "Keenetic-2906";
char pass[] = "863NitNQ";

void connect() {
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected"); 
  Blynk.begin(auth, ssid, pass);
}
