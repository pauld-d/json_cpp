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

![image](https://github.com/pauld-d/json_cpp/assets/36675895/209775e6-3783-4a7e-ad87-37e329ed69ef)


--- 

std::string to JSON: 
```
JsonNode json = string_to_json("{\"name\":\"Paul Demanze\",\"age\":23,\"jobTitle\":\"Software Engineer\",\"companies\":[\"Google\",\"PriceHubble\",\"NavLive\"]}");
std::cout << "name: " << json["name"] << std::endl; 
std::cout << "companies: " << json["companies"] << std::endl; 
```

![image](https://github.com/pauld-d/json_cpp/assets/36675895/fc2911a6-6a02-4b72-a48b-04048571d0ce)

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

![image](https://github.com/pauld-d/json_cpp/assets/36675895/2861982d-1267-47a1-a2bb-ee9ba0c815aa)

--- 

Nesting: 
```
JsonNode json = json_empty_object();
json["just"]["testing"]["the"]["nesting"] = json_null(); 
std::cout << json_to_string(json) << std::endl; 
```

![image](https://github.com/pauld-d/json_cpp/assets/36675895/b9295686-aa9a-40b9-831b-e23fceaeefef)

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

![image](https://github.com/pauld-d/json_cpp/assets/36675895/44fb049b-30e1-4381-8368-edb9bcb6d2fd)

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

![image](https://github.com/pauld-d/json_cpp/assets/36675895/a28ffef6-f166-43af-b8d7-c15e1ff4b430)

--- 

Iterating through an object:

```
JsonNode json = json_empty_object();
json["key0"] = "value0"; 
json["key1"] = "value1"; 
for (auto& [key,value] : json) 
    std::cout << "key=" << key << ", value=" << value << std::endl; 
```

![image](https://github.com/pauld-d/json_cpp/assets/36675895/db828baf-b007-48d3-8d02-92d4d40efae3)

---

Iterating through an array: 

```
JsonNode json = string_to_json("{\"backpack\":[\"Gengis Khan's Crown\",\"The Holy Grail\",\"The Bible\",\"The Shroud Of Turin\"],\"name\":\"Percival\"}");
for (auto& [key,value] : json["backpack"]) 
{
    std::cout << "    key=" << key << ", value=" << value << std::endl; 
}

![image](https://github.com/pauld-d/json_cpp/assets/36675895/ef35b94f-0c96-42b4-851e-0db36d6cbe95)
