#ifndef _USERDEFINEDTYPE_
#define  _USERDEFINEDTYPE_
 
#include "binary.h"

struct UserDefinedType
{
    int idx;
    std::string name;
    std::vector<char> data;


    bool operator==(const UserDefinedType &rhs)
    {
        return idx == rhs.idx && name == rhs.name && data == rhs.data;
    }
};

#endif