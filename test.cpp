#include <cctype>
#include <iostream>

#include "src/chess/board.h"

char piece_symbol(const chess::Piece& piece) {
    char symbol;

    switch (piece.type()) {
    case chess::PieceType::King:
        symbol = 'K';
        break;
    case chess::PieceType::Queen:
        symbol = 'Q';
        break;
    case chess::PieceType::Rook:
        symbol = 'R';
        break;
    case chess::PieceType::Bishop:
        symbol = 'B';
        break;
    case chess::PieceType::Knight:
        symbol = 'N';
        break;
    case chess::PieceType::Pawn:
        symbol = 'P';
        break;
    }

    if (piece.color() == chess::Color::Black) {
        symbol = static_cast<char>(std::tolower(symbol));
    }

    return symbol;
}

int main() {
    const chess::Board board;

    std::cout << "8x8 chess board \n";
    for (std::size_t row = 0; row < 8; ++row) {
        std::cout << row << " | ";

        for (std::size_t column = 0; column < 8; ++column) {
            const std::size_t square = row * 8 + column;
            const chess::Piece* piece = board.piece_at(square);

            std::cout << (piece == nullptr ? '.' : piece_symbol(*piece)) << ' ';
        }

        std::cout << "| \n";
    }

    std::cout << "\nUppercase: White, lowercase: Black\n";
    return 0;
}