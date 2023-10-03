# json_cpp
Single-file header-only C++ JSON library

USAGE 1 (STRING TO JSON):  
```
JsonNode json = string_to_json("{\"name\":\"Paul Demanze\",\"age\":23,\"jobTitle\":\"Software Engineer\",\"companies\":[\"Google\",\"PriceHubble\",\"NavLive\"]}");

std::string name = json["name"]; 
std::cout << "name: " << name << std::endl; 
std::cout << "companies: " << json["companies"] << std::endl; 
```

USAGE 2 (JSON TO STRING): 
```
     JsonNode json = json_empty_object(); 
    
    json["name"] = "Paul Demanze";
    json["age"] = 5157; 
    json["job"] = "Pharaoh"; 
    
    std::cout << json_to_string(json) << std::endl; 
```

CREATING ARRAYS: 
```
    json = json_empty_object(); 
    
    json["backpack"] = json_empty_array(); 
    json["backpack"].push_back("Gengis Khan's Crown");
    json["backpack"].push_back("The Holy Grail");
    json["backpack"].push_back("The Bible");
    json["backpack"].push_back("The Shroud Of Turin");

    std::cout << json_to_string(json) << std::endl; 
```
