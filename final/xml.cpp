#include "xml.h"
#include "tinyxml2.h"
#include <typeinfo>
#include <iostream>
#include <string>
using namespace tinyxml2;

namespace serializer
{
    namespace xml
    {
        const std::string tag = "XMLWrapperSerializer";
        const std::string value = "val";
        template <typename T>
        void serialize(const T &t, const std::string &filename)
        {
            const char *declaration = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
            XMLDocument *doc = new XMLDocument();
            doc->Parse(declaration);
            XMLElement *root = doc->NewElement(tag.c_str());
            doc->InsertEndChild(root);
            serialize(t, doc, root);
            doc->SaveFile(filename.c_str());

            delete doc;
        }

        template <typename T>
        void serialize(const T &t, XMLDocument *doc, XMLElement *root)
        {
            static_assert(std::is_arithmetic<T>::value, "T must be arithmetic type");
            std::string name = typeid(t).name();
            XMLElement *elem = doc->NewElement(name.c_str());
            elem->SetAttribute(value.c_str(), t);
            root->InsertEndChild(elem);
        }
        template <>
        void serialize(const std::string &t, XMLDocument *doc, XMLElement *root)
        {
            std::string name = "string";
            XMLElement *elem = doc->NewElement(name.c_str());
            elem->SetAttribute(value.c_str(), t.c_str());
            root->InsertEndChild(elem);
        }
        template <typename T>
        void serialize(const std::vector<T> &t, XMLDocument *doc, XMLElement *root)
        {
            std::string name = "vector";
            XMLElement *elem = doc->NewElement(name.c_str());
            root->InsertEndChild(elem);

            for (auto temp : t)
            {
                serialize(temp, doc, elem);
            }
        }
        template <typename T>
        void serialize(const std::list<T> &t, XMLDocument *doc, XMLElement *root)
        {
            std::string name = "list";
            XMLElement *elem = doc->NewElement(name.c_str());
            root->InsertEndChild(elem);

            for (auto temp : t)
            {
                serialize(temp, doc, elem);
            }
        }
        template <typename T>
        void serialize(const std::set<T> &t, XMLDocument *doc, XMLElement *root)
        {
            std::string name = "set";
            XMLElement *elem = doc->NewElement(name.c_str());
            root->InsertEndChild(elem);

            for (auto temp : t)
            {
                serialize(temp, doc, elem);
            }
        }
        template <typename T1, typename T2>
        void serialize(const std::pair<T1, T2> t, XMLDocument *doc, XMLElement *root)
        {
            std::string name = "pair";
            XMLElement *elem = doc->NewElement(name.c_str());
            root->InsertEndChild(elem);
            serialize(t.first, doc, elem);
            serialize(t.second, doc, elem);
        }

        template <typename T1, typename T2>
        void serialize(const std::map<T1, T2> t, XMLDocument *doc, XMLElement *root)
        {
            std::string name = "map";
            XMLElement *elem = doc->NewElement(name.c_str());
            root->InsertEndChild(elem);
            for (auto x : t)
            {
                serialize(x, doc, elem);
            }
        }
        template <typename T>
        void deserialize(T &t, const std::string &filename)
        {
            XMLDocument *doc = new XMLDocument();
            doc->LoadFile(filename.c_str());
            XMLElement *elem = doc->FirstChildElement(tag.c_str())->FirstChildElement();
            deserialize(t, elem);

            delete doc;
        }
        template <typename T>
        void deserialize(T &t, XMLElement *elem)
        {
            static_assert(std::is_arithmetic<T>::value, "T must be arithmetic type");
            elem->QueryAttribute(value.c_str(), &t);
        }
        template <>
        void deserialize(std::string &t, XMLElement *elem)
        {
            char *s = nullptr;
            elem->QueryStringAttribute(value.c_str(), (const char **)&s);
            t = s;
        }
        template <typename T>
        void deserialize(std::vector<T> &t, XMLElement *elem)
        {
            T temp;
            XMLElement *new_elem = elem->FirstChildElement();
            while (new_elem)
            {
                deserialize(temp, new_elem);
                t.push_back(temp);
                new_elem = new_elem->NextSiblingElement();
            }
        }
        template <typename T>
        void deserialize(std::set<T> &t, XMLElement *elem)
        {
            T temp;
            XMLElement *new_elem = elem->FirstChildElement();
            while (new_elem)
            {
                deserialize(temp, new_elem);
                t.insert(temp);
                new_elem = new_elem->NextSiblingElement();
            }
        }
        template <typename T>
        void deserialize(std::list<T> &t, XMLElement *elem)
        {
            T temp;
            XMLElement *new_elem = elem->FirstChildElement();
            while (new_elem)
            {
                deserialize(temp, new_elem);
                t.push_back(temp);
                new_elem = new_elem->NextSiblingElement();
            }
        }
        template <typename T1, typename T2>
        void deserialize(std::map<T1, T2> &t, XMLElement *elem)
        {
            std::pair<T1, T2> temp;
            XMLElement *new_elem = elem->FirstChildElement();
            while (new_elem)
            {
                deserialize(temp, new_elem);
                t.insert(temp);
                new_elem = new_elem->NextSiblingElement();
            }
        }
        template <typename T1, typename T2>
        void deserialize(std::pair<T1, T2> &t, XMLElement *elem)
        {
            XMLElement *new_elem = elem->FirstChildElement();
            T1 t1;
            T2 t2;
            deserialize(t1, new_elem);
            new_elem = new_elem->NextSiblingElement();
            deserialize(t2, new_elem);
            t = std::make_pair(t1, t2);
        }

        template <>
        void deserialize(char &t, XMLElement *elem)
        {
            int temp;
            elem->QueryAttribute(value.c_str(), &temp);
            t = (int)temp;
        }


    }
}
