# json_cpp
Single-file header-only C++ JSON library

---

USAGE: 
```
#include "json_cpp.h"
```

--- 

JSON to std::string: 
```
JsonNode json = json_empty_object(); 
json["name"] = "Tutankhamun";
json["age"] = 5157; 
json["job"] = "Pharaoh"; 
std::cout << json_to_string(json) << std::endl; 
```

![image](https://github.com/pauld-d/json_cpp/assets/36675895/46161082-624f-4d08-b91a-2d3898c2133a)



--- 

std::string to JSON: 
```
JsonNode json = string_to_json("{\"name\":\"Paul Demanze\",\"age\":23,\"jobTitle\":\"Software Engineer\",\"companies\":[\"Google\",\"PriceHubble\",\"NavLive\"]}");
std::cout << "name: " << json["name"] << std::endl; 
std::cout << "companies: " << json["companies"] << std::endl; 
```

![image](https://github.com/pauld-d/json_cpp/assets/36675895/4cdbe11d-90a5-4bd5-b757-e1002beefa12)

--- 

Arrays: 
```
JsonNode json = json_empty_object();
json["name"] = "Percival"; 
json["backpack"] = json_empty_array(); 
json["backpack"].push_back("Gengis Khan's Crown");
json["backpack"].push_back("The Holy Grail");
json["backpack"].push_back("The Bible");
json["backpack"].push_back("The Shroud Of Turin");
std::cout << json_to_string(json) << std::endl; 
```

![image](https://github.com/pauld-d/json_cpp/assets/36675895/e3b9c695-db13-4d61-ba62-52f1daee6c8e)


--- 

Nesting: 
```
JsonNode json = json_empty_object();
json["just"]["testing"]["the"]["nesting"] = json_null(); 
std::cout << json_to_string(json) << std::endl; 
```

![image](https://github.com/pauld-d/json_cpp/assets/36675895/467e858f-9f02-423a-8948-eb4e6d6de3b3)


--- 

Testing key existence: 
```
JsonNode json = json_empty_object();
json["key0"] = true; 
bool has_key0 = json.contains("key0"); 
bool has_key1 = json.contains("key1"); 
std::cout << "has_key0: " << (has_key0 ? "true" : "false") << std::endl; 
std::cout << "has_key1: " << (has_key1 ? "true" : "false") << std::endl; 
```

![image](https://github.com/pauld-d/json_cpp/assets/36675895/54df24fe-df82-40a8-aa0c-6324a1b5050e)


--- 

Listing keys: 
```
JsonNode json = json_empty_object();
json["key0"] = true; 
json["key1"] = 3.141f; 
std::vector<std::string> keys = json.keys(); 
for (std::string& k : keys) 
    std::cout << "key=" << k << std::endl; 
```

![image](https://github.com/pauld-d/json_cpp/assets/36675895/11dc0f9b-99d1-4b99-b1fe-cdcbfe947974)


--- 

Iterating through an object:

```
JsonNode json = json_empty_object();
json["key0"] = "value0"; 
json["key1"] = "value1"; 
for (auto& [key,value] : json) 
    std::cout << "key=" << key << ", value=" << value << std::endl; 
```

![image](https://github.com/pauld-d/json_cpp/assets/36675895/7be5369f-18d7-4c9a-98ef-95223bcf725b)


---

Iterating through an array: 

```
JsonNode json = string_to_json("{\"backpack\":[\"Gengis Khan's Crown\",\"The Holy Grail\",\"The Bible\",\"The Shroud Of Turin\"],\"name\":\"Percival\"}");
for (auto& [key,value] : json["backpack"]) 
{
    std::cout << "key=" << key << ", value=" << value << std::endl; 
}
```

![image](https://github.com/pauld-d/json_cpp/assets/36675895/2395c81c-ffdc-4b15-bbc9-ddd63084a93f)

---

Copying 

```
JsonNode json1 = ... ; 
JsonNode json2 = json1;
```
