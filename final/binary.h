#ifndef BINARY_H
#define BINARY_H
#include <fstream>
#include <utility>
#include <vector>
#include <list>
#include <set>
#include <map>
namespace serializer
{
    namespace binary
    {
        /// @brief Serialize arithmeric type
        /// @tparam T
        /// @param t
        /// @param out file output stream
        template <typename T>
        void serialize(const T &t, std::ofstream &out);

        /// @brief Serialize std::string
        /// @tparam T
        /// @param t
        /// @param out
        template <typename T>
        void serialize(const std::string &t, std::ofstream &out);
        /// @brief Sirialization interface
        /// @tparam T
        /// @param t
        /// @param filename
        template <typename T>
        void serialize(const T &t, const std::string &filename);

        /// @brief Serialize pair type
        /// @tparam T1
        /// @tparam T2
        /// @param t
        /// @param out
        template <typename T1, typename T2>
        void serialize(const std::pair<T1, T2> &t, std::ofstream &out);

        /// @brief Serialize map type
        /// @tparam T1
        /// @tparam T2
        /// @param t
        /// @param out
        template <typename T1, typename T2>
        void serialize(const std::map<T1, T2> &t, std::ofstream &out);

        /// @brief Serialize vector type
        /// @tparam T
        /// @param t
        /// @param out
        template <typename T>
        void serialize(const std::vector<T> &t, std::ofstream &out);

        /// @brief Serialize set type
        /// @tparam T
        /// @param t
        /// @param out
        template <typename T>
        void serialize(const std::set<T> &t, std::ofstream &out);

        /// @brief Serialize list type
        /// @tparam T
        /// @param t
        /// @param out
        template <typename T>
        void serialize(const std::list<T> &t, std::ofstream &out);

        template <typename T>
        void deserialize(T &t, std::string filename);

        template <typename T>
        void deserialize(T &t, std::ifstream &in);

        template <typename T>
        void deserialize(std::string &t, std::ifstream &in);

        template <typename T1, typename T2>
        void deserialize(std::pair<T1, T2> &t, std::ifstream &in);

        template <typename T1, typename T2>
        void deserialize(std::map<T1, T2> &t, std::ifstream &in);

        template <typename T>
        void deserialize(std::vector<T> &t, std::ifstream &in);

        template <typename T>
        void deserialize(std::set<T> &t, std::ifstream &in);

        template <typename T>
        void deserialize(std::list<T> &t, std::ifstream &in);
    }
}

#include "binary.cpp"
#endif