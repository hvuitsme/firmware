#pragma once

#include "quantum.h"

#define XXX KC_NO

#define LAYOUT(\
    A00, A01, A02, A03, A04, A05,      B00, B01, B02, B03, B04, B05,\
    A10, A11, A12, A13, A14, A15,      B10, B11, B12, B13, B14, B15,\
    A20, A21, A22, A23, A24, A25, A40, B20, B21, B22, B23, B24, B25,\
    A30, A31, A32, A33, A34, A35, A45, B30, B31, B32, B33, B34, B35 \
){\
{ A00, A01, A02, A03, A04, A05 },\
{ A10, A11, A12, A13, A14, A15 },\
{ A20, A21, A22, A23, A24, A25 },\
{ A30, A31, A32, A33, A34, A35 },\
{ A40, XXX, XXX, XXX, XXX, A45 },\
{ B00, B01, B02, B03, B04, B05 },\
{ B10, B11, B12, B13, B14, B15 },\
{ B20, B21, B22, B23, B24, B25 },\
{ B30, B31, B32, B33, B34, B35 } \
}
