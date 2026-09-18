#include "board.h"

namespace chess {

Board::Board() {
    constexpr std::array<PieceType, 8> back_rank = {
        PieceType::Rook,
        PieceType::Knight,
        PieceType::Bishop,
        PieceType::Queen,
        PieceType::King,
        PieceType::Bishop,
        PieceType::Knight,
        PieceType::Rook
    };
    constexpr std::array<PieceType, 8> pawn_rank = {
        PieceType::Pawn,
        PieceType::Pawn,
        PieceType::Pawn,
        PieceType::Pawn,
        PieceType::Pawn,
        PieceType::Pawn,
        PieceType::Pawn,
        PieceType::Pawn
    };

    place_pieces(0, Color::Black, back_rank);
    place_pieces(8, Color::Black, pawn_rank);
    place_pieces(48, Color::White, pawn_rank);
    place_pieces(56, Color::White, back_rank);
}

const Piece* Board::piece_at(std::size_t square) const noexcept {
    if (square >= SquareCount || !squares_[square].has_value()) {
        return nullptr;
    }

    return &squares_[square].value();
}

bool Board::place_piece(std::size_t square, Piece piece) noexcept {
    if (square >= SquareCount) {
        return false;
    }

    squares_[square] = piece;
    return true;
}

void Board::place_pieces(
    std::size_t first_square,
    Color color,
    const std::array<PieceType, 8>& piece_types) {
    for (std::size_t offset = 0; offset < piece_types.size(); ++offset) {
        place_piece(first_square + offset, Piece(color, piece_types[offset]));
    }
}

}  // namespace chess