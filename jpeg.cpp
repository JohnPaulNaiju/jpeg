#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdint>

#pragma pack(push, 1)

struct fileHeader{
    uint16_t signature{0x4D42};
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

    std::ifstream bmpFile;
    std::string filePath;

    while(true){

        std::cout << "Enter the path to BMP image: ";
        std::getline(std::cin, filePath);

        bmpFile.open(filePath, std::ios_base::binary);

        if(bmpFile) break;
        else std::cerr << "Couldn't open file" << std::endl;

    }

    fileHeader file_header;

    bmpFile.read(reinterpret_cast<char*>(&file_header), sizeof(file_header));

    if(file_header.signature != 0x4D42){
        std::cerr << "Hey we only compress a .bmp file" << std::endl;
        bmpFile.close();
        return 1;
    }

    infoHeader info_header;

    bmpFile.read(reinterpret_cast<char*>(&info_header), sizeof(info_header));

    if(info_header.bitsPerPixel != 24){
        std::cerr << "Hey we only compress a 24 bit .bmp file" << std::endl;
        bmpFile.close();
        return 1;
    }

    bmpFile.seekg(file_header.dataOffset, bmpFile.beg);

    int bytesPerPixel = info_header.bitsPerPixel / 8;
    int stride = info_header.width * bytesPerPixel;
    int padding = ((info_header.width * 4) - (stride)) % 4;

    std::vector<pixel> pixels;

    pixels.resize(info_header.width * info_header.height);

    for(int i = 0; i < info_header.height; ++i){}

    return 0;

};