#ifndef NNUE_H
#define NNUE_H

#include <stdalign.h>
#include <stdint.h>

#include "types.h"
#include "bitboards.h"
#include "misc.h"

#define Position Board
#define Color int
#define Square int
#define Piece int
#define Value int
#define Bitboard uint64_t

#define SQ_NONE 64

#define pieces()         ((pos->colours[0] | pos->colours[1]))
#define pieces_p(x)      (pos->pieces[(x)])
#define piece_on(x)      (pos->squares[x])
#define type_of_p(x)     (pieceType((x)))
#define square_of(c, p)  (getlsb(pos->colours[c] & pos->pieces[p]))
#define make_piece(c, t) (makePiece((t), (c)))
#define stm()            (pos->turn)

#define pop_lsb(x)  (poplsb(x))

#define clamp(a, b, c) ((a) < (b) ? (b) : (a) > (c) ? (c) : (a))

struct DirtyPiece {
  int dirtyNum;
  Piece pc[3];
  Square from[3];
  Square to[3];
};

typedef struct DirtyPiece DirtyPiece;

typedef struct {
  alignas(64) int16_t accumulation[2][256];
  bool computedAccumulation;
} Accumulator;

void nnue_init(void);
Value nnue_evaluate(const Position *pos);

#endif
