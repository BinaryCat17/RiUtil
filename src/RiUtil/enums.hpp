#pragma once
#include <magic_enum.hpp>
#include <string>
#include <optional>

namespace rise {
    template<typename EnumT>
    std::string toString(EnumT val);

    template<typename EnumT>
    std::optional<EnumT> fromString(std::string const &str);

    template<typename EnumT, typename = std::enable_if_t<magic_enum::is_scoped_enum<EnumT>::value>>
    std::string toString(EnumT val) {
        return magic_enum::enum_name(val);
    }

    template<typename EnumT, typename = std::enable_if_t<magic_enum::is_scoped_enum<EnumT>::value>>
    std::optional<EnumT> fromString(std::string const &str) {
        return magic_enum::enum_cast<EnumT>(str);
    }

    template<typename Bit_T, typename Mask_T = uint32_t>
    class BitFlags {
        template<typename T, typename MT>
        friend bool operator==(BitFlags<T, MT> const &lhs, BitFlags<T, MT> const &rhs);

    public:
        BitFlags() = default;

        BitFlags(Bit_T const &bit) noexcept: mask_(static_cast<Mask_T>(bit)) {
        }

        explicit BitFlags(Mask_T const &flags) : mask_(flags) {
        }


        BitFlags &operator|=(BitFlags const &rhs) noexcept {
            mask_ |= rhs.mask_;
            return *this;
        }

        BitFlags &operator&=(BitFlags const &rhs) noexcept {
            mask_ &= rhs.mask_;
            return *this;
        }

        BitFlags &operator^=(BitFlags const &rhs) noexcept {
            mask_ ^= rhs.mask_;
            return *this;
        }

        explicit operator bool() const {
            return static_cast<bool>(mask_);
        }

        explicit operator Mask_T() const {
            return mask_;
        }

    private:
        Mask_T mask_ = {};
    };

    template<typename T, typename MT>
    bool operator==(BitFlags<T, MT> const &lhs, BitFlags<T, MT> const &rhs) {
        return lhs.mask_ == rhs.mask_;
    }

    template<typename T, typename MT>
    bool operator!=(BitFlags<T, MT> const &lhs, BitFlags<T, MT> const &rhs) {
        return !(lhs == rhs);
    }

    template<typename T, typename MT>
    bool operator==(BitFlags<T, MT> const &lhs, T const &rhs) {
        return lhs == BitFlags<T, MT>(rhs);
    }

    template<typename T, typename MT>
    bool operator!=(BitFlags<T, MT> const &lhs, T const &rhs) {
        return lhs != BitFlags<T, MT>(rhs);
    }

    template<typename T, typename MT>
    bool operator==(T const &lhs, BitFlags<T, MT> const &rhs) {
        return BitFlags<T, MT>(lhs) == rhs;
    }

    template<typename T, typename MT>
    bool operator!=(T const &lhs, BitFlags<T, MT> const &rhs) {
        return BitFlags<T, MT>(lhs) != rhs;
    }

    template<typename T, typename MT>
    BitFlags<T, MT> operator|(BitFlags<T, MT> const &lhs, BitFlags<T, MT> const &rhs) {
        BitFlags<T, MT> result = lhs;
        result |= rhs;
        return result;
    }

    template<typename T, typename MT>
    BitFlags<T, MT> operator&(BitFlags<T, MT> const &lhs, BitFlags<T, MT> const &rhs) {
        BitFlags<T, MT> result = lhs;
        result &= rhs;
        return result;
    }

    template<typename T, typename MT>
    BitFlags<T, MT> operator^(BitFlags<T, MT> const &lhs, BitFlags<T, MT> const &rhs) {
        BitFlags<T, MT> result = lhs;
        result ^= rhs;
        return result;
    }

    template<typename T, typename MT>
    BitFlags<T, MT> operator|(BitFlags<T, MT> const &lhs, T const &rhs) noexcept {
        BitFlags<T, MT> result = lhs;
        result |= rhs;
        return result;
    }

    template<typename T, typename MT>
    BitFlags<T, MT> operator&(BitFlags<T, MT> const &lhs, T const &rhs) noexcept {
        BitFlags<T, MT> result = lhs;
        result &= rhs;
        return result;
    }

    template<typename T, typename MT>
    BitFlags<T, MT> operator^(BitFlags<T, MT> const &lhs, T const &rhs) noexcept {
        BitFlags<T, MT> result = lhs;
        result ^= rhs;
        return result;
    }

    template<typename T, typename MT>
    BitFlags<T, MT> operator|(T const &lhs, BitFlags<T, MT> const &rhs) {
        BitFlags<T, MT> result = lhs;
        result |= rhs;
        return result;
    }

    template<typename T, typename MT>
    BitFlags<T, MT> operator&(T const &lhs, BitFlags<T, MT> const &rhs) {
        BitFlags<T, MT> result = lhs;
        result &= rhs;
        return result;
    }

    template<typename T, typename MT>
    BitFlags<T, MT> operator^(T const &lhs, BitFlags<T, MT> const &rhs) {
        BitFlags<T, MT> result = lhs;
        result ^= rhs;
        return result;
    }

    template <typename Enum_T, typename FlagT>
    std::string flagsToString(BitFlags<Enum_T, FlagT> value)
    {
        std::string result;
        for (auto val : magic_enum::enum_values<Enum_T>())
        {
            if (val & value)
            {
                result += magic_enum::enum_name(val);
                result += " ";
            }
        }
        if (!result.empty())
        {
            result.pop_back();
        }
        return result;
    }

    template <typename Enum_T, typename FlagT>
    std::ostream &operator<<(std::ostream &os, BitFlags<Enum_T, FlagT> value)
    {
        os << flagsToString(value);
        return os;
    }
}

#define RISE_MAKE_BIT_FLAGS(name, ...)                                        \
  enum class name __VA_ARGS__; using name##Flags = ::rise::BitFlags<name>;    \
  inline ::rise::BitFlags<name> operator|(name a, name b) noexcept            \
  {                                                                           \
    return ::rise::BitFlags<name>(a) | b;                                     \
  }