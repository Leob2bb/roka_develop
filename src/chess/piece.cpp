#include "piece.hpp"

namespace chess {

Piece::Piece(Color color, PieceType type) noexcept
	: color_(color), type_(type) {}

Color Piece::color() const noexcept {
	return color_;
}

PieceType Piece::type() const noexcept {
	return type_;
}

}  // namespace chess
