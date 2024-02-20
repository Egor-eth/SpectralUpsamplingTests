#ifndef INCLUDE_SPECTRAL_SPEC_SP_LUT_H
#define INCLUDE_SPECTRAL_SPEC_SP_LUT_H
#include <spectral/internal/math/math.h>
#include <cinttypes>
#include <istream>

namespace spec {
    
    class LUT
    {
    public:
        static constexpr uint64_t FILE_MARKER = 0xfafa0000ab0ba000;

        LUT(vec3 *data, unsigned step) : step{step}, size{256 / step + (255 % step != 0)}, data{data} {}

        LUT(unsigned step) : step{step}, size{256 / step + (255 % step != 0)}, data{new vec3[size * size * size]} {}

        LUT(const LUT &) = delete;
        LUT &operator=(const LUT &) = delete;

        LUT(LUT &&l) : step{l.step}, size{l.size}, data{}
        {
            std::swap(data, l.data);
        }

        ~LUT()
        {
            delete[] data;
        }

        unsigned get_size() const
        {
            return size;
        }

        unsigned get_step() const
        {
            return step;
        }

        const vec3 *get_raw_data() const
        {
            return data;
        }

        vec3 eval(int a, int b, int alpha) const;

        static LUT load_from(std::istream &src);

    private:
        const unsigned step;
        const unsigned size;
        vec3 *data;

        const vec3 &at(int i, int j, int k) const
        {
            return data[((k * size) + i) * size + j];
        }
        Float aid_to_alpha(int c) const;
    };


}

#endif