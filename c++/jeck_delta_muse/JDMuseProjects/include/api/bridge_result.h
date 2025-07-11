// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from validation.djinni

#pragma once

#include "api/bridge_result_level.h"
#include <cstdint>
#include <string>
#include <utility>

namespace interaxon { namespace bridge {

/**
 * Represents the result of a synchronous operation.
 *
 * Results can be at different levels: eg, success, info, warning, error
 */
struct Result final {
    /**
     * The level of the result.
     * \return The \classlink{ResultLevel}
     */
    ResultLevel level;
    /**
     * The type of operation that this result applies to as a string.
     * \return The type of this result.
     */
    std::string type;
    /**
     * A machine-parseable error code
     * \return 0 if the result is a success, non-zero otherwise.
     */
    int32_t code;
    /**
     * Human-readable description
     * \return A verbose description of the result (error message or status)
     */
    std::string info;

    Result(ResultLevel level_,
           std::string type_,
           int32_t code_,
           std::string info_)
    : level(std::move(level_))
    , type(std::move(type_))
    , code(std::move(code_))
    , info(std::move(info_))
    {}
};

} }  // namespace interaxon::bridge
