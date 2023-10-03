# json_cpp
Single-file header-only C++ JSON library

Reading: 
```
#include "json_cpp.h"

int main() {
    std::string example = "{\"name\":\"Paul Demanze\",\"age\":23,\"jobTitle\":\"Software Engineer\",\"companies\":[\"Google\",\"PriceHubble\",\"NavLive\"]}";
    JsonNode node = string_to_json(example); 
    std::cout << node["name"] << std::endl; 
}
```
