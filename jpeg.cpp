#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdint>

#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
    const uint16_t bmpSign = 0x424D;
#elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
    const uint16_t bmpSign = 0x4D42;
#else
    #error "Endianness not supported"
#endif

#pragma pack(push, 1)

struct fileHeader{
    uint16_t signature{bmpSign};
    uint32_t fileSize{0};
    uint32_t reserved{0};
    uint32_t dataOffset{0};
};

struct infoHeader{
    
};

#pragma pack(pop)
