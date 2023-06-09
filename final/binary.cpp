#include "binary.h"

namespace serializer
{
    namespace binary
    {
        template <typename T>
        void serialize(const T &t, std::ofstream& out) {
            auto size = sizeof(t);
            out.write(reinterpret_cast<char*>(&size), sizeof(size));
            out.write(reinterpret_cast<char *>(&t), size);
        }

        void serialize(const std::string &t, std::ofstream& out)
        {
            auto size = t.length();
            out.write(reinterpret_cast<char*>(&size), sizeof(size));
            out.write(t.c_str(), size);
        }

        template <typename T>
        void serialize(const T &t, const std::string &filename)
        {
            std::ofstream out(filename, std::ios::binary);
            serialize(t, out);
            out.close();
        }
    }
}