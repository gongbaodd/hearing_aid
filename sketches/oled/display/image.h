static unsigned char baby_cry_bits[] = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00,
   0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x03, 0xfe, 0x03, 0x00, 0xf0,
   0x00, 0x00, 0xfc, 0x07, 0xfe, 0x07, 0x00, 0xf0, 0x00, 0x00, 0xfe, 0x07,
   0x8f, 0x07, 0x00, 0xf0, 0x00, 0x00, 0x1e, 0x0f, 0x0f, 0x07, 0x00, 0xf0,
   0x00, 0x00, 0x0e, 0x0f, 0x0f, 0x07, 0x00, 0xf0, 0x00, 0x00, 0x0e, 0x0f,
   0x0f, 0x0f, 0x00, 0xfe, 0x07, 0x00, 0x0f, 0x0f, 0x7e, 0x0f, 0xc0, 0xff,
   0x3f, 0x00, 0xef, 0x07, 0xfe, 0x0f, 0xf8, 0xff, 0xff, 0x01, 0xff, 0x07,
   0xfc, 0x0f, 0xfc, 0xff, 0xff, 0x03, 0xff, 0x03, 0xe0, 0x0f, 0xff, 0x00,
   0xf0, 0x0f, 0x7f, 0x00, 0x00, 0x80, 0x1f, 0x00, 0x80, 0x1f, 0x00, 0x00,
   0x00, 0xc0, 0x07, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0xe0, 0x03, 0x00,
   0x00, 0x7c, 0x00, 0x00, 0x00, 0xf0, 0x01, 0x00, 0x00, 0xf8, 0x00, 0x00,
   0x00, 0xf8, 0x00, 0x00, 0x00, 0xf0, 0x01, 0x00, 0x1c, 0x7c, 0x00, 0x00,
   0x00, 0xe0, 0x83, 0x03, 0x3c, 0x3e, 0x00, 0x00, 0x00, 0xc0, 0xc7, 0x03,
   0x18, 0x1e, 0x18, 0x00, 0x80, 0x81, 0x87, 0x01, 0x00, 0x0f, 0x3c, 0x00,
   0xc0, 0x03, 0x0f, 0x00, 0x00, 0x0f, 0xfc, 0x00, 0xf0, 0x03, 0x0f, 0x00,
   0x80, 0x07, 0xf8, 0x01, 0xf8, 0x01, 0x1e, 0x00, 0x80, 0x07, 0xf0, 0x03,
   0xfc, 0x00, 0x1e, 0x00, 0x80, 0x03, 0xc0, 0x07, 0x3e, 0x00, 0x1c, 0x00,
   0xe0, 0x03, 0xf0, 0x07, 0xfe, 0x00, 0x7c, 0x00, 0xf8, 0x03, 0xfc, 0x03,
   0xfc, 0x03, 0xfc, 0x01, 0xfc, 0x01, 0xfc, 0x00, 0xf0, 0x03, 0xf8, 0x03,
   0x7c, 0x00, 0x3c, 0x00, 0xc0, 0x03, 0xe0, 0x03, 0x1e, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x80, 0x07, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07,
   0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0x1e, 0x00, 0x00, 0xf0,
   0x00, 0x00, 0x80, 0x07, 0x3e, 0x00, 0x00, 0xfe, 0x07, 0x00, 0xc0, 0x07,
   0xfc, 0x01, 0x80, 0xff, 0x1f, 0x00, 0xf8, 0x03, 0xf8, 0x03, 0xc0, 0xff,
   0x3f, 0x00, 0xfc, 0x01, 0xf0, 0x03, 0xe0, 0x07, 0x7e, 0x00, 0xfc, 0x00,
   0xc0, 0x03, 0xe0, 0x01, 0x78, 0x00, 0x3c, 0x00, 0x80, 0x07, 0xf0, 0x00,
   0xf0, 0x00, 0x1e, 0x00, 0x80, 0x07, 0xf0, 0x00, 0xf0, 0x00, 0x1e, 0x00,
   0x80, 0x07, 0x78, 0x60, 0xe0, 0x01, 0x0e, 0x00, 0x00, 0x0f, 0x78, 0xf0,
   0xe0, 0x01, 0x0f, 0x00, 0x00, 0x1f, 0x38, 0xf0, 0xe0, 0x81, 0x0f, 0x00,
   0x00, 0x1e, 0x38, 0xf0, 0xc0, 0x81, 0x07, 0x00, 0x00, 0x3c, 0xf8, 0xff,
   0xff, 0xc1, 0x03, 0x00, 0x00, 0x7c, 0xf8, 0xff, 0xff, 0xe1, 0x03, 0x00,
   0x00, 0xf8, 0xf0, 0xff, 0xff, 0xf0, 0x01, 0x00, 0x80, 0xf0, 0x01, 0x00,
   0x00, 0xf8, 0x20, 0x00, 0xc0, 0xe1, 0x03, 0x00, 0x00, 0x7c, 0x70, 0x00,
   0xc0, 0xc1, 0x0f, 0x00, 0x00, 0x3f, 0x70, 0x00, 0xc0, 0x81, 0x3f, 0x00,
   0xc0, 0x1f, 0x30, 0x00, 0x00, 0x00, 0xfe, 0x01, 0xf8, 0x07, 0x00, 0x00,
   0x00, 0x00, 0xfc, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff,
   0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0x1f, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

static unsigned char siren_bits[] = {
   0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0xf0,
   0x00, 0x1e, 0x00, 0x00, 0x00, 0x80, 0x07, 0xf0, 0x00, 0x1e, 0x00, 0x00,
   0x00, 0x00, 0x0f, 0xf0, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x60,
   0x80, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x80, 0x07, 0x00, 0x00,
   0x00, 0x00, 0x1c, 0x00, 0x80, 0x03, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00,
   0x80, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xfe, 0x07, 0x00, 0x00, 0x00, 0xc0, 0x01, 0x80, 0xff,
   0x1f, 0x00, 0x38, 0x00, 0xc0, 0x07, 0xe0, 0xff, 0x7f, 0x00, 0x3e, 0x00,
   0xc0, 0x1f, 0xf0, 0x07, 0xfe, 0x80, 0x3f, 0x00, 0x80, 0x1f, 0xf8, 0x01,
   0xf8, 0x81, 0x1f, 0x00, 0x00, 0x1e, 0x7c, 0x00, 0xe0, 0x83, 0x07, 0x00,
   0x00, 0x18, 0x3e, 0x00, 0xc0, 0x87, 0x01, 0x00, 0x00, 0x00, 0x1f, 0x60,
   0x80, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x0f, 0x00, 0x00,
   0x00, 0x80, 0x07, 0xf0, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x80, 0x07, 0xf0,
   0x00, 0x1e, 0x00, 0x00, 0x00, 0x80, 0x03, 0xf0, 0x00, 0x1c, 0x00, 0x00,
   0x00, 0xc0, 0x03, 0xf0, 0x00, 0x3c, 0x00, 0x00, 0x00, 0xc0, 0x03, 0xf0,
   0x00, 0x3c, 0x00, 0x00, 0xf8, 0xc3, 0x03, 0xf0, 0x00, 0x3c, 0xfc, 0x01,
   0xfc, 0xc7, 0x03, 0xf0, 0x00, 0x3c, 0xfe, 0x03, 0xf8, 0xc3, 0x03, 0xf0,
   0x00, 0x3c, 0xfc, 0x01, 0x00, 0xc0, 0x03, 0xf0, 0x00, 0x3c, 0x00, 0x00,
   0x00, 0xc0, 0x03, 0xf0, 0x00, 0x3c, 0x00, 0x00, 0x00, 0xc0, 0x03, 0x60,
   0x00, 0x3c, 0x00, 0x00, 0x00, 0xc0, 0x03, 0x00, 0x00, 0x3c, 0x00, 0x00,
   0x00, 0xc0, 0x03, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0xc0, 0x03, 0x00,
   0x00, 0x3c, 0x00, 0x00, 0x00, 0xc0, 0x03, 0x60, 0x00, 0x3c, 0x00, 0x00,
   0x00, 0xc0, 0x03, 0xf0, 0x00, 0x3c, 0x00, 0x00, 0x00, 0xc0, 0x03, 0xf0,
   0x00, 0x3c, 0x00, 0x00, 0x00, 0xc0, 0x03, 0x60, 0x00, 0x3c, 0x00, 0x00,
   0x00, 0xc0, 0x03, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0xc0, 0x03, 0x00,
   0x00, 0x3c, 0x00, 0x00, 0x00, 0xc0, 0x03, 0x00, 0x00, 0x3c, 0x00, 0x00,
   0x00, 0xc0, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff,
   0xff, 0xff, 0x01, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x03, 0x00,
   0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x07, 0x00, 0x00, 0x1e, 0x00, 0x00,
   0x00, 0x80, 0x07, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00,
   0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0xff, 0xff, 0xff,
   0xff, 0xff, 0x0f, 0x00, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x00,
   0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 0xe0, 0xff, 0xff, 0xff,
   0xff, 0xff, 0x7f, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00,
   0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x70, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xe0, 0x00, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00,
   0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xf0, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0x00, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00 };

static unsigned char telephone_bits[] = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
   0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x01, 0x00, 0x00,
   0x00, 0x00, 0xff, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00, 0xe0, 0xff, 0xff,
   0xff, 0x7f, 0x00, 0x00, 0x00, 0xf8, 0x3f, 0x00, 0xc0, 0xff, 0x01, 0x00,
   0x00, 0xfe, 0x03, 0x00, 0x00, 0xfc, 0x07, 0x00, 0x80, 0x7f, 0x00, 0x00,
   0x00, 0xe0, 0x1f, 0x00, 0xc0, 0x1f, 0x00, 0x00, 0x00, 0x80, 0x3f, 0x00,
   0xe0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0xf0, 0x01, 0x00, 0x00,
   0x00, 0x00, 0xf8, 0x00, 0xf8, 0x00, 0x00, 0xff, 0x0f, 0x00, 0xf0, 0x01,
   0x7c, 0x00, 0xf0, 0xff, 0x7f, 0x00, 0xe0, 0x03, 0x3e, 0x00, 0xfe, 0xff,
   0xff, 0x03, 0xc0, 0x03, 0x1e, 0x80, 0xff, 0xff, 0xff, 0x1f, 0x80, 0x07,
   0x0e, 0xc0, 0x7f, 0x00, 0xe0, 0x3f, 0x00, 0x07, 0x0f, 0xe0, 0x0f, 0x00,
   0x00, 0x7f, 0x00, 0x0f, 0x0f, 0xe0, 0x01, 0x00, 0x00, 0x78, 0x00, 0x0f,
   0x0f, 0xc0, 0x01, 0x00, 0x00, 0x38, 0x00, 0x0f, 0x0f, 0xc0, 0x03, 0x00,
   0x00, 0x3c, 0x00, 0x0f, 0x0f, 0xc0, 0x03, 0x00, 0x00, 0x3c, 0x00, 0x0f,
   0xff, 0xff, 0x01, 0x00, 0x00, 0x7c, 0x80, 0x0f, 0xfe, 0xff, 0x01, 0x03,
   0x0c, 0xf8, 0xff, 0x07, 0xfc, 0xff, 0x00, 0x07, 0x0e, 0xf0, 0xff, 0x03,
   0xf8, 0x7f, 0x00, 0x07, 0x0e, 0xe0, 0xff, 0x01, 0x00, 0x00, 0x00, 0x07,
   0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x01, 0x00, 0x00,
   0x00, 0x00, 0xfc, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff,
   0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x0f, 0x00, 0x00,
   0x00, 0x80, 0x0f, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0xc0, 0x07, 0x00,
   0x00, 0x3e, 0x00, 0x00, 0x00, 0xe0, 0x03, 0x00, 0x00, 0x7c, 0x00, 0x00,
   0x00, 0xf0, 0x01, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x00, 0xf0, 0x00, 0xfc,
   0x03, 0xf0, 0x00, 0x00, 0x00, 0x78, 0x00, 0xff, 0x0f, 0xe0, 0x01, 0x00,
   0x00, 0x7c, 0x80, 0xff, 0x1f, 0xe0, 0x03, 0x00, 0x00, 0x3e, 0xc0, 0x0f,
   0x3f, 0xc0, 0x07, 0x00, 0x00, 0x1e, 0xc0, 0x03, 0x3c, 0x80, 0x07, 0x00,
   0x00, 0x1e, 0xe0, 0x01, 0x78, 0x80, 0x07, 0x00, 0x00, 0x0f, 0xe0, 0x01,
   0x78, 0x00, 0x0f, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x70, 0x00, 0x0e, 0x00,
   0x80, 0x07, 0xe0, 0x00, 0x70, 0x00, 0x1e, 0x00, 0x80, 0x07, 0xe0, 0x00,
   0x70, 0x00, 0x1e, 0x00, 0x80, 0x07, 0xe0, 0x00, 0x70, 0x00, 0x1e, 0x00,
   0x80, 0x03, 0xe0, 0x01, 0x78, 0x00, 0x1c, 0x00, 0x80, 0x03, 0xe0, 0x01,
   0x78, 0x00, 0x1c, 0x00, 0xc0, 0x03, 0xc0, 0x03, 0x3c, 0x00, 0x3c, 0x00,
   0xc0, 0x03, 0xc0, 0x0f, 0x3f, 0x00, 0x3c, 0x00, 0xc0, 0x03, 0x80, 0xff,
   0x1f, 0x00, 0x3c, 0x00, 0xc0, 0x03, 0x00, 0xff, 0x0f, 0x00, 0x3c, 0x00,
   0xc0, 0x03, 0x00, 0xfc, 0x03, 0x00, 0x3c, 0x00, 0xc0, 0x03, 0x00, 0x00,
   0x00, 0x00, 0x3c, 0x00, 0xc0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00,
   0xc0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0xc0, 0xff, 0xff, 0xff,
   0xff, 0xff, 0x3f, 0x00, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00,
   0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x80, 0xff, 0xff, 0xff,
   0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };