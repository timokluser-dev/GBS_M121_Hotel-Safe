/**
 * Hotel Safe Client: API Library
 * Used to prepare and send data to the backend API
 * INFO: Needs to have `.ino` file ending
 * @version 1.0
 * @author ddemiraj, timokluser-dev
 * @see https://arduinojson.org
 */

// reserved JSON size per document [in Bytes]
#define JSONSIZE 300

// alias for C# known `null`
#define JSONNULL nullptr

// how many digits log the pin is
#define PINLENGTH 6

class BackendHelper
{
private:
public:
    static DynamicJsonDocument parseJSON(String json)
    {
        DynamicJsonDocument parsedJson(JSONSIZE);

        DeserializationError error = deserializeJson(parsedJson, json);

        if (error)
        {
            Serial.println("JSON deserialize failed: " + String(error.f_str()));
        }

        return parsedJson;
    }

    static DynamicJsonDocument prepareJSONDocument()
    {
        DynamicJsonDocument jsonArray(JSONSIZE);

        return jsonArray;
    }

    static String generateJSON(DynamicJsonDocument jsonArray)
    {
        String json;
        serializeJson(jsonArray, json);

        return json;
    }
};

class Backend
{
private:
public:
};
