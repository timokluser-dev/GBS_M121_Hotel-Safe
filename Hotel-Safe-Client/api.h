/**
 * Hotel Safe Client: API Library
 * Used to prepare and send data to the backend API
 * @version 1.0
 * @author ddemiraj, timokluser-dev
 * @see https://arduinojson.org
 */

#include "libraries/ArduinoJson.h"

// reserved JSON size per document [in Bytes]
#define JSONSIZE 200

#define PINLENGTH 6

DynamicJsonDocument parseJSON(String json)
{
    DynamicJsonDocument parsedJson(JSONSIZE);

    DeserializationError error = deserializeJson(parsedJson, json);

    if (error)
    {
        Serial.println("JSON deserialize failed: " + String(error.f_str()));
    }

    return parsedJson;
}

DynamicJsonDocument generateJSONPrepareDocument()
{
    DynamicJsonDocument jsonArray(JSONSIZE);

    return jsonArray;
}

String generateJSON(DynamicJsonDocument jsonArray)
{
    String json;
    serializeJson(jsonArray, json);

    return json;
}
