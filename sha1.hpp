#pragma once
#include <cstdint>
#include <string>
#include <string_view>

struct Sha1 {
public:
    uint32_t state[5] { 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0 };

    Sha1() = default;

    std::string to_string() const {
        std::string str;
        const char *alphabet = "0123456789abcdef";
        for (int i = 0; i < 5; i++){
            for (int j = 7; j >= 0; j--){
                str += alphabet[(state[i] >> j * 4) & 0xf];
            }
        }
        return str;
    }

    bool operator==(const Sha1& rhs) const
    {
        return
            state[0] == rhs.state[0] &&
            state[1] == rhs.state[1] &&
            state[2] == rhs.state[2] &&
            state[3] == rhs.state[3] &&
            state[4] == rhs.state[4];
    }

    bool operator!=(const Sha1& rhs) const
    {
        return
            state[0] != rhs.state[0] ||
            state[1] != rhs.state[1] ||
            state[2] != rhs.state[2] ||
            state[3] != rhs.state[3] ||
            state[4] != rhs.state[4];
    }
};
