#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

typedef struct NormalHeader {
    uint8_t a;
    uint32_t b;
} NormalHeader;
#ifdef _MSC_VER
#pragma pack(push, 1)
typedef struct PackedHeader {
    uint8_t a;
    uint32_t b;
} PackedHeader;
#pragma pack(pop)
#else
typedef struct __attribute__((__packed__)) PackedHeader {
    uint8_t a;
    uint32_t b;
} PackedHeader;
#endif

NormalHeader NormalHeader_create(uint8_t a, uint32_t b);
PackedHeader PackedHeader_create(uint8_t a, uint32_t b);

NormalHeader NormalHeader_create(uint8_t a, uint32_t b) {
    NormalHeader self;
    memset(&self, 0, sizeof(NormalHeader));
        self.a = a;
    self.b = b;
    return self;
}

PackedHeader PackedHeader_create(uint8_t a, uint32_t b) {
    PackedHeader self;
    memset(&self, 0, sizeof(PackedHeader));
        self.a = a;
    self.b = b;
    return self;
}

int main(int argc, char** argv) {
    printf("%d\n", sizeof(NormalHeader));
    printf("%d\n", sizeof(PackedHeader));
    return 0;
}
