/*
 * Copyright (c) 2024, Niko Križnik <niko.kriznik0@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <fmt/core.h>

#include "characters.hpp"
#include "op_codes.hpp"

auto main([[maybe_unused]] int argc_, [[maybe_unused]] char **argv_) -> int
{
    fmt::print("sic - A CHIP-8 emulator\n");

    fmt::print("{:#06X} - CLS\n", sic::op_code::CLS);

    fmt::print("3:\n");
    for (const auto row : sic::characters::CHAR_3)
    {
        fmt::print("{:08b}\n", row);
    }

    return 0;
}
