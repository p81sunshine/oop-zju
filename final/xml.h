#ifndef XML_H
#define XML_H

#include <utility>
#include <vector>
#include <list>
#include <set>
#include <map>

#include "tinyxml2.h"
using namespace tinyxml2;
namespace serializer
{
    namespace xml
    {

#define XMLBEGINREGISTER_STRUCT_SERIALIZEBIN                                \
    const char *declaration = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"; \
    XMLDocument *doc = new XMLDocument();                                   \
    doc->Parse(declaration);                                                \
    std::string tag = "XMLWrapper";                                         \
    XMLElement *root = doc->NewElement(tag.c_str());                        \
    doc->InsertEndChild(root);                                              \
    XMLElement *elem = doc->NewElement("UserDefinedStruct");                \
    root->InsertEndChild(elem);

#define XMLREGISTER_STRUCT_MEMBER_SERIALIZE(t, memberName) serialize(t.memberName, doc, elem);
#define XMLEND_REGISTERSTRUCT_SERIALIZE() \
    doc->SaveFile("./res/UserDefineType.xml");  \
    delete doc;

#define XMLBEGIN_REGISTER_STRUCT_DESERIALIZEBIN() \
    XMLDocument *doc_ = new XMLDocument();        \
    doc_->LoadFile("./res/UserDefineType.xml");         \
    std::string tag_ = "XMLWrapper";              \
    XMLElement *elem_ = doc->FirstChildElement(tag_.c_str())->FirstChildElement();
#define XMLREGISTER_STRUCT_MEMBERDESERIALIZE_1(t, memberName) \
    XMLElement *new_elem_ = elem_->FirstChildElement();       \
    deserialize(t.memberName, new_elem_);
#define XMLREGISTER_STRUCT_MEMBERDESERIALIZE_2(t, memberName) \
    new_elem_ = new_elem_->NextSiblingElement();              \
    deserialize(t.memberName, new_elem_);
#define END_REGISTER_STRUCT_DESERIALIZE_XML() delete doc_;

        template <typename T>
        void serialize(const T &t, const std::string &filename);

        template <typename T>
        void serialize(const T &t, XMLDocument *doc, XMLElement *root);

        template <>
        void serialize(const std::string &t, XMLDocument *doc, XMLElement *root);

        template <typename T>
        void serialize(const std::vector<T> &t, XMLDocument *doc, XMLElement *root);

        template <typename T>
        void serialize(const std::list<T> &t, XMLDocument *doc, XMLElement *root);

        template <typename T>
        void serialize(const std::set<T> &t, XMLDocument *doc, XMLElement *root);

        template <typename T1, typename T2>
        void serialize(const std::pair<T1, T2> t, XMLDocument *doc, XMLElement *root);

        template <typename T1, typename T2>
        void serialize(const std::map<T1, T2> t, XMLDocument *doc, XMLElement *root);


        template <typename T>
        void deserialize(T &t, const std::string &filename);

        template <typename T>
        void deserialize(T &t, XMLElement *elem);

        template <typename T>
        void deserialize(std::string &t, XMLElement *elem);

        template <typename T>
        void deserialize(std::vector<T> &t, XMLElement *elem);

        template <typename T>
        void deserialize(std::set<T> &t, XMLElement *elem);

        template <typename T>
        void deserialize(std::list<T> &t, XMLElement *elem);

        template <typename T1, typename T2>
        void deserialize(std::map<T1, T2> &t, XMLElement *elem);

        template <typename T1, typename T2>
        void deserialize(std::pair<T1, T2> &t, XMLElement *elem);

    }
}

#include "xml.cpp"
#endif