/*******************************************************************************
    OpenAirInterface
    Copyright(c) 1999 - 2014 Eurecom

    OpenAirInterface is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.


    OpenAirInterface is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with OpenAirInterface.The full GNU General Public License is
   included in this distribution in the file called "COPYING". If not,
   see <http://www.gnu.org/licenses/>.

  Contact Information
  OpenAirInterface Admin: openair_admin@eurecom.fr
  OpenAirInterface Tech : openair_tech@eurecom.fr
  OpenAirInterface Dev  : openair4g-devel@eurecom.fr

  Address      : Eurecom, Compus SophiaTech 450, route des chappes, 06451 Biot, France.

 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "OctetString.h"

#ifndef DETACH_TYPE_H_
#define DETACH_TYPE_H_

#define DETACH_TYPE_MINIMUM_LENGTH 1
#define DETACH_TYPE_MAXIMUM_LENGTH 1

typedef struct DetachType_tag {
#define DETACH_TYPE_NORMAL_DETACH 0
#define DETACH_TYPE_SWITCH_OFF    1
  uint8_t  switchoff:1;
#define DETACH_TYPE_EPS     0b001
#define DETACH_TYPE_IMSI    0b010
#define DETACH_TYPE_EPS_IMSI    0b011
#define DETACH_TYPE_RESERVED_1    0b110
#define DETACH_TYPE_RESERVED_2    0b111
  uint8_t  typeofdetach:3;
} DetachType;

int encode_detach_type(DetachType *detachtype, uint8_t iei, uint8_t *buffer, uint32_t len);

void dump_detach_type_xml(DetachType *detachtype, uint8_t iei);

uint8_t encode_u8_detach_type(DetachType *detachtype);

int decode_detach_type(DetachType *detachtype, uint8_t iei, uint8_t *buffer, uint32_t len);

int decode_u8_detach_type(DetachType *detachtype, uint8_t iei, uint8_t value, uint32_t len);

#endif /* DETACH TYPE_H_ */

