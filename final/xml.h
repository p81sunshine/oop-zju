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
        template <typename T>
        void serialize(const T &t, const std::string &filename);

        template <typename T>
        void serialize(const T& t, XMLDocument* doc, XMLElement* root);

    }
}

#include "xml.cpp"
#endif