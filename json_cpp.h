/* json_cpp - v0.5 - Single-file header-only json reading and writing library 
https://github.com/pauld-d/json_cpp

Copyright (c) 1997-2099 Paul Demanze 

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <stdexcept>

struct Json {
    enum { JSON_STRING, JSON_VALUE, JSON_OBJECT, JSON_ARRAY };
    
    private: 
        int type;
        std::string v;
        std::map<std::string, Json> on; 
    
    public:
        Json() 
        {
            type = JSON_OBJECT; 
        }
        bool isString() 
        {
            return type == JSON_STRING; 
        }
        
        bool isValue() 
        {
            return type == JSON_VALUE; 
        }
        
        bool isObject() 
        {
            return type == JSON_OBJECT; 
        }
        
        bool isArray() 
        {
            return type == JSON_ARRAY; 
        }
        
        Json& operator=(char* value) 
        {
            type = JSON_STRING; 
            v = std::string(value); 
            on.clear();
            return *this; 
        }
        
        Json& operator=(const char* value) 
        {
            type = JSON_STRING; 
            v = std::string(value); 
            on.clear();
            return *this; 
        }
        
        Json& operator=(std::string value) 
        {
            type = JSON_STRING; 
            v = value; 
            on.clear();
            return *this; 
        }
        
        Json& operator=(unsigned int value) 
        {
            type = JSON_VALUE; 
            v = std::to_string(value); 
            on.clear();
            return *this; 
        }
        
        Json& operator=(unsigned long int value) 
        {
            type = JSON_VALUE; 
            v = std::to_string(value); 
            on.clear();
            return *this; 
        }
        
        Json& operator=(unsigned long long int value) 
        {
            type = JSON_VALUE; 
            v = std::to_string(value); 
            on.clear();
            return *this; 
        }
        
        Json& operator=(int value) 
        {
            type = JSON_VALUE; 
            v = std::to_string(value); 
            on.clear();
            return *this; 
        }
        
        Json& operator=(long int value) 
        {
            type = JSON_VALUE; 
            v = std::to_string(value); 
            on.clear();
            return *this; 
        }
        
        Json& operator=(long long int value) 
        {
            type = JSON_VALUE; 
            v = std::to_string(value); 
            on.clear();
            return *this; 
        }
        
        Json& operator=(bool value) 
        {
            type = JSON_VALUE; 
            v = value ? "true" : "false"; 
            on.clear();
            return *this; 
        }
        
        Json& operator=(float value) 
        {
            type = JSON_VALUE; 
            v = std::to_string(value); 
            on.clear();
            return *this; 
        }
        
        Json& operator=(double value) 
        {
            type = JSON_VALUE; 
            v = std::to_string(value); 
            on.clear();
            return *this; 
        }
        
        template<typename T>
        void push_back(T value) 
        {
	    if (type == JSON_OBJECT)
                if (on.empty())
                    type = JSON_ARRAY; 
            
            if (type != JSON_ARRAY)
                throw std::invalid_argument("Cannot push because this JSON node is not an array"); 
                
            on[std::to_string(on.size())] = value; 
        }
        
        operator std::string() 
        {
            return v; 
        }
    
        std::string to_string() 
        {
            std::string output = ""; 
            if (type == JSON_STRING) 
            {
                output += "\""; 
                output += v; 
                output += "\""; 
            }
            else if (type == JSON_VALUE) 
            {
                output += v; 
            }
            else if (type == JSON_OBJECT) 
            {
                output += "{"; 
                std::map<std::string, Json>::iterator it = on.begin(); 
                bool first = true; 
                while (it != on.end()) 
                {
                    if (!first)
                        output += ",";
                    first = false; 
                    output += "\""; 
                    output += it->first;
                    output += "\""; 
                    output += ":"; 
                    output += it->second.to_string();
                    it++; 
                }
                output += "}"; 
            }
            else if (type == JSON_ARRAY) 
            {
                output += "["; 
                std::map<std::string, Json>::iterator it = on.begin(); 
                bool first = true; 
                while (it != on.end()) 
                {
                    if (!first)
                        output += ",";
                    first = false; 
                    output += it->second.to_string(); 
                    it++; 
                }
                output += "]"; 
            }
            return output; 
        }
        
        friend std::ostream& operator<<(std::ostream& out, Json n)
	    {
	        if (n.type == JSON_STRING)
	            out << n.v; 
	        else
	            out << n.to_string(); 
	        return out; 
	    }
	    
	    bool contains(std::string key)
	    {
	        return on.find(key) != on.end(); 
	    }
	    
	    bool has_key(std::string key)
	    {
	        return on.find(key) != on.end(); 
	    }
	    
	    std::vector<std::string> keys() 
	    {
	        std::vector<std::string> result; 
	        std::map<std::string, Json>::iterator it = on.begin(); 
            while (it != on.end()) 
            {
                result.push_back(it->first); 
                it++; 
            }
            return result; 
	    }
        
        Json& operator[](std::string key) 
        {
            if (is_null())
            {
                type = JSON_OBJECT; 
                v = ""; 
            }
            
            if (type != JSON_OBJECT)
                throw std::invalid_argument("Cannot search key " + key + "because this JSON node is not an object"); 
                
            auto iterator = on.find(key); 
            
            if (iterator == on.end())
            {
                on[key] = new_null(); 
                return on[key]; 
            }
            else
            {
                return iterator->second; 
            }
        }
        
        Json operator[](long long int key) 
        {
            if (type != JSON_ARRAY) throw std::invalid_argument("Cannot access index " + std::to_string(key) + " because this JSON node is not an array"); 
            
            auto stringified = std::to_string(key); 
            auto it = on.find(stringified); 
            if (it != on.end())
            {
                return it->second; 
            }
            else
            {
                throw std::out_of_range("Index " + stringified + " is out of range in array of size " + std::to_string(on.size())); 
            }
        }
        
        long unsigned int size() 
        {
            if (type != JSON_ARRAY) throw std::invalid_argument("Cannot access size because this JSON node is not an array"); 
            return on.size(); 
        }
        
        static char* skip_whitespace(char* c) 
        {
            while (*c == ' ' || *c == '\t' || *c == '\n' || *c == '\r') c++;
            return c;
        }
        
        static char* parse_string(char* c, std::string& s) 
        {
            c++; 
            char* x = c;
            while (*c != '\0' && *c != '"') c++;
            if (*c == '"') {
                s = std::string(x, c); 
                c++;
            }
            return c;
        }
        
        static char* parse_anything(char* c, std::string& str) {
            char* start = c;
            while (*c != '\0' && *c != '"' && *c != '{' && *c != '}' && *c != '[' && *c != ']' && *c != ',' && *c != ':' && *c != ' ' && *c != '\t' && *c != '\n' && *c != '\r') {
                c++;
            }
            str = std::string(start, c); 
            return c;
        }
        
        static char* parse_object(char* json, Json& obj) 
        {
            json = skip_whitespace(json); 
            if (*json != '{') {
                return NULL;
            }
            json++; 
            json = skip_whitespace(json);
            if (*json == '}') {
                json++; 
                return json;
            }
            while (1) 
            {
                if (obj.on.size() > 0) {
                    json = skip_whitespace(json);
                    if (*json != ',') {
                        return NULL;
                    }
                    json++; 
                }
                json = skip_whitespace(json);
                if (*json != '"') {
                    return NULL;
                }
                Json value;
                std::string key; 
                json = parse_string(json, key);
                if (json == NULL) {
                    return NULL;
                }
                json = skip_whitespace(json);
                if (*json != ':') {
                    return NULL;
                }
                json++;
                json = parse(json, value);
                if (json == NULL) {
                    return NULL;
                }
                obj.on[key] = value; 
                json = skip_whitespace(json);
                if (*json == '}') {
                    json++; 
                    return json;
                }
            }
        }
        
        static char* parse_array(char* json, Json& arr) {
            json++; 
            json = skip_whitespace(json);
            if (*json == ']') {
                json++; 
                return json;
            }
            while (1) {
                if (arr.on.size() > 0) {
                    json = skip_whitespace(json);
                    if (*json != ',') {
                        return NULL;
                    }
                    json++; 
                }
                json = skip_whitespace(json);
                Json value;
                json = parse(json, value);
                if (json == NULL) {
                    return NULL;
                }
                arr.on[std::to_string(arr.on.size())] = value; 
                json = skip_whitespace(json);
                if (*json == ']') {
                    json++;
                    return json;
                }
            }
        }
        
        static char* parse(char* json, Json& value) {
            json = skip_whitespace(json);
            switch (*json) {
                case '"':
                    value.type = JSON_STRING;
                    json = parse_string(json, value.v);
                    return json; 
                case '{':
                    value.type = JSON_OBJECT;
                    return parse_object(json, value);
                case '[':
                    value.type = JSON_ARRAY;
                    return parse_array(json, value);
                case 0: 
                    return NULL; 
                default: 
                    value.type = JSON_VALUE;
                    json = parse_anything(json, value.v);
                    return json; 
            }
            return NULL;
        }
        
        static Json value(std::string value) 
        {
            Json node; 
            node.type = JSON_VALUE; 
            node.v = value; 
            return node; 
        }
        
        static Json null_value() 
        {
            return value("null"); 
        }
        
        bool is_null() 
        {
            return type == JSON_VALUE && v == "null"; 
        }
        
        typedef std::map<std::string, Json>::iterator iterator;

        iterator begin() {
            return on.begin();
        }
    
        iterator end() {
            return on.end();
        }
};

Json string_to_json(std::string s) 
{
    Json node; 
    Json::parse((char*)s.c_str(), node); 
    return node; 
}

std::string json_to_string(Json n) 
{
    return n.to_string(); 
}
