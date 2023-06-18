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
    serialize(s1, "./res/out.bin");
    deserialize(s2, "./res/out.bin");

    double d1 = 21.22, d2;
    serialize(d1, "./res/out.bin");
    deserialize(d2, "./res/out.bin");

    int i1 = 2, i2;
    serialize(i1, "./res/out.bin");
    deserialize(i2, "./res/out.bin");

    char c1 = 'o', c2;
    serialize(c1, "./res/out.bin");
    deserialize(c2, "./res/out.bin");

    bool b1 = false, b2;
    serialize(b1, "./res/out.bin");
    deserialize(b2, "./res/out.bin");

    std::set<int> set1{1, 2, 3}, set2;
    serialize(set1, "./res/out.bin");
    deserialize(set2, "./res/out.bin");

    std::list<double> l1{1.0, 2.2, 3.3}, l2;
    serialize(l1, "./res/out.bin");
    deserialize(l2, "./res/out.bin");

    std::vector<char> v1{'c', 'b', 'd'}, v2;
    serialize(v1, "./res/out.bin");
    deserialize(v2, "./res/out.bin");

    std::pair<int, int> p1{1, 2}, p2;
    serialize(p1, "./res/out.bin");
    deserialize(p2, "./res/out.bin");

    std::map<int, std::set<int>> m1{{1, set1}, {2, set2}}, m2;
    serialize(m1, "./res/out.bin");
    deserialize(m2, "./res/out.bin");

    struct userDefine
    {
        std::vector<int> s;
        std::string t;
        std::pair<int, std::string> p;

        bool operator==(const userDefine &rhs) const {
            return s == rhs.s && t == rhs.t && p == rhs.p;
        }
    };

    userDefine u1, u2;

    u1.s = {1, 2, 3, 4};
    u1.t = "UserDefine";
    u1.p = std::make_pair(1, "xx");

    
    // A convinent way for user to serialize a struct
    BEGINREGISTER_STRUCT_SERIALIZEBIN
    REGISTER_STRUCT_MEMBER_SERIALIZE_BIN(u1,s)
    REGISTER_STRUCT_MEMBER_SERIALIZE_BIN(u1,t)
    REGISTER_STRUCT_MEMBER_SERIALIZE_BIN(u1,p)
    END_REGISTERSTRUCT_SERIALIZE_BIN()

    // A convinent way for user to deserialize a struct
    BEGIN_REGISTER_STRUCT_DESERIALIZEBIN()
    REGISTER_STRUCT_MEMBERDESERIALIZE_BIN(u2,s);
    REGISTER_STRUCT_MEMBERDESERIALIZE_BIN(u2,t);
    REGISTER_STRUCT_MEMBERDESERIALIZE_BIN(u2,p);
    END_REGISTER_STRUCT_DESERIALIZE_BIN()
    expect_eqal(s1, s2, "string");
    expect_eqal(d1, d2, "double");
    expect_eqal(i1, i2, "integer");
    expect_eqal(b1, b2, "boolean");
    expect_eqal(c1, c2, "boolean");
    expect_eqal(set1, set2, "std::set");
    expect_eqal(l1, l2, "std::list");
    expect_eqal(v1, v2, "std::vector");
    expect_eqal(p1, p1, "std::pair");
    expect_eqal(m1, m2, "std::map");
    expect_eqal(u1, u2, "userDefinedType");

    std::cout << "------------------End-------------\n";
    test = 0;
}

void xmlTest()
{
    std::cout << "--------XML Serialization Test --------------\n";
    using serializer::xml::deserialize;
    using serializer::xml::serialize;

    std::string s1 = "Hello World!", s2;
    serialize(s1, "./res/string.xml");
    deserialize(s2, "./res/string.xml");

    double d1 = 21.22, d2;
    serialize(d1, "./res/double.xml");
    deserialize(d2, "./res/double.xml");

    int i1 = 2, i2;
    serialize(i1, "./res/int.xml");
    deserialize(i2, "./res/int.xml");

    char c1 = 'o', c2;
    serialize(c1, "./res/char.xml");
    deserialize(c2, "./res/char.xml");

    bool b1 = false, b2;
    serialize(b1, "./res/bool.xml");
    deserialize(b2, "./res/bool.xml");

    std::set<int> set1{1, 2, 3}, set2;
    serialize(set1, "./res/set.xml");
    deserialize(set2, "./res/set.xml");

    std::list<double> l1{1.0, 2.2, 3.3}, l2;
    serialize(l1, "./res/list.xml");
    deserialize(l2, "./res/list.xml");

    std::vector<char> v1{'c', 'b', 'd'}, v2;
    serialize(v1, "./res/vector.xml");
    deserialize(v2, "./res/vector.xml");

    std::pair<int, int> p1{1, 2}, p2;
    serialize(p1, "./res/pair.xml");
    deserialize(p2, "./res/pair.xml");

    std::map<int, std::set<int>> m1{{1, set1}, {2, set2}}, m2;
    serialize(m1, "./res/map.xml");
    deserialize(m2, "./res/map.xml");

    struct userDefine
    {
        std::vector<int> s;
        std::string t;
        std::pair<int, std::string> p;

        bool operator==(const userDefine &rhs) const {
            return s == rhs.s && t == rhs.t && p == rhs.p;
        }
    };

    userDefine u1, u2;

    u1.s = {1, 2, 3, 4};
    u1.t = "UserDefine";
    u1.p = std::make_pair(1, "xx");

    
    XMLBEGINREGISTER_STRUCT_SERIALIZEBIN
    XMLREGISTER_STRUCT_MEMBER_SERIALIZE(u1,s)
    XMLREGISTER_STRUCT_MEMBER_SERIALIZE(u1,t)
    XMLREGISTER_STRUCT_MEMBER_SERIALIZE(u1,p)
    XMLEND_REGISTERSTRUCT_SERIALIZE()

    XMLBEGIN_REGISTER_STRUCT_DESERIALIZEBIN()
    XMLREGISTER_STRUCT_MEMBERDESERIALIZE_1(u2,s)
    XMLREGISTER_STRUCT_MEMBERDESERIALIZE_2(u2,t)
    XMLREGISTER_STRUCT_MEMBERDESERIALIZE_2(u2,p)
    END_REGISTER_STRUCT_DESERIALIZE_XML()

    expect_eqal(c1, c2, "char");
    expect_eqal(d1, d2, "double");
    expect_eqal(i1, i2, "integer");
    expect_eqal(b1, b2, "boolean");
    expect_eqal(s1, s2, "string");
    expect_eqal(set1, set2, "std::set");
    expect_eqal(l1, l2, "std::list");
    expect_eqal(v1, v2, "std::vector");
    expect_eqal(p1, p1, "std::pair");
    expect_eqal(m1, m2, "std::map");
    expect_eqal(u1, u2, "userDefinedType");
}
int main()
{
    binaryTest();
    xmlTest();
}