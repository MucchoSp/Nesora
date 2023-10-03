#pragma once



//utf8���疳����艹�}�Ŏg���镶����ɕϊ����܂��B
//�g�p�͔񐄏��ł��B
int EncoderFromUTF8(const char* utf8, char* out) {
	delete[] out;

	const char* work_utf8 = utf8;
	int size = 0;
	while (work_utf8 != 0) {

		if ('!' < *work_utf8 and *work_utf8 < '~')
			size++;
		else if (*(work_utf8++) == 0xe3) {
			if (*work_utf8 == 0x81) {
				if (0x80 < *(++work_utf8))
					size += 2;
				else
					return 1;
			}
			else if (*work_utf8 == 0x82) {
				if (*(++work_utf8) < 0x93)
					size += 2;
				else
					return 1;
			}
			else if (*work_utf8 == 0x80) {
				if (*(++work_utf8) == 0x81 or *(work_utf8) == 0x82)
					size += 2;
				else
					return 1;
			}
			else
				return 1;
		}
		else
			return 1;

		work_utf8++;
	}

	out = new char[size + 1];
	work_utf8 = utf8;
	while (work_utf8 != 0) {

		if ('!' < *work_utf8 and *work_utf8 < '~')
			*out = *work_utf8;
		else if (*(work_utf8++) == 0xe3) {
			if (*work_utf8 == 0x81) {
				if (0x80 < *(++work_utf8)) {
					*(out++) = 0x82;
					*out = (*work_utf8) -0x81 + 0x9f;
				}
			}
			else if (*work_utf8 == 0x82) {
				if (*(++work_utf8) < 0x93) {
					if (0x80 < *(++work_utf8)) {
						*(out++) = 0x82;
						*out = (*work_utf8) - 0x80 + 0xde;
					}
				}
			}
			else if (*work_utf8 == 0x80) {
				if (*(++work_utf8) == 0x81) {
					*(out++) = 0x81;
					*out = 0x41;
				}
				else if(*(work_utf8) == 0x82) {
					*(out++) = 0x81;
					*out = 0x42;
				}

			}
		}

		work_utf8++;out++;
	}



	return 0;
}

