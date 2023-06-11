#include "xml.h"
#include "tinyxml2.h"
#include <typeinfo>
#include <iostream>
using namespace tinyxml2;

namespace serializer
{
    namespace xml
    {
        template <typename T>
        void serialize(const T &t, const std::string &filename)
        {
            const char *declaration = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
            XMLDocument *doc = new XMLDocument();
            doc->Parse(declaration);
            XMLElement *root = doc->NewElement("XMLWrapperSerializer");
            doc->InsertEndChild(root);
            serialize(t, doc, root );
            doc->SaveFile(filename.c_str());
        }
        template <typename T>
        void serialize(const T &t, XMLDocument *doc, XMLElement *root)
        {
            static_assert(std::is_arithmetic<T>::value, "T must be arithmetic type");
            std::string name = typeid(t).name();
            XMLElement* elem = doc->NewElement(name.c_str());
            root->InsertEndChild(elem);
            elem->SetText(t);
        }
    }
}
