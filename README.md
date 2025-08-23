# C++ JPEG Compressor 📸 (ongoing)

This is a JPEG compressor built from scratch in C++. It takes a simple `.bmp` image and squishes it down into a `.jpg` file, all without using any external libraries.

## Key processes

JPEG compression is a fascinating process that cleverly takes advantage of the flaws of our eyes. It's a multi-step pipeline that trims down data we're not likely to miss. The key processes include:

- Color Space Conversion
- Chrominance Downsampling
- Discrete Cosine Transform (DCT)
- Quantization
- Entropy Encoding

All of these are written in scratch without any libraries.

Another hurdle is that reading and loading a .bmp file is cumbersome and must be done according to the bitmap file format standards or you end up with scrambled bits especially when built using low level languages like C/C++.

## References

1) [BMP File Format](https://www.ece.ualberta.ca/~elliott/ee552/studentAppNotes/2003_w/misc/bmp_file_format/bmp_file_format.htm)
2) [JPEG research paper](https://arxiv.org/pdf/1405.6147)

## Usage
