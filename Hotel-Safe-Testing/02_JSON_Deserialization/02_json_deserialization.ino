#include "api.h"

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  // mock API response
  String json = "{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.756080,2.302038],\"user\":{\"name\":\"Paul\",\"age\":12}}";

  DynamicJsonDocument response = parseJSON(json);

  String sensor = response["sensor"];
  String uname = response["user"]["name"];

  Serial.println(sensor);
  Serial.println(uname);

  Serial.println("----------------");
  delay(500);

  // mock request build
  DynamicJsonDocument request = generateJSONPrepareDocument();

  request["key"] = "value";
  request["hello"] = "world";
  request["data"]["t1"] = "1";
  request["data"]["t2"] = "1";
  request["data"]["empty"] = JSONNULL; // how to do null values - https://arduinojson.org/v6/issues/cannot-use-null/

  String out = generateJSON(request);

  Serial.println(out);
}
