#include "binary.cpp"
#include <iostream>
#include <string>

using serializer::binary::serialize;

int main() {
    std::string s1 = "Hello World!", s2;
    serialize(s1, "out.bin");
    
}