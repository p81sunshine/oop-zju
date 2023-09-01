#include "binary.h"

namespace serializer
{
    namespace binary
    {

        template <typename T>
        void serialize(const T &t, std::ofstream &out)
        {
            static_assert(std::is_arithmetic<T>::value, "T must be arithmetic type");
            auto size = sizeof(t);
            out.write(reinterpret_cast<const char *>(&size), sizeof(size));
            out.write(reinterpret_cast<const char *>(&t), size);
        }

        void serialize(const std::string &t, std::ofstream &out)
        {
            auto size = t.length();
            out.write(reinterpret_cast<const char *>(&size), sizeof(size));
            out.write(t.c_str(), size);
        }

        // Wrapper for serialization
        template <typename T>
        void serialize(const T &t, const std::string &filename)
        {
            std::ofstream out(filename, std::ios::binary);
            serialize(t, out);
            out.close();
        }

        template <typename T1, typename T2>
        void serialize(const std::pair<T1, T2> &t, std::ofstream &out)
        {
            serialize(t.first, out);
            serialize(t.second, out);
        }

        template <typename T1, typename T2>
        void serialize(const std::map<T1, T2> &t, std::ofstream &out)
        {
            auto size = t.size();
            out.write(reinterpret_cast<const char *>(&size), sizeof(size));
            for (const auto [x, y] : t)
            {
                serialize(x, out);
                serialize(y, out);
            }
        }

        template <typename T>
        void serialize(const std::vector<T> &t, std::ofstream &out)
        {
            auto size = t.size();
            out.write(reinterpret_cast<const char *>(&size), sizeof(size));
            for (const auto x : t)
            {
                serialize(x, out);
            }
        }

        template <typename T>
        void serialize(const std::set<T> &t, std::ofstream &out)
        {
            auto size = t.size();
            out.write(reinterpret_cast<const char *>(&size), sizeof(size));
            for (const auto x : t)
            {
                serialize(x, out);
            }
        }

        template <typename T>
        void serialize(const std::list<T> &t, std::ofstream &out)
        {
            auto size = t.size();
            out.write(reinterpret_cast<const char *>(&size), sizeof(size));
            for (const auto x : t)
            {
                serialize(x, out);
            }
        }

        template <typename T>
        void deserialize(T &t, std::string filename)
        {
            std::ifstream in(filename, std::ios::binary);
            deserialize(t, in);
            in.close();
        }

        template <typename T>
        void deserialize(T &t, std::ifstream &in)
        {
            size_t size;
            in.read(reinterpret_cast<char *>(&size), sizeof(size));
            in.read(reinterpret_cast<char *>(&t), size);
        }
        template <>
        void deserialize(std::string &t, std::ifstream &in)
        {
            size_t size;
            in.read(reinterpret_cast<char *>(&size), sizeof(size));
            char *buffer = new char[size];  // 创建一个缓冲区来存储文件内容
            in.read(buffer, size);          // 从文件中读取二进制数据
            std::string str2(buffer, size); // 将读取的二进制数据转换为字符串
            t = str2;
            delete[] buffer; // 释放缓冲区的内存
        }

        template <typename T1, typename T2>
        void deserialize(std::pair<T1, T2> &t, std::ifstream &in)
        {
            deserialize(t.first, in);
            deserialize(t.second, in);
        }
        template <typename T1, typename T2>
        void deserialize(std::map<T1, T2> &t, std::ifstream &in)
        {
            size_t size;
            in.read(reinterpret_cast<char *>(&size), sizeof(size));
            for (int i = 0; i < size; i++)
            {
                T1 temp1;
                T2 temp2;
                deserialize(temp1, in);
                deserialize(temp2, in);
                t[temp1] = temp2;
            }
        }
        template <typename T>
        void deserialize(std::vector<T> &t, std::ifstream &in)
        {
            size_t size;
            in.read(reinterpret_cast<char *>(&size), sizeof(size));
            for (int i = 0; i < size; i++)
            {
                T temp;
                deserialize(temp, in);
                t.push_back(temp);
            }
        }
        template <typename T>
        void deserialize(std::set<T> &t, std::ifstream &in)
        {
            size_t size;
            in.read(reinterpret_cast<char *>(&size), sizeof(size));
            for (int i = 0; i < size; i++)
            {
                T temp;
                deserialize(temp, in);
                t.insert(temp);
            }
        }

        template <typename T>
        void deserialize(std::list<T> &t, std::ifstream &in)
        {
            size_t size;
            in.read(reinterpret_cast<char *>(&size), sizeof(size));
            for (int i = 0; i < size; i++)
            {
                T temp;
                deserialize(temp, in);
                t.push_back(temp);
            }
        }

#define BEGINREGISTER_STRUCT_SERIALIZEBIN std::ofstream out("./res/out.bin", std::ios::binary);
#define REGISTER_STRUCT_MEMBER_SERIALIZE_BIN(t, memberName) serialize(t.memberName, out);
#define END_REGISTERSTRUCT_SERIALIZE_BIN() out.close();

#define BEGIN_REGISTER_STRUCT_DESERIALIZEBIN() std::ifstream in("./res/out.bin", std::ios::binary);
#define REGISTER_STRUCT_MEMBERDESERIALIZE_BIN(t, memberName) deserialize(t.memberName, in);
#define END_REGISTER_STRUCT_DESERIALIZE_BIN() in.close();

    }
}