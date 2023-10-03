# json_cpp
Single-file header-only C++ JSON library

USAGE: 
```
JsonNode json = string_to_json("{\"name\":\"Paul Demanze\",\"age\":23,\"jobTitle\":\"Software Engineer\",\"companies\":[\"Google\",\"PriceHubble\",\"NavLive\"]}");

std::string name = json["name"]; 
std::cout << "name: " << name << std::endl; 
std::cout << "companies: " << json["companies"] << std::endl; 
```
OUTPUT: 
```
name: "Paul Demanze"
companies: ["Google","PriceHubble","NavLive"]
```
