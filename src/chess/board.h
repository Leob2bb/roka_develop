#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <array>
#include <cstddef>
#include <optional>

#include "piece.hpp"

namespace chess {

class Board {
public:
    static constexpr std::size_t SquareCount = 64;

    Board();

    const Piece* piece_at(std::size_t square) const noexcept;
    bool place_piece(std::size_t square, Piece piece) noexcept;

private:
    std::array<std::optional<Piece>, SquareCount> squares_{};

    void place_pieces(
        std::size_t first_square,
        Color color,
        const std::array<PieceType, 8>& piece_types);
};

}  // namespace chess

#endif  // CHESS_BOARD_H