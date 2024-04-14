#pragma once

#include <cstdint>

namespace sic {

namespace op_code {

// 00E0 - CLS
inline constexpr std::uint16_t CLS = 0x00E0;
// 00EE - RET
inline constexpr std::uint16_t RET = 0x00EE;
// 1nnn - JP addr
inline constexpr std::uint16_t JP_MASK = 0x1FFF;
// 2nnn - CALL addr
inline constexpr std::uint16_t CALL_MASK = 0x2FFF;
// 3xkk - SE Vx, byte
inline constexpr std::uint16_t SE_VX_MASK = 0x3FFF;
// 4xkk - SNE Vx, byte
inline constexpr std::uint16_t SNE_VX_MASK = 0x4FFF;
// 5xy0 - SE Vx, Vy
inline constexpr std::uint16_t SE_VX_VY_MASK = 0x5FF0;
// 6xkk - LD Vx, byte
inline constexpr std::uint16_t LD_VX_MASK = 0x6FFF;
// 7xkk - ADD Vx, byte
inline constexpr std::uint16_t ADD_VX_MASK = 0x7FFF;
// 8xy0 - LD Vx, Vy
inline constexpr std::uint16_t LD_VX_VY_MASK = 0x8FF0;
// 8xy1 - OR Vx, Vy
inline constexpr std::uint16_t OR_VX_VY_MASK = 0x8FF1;
// 8xy2 - AND Vx, Vy
inline constexpr std::uint16_t AND_VX_VY_MASK = 0x8FF2;
// 8xy3 - XOR Vx, Vy
inline constexpr std::uint16_t XOR_VX_VY_MASK = 0x8FF3;
// 8xy4 - ADD Vx, Vy
inline constexpr std::uint16_t ADD_VX_VY_MASK = 0x8FF4;
// 8xy5 - SUB Vx, Vy
inline constexpr std::uint16_t SUB_VX_VY_MASK = 0x8FF5;
// 8xy6 - SHR Vx {, Vy}
inline constexpr std::uint16_t SHR_VX_VY_MASK = 0x8FF6;
// 8xy7 - SUBN Vx, Vy
inline constexpr std::uint16_t SUBN_VX_VY_MASK = 0x8FF7;
// 8xyE - SHL Vx {, Vy}
inline constexpr std::uint16_t SHL_VX_VY_MASK = 0x8FFE;
// 9xy0 - SNE Vx, Vy
inline constexpr std::uint16_t SNE_VX_VY_MASK = 0x9FF0;
// Annn - LD I, addr
inline constexpr std::uint16_t LD_I_MASK = 0xAFFF;
// Bnnn - JP V0, addr
inline constexpr std::uint16_t JP_V0_MASK = 0xBFFF;
// Cxkk - RND Vx, byte
inline constexpr std::uint16_t RND_VX_MASK = 0xCFFF;
// Dxyn - DRW Vx, Vy, nibble
inline constexpr std::uint16_t DRW_VX_VY_MASK = 0xDFFF;
// Ex9E - SKP Vx
inline constexpr std::uint16_t SKP_VX_MASK = 0xEF9E;
// ExA1 - SKNP Vx
inline constexpr std::uint16_t SKNP_VX_MASK = 0xEFA1;
// Fx07 - LD Vx, DT
inline constexpr std::uint16_t LD_VX_DT_MASK = 0xFF07;
// Fx0A - LD Vx, K
inline constexpr std::uint16_t LD_VX_K_MASK = 0xFF0A;
// Fx15 - LD DT, Vx
inline constexpr std::uint16_t LD_DT_VX_MASK = 0xFF15;
// Fx18 - LD ST, Vx
inline constexpr std::uint16_t LD_ST_VX_MASK = 0xFF18;
// Fx1E - ADD I, Vx
inline constexpr std::uint16_t ADD_I_VX_MASK = 0xFF1E;
// Fx29 - LD F, Vx
inline constexpr std::uint16_t LD_F_VX_MASK = 0xFF29;
// Fx33 - LD B, Vx
inline constexpr std::uint16_t LD_B_VX_MASK = 0xFF33;
// Fx55 - LD [I], Vx
inline constexpr std::uint16_t LD_I_VX_MASK = 0xFF55;
// Fx65 - LD Vx, [I]
inline constexpr std::uint16_t LD_VX_I_MASK = 0xFF65;

} // namespace op_code

} // namespace sic
