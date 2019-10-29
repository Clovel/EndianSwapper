#ifndef ENDIANSWAPPER_HXX
#define ENDIANSWAPPER_HXX

/* Includes -------------------------------------------- */
#include <limits.h>

/* Class ----------------------------------------------- */
/** @class EndianSwapper<T>
 * @brief Static utility that allows 
 * endian swapping of a data of type T. 
 * @tparam T Type of the data to swap
 */
class EndianSwapper {
    public:
        /** @fn swapEndian<T>(const T pSource)
         * @brief Static method that swaps a given 
         * data's endianness and returns the result.
         * @tparam T            Type of the data to swap
         * @param[in] pSource   Data input. Shall not be altered
         * 
         * @return Swapped data
         */
        template<typename T> static T swapEndian(const T pSource) {
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
