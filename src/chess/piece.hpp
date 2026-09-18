#ifndef CHESS_PIECE_HPP
#define CHESS_PIECE_HPP

namespace chess {

enum class Color {
    White,
    Black
};

enum class PieceType {
    King,
    Queen,
    Rook,
    Bishop,
    Knight,
    Pawn
};

class Piece {
public:
    Piece(Color color, PieceType type) noexcept;

    Color color() const noexcept;

    PieceType type() const noexcept;

private:
    Color color_;
    PieceType type_;
};

}  // namespace chess

#endif  // CHESS_PIECE_HPP