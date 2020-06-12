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
}