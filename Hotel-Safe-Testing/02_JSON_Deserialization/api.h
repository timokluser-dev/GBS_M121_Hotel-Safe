#include "libraries/ArduinoJson.h"

// reserved JSON size per document [in Bytes]
#define JSONSIZE 300
// alias for C# known `null`
#define JSONNULL nullptr

/**
 * Parse a API JSON Response
 * @param json JSON Response in String format
 * @return Array based on Response
 */
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

/**
 * Generate a JSON Document before serialization
 * @return Array to do changes and use as parameter for generateJSON(jsonArray) after
 */
DynamicJsonDocument generateJSONPrepareDocument()
{
    DynamicJsonDocument jsonArray(JSONSIZE);

    return jsonArray;
}

/**
 * Serialize a Array to a JSON String 
 * Call generateJSONPrepareDocument() before
 * @return JSON String
 */
String generateJSON(DynamicJsonDocument jsonArray)
{
    String json;
    serializeJson(jsonArray, json);

    return json;
}
