#ifndef TYPE_DATA_STRUCT_H
#define TYPE_DATA_STRUCT_H

typedef struct type_data {
  int value;
  byte h_byte;
  byte l_byte;
} Data;

//separate significant ones
void sprt_ones(type_data* data) {
  data->h_byte = highByte(data->value);
  data->l_byte = lowByte(data->value);
}

//concatenate into a single word
void concat_bytes(type_data* data) {
  data->value = (data->h_byte << 8) + data->l_byte;
}
// type_data concat_bytes(byte h_byte, byte l_byte) {
//   return (h_byte << 8) + l_Byte;
// }

#endif