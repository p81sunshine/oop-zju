#include "binary.h"

struct UserDefinedType
{
    int idx;
    std::string name;
    std::vector<char> data;

    void serialize()
    {
        serializer::binary::serialize(idx, "outidx.bin");
        serializer::binary::serialize(name, "outname.bin");
        serializer::binary::serialize(data, "outdata.bin");
    }

    void deserialize()
    {
        serializer::binary::deserialize(idx, "outidx.bin");
        serializer::binary::deserialize(name, "outname.bin");
        serializer::binary::deserialize(data, "outdata.bin");
    }

    bool operator==(const UserDefinedType &rhs)
    {
        return idx == rhs.idx && name == rhs.name && data == rhs.data;
    }
};