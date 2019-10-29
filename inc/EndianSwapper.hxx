#ifndef ENDIANSWAPPER_HXX
#define ENDIANSWAPPER_HXX

/* Includes -------------------------------------------- */
#include <limits.h>

/* Class ----------------------------------------------- */
class EndianUtility {
    public:
        template<typename T> static T swap_endian(const T pSource) {
            static_assert(CHAR_BIT == 8, "CHAR_BIT != 8");
​
            union {
                T             data;
                unsigned char data8[sizeof(T)];
            } src, dest;
​
            /* Set the source data */
            src.data = pSource;
​
            /* Swap source data & set destination data w/ it */
            for (size_t i = 0U; i < sizeof(T); ++i) {
                dest.data8[i] = src.data8[sizeof(T) - i - 1];
            }
​
            return dest.data;
        }
};

#endif /* ENDIANSWAPPER_HXX */
