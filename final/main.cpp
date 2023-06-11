#include <iostream>
#include <string>
#include <typeinfo>
#include "binary.h"
#include "UserDefinedType.h"
#include "test_utility.h"
#include "xml.h"

void binaryTest()
{
    std::cout << "--------Binary Serialization Test --------------\n";
    using serializer::binary::deserialize;
    using serializer::binary::serialize;

    std::string s1 = "Hello World!", s2;
    serialize(s1, "out.bin");
    deserialize(s2, "out.bin");

    double d1 = 21.22, d2;
    serialize(d1, "out.bin");
    deserialize(d2, "out.bin");

    int i1 = 2, i2;
    serialize(i1, "out.bin");
    deserialize(i2, "out.bin");

    char c1 = 'o', c2;
    serialize(c1, "out.bin");
    deserialize(c2, "out.bin");

    bool b1 = false, b2;
    serialize(b1, "out.bin");
    deserialize(b2, "out.bin");

    std::set<int> set1{1, 2, 3}, set2;
    serialize(set1, "out.bin");
    deserialize(set2, "out.bin");

    std::list<double> l1{1.0, 2.2, 3.3}, l2;
    serialize(l1, "out.bin");
    deserialize(l2, "out.bin");

    std::vector<char> v1{'c', 'b', 'd'}, v2;
    serialize(v1, "out.bin");
    deserialize(v2, "out.bin");

    std::pair<int, int> p1{1, 2}, p2;
    serialize(p1, "out.bin");
    deserialize(p2, "out.bin");

    std::map<int, std::set<int>> m1{{1, set1}, {2, set2}}, m2;
    serialize(m1, "out.bin");
    deserialize(m2, "out.bin");

    UserDefinedType u1{i1, s1, v1}, u2;
    u1.serialize();
    u2.deserialize();

    expect_eqal(s1, s2, "string");
    expect_eqal(d1, d2, "double");
    expect_eqal(i1, i2, "integer");
    expect_eqal(b1, b2, "boolean");
    expect_eqal(set1, set2, "std::set");
    expect_eqal(l1, l2, "std::list");
    expect_eqal(v1, v2, "std::vector");
    expect_eqal(p1, p1, "std::pair");
    expect_eqal(m1, m2, "std::map");
    expect_eqal(u1, u2, "userDefinedType");

    std::cout << "------------------End-------------\n";
}

void xmlTest() 
{
    std::cout << "--------XML Serialization Test --------------\n";
    // using serializer::xml::deserialize;
    using serializer::xml::serialize;

    // std::string s1 = "Hello World!", s2;
    // serialize(s1, "out.bin");
    // deserialize(s2, "out.bin");

    double d1 = 21.22, d2;
    serialize(d1, typeid(d1).name() + std::string(".xml"));
    // deserialize(d2, "out.xml");

    int i1 = 2, i2;
    serialize(i1, typeid(i1).name() + std::string(".xml"));
    // deserialize(i2, "out.xml");

    char c1 = 'o', c2;
    serialize(c1, typeid(c1).name() + std::string(".xml"));
    // deserialize(c2, "out.xml");

    bool b1 = false, b2;
    serialize(c1, typeid(b1).name() + std::string(".xml"));
    // deserialize(b2, "out.xml");

}
int main()
{
    binaryTest();
    xmlTest();
}