#pragma once

#include "quantum.h"

#define XXX KC_NO

#define LAYOUT( \
  K00, K01, K02, K03, K04, K05, \
  K10, K11, K12, K13, K14, K15, \
  K20, K21, K22, K23, K24, K25, \
  K30, K31,      K33            \
) { \
  { K00,   K01,   K02,   K03,   K04,   K05},  \
  { K10,   K11,   K12,   K13,   K14,   K15},  \
  { K20,   K21,   K22,   K23,   K24,   K25},  \
  { K30,   K31,   XXX,   K33,   XXX,   XXX}   \
}
