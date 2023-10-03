# json_cpp
Single-file header-only C++ JSON library

Compatible with all compilers and architectures

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
json = json_empty_object();
json["name"] = "Percival"; 
json["backpack"] = json_empty_array(); 
json["backpack"].push_back("Gengis Khan's Crown");
json["backpack"].push_back("The Holy Grail");
json["backpack"].push_back("The Bible");
json["backpack"].push_back("The Shroud Of Turin");
std::cout << json_to_string(json) << std::endl; 
```

![image](https://github.com/pauld-d/json_cpp/assets/36675895/2861982d-1267-47a1-a2bb-ee9ba0c815aa)

