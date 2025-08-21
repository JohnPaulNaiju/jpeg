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
    uint32_t size{0};
    int32_t width{0};
    int32_t height{0};
    uint16_t planes{1};
    uint16_t bitsPerPixel{0};
    uint32_t compression{0};
    uint32_t imageSize{0};
    int32_t xPixelsPerM{0};
    int32_t yPixelsPerM{0};
    uint32_t colorsUsed{0};
    uint32_t importantColors{0};
};

struct pixel{
    uint8_t blue;
    uint8_t green;
    uint8_t red;
};

#pragma pack(pop)

int main(){

    return 0;
};