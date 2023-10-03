// 
// +--------------------------------------------------------------------------------------------+
// |	���}�덆�@��^ - CUI - ���}�R�[�h														|
// |	Copyright (c) 2021 �ށ[����sp															|
// +--------------------------------------------------------------------------------------------+
// |																							|
// |	���}�R�[�h�֌W�̃N���X��֐��̒�`�ł��B												|
// |																							|
// +--------------------------------------------------------------------------------------------+
// |																							|
// |	NSString�́Astd::string�Ɠ����悤�Ɏg���܂��B											|
// |																							|
// +--------------------------------------------------------------------------------------------+
//
// 2023�N�ɉ����ς�

#include "Nesora_for_embedded_systems.h"

//shift-jis�̏�ʃr�b�g0x82�����}�R�[�h�ɃG���R�[�h
NSCHAR nsc::nscharencode(unsigned char c) {
	switch (c) {
		//-----JIS�R�[�h��-----
	case 0x9f:
		//��
		return NSp1;
		//===== 0xa0 =====
	case 0xa0:
		//��
		return NSa;
	case 0xa1:
		//��
		return NSp2;
	case 0xa2:
		//��
		return NSi;
	case 0xa3:
		//��
		//�u���v�Ɠ���
	case 0xa4:
		//��
		return NSu;
	case 0xa5:
		//��
		return NSp3;
	case 0xa6:
		//��
		return NSe;
	case 0xa7:
		//��
		return NSp4;
	case 0xa8:
		//��
		return NSo;
	case 0xa9:
		//��
		return NSka;
	case 0xaa:
		//��
		return NSga;
	case 0xab:
		//��
		return NSki;
	case 0xac:
		//��
		return NSgi;
	case 0xad:
		//��
		return NSku;
	case 0xae:
		//��
		return NSgu;
	case 0xaf:
		//��
		return NSke;

		//===== 0xb0 =====
	case 0xb0:
		//��
		return NSge;
	case 0xb1:
		//��
		return NSko;
	case 0xb2:
		//��
		return NSgo;
	case 0xb3:
		//��
		return NSsa;
	case 0xb4:
		//��
		return NSza;
	case 0xb5:
		//��
		return NSshi;
	case 0xb6:
		//��
		return NSji;
	case 0xb7:
		//��
		return NSsu;
	case 0xb8:
		//��
		return NSzu;
	case 0xb9:
		//��
		return NSse;
	case 0xba:
		//��
		return NSze;
	case 0xbb:
		//��
		return NSso;
	case 0xbc:
		//��
		return NSzo;
	case 0xbd:
		//��
		return NSta;
	case 0xbe:
		//��
		return NSda;
	case 0xbf:
		//��
		return NSti;

		//===== 0xc0 =====
	case 0xc0:
		//��
		return NSdi;
	case 0xc1:
		//��
		return NStt;
	case 0xc2:
		//��
		return NStu;
	case 0xc3:
		//��
		return NSdu;
	case 0xc4:
		//��
		return NSte;
	case 0xc5:
		//��
		return NSde;
	case 0xc6:
		//��
		return NSto;
	case 0xc7:
		//��
		return NSdo;
	case 0xc8:
		//��
		return NSna;
	case 0xc9:
		//��
		return NSni;
	case 0xca:
		//��
		return NSnu;
	case 0xcb:
		//��
		return NSne;
	case 0xcc:
		//��
		return NSno;
	case 0xcd:
		//��
		return NSha;
	case 0xce:
		//��
		return NSba;
	case 0xcf:
		//��
		return NSpa;

		//===== 0xd0 =====
	case 0xd0:
		//��
		return NShi;
	case 0xd1:
		//��
		return NSbi;
	case 0xd2:
		//��
		return NSpi;
	case 0xd3:
		//��
		return NShu;
	case 0xd4:
		//��
		return NSbu;
	case 0xd5:
		//��
		return NSpu;
	case 0xd6:
		//��
		return NShe;
	case 0xd7:
		//��
		return NSbe;
	case 0xd8:
		//��
		return NSpe;
	case 0xd9:
		//��
		return NSho;
	case 0xda:
		//��
		return NSbo;
	case 0xdb:
		//��
		return NSpo;
	case 0xdc:
		//��
		return NSma;
	case 0xdd:
		//��
		return NSmi;
	case 0xde:
		//��
		return NSmu;
	case 0xdf:
		//��
		return NSme;

		//===== 0xe0 =====
	case 0xe0:
		//��
		return NSmo;
	case 0xe1:
		//��
		return NSp1;
	case 0xe2:
		//��
		return NSya;
	case 0xe3:
		//��
		return NSp2;
	case 0xe4:
		//��
		return NSyu;
	case 0xe5:
		//��
		return NSp4;
	case 0xe6:
		//��
		return NSyo;
	case 0xe7:
		//��
		return NSra;
	case 0xe8:
		//��
		return NSri;
	case 0xe9:
		//��
		return NSru;
	case 0xea:
		//��
		return NSre;
	case 0xeb:
		//��
		return NSro;
	case 0xec:
		//��
		return NSp1;
	case 0xed:
		//��
		return NSwa;
	case 0xee:
		//��
		return NSwi;
	case 0xef:
		//��
		return NSwe;

		//===== 0xf0 =====
	case 0xf0:
		//��
		return NSwo;
	case 0xf1:
		//��
		return NSnn1;
	default:

		;
	}

	return NSNULL;
}

//���}�����ŏ����ꂽ�}���`�o�C�g����������}�R�[�h�ɃG���R�[�h
NSSTRINGDATA nsc::nsstrencode(const unsigned char* str) {

	size_t textlen = 0, youon = 0;

	//�����̑I��(textlen�ɂ͕������̐����Ayouon�ɂ͕������̝X���̐����J�E���g����B)
	for (size_t i = 0;i < strlen((const char*)str);i++) {
		if (str[i] == 0x81 or str[i] == 0x82) {
			textlen++;
			i++;
			if (str[i] == 0x9f or str[i] == 0xa1 or str[i] == 0xa3 or str[i] == 0xa5 or str[i] == 0xa7 or str[i] == 0xe1 or str[i] == 0xe3 or str[i] == 0xe5 or str[i] == 0xec)
				youon++;
		}
	};

	NSSTRINGDATA out = new NSCHARDATA[textlen + 1];
	for (size_t i = 0;i < textlen + 1;i++)
		out[i] = nscreateCharData(0, 0, 0, 0);

	int i = 0;size_t n = 0;char nowmode = 0, nowmodepitchpm = 0;
	NSCHARDATA nowmoji = {};
	uint16_t ctime = NSDATAINIT_T;uint32_t alltime = 0;int16_t pitch = NSDATAINIT_P;
	while (str[i] != 0 and n < textlen + 1) {
		//�ʏ�̏���
		if (nowmode == 0) {
			//������
			if (str[i] == 0x82) {
				//���ʂ̕���
				if ((nscharencode(str[i + 1]) & 0xf0) != 0xf0) {
					alltime += ctime;
					nowmoji.c = nscharencode(str[i + 1]);
					nowmoji.time = alltime;
					nowmoji.ctime = ctime;
					nowmoji.pitch = pitch;
					out[n] = nowmoji;
					n++;
					i += 2;
				}
				//���ꐧ�䕶��(�X��)
				else {
					if (n) {
						if (nscharencode(str[i + 1]) == NStt) {
							alltime -= out[n - 1].ctime;
							out[n - 1].ctime = GEMINATE_CONSONANT_SPEED;
							out[n - 1].time = alltime + out[n - 1].ctime;
							nowmoji.c = NSspc;
							nowmoji.pitch = pitch;
							nowmoji.ctime = (unsigned char)(ctime * GEMINATE_CONSONANT_TMAG - GEMINATE_CONSONANT_SPEED);
							alltime += GEMINATE_CONSONANT_SPEED + nowmoji.ctime;
							nowmoji.time = alltime;
							out[n] = nowmoji;
							n++;
						}
						else {
							out[n - 1].c += nscharencode(str[i + 1]) & 0x0f;
						}
					}
					i += 2;
				}
			}
			//�L��
			else if (str[i] == 0x81) {
				switch (str[i + 1]) {
				case 0x41:
					//��_
					nowmoji.c = NSspc;
					nowmoji.time = alltime;
					nowmoji.ctime = ctime;
					nowmoji.pitch = pitch;
					out[n] = nowmoji;
					n++;alltime += ctime;
					break;
				case 0x42:
					//��Ǔ_
					nowmoji.c = NSspc;
					nowmoji.time = alltime;
					nowmoji.ctime = ctime * 2;
					nowmoji.pitch = pitch;
					out[n] = nowmoji;
					n++;alltime += ctime * 2;
					break;
				default:;
				}
				i += 2;
			}
			//�X�s�[�h�A�s�b�`�w��
			else if (str[i] == '<') {
				if (str[i + 1] == 'S' or str[i + 1] == 's') {
					nowmode = 1;
					ctime = 0;
					i += 2;
				}
				else if (str[i + 1] == 'P' or str[i + 1] == 'p') {
					if (str[i + 2] == 'u' or str[i + 2] == 'U') {
						pitch += 5;
						i += 4;
					}
					else if (str[i + 2] == 'd' or str[i + 2] == 'D') {
						pitch -= 5;
						i += 4;
					}
					else {
						nowmode = 2;
						pitch = 0;
						i += 2;
					}
				}
			}
			//�R�����g
			else if (str[i] == '(') {
				nowmode = 4;
			}
			//���̑�
			else {
				i++;
			}
		}
		//�X�s�[�h�̐����̏���
		else if (nowmode == 1) {
			if (str[i] == '>')
				nowmode = 0;
			else {
				if (str[i] >= '0' and str[i] <= '9') {
					ctime *= 10;
					ctime += str[i] - '0';
				}
				else {
					nowmode = 0;
				}
			}
			i++;
		}
		//�s�b�`�̕����̏���
		else if (nowmode == 2) {
			if (str[i] == '+') {
				nowmodepitchpm = 1;
				nowmode = 3;
				i++;
			}
			else if (str[i] == '-') {
				nowmodepitchpm = -1;
				nowmode = 3;
				i++;
			}
			else {
				nowmodepitchpm = 1;
				nowmode = 3;
			}
		}
		//�s�b�`�̐����̏���
		else if (nowmode == 3) {
			if (str[i] == '>') {
				pitch *= nowmodepitchpm;
				nowmode = 0;
			}
			else {
				if (str[i] >= '0' and str[i] <= '9') {
					pitch *= 10;
					pitch += str[i] - '0';
				}
				else {
					nowmode = 0;
				}
			}
			i++;
		}
		//�R�����g
		else if (nowmode == 4) {
			if (str[i] == ')')
				nowmode = 0;
			i++;
		}
	}

	return out;
}

//���}�����ŏ����ꂽ�}���`�o�C�g����������}�R�[�h�ɃG���R�[�h
NSSTRINGDATA nsc::nsstrencode(const char* str) {

	size_t stringlen = strlen(str) + 1;
	unsigned char* text = new unsigned char[stringlen];
	for (size_t i = 0; i < stringlen;i++)text[i] = 0;

	//char�^�̕������unsigned char�^�ɕϊ�
	for (size_t i = 0; i < stringlen;i++)
		text[i] = (unsigned char)((int)str[i] & 0xff);

	return nsstrencode(text);
}

NSSTRINGDATA nsc::nsromajiencode(const unsigned char* str) {

	size_t textlen = 0, youon = 0;

	//�����̑I��(textlen�ɂ͕������̐����Ayouon�ɂ͕������̝X���̐����J�E���g����B)
	for (size_t i = 0;i < strlen((const char*)str);i++) {
		if (('A' <= str[i] and str[i] <= 'Z') or ('a' <= str[i] and str[i] <= 'z')) {
			textlen++;
			i++;
		}
	};

	NSSTRINGDATA out = new NSCHARDATA[textlen + 1];
	for (size_t i = 0;i < textlen + 1;i++)
		out[i] = nscreateCharData(0, 0, 0, 0);

	int i = 0;size_t n = 0;char nowmode = 0, nowmodepitchpm = 0;
	NSCHARDATA nowmoji = {};
	uint16_t ctime = NSDATAINIT_T;uint32_t alltime = 0;int16_t pitch = NSDATAINIT_P;
	while (str[i] != 0 and n < textlen + 1) {
		//�ʏ�̏���
		if (nowmode == 0) {
			//������
			if (('A' <= str[i] and str[i] <= 'Z') or ('a' <= str[i] and str[i] <= 'z')) {
				if (str[i] == 'a' or str[i] == 'A') {
					//��
					nowmoji.c = NSa;
				}
				else if (str[i] == 'i' or str[i] == 'I') {
					//��
					nowmoji.c = NSi;
				}
				else if (str[i] == 'u' or str[i] == 'U') {
					//��
					nowmoji.c = NSu;
				}
				else if (str[i] == 'e' or str[i] == 'E') {
					//��
					nowmoji.c = NSe;
				}
				else if (str[i] == 'o' or str[i] == 'O') {
					//��
					nowmoji.c = NSo;
				}
				else if (str[i] == 'k' or str[i] == 'K') {
					i++;
					if (str[i] == 'a' or str[i] == 'A') //��
						nowmoji.c = NSka;
					else if (str[i] == 'i' or str[i] == 'I') //��
						nowmoji.c = NSki;
					else if (str[i] == 'u' or str[i] == 'U') //��
						nowmoji.c = NSku;
					else if (str[i] == 'e' or str[i] == 'E') //��
						nowmoji.c = NSke;
					else if (str[i] == 'o' or str[i] == 'O') //��
						nowmoji.c = NSko;
					else if (str[i] == 'y' or str[i] == 'Y') {
						i++;
						if (str[i] == 'a' or str[i] == 'A') //����
							nowmoji.c = NSkya;
						else if (str[i] == 'u' or str[i] == 'U') //����
							nowmoji.c = NSkyu;
						else if (str[i] == 'e' or str[i] == 'E') //����
							nowmoji.c = NSkye;
						else if (str[i] == 'o' or str[i] == 'O') //����
							nowmoji.c = NSkyo;
					}
					else if (str[i] == 'w' or str[i] == 'W') {
						i++;
						if (str[i] == 'a' or str[i] == 'A') //����
							nowmoji.c = NSkwa;
						else if (str[i] == 'i' or str[i] == 'I') //����
							nowmoji.c = NSkwi;
						else if (str[i] == 'e' or str[i] == 'E') //����
							nowmoji.c = NSkwe;
						else if (str[i] == 'o' or str[i] == 'O') //����
							nowmoji.c = NSkwo;
					}
				}
				else if (str[i] == 'g' or str[i] == 'G') {
					i++;
					if (str[i] == 'a' or str[i] == 'A')
						nowmoji.c = NSga;
					else if (str[i] == 'i' or str[i] == 'I')
						nowmoji.c = NSgi;
					else if (str[i] == 'u' or str[i] == 'U')
						nowmoji.c = NSgu;
					else if (str[i] == 'e' or str[i] == 'E')
						nowmoji.c = NSge;
					else if (str[i] == 'o' or str[i] == 'O')
						nowmoji.c = NSgo;
					else if (str[i] == 'y' or str[i] == 'Y') {
						i++;
						if (str[i] == 'a' or str[i] == 'A')
							nowmoji.c = NSgya;
						else if (str[i] == 'u' or str[i] == 'U')
							nowmoji.c = NSgyu;
						else if (str[i] == 'e' or str[i] == 'E')
							nowmoji.c = NSgye;
						else if (str[i] == 'o' or str[i] == 'O')
							nowmoji.c = NSgyo;
					}
					else if (str[i] == 'w' or str[i] == 'W') {
						i++;
						if (str[i] == 'a' or str[i] == 'A')
							nowmoji.c = NSgwa;
						else if (str[i] == 'i' or str[i] == 'I')
							nowmoji.c = NSgwi;
						else if (str[i] == 'e' or str[i] == 'E')
							nowmoji.c = NSgwe;
						else if (str[i] == 'o' or str[i] == 'O')
							nowmoji.c = NSgwo;
					}
				}
				else if (str[i] == 't' or str[i] == 'T') {
					i++;
					if (str[i] == 'a' or str[i] == 'A')
						nowmoji.c = NSta;
					else if (str[i] == 'i' or str[i] == 'I')
						nowmoji.c = NSti;
					else if (str[i] == 'u' or str[i] == 'U')
						nowmoji.c = NStu;
					else if (str[i] == 'e' or str[i] == 'E')
						nowmoji.c = NSte;
					else if (str[i] == 'o' or str[i] == 'O')
						nowmoji.c = NSto;
					else if (str[i] == 'y' or str[i] == 'Y') {
						i++;
						if (str[i] == 'a' or str[i] == 'A')
							nowmoji.c = NStya;
						else if (str[i] == 'u' or str[i] == 'U')
							nowmoji.c = NStyu;
						else if (str[i] == 'e' or str[i] == 'E')
							nowmoji.c = NStye;
						else if (str[i] == 'o' or str[i] == 'O')
							nowmoji.c = NStyo;
					}
					else if (str[i] == 'w' or str[i] == 'W') {
						i++;
						if (str[i] == 'a' or str[i] == 'A')
							nowmoji.c = NStwa;
						else if (str[i] == 'i' or str[i] == 'I')
							nowmoji.c = NStwi;
						else if (str[i] == 'e' or str[i] == 'E')
							nowmoji.c = NStwe;
						else if (str[i] == 'o' or str[i] == 'O')
							nowmoji.c = NStwo;
					}
				}
				else if (str[i] == 'd' or str[i] == 'D') {
					i++;
					if (str[i] == 'a' or str[i] == 'A')
						nowmoji.c = NSda;
					else if (str[i] == 'i' or str[i] == 'I')
						nowmoji.c = NSdi;
					else if (str[i] == 'u' or str[i] == 'U')
						nowmoji.c = NSdu;
					else if (str[i] == 'e' or str[i] == 'E')
						nowmoji.c = NSde;
					else if (str[i] == 'o' or str[i] == 'O')
						nowmoji.c = NSdo;
					else if (str[i] == 'y' or str[i] == 'Y') {
						i++;
						if (str[i] == 'a' or str[i] == 'A')
							nowmoji.c = NSdya;
						else if (str[i] == 'u' or str[i] == 'U')
							nowmoji.c = NSdyu;
						else if (str[i] == 'e' or str[i] == 'E')
							nowmoji.c = NSdye;
						else if (str[i] == 'o' or str[i] == 'O')
							nowmoji.c = NSdyo;
					}
					else if (str[i] == 'w' or str[i] == 'W') {
						i++;
						if (str[i] == 'a' or str[i] == 'A')
							nowmoji.c = NSdwa;
						else if (str[i] == 'i' or str[i] == 'I')
							nowmoji.c = NSdwi;
						else if (str[i] == 'e' or str[i] == 'E')
							nowmoji.c = NSdwe;
						else if (str[i] == 'o' or str[i] == 'O')
							nowmoji.c = NSdwo;
					}
				}
				else if (str[i] == 'p' or str[i] == 'P') {
					i++;
					if (str[i] == 'a' or str[i] == 'A')
						nowmoji.c = NSpa;
					else if (str[i] == 'i' or str[i] == 'I')
						nowmoji.c = NSpi;
					else if (str[i] == 'u' or str[i] == 'U')
						nowmoji.c = NSpu;
					else if (str[i] == 'e' or str[i] == 'E')
						nowmoji.c = NSpe;
					else if (str[i] == 'o' or str[i] == 'O')
						nowmoji.c = NSpo;
					else if (str[i] == 'y' or str[i] == 'Y') {
						i++;
						if (str[i] == 'a' or str[i] == 'A')
							nowmoji.c = NSpya;
						else if (str[i] == 'u' or str[i] == 'U')
							nowmoji.c = NSpyu;
						else if (str[i] == 'e' or str[i] == 'E')
							nowmoji.c = NSpye;
						else if (str[i] == 'o' or str[i] == 'O')
							nowmoji.c = NSpyo;
					}
					else if (str[i] == 'w' or str[i] == 'W') {
						i++;
						if (str[i] == 'a' or str[i] == 'A')
							nowmoji.c = NSpwa;
						else if (str[i] == 'i' or str[i] == 'I')
							nowmoji.c = NSpwi;
						else if (str[i] == 'e' or str[i] == 'E')
							nowmoji.c = NSpwe;
						else if (str[i] == 'o' or str[i] == 'O')
							nowmoji.c = NSpwo;
					}
				}
				else if (str[i] == 'b' or str[i] == 'B') {
					i++;
					if (str[i] == 'a' or str[i] == 'A')
						nowmoji.c = NSba;
					else if (str[i] == 'i' or str[i] == 'I')
						nowmoji.c = NSbi;
					else if (str[i] == 'u' or str[i] == 'U')
						nowmoji.c = NSbu;
					else if (str[i] == 'e' or str[i] == 'E')
						nowmoji.c = NSbe;
					else if (str[i] == 'o' or str[i] == 'O')
						nowmoji.c = NSbo;
					else if (str[i] == 'y' or str[i] == 'Y') {
						i++;
						if (str[i] == 'a' or str[i] == 'A')
							nowmoji.c = NSbya;
						else if (str[i] == 'u' or str[i] == 'U')
							nowmoji.c = NSbyu;
						else if (str[i] == 'e' or str[i] == 'E')
							nowmoji.c = NSbye;
						else if (str[i] == 'o' or str[i] == 'O')
							nowmoji.c = NSbyo;
					}
					else if (str[i] == 'w' or str[i] == 'W') {
						i++;
						if (str[i] == 'a' or str[i] == 'A')
							nowmoji.c = NSbwa;
						else if (str[i] == 'i' or str[i] == 'I')
							nowmoji.c = NSbwi;
						else if (str[i] == 'e' or str[i] == 'E')
							nowmoji.c = NSbwe;
						else if (str[i] == 'o' or str[i] == 'O')
							nowmoji.c = NSbwo;
					}
				}
				else if (str[i] == 's' or str[i] == 'S') {
					i++;
					if (str[i] == 'a' or str[i] == 'A')
						nowmoji.c = NSsa;
					else if (str[i] == 'i' or str[i] == 'I')
						nowmoji.c = NSsi;
					else if (str[i] == 'u' or str[i] == 'U')
						nowmoji.c = NSsu;
					else if (str[i] == 'e' or str[i] == 'E')
						nowmoji.c = NSse;
					else if (str[i] == 'o' or str[i] == 'O')
						nowmoji.c = NSso;
					else if (str[i] == 'y' or str[i] == 'Y') {
						i++;
						if (str[i] == 'a' or str[i] == 'A')
							nowmoji.c = NSsya;
						else if (str[i] == 'u' or str[i] == 'U')
							nowmoji.c = NSsyu;
						else if (str[i] == 'e' or str[i] == 'E')
							nowmoji.c = NSsye;
						else if (str[i] == 'o' or str[i] == 'O')
							nowmoji.c = NSsyo;
					}
					else if (str[i] == 'w' or str[i] == 'W') {
						i++;
						if (str[i] == 'a' or str[i] == 'A')
							nowmoji.c = NSswa;
						else if (str[i] == 'i' or str[i] == 'I')
							nowmoji.c = NSswi;
						else if (str[i] == 'e' or str[i] == 'E')
							nowmoji.c = NSswe;
						else if (str[i] == 'o' or str[i] == 'O')
							nowmoji.c = NSswo;
					}
				}
				else if (str[i] == 'z' or str[i] == 'Z') {
					i++;
					if (str[i] == 'a' or str[i] == 'A')
						nowmoji.c = NSza;
					else if (str[i] == 'i' or str[i] == 'I')
						nowmoji.c = NSzi;
					else if (str[i] == 'u' or str[i] == 'U')
						nowmoji.c = NSzu;
					else if (str[i] == 'e' or str[i] == 'E')
						nowmoji.c = NSze;
					else if (str[i] == 'o' or str[i] == 'O')
						nowmoji.c = NSzo;
					else if (str[i] == 'y' or str[i] == 'Y') {
						i++;
						if (str[i] == 'a' or str[i] == 'A')
							nowmoji.c = NSzya;
						else if (str[i] == 'u' or str[i] == 'U')
							nowmoji.c = NSzyu;
						else if (str[i] == 'e' or str[i] == 'E')
							nowmoji.c = NSzye;
						else if (str[i] == 'o' or str[i] == 'O')
							nowmoji.c = NSzyo;
					}
					else if (str[i] == 'w' or str[i] == 'W') {
						i++;
						if (str[i] == 'a' or str[i] == 'A')
							nowmoji.c = NSzwa;
						else if (str[i] == 'i' or str[i] == 'I')
							nowmoji.c = NSzwi;
						else if (str[i] == 'e' or str[i] == 'E')
							nowmoji.c = NSzwe;
						else if (str[i] == 'o' or str[i] == 'O')
							nowmoji.c = NSzwo;
					}
				}
				else if (str[i] == 'h' or str[i] == 'H') {
					i++;
					if (str[i] == 'a' or str[i] == 'A')
						nowmoji.c = NSha;
					else if (str[i] == 'i' or str[i] == 'I')
						nowmoji.c = NShi;
					else if (str[i] == 'u' or str[i] == 'U')
						nowmoji.c = NShu;
					else if (str[i] == 'e' or str[i] == 'E')
						nowmoji.c = NShe;
					else if (str[i] == 'o' or str[i] == 'O')
						nowmoji.c = NSho;
					else if (str[i] == 'y' or str[i] == 'Y') {
						i++;
						if (str[i] == 'a' or str[i] == 'A')
							nowmoji.c = NShya;
						else if (str[i] == 'u' or str[i] == 'U')
							nowmoji.c = NShyu;
						else if (str[i] == 'e' or str[i] == 'E')
							nowmoji.c = NShye;
						else if (str[i] == 'o' or str[i] == 'O')
							nowmoji.c = NShyo;
					}
					else if (str[i] == 'w' or str[i] == 'W') {
						i++;
						if (str[i] == 'a' or str[i] == 'A')
							nowmoji.c = NShwa;
						else if (str[i] == 'i' or str[i] == 'I')
							nowmoji.c = NShwi;
						else if (str[i] == 'e' or str[i] == 'E')
							nowmoji.c = NShwe;
						else if (str[i] == 'o' or str[i] == 'O')
							nowmoji.c = NShwo;
					}
				}
				else if (str[i] == 'n' or str[i] == 'N') {
					i++;
					if (str[i] == 'a' or str[i] == 'A')
						nowmoji.c = NSna;
					else if (str[i] == 'i' or str[i] == 'I')
						nowmoji.c = NSni;
					else if (str[i] == 'u' or str[i] == 'U')
						nowmoji.c = NSnu;
					else if (str[i] == 'e' or str[i] == 'E')
						nowmoji.c = NSne;
					else if (str[i] == 'o' or str[i] == 'O')
						nowmoji.c = NSno;
					else if (str[i] == 'y' or str[i] == 'Y') {
						i++;
						if (str[i] == 'a' or str[i] == 'A')
							nowmoji.c = NSnya;
						else if (str[i] == 'u' or str[i] == 'U')
							nowmoji.c = NSnyu;
						else if (str[i] == 'e' or str[i] == 'E')
							nowmoji.c = NSnye;
						else if (str[i] == 'o' or str[i] == 'O')
							nowmoji.c = NSnyo;
					}
					else if (str[i] == 'w' or str[i] == 'W') {
						i++;
						if (str[i] == 'a' or str[i] == 'A')
							nowmoji.c = NSnwa;
						else if (str[i] == 'i' or str[i] == 'I')
							nowmoji.c = NSnwi;
						else if (str[i] == 'e' or str[i] == 'E')
							nowmoji.c = NSnwe;
						else if (str[i] == 'o' or str[i] == 'O')
							nowmoji.c = NSnwo;
					}
					else if (str[i] == 'n' or str[i] == 'N')
						nowmoji.c = NSnn1;
				}
				else if (str[i] == 'm' or str[i] == 'M') {
					i++;
					if (str[i] == 'a' or str[i] == 'A')
						nowmoji.c = NSma;
					else if (str[i] == 'i' or str[i] == 'I')
						nowmoji.c = NSmi;
					else if (str[i] == 'u' or str[i] == 'U')
						nowmoji.c = NSmu;
					else if (str[i] == 'e' or str[i] == 'E')
						nowmoji.c = NSme;
					else if (str[i] == 'o' or str[i] == 'O')
						nowmoji.c = NSmo;
					else if (str[i] == 'y' or str[i] == 'Y') {
						i++;
						if (str[i] == 'a' or str[i] == 'A')
							nowmoji.c = NSmya;
						else if (str[i] == 'u' or str[i] == 'U')
							nowmoji.c = NSmyu;
						else if (str[i] == 'e' or str[i] == 'E')
							nowmoji.c = NSmye;
						else if (str[i] == 'o' or str[i] == 'O')
							nowmoji.c = NSmyo;
					}
					else if (str[i] == 'w' or str[i] == 'W') {
						i++;
						if (str[i] == 'a' or str[i] == 'A')
							nowmoji.c = NSmwa;
						else if (str[i] == 'i' or str[i] == 'I')
							nowmoji.c = NSmwi;
						else if (str[i] == 'e' or str[i] == 'E')
							nowmoji.c = NSmwe;
						else if (str[i] == 'o' or str[i] == 'O')
							nowmoji.c = NSmwo;
					}
				}
				else if (str[i] == 'r' or str[i] == 'R') {
					i++;
					if (str[i] == 'a' or str[i] == 'A')
						nowmoji.c = NSra;
					else if (str[i] == 'i' or str[i] == 'I')
						nowmoji.c = NSri;
					else if (str[i] == 'u' or str[i] == 'U')
						nowmoji.c = NSru;
					else if (str[i] == 'e' or str[i] == 'E')
						nowmoji.c = NSre;
					else if (str[i] == 'o' or str[i] == 'O')
						nowmoji.c = NSro;
					else if (str[i] == 'y' or str[i] == 'Y') {
						i++;
						if (str[i] == 'a' or str[i] == 'A')
							nowmoji.c = NSrya;
						else if (str[i] == 'u' or str[i] == 'U')
							nowmoji.c = NSryu;
						else if (str[i] == 'e' or str[i] == 'E')
							nowmoji.c = NSrye;
						else if (str[i] == 'o' or str[i] == 'O')
							nowmoji.c = NSryo;
					}
					else if (str[i] == 'w' or str[i] == 'W') {
						i++;
						if (str[i] == 'a' or str[i] == 'A')
							nowmoji.c = NSrwa;
						else if (str[i] == 'i' or str[i] == 'I')
							nowmoji.c = NSrwi;
						else if (str[i] == 'e' or str[i] == 'E')
							nowmoji.c = NSrwe;
						else if (str[i] == 'o' or str[i] == 'O')
							nowmoji.c = NSrwo;
					}
				}
				else if (str[i] == 'y' or str[i] == 'Y') {
					i++;
					if (str[i] == 'a' or str[i] == 'A')
						nowmoji.c = NSya;
					else if (str[i] == 'u' or str[i] == 'U')
						nowmoji.c = NSyu;
					else if (str[i] == 'e' or str[i] == 'E')
						nowmoji.c = NSye;
					else if (str[i] == 'o' or str[i] == 'O')
						nowmoji.c = NSyo;
				}
				else if (str[i] == 'w' or str[i] == 'W') {
					i++;
					if (str[i] == 'a' or str[i] == 'A')
						nowmoji.c = NSwa;
					else if (str[i] == 'i' or str[i] == 'I')
						nowmoji.c = NSwi;
					else if (str[i] == 'e' or str[i] == 'E')
						nowmoji.c = NSwe;
					else if (str[i] == 'o' or str[i] == 'O')
						nowmoji.c = NSwo;
				}

				nowmoji.time = alltime;
				nowmoji.ctime = ctime;
				nowmoji.pitch = pitch;
				out[n] = nowmoji;
				alltime += ctime;
				n++;i++;
			}
			//�L��
			else if (str[i] == ',') {
				//��_
				nowmoji.c = NSspc;
				nowmoji.time = alltime;
				nowmoji.ctime = ctime;
				nowmoji.pitch = pitch;
				out[n] = nowmoji;
				n++;alltime += ctime;
				i++;
			}
			else if(str[i] == '.'){
				//��Ǔ_
				nowmoji.c = NSspc;
				nowmoji.time = alltime;
				nowmoji.ctime = ctime * 2;
				nowmoji.pitch = pitch;
				out[n] = nowmoji;
				n++;alltime += ctime * 2;
				i++;
			}
			//�X�s�[�h�A�s�b�`�w��
			else if (str[i] == '<') {
				if (str[i + 1] == 'S' or str[i + 1] == 's') {
					nowmode = 1;
					ctime = 0;
					i += 2;
				}
				else if (str[i + 1] == 'P' or str[i + 1] == 'p') {
					if (str[i + 2] == 'u' or str[i + 2] == 'U') {
						pitch += 5;
						i += 4;
					}
					else if (str[i + 2] == 'd' or str[i + 2] == 'D') {
						pitch -= 5;
						i += 4;
					}
					else {
						nowmode = 2;
						pitch = 0;
						i += 2;
					}
				}
			}
			//�R�����g
			else if (str[i] == '(') {
				nowmode = 4;
			}
			//���̑�
			else {
				i++;
			}
		}
		//�X�s�[�h�̐����̏���
		else if (nowmode == 1) {
			if (str[i] == '>')
				nowmode = 0;
			else {
				if (str[i] >= '0' and str[i] <= '9') {
					ctime *= 10;
					ctime += str[i] - '0';
				}
				else {
					nowmode = 0;
				}
			}
			i++;
		}
		//�s�b�`�̕����̏���
		else if (nowmode == 2) {
			if (str[i] == '+') {
				nowmodepitchpm = 1;
				nowmode = 3;
				i++;
			}
			else if (str[i] == '-') {
				nowmodepitchpm = -1;
				nowmode = 3;
				i++;
			}
			else {
				nowmodepitchpm = 1;
				nowmode = 3;
			}
		}
		//�s�b�`�̐����̏���
		else if (nowmode == 3) {
			if (str[i] == '>') {
				pitch *= nowmodepitchpm;
				nowmode = 0;
			}
			else {
				if (str[i] >= '0' and str[i] <= '9') {
					pitch *= 10;
					pitch += str[i] - '0';
				}
				else {
					nowmode = 0;
				}
			}
			i++;
		}
		//�R�����g
		else if (nowmode == 4) {
			if (str[i] == ')')
				nowmode = 0;
			i++;
		}
	}

	return out;
}

//���}�����ŏ����ꂽ�}���`�o�C�g����������}�R�[�h�ɃG���R�[�h
NSSTRINGDATA nsc::nsromajiencode(const char* str) {

	size_t stringlen = strlen(str) + 1;
	unsigned char* text = new unsigned char[stringlen];
	for (size_t i = 0; i < stringlen;i++)text[i] = 0;

	//char�^�̕������unsigned char�^�ɕϊ�
	for (size_t i = 0; i < stringlen;i++)
		text[i] = (unsigned char)((int)str[i] & 0xff);

	return nsromajiencode(text);
}

//NSCHARDATA�^�̕ϐ����쐬
NSCHARDATA nsc::nscreateCharData(uint32_t time, uint16_t ctime, NSCHAR c, int16_t pitch) {
	NSCHARDATA out = {};
	out.c = c;out.ctime = ctime;out.pitch = pitch;out.time = time;
	return out;
}

//NSSTRINGDATA�^�̕ϐ����R�s�[
void nsc::nsstrcpy(NSSTRINGDATA destination, const NSSTRINGDATA source) {
	int i = 0;
	while (source[i].c != 0) {
		destination[i].c = source[i].c;
		destination[i].ctime = source[i].ctime;
		destination[i].pitch = source[i].pitch;
		destination[i].time = source[i].time;
		i++;
	}
}

//NSSTRINGDATA�^�̕��������擾
size_t nsc::nsstrlen(NSSTRINGDATA str) {
	size_t size = 0;
	while (str[size].c != 0)
		size++;
	return size;
}

//NSSTRING�^�̕��������擾
size_t nsc::nsstrlen(NSSTRING str) {
	size_t size = 0;
	while (str[size] != 0)
		size++;
	return size;
}

//const unsigned char�^�̕��������擾
size_t nsc::nsstrlen(const unsigned char* str) {
	size_t size = 0;
	while (str[size] != 0)
		size++;
	return size;
}

//���}�R�[�h�𕽉����ɃG���R�[�h
const char* nsc::nschardecode(NSCHAR c) {
	switch (c) {
		// --- 0x00 ---
	case NSNUL:
		return 0;
	case NSa:
		return "��";
	case NSi:
		return "��";
	case NSya:
		return "��";
	case NSyu:
		return "��";
	case NSye:
		return "�]";
	case NSyo:
		return "��";
	case NSu:
		return "��";
	case NSwa:
		return "��";
	case NSwi:
		return "��";
	case NSwe:
		return "��";
	case NSwo:
		return "��";
	case NSe:
		return "��";
	case NSo:
		return "��";
	case NS_0e:
		return "0e";
	case NS_0f:
		return "0f";

		// --- 0x10 ---
	case NSk:
		return "k";
	case NSka:
		return "��";
	case NSki:
		return "��";
	case NSkya:
		return "����";
	case NSkyu:
		return "����";
	case NSkye:
		return "����";
	case NSkyo:
		return "����";
	case NSku:
		return "��";
	case NSkwa:
		return "����";
	case NSkwi:
		return "����";
	case NSkwe:
		return "����";
	case NSkwo:
		return "����";
	case NSke:
		return "��";
	case NSko:
		return "��";
	case NS_1e:
		return "��";
	case NS_1f:
		return "��";

		// --- 0x20 ---
	case NSg:
		return "g";
	case NSga:
		return "��";
	case NSgi:
		return "��";
	case NSgya:
		return "����";
	case NSgyu:
		return "����";
	case NSgye:
		return "����";
	case NSgyo:
		return "����";
	case NSgu:
		return "��";
	case NSgwa:
		return "����";
	case NSgwi:
		return "����";
	case NSgwe:
		return "����";
	case NSgwo:
		return "����";
	case NSge:
		return "��";
	case NSgo:
		return "��";
	case NS_2e:
		return "2e";
	case NS_2f:
		return "2f";

		// --- 0x30 ---
	case NSt:
		return "t";
	case NSta:
		return "��";
	case NSti:
		return "��";
	case NStya:
		return "����";
	case NStyu:
		return "����";
	case NStye:
		return "����";
	case NStyo:
		return "����";
	case NStu:
		return "��";
	case NStwa:
		return "��";
	case NStwi:
		return "��";
	case NStwe:
		return "��";
	case NStwo:
		return "��";
	case NSte:
		return "��";
	case NSto:
		return "��";
	case NS_3e:
		return "3e";
	case NS_3f:
		return "3f";

		// --- 0x40 ---
	case NSd:
		return "d";
	case NSda:
		return "��";
	case NSdi:
		return "��";
	case NSdya:
		return "����";
	case NSdyu:
		return "����";
	case NSdye:
		return "����";
	case NSdyo:
		return "����";
	case NSdu:
		return "��";
	case NSdwa:
		return "�Â�";
	case NSdwi:
		return "�Â�";
	case NSdwe:
		return "�Â�";
	case NSdwo:
		return "�Â�";
	case NSde:
		return "��";
	case NSdo:
		return "��";
	case NS_4e:
		return "4e";
	case NS_4f:
		return "4f";

		// --- 0x50 ---
	case NSp:
		return "p";
	case NSpa:
		return "��";
	case NSpi:
		return "��";
	case NSpya:
		return "�҂�";
	case NSpyu:
		return "�҂�";
	case NSpye:
		return "�҂�";
	case NSpyo:
		return "�҂�";
	case NSpu:
		return "��";
	case NSpwa:
		return "�Ղ�";
	case NSpwi:
		return "�Ղ�";
	case NSpwe:
		return "�Ղ�";
	case NSpwo:
		return "�Ղ�";
	case NSpe:
		return "��";
	case NSpo:
		return "��";
	case NS_5e:
		return "5e";
	case NS_5f:
		return "5f";

		// --- 0x60 ---
	case NSb:
		return "b";
	case NSba:
		return "��";
	case NSbi:
		return "��";
	case NSbya:
		return "�т�";
	case NSbyu:
		return "�т�";
	case NSbye:
		return "�т�";
	case NSbyo:
		return "�т�";
	case NSbu:
		return "��";
	case NSbwa:
		return "�Ԃ�";
	case NSbwi:
		return "�Ԃ�";
	case NSbwe:
		return "�Ԃ�";
	case NSbwo:
		return "�Ԃ�";
	case NSbe:
		return "��";
	case NSbo:
		return "��";
	case NS_6e:
		return "6e";
	case NS_6f:
		return "6f";

		// --- 0x70 ---
	case NSs:
		return "s";
	case NSsa:
		return "��";
	case NSsi:
		return "��";
	case NSsya:
		return "����";
	case NSsyu:
		return "����";
	case NSsye:
		return "����";
	case NSsyo:
		return "����";
	case NSsu:
		return "��";
	case NSswa:
		return "����";
	case NSswi:
		return "����";
	case NSswe:
		return "����";
	case NSswo:
		return "����";
	case NSse:
		return "��";
	case NSso:
		return "��";
	case NS_7e:
		return "7e";
	case NS_7f:
		return "7f";

		// --- 0x80 ---
	case NSz:
		return "z";
	case NSza:
		return "��";
	case NSzi:
		return "��";
	case NSzya:
		return "����";
	case NSzyu:
		return "����";
	case NSzye:
		return "����";
	case NSzyo:
		return "����";
	case NSzu:
		return "��";
	case NSzwa:
		return "����";
	case NSzwi:
		return "����";
	case NSzwe:
		return "����";
	case NSzwo:
		return "����";
	case NSze:
		return "��";
	case NSzo:
		return "��";
	case NS_8e:
		return "8e";
	case NS_8f:
		return "8f";

		// --- 0x90 ---
	case NSh:
		return "h";
	case NSha:
		return "��";
	case NShi:
		return "��";
	case NShya:
		return "�Ђ�";
	case NShyu:
		return "�Ђ�";
	case NShye:
		return "�Ђ�";
	case NShyo:
		return "�Ђ�";
	case NShu:
		return "��";
	case NShwa:
		return "�ӂ�";
	case NShwi:
		return "�ӂ�";
	case NShwe:
		return "�ӂ�";
	case NShwo:
		return "�ӂ�";
	case NShe:
		return "��";
	case NSho:
		return "��";
	case NS_9e:
		return "9e";
	case NS_9f:
		return "9f";

		// --- 0xa0 ---
	case NSn:
		return "n";
	case NSna:
		return "��";
	case NSni:
		return "��";
	case NSnya:
		return "�ɂ�";
	case NSnyu:
		return "�ɂ�";
	case NSnye:
		return "�ɂ�";
	case NSnyo:
		return "�ɂ�";
	case NSnu:
		return "��";
	case NSnwa:
		return "�ʂ�";
	case NSnwi:
		return "�ʂ�";
	case NSnwe:
		return "�ʂ�";
	case NSnwo:
		return "�ʂ�";
	case NSne:
		return "��";
	case NSno:
		return "��";
	case NS_ae:
		return "ae";
	case NS_af:
		return "ao";

		// --- 0xb0 ---
	case NSm:
		return "m";
	case NSma:
		return "��";
	case NSmi:
		return "��";
	case NSmya:
		return "�݂�";
	case NSmyu:
		return "�݂�";
	case NSmye:
		return "�݂�";
	case NSmyo:
		return "�݂�";
	case NSmu:
		return "��";
	case NSmwa:
		return "�ނ�";
	case NSmwi:
		return "�ނ�";
	case NSmwe:
		return "�ނ�";
	case NSmwo:
		return "�ނ�";
	case NSme:
		return "��";
	case NSmo:
		return "��";
	case NS_be:
		return "be";
	case NS_bf:
		return "bf";

		// --- 0xc0 ---
	case NSr:
		return "r";
	case NSra:
		return "��";
	case NSri:
		return "��";
	case NSrya:
		return "���";
	case NSryu:
		return "���";
	case NSrye:
		return "�肥";
	case NSryo:
		return "���";
	case NSru:
		return "��";
	case NSrwa:
		return "�邟";
	case NSrwi:
		return "�邡";
	case NSrwe:
		return "�邥";
	case NSrwo:
		return "�邧";
	case NSre:
		return "��";
	case NSro:
		return "��";
	case NS_ce:
		return "ce";
	case NS_cf:
		return "cf";

		// --- 0xd0 ---
	case NSnn:
		return "nn";
	case NSnn1:
		return "��";
	case NSnn2:
		return "��";
	case NS_d3:
		return "d3";
	case NS_d4:
		return "d4";
	case NS_d5:
		return "d5";
	case NS_d6:
		return "d6";
	case NS_d7:
		return "d7";
	case NS_d8:
		return "d8";
	case NS_d9:
		return "d9";
	case NS_da:
		return "da";
	case NS_db:
		return "db";
	case NS_dc:
		return "dc";
	case NS_dd:
		return "dd";
	case NS_de:
		return "de";
	case NS_df:
		return "df";

		// --- 0xe0 ---
	case NS_e0:
		return "e0";
	case NSspc:
		return "��";
	case NSvls:
		return "��";
	case NS_e3:
		return "e3";
	case NS_e4:
		return "e4";
	case NS_e5:
		return "e5";
	case NS_e6:
		return "e6";
	case NS_e7:
		return "e7";
	case NS_e8:
		return "e8";
	case NS_e9:
		return "e9";
	case NS_ea:
		return "ea";
	case NS_eb:
		return "eb";
	case NS_ec:
		return "ec";
	case NS_ed:
		return "ed";
	case NS_ee:
		return "ee";
	case NS_ef:
		return "ef";

		// --- 0xf0 ---
	case NS_f0:
		return "f0";
	case NSp1:
		return "�X1";
	case NSp2:
		return "�X2";
	case NSp3:
		return "�X3";
	case NSp4:
		return "�X4";
	case NStt:
		return "��";
	case NS_f6:
		return "f6";
	case NS_f7:
		return "f7";
	case NS_f8:
		return "f8";
	case NS_f9:
		return "f9";
	case NS_fa:
		return "fa";
	case NS_fb:
		return "fb";
	case NS_fc:
		return "fc";
	case NS_fd:
		return "fd";
	case NS_fe:
		return "fe";
	case NS_ff:
		return "ff";

	default:
		return 0;
	}
	return 0;
}

//���}�R�[�h�̕�������}���`�o�C�g������Ƀf�R�[�h
const char* nsc::nsstrdecode(NSSTRINGDATA str) {
	NSSTRING out = new NSCHAR[nsstrlen(str) + 1];
	for (size_t i = 0;i < nsstrlen(str) + 1;i++)
		out[i] = NSNUL;

	for (size_t i = 0;i < nsstrlen(str);i++)
		out[i] = str[i].c;

	return nsstrdecode(out);
}

//���}�R�[�h�̕�������}���`�o�C�g������Ƀf�R�[�h
const char* nsc::nsstrdecode(NSSTRING str) {
	char* out = new char[nsstrlen(str) + 1];
	for (size_t i = 0;i < nsstrlen(str) + 1;i++)
		out[i] = NSNUL;

	for (size_t i = 0;i < nsstrlen(str);i++)
		strcat(out, nschardecode(str[i]));

	return out;
}


//  +-------------------------------------------------------------------------------------------+
//  |   ���}������^�̏��X��p�̃N���X                                                          |
//  |   string�^�݂����Ɏg����恙                                                              |
//  +-------------------------------------------------------------------------------------------+

//��̉��}������^���쐬
NSString::NSString() {
	n_capacity = n_size = n_wsize = n_wcapacity = 0;
	n_string = new NSCHARDATA[n_size + 1];
	n_string[0] = nsc::nscreateCharData(0, 0, 0, 0);
}

//�}���`�o�C�g�����񂩂特�}������^���쐬
NSString::NSString(const char* c) {
	bool isJis = false;
	const unsigned char* work = (const unsigned char*)c;
	while (*work != 0) if (*(work++) == 0x82) {
		isJis = true;break;
	}
	if (isJis)
		n_string = nsc::nsstrencode(c);
	else
		n_string = nsc::nsromajiencode(c);
	n_capacity = (strlen(c) + 1) * sizeof(NSCHARDATA);
	n_wsize = n_wcapacity = nsc::nsstrlen(n_string);
	n_size = n_wsize * sizeof(NSCHARDATA);
}

//���}�R�[�h�^���特�}������^���쐬
NSString::NSString(const NSSTRING c) {
	size_t size = nsc::nsstrlen(c);
	NSSTRINGDATA str = new NSCHARDATA[size];
	int32_t alltime = NSDATAINIT_T;
	for (size_t i = 0; i < size;i++) {
		str[i].c = c[i];
		str[i].ctime = NSDATAINIT_T;
		str[i].time = alltime;
		str[i].pitch = NSDATAINIT_P;
		alltime += NSDATAINIT_T;
	}
	n_string = str;
	n_capacity = size * sizeof(NSCHARDATA);
	n_wsize = n_wcapacity = nsc::nsstrlen(n_string);
	n_size = n_wsize * sizeof(NSCHARDATA);
}

//���}�f�[�^�^���特�}������^���쐬
NSString::NSString(const NSSTRINGDATA c) {
	size_t size = nsc::nsstrlen(c);
	n_string = c;
	n_capacity = size * sizeof(NSCHARDATA);
	n_wsize = n_wcapacity = nsc::nsstrlen(n_string);
	n_size = n_wsize * sizeof(NSCHARDATA);
}

//���}������^�̕���
NSString::NSString(const NSString& s) {
	n_capacity = s.n_capacity;
	n_wcapacity = s.n_wcapacity;
	n_size = s.n_size;
	n_wsize = s.n_wsize;
	n_string = new NSCHARDATA[n_size + 1];
	nsc::nsstrcpy(n_string, s.n_string);
}


NSString::~NSString() {
}

//  ----���Z�q----

NSCHARDATA& NSString::operator [](const size_t n) {
	return n_string[n];
}

const NSCHARDATA& NSString::operator [](const size_t n) const {
	return n_string[n];
}

NSString NSString::operator +(const char* c) {
	NSString retval(*this);
	retval += c;
	return retval;
}

NSString NSString::operator +(const NSString& str) {
	NSString retval(*this);
	retval += str;
	return retval;
}

NSString& NSString::operator +=(const char* c) {
	NSString str(c);
	*this += str;
	return *this;
}

NSString& NSString::operator +=(const NSString& str) {
	size_t new_wsize = this->n_wsize + str.n_wsize;
	if (this->n_wcapacity < new_wsize) {
		while (this->n_wcapacity < new_wsize) {
			this->n_wcapacity *= 2;
		}
		NSSTRINGDATA new_n_string = new NSCHARDATA[this->n_wcapacity + 1];
		memcpy(new_n_string, this->n_string, this->n_size);
		this->n_string = new_n_string;
	}
	nsc::nsstrcpy(this->n_string + this->n_size, str.n_string);
	this->n_size = this->n_size + str.n_size;
	this->n_wsize = new_wsize;
	return *this;
}

//  ----�����o�֐�----

//�����������Ă��邩
bool NSString::empty() const {
	return (n_wsize == 0);
}

//�T�C�Y(�o�C�g��)
size_t NSString::size() const {
	return n_size;
}

//������
size_t NSString::length() const {
	return n_wsize;
}

//�ő�̕�����
size_t NSString::capacity() const {
	return n_capacity;
}

//���߂̕���
const NSCHARDATA& NSString::front() const {
	return n_string[0];
}

//����̕���
const NSCHARDATA& NSString::back() const {
	return n_string[n_wsize - 1];
}

//���߂̕���
NSCHARDATA& NSString::front() {
	return n_string[0];
}

//�I���̕���
NSCHARDATA& NSString::back() {
	return n_string[n_wsize - 1];
}

//char*������ɕϊ�
const char* NSString::c_str() const {
	return nsc::nsstrdecode(this->n_string);
}

//0.01�b�P�ʂł̑S�̂̎���
size_t NSString::alltime() const {
	size_t size = 0;
	for (size_t i = 0;i < n_wsize;i++)
		size += n_string[i].ctime;
	return size;
}





//	���}�덆�@ ���C���v���O����
//	
//	���}�덆�@�̃��C���v���O�����ł��B
// 
//	Copyright (c) 2021 MucchoSP

//=====���쐬=====

//���X�g���獇�����ꂽsin�g�𐶐�
int mainMakeVoiseF::makeSinWave(int num, std::vector<nsfloat> Hz, std::vector<nsfloat> s, std::vector<nsfloat>& out, nsfloat a, bool doformant) {
	//num...Hz��s�̒��� Hz...�{�� s...�e�{���̑傫�� out...�o�͔z�� size...�o�͔z��̃T�C�Y

	nsfloat sinha = 0.0;
	int* canUseHz;
	int num2 = 0;
	std::vector<nsfloat> output1(out.size(), 0.0);
	std::vector<nsfloat> output2(out.size(), 0.0);
	std::vector<nsfloat> output3(out.size(), 0.0);

	//���̑傫����0�łȂ��ꍇ�̂ݒʂ��B
	for (int i = 0;i < num;i++)
		if (s[i])
			num2++;
	canUseHz = new int[num2 + 1];
	size_t work = 0;
	for (int i = 0;i < num;i++)
		if (s[i]) {
			canUseHz[work] = i;
			work++;
		}

	nsfloat alls = 0;
	for (int i = 0;i < num;i++)alls += s[i];
	alls *= 2;

	if (doformant) {
		//sin�g�̍���
		for (size_t i = 0;i < out.size();i++) {
			for (int j = 0;j < num2;j++) {
				if (formants[2] > out.size())
					sinha = sin(((nsfloat)i + a) * 2.0 * (nsfloat)PI / ((nsfloat)SMPL / Hz[canUseHz[j]]));						//j�̎��g����i�̎���sin�g�̒l���v�Z����B
				else
					sinha = cos(((nsfloat)i + a) * 2.0 * (nsfloat)PI / ((nsfloat)SMPL / Hz[canUseHz[j]]));						//j�̎��g����i�̎���cos�g�̒l���v�Z����B
				output1[i] = output1[i] + sinha * s[canUseHz[j]];															//sinha���A���ꂼ��̑傫���ł������킹�đ����B
			}
			output1[i] /= alls;																								//���ω����ďo�͂���B
		}

		//�t�B���^�[�̎��(�m�b�`�t�B���^�[)
		//1.�m�b�`�t�B���^�[����	2.���ׂĂɃm�b�`�t�B���^�[��K�p	3.������x����������΃m�b�`�t�B���^�[��K�p
		switch (3) {
		case 1:
			hipassFilter(output1, output2, SMPL, formants[0], 0.707);															//�n�C�p�X�t�B���^�[
			lowpassFilter(output2, out, SMPL, formants[3], 1.0);																//���[�p�X�t�B���^�[
			break;
		case 2:
			hipassFilter(output1, output2, SMPL, formants[0], 0.707);															//�n�C�p�X�t�B���^�[
			lowpassFilter(output2, output3, SMPL, formants[3], 1.0);															//���[�p�X�t�B���^�[
			for (int i = 0; i < 3;i++)
				notchpassFilter(output3, out, SMPL, (formants[i] + formants[i + 1]) / 3.0, formants[i + 1] / formants[i] / 4.0);	//�m�b�`�p�X�t�B���^�[
			break;
		default:

			hipassFilter(output1, output2, SMPL, formants[0], 0.707);															//�n�C�p�X�t�B���^�[
			lowpassFilter(output2, output3, SMPL, formants[3], 1.0);															//���[�p�X�t�B���^�[

			for (int i = 0; i < 3;i++) {
				if (formants[i] * 2 < formants[i + 1])
					notchpassFilter(output3, out, SMPL, (formants[i] + formants[i + 1]) / 3.0, formants[i + 1] / formants[i] / 4.0);	//�m�b�`�p�X�t�B���^�[
			}
		}
	}
	else {
		//sin�g�̍���
		for (size_t i = 0;i < out.size();i++) {
			for (int j = 0;j < num2;j++) {
				sinha = sin(((nsfloat)i + a) * 2.0 * (nsfloat)PI / ((nsfloat)SMPL / Hz[canUseHz[j]]));							//j�̎��g����i�̎���sin�g�̒l���v�Z����B
				output1[i] = output1[i] + sinha * s[canUseHz[j]];															//sinha���A���ꂼ��̑傫���ł������킹�đ����B
			}
			output1[i] /= alls;																								//���ω����ďo�͂���B
		}
		hipassFilter(output1, output2, SMPL, Hz[0], 0.707);															//�n�C�p�X�t�B���^�[
		lowpassFilter(output2, out, SMPL, Hz[num - 1], 1.0);																//���[�p�X�t�B���^�[
	}

	return 0;
}

//�P����sin�g�𐶐�
int mainMakeVoiseF::makeSinha(nsfloat Hz, nsfloat s, std::vector<nsfloat>& out) {

	nsfloat sinha;
	nsfloat t = SMPL / Hz;
	nsfloat hr = 1 / t;		//�ω���

	for (int i = 0; i < out.size(); i++) {
		sinha = sin(hr * i * 2 * PI);
		out[i] = sinha * s;
	}

	return 0;
}

//����̎��Ԃ̎��g�����擾
nsfloat mainMakeVoiseF::makeMomentSinWave(int num, std::vector<nsfloat> Hz, std::vector<nsfloat> s, int gets) {

	int ho0 = SMPL / 2;//(int)(4.0 / (nsfloat)Hz[0] * SMPL);
	std::vector<nsfloat> out(ho0, 0.0);

	makeSinWave(num, Hz, s, out, ho0);

	nsfloat ret = out[gets % ho0];

	return ret;
}

//��{�{���ݒ�
int mainMakeVoiseF::makeHarmonicOvertone(nsfloat bsf) {

	hosize = (int)(MAXFREQ / bsf);
	harmonicOvertones.resize(hosize);
	harmonictoneFilters.resize(hosize);
	for (int i = 1; i <= hosize;i++)
		harmonicOvertones[i - 1] = bsf * i;		//�{���쐬
	bf = bsf;
	return 0;
}

//�t�H���}���g���X�g�Ɏ��g����ݒ�
int mainMakeVoiseF::setFormants(nsfloat F1, nsfloat F2, nsfloat F3, nsfloat F4) {

	formants[0] = F1;
	formants[1] = F2;
	formants[2] = F3;
	formants[3] = F4;

	return 0;
}

//=====����������=====

//��{�{���̑傫������������
int mainMakeVoiseF::makeFilter() {

	nsfloat a = 0.0, b = 0.0;
	int c = 0;

	//�t�B���^�[������
	for (int i = 0;i < hosize;i++)
		harmonictoneFilters[i] = 0.0;

	//�t�B���^�[�쐬
	for (int j = 0;j < hosize;j++) {
		for (int i = 0;i < 4;i++) {
			b = (nsfloat)harmonicOvertones[j] - (nsfloat)formants[i];														//���̎��g���ƃt�H���}���g�̋������v�Z
			a = (-1.0 * sqrt(pow(POW2(b * (1.0 / (nsfloat)FILTERWIDTH)), (1.0 / 3.0))) + 1.0);							//�T�C�N���C�h�֐������p�����t�B���^�[�̌v�Z��
			if (!isfinite(a) || (a < 0))
				continue;																								//�����̏ꍇ�A��΂��B
			harmonictoneFilters[j] = harmonictoneFilters[j] + a;														//�o�����l�𑫂��B
		}
		if (formants[0] < harmonicOvertones[j])																			//�t�H���}���g1��菬�������ǂ���
			harmonictoneFilters[j] = harmonictoneFilters[j] / 4.0 * (1.0 / ((nsfloat)j + formants[0] / harmonicOvertones[0] + 1.0)) * 12;	//�t�B���^�[�̕��ϒl���o���Aj�̔����̌`�Ńt�B���^�[�������A�\��{����B
		else
			harmonictoneFilters[j] = harmonictoneFilters[j] / 4.0 * (1.0 / ((nsfloat)-j + formants[0] / harmonicOvertones[0] + 1.0)) * 12;	//�t�B���^�[�̕��ϒl���o���A-j�̔����̌`�Ńt�B���^�[�������A�\��{����B
	}

	//���̌���
	if (softness) {
		for (int i = 0;i < hosize;i++) {
			nsfloat sn = log(softness / harmonicOvertones[i]) / log(softness / bf);
			harmonictoneFilters[i] = harmonictoneFilters[i] * sn;
		}
	}

	//�t�B���^�[�̃t�B���^�[
	for (int i = 0;i < hosize;i++) {
		if (harmonictoneFilters[i] < 0.01)
			harmonictoneFilters[i] = 0;																					//0.01�ȉ��̏����ȉ��͎�菜���B
		else {
			//harmonictoneFilters[i] *= harmonictoneFilters[i] * 2;														//�t�B���^�[�̍����L����B
			c = (int)(harmonictoneFilters[i] * 100);harmonictoneFilters[i] = (nsfloat)c / 100.0;							//�t�B���^�[�̒l�������_��O�ʂŐ؂�̂Ă�B
		}
	}



	return 0;
}

//�N���X���̃p�����[�^����sin�g������
int mainMakeVoiseF::makeSinWaveFromClass(std::vector<nsfloat>& out, nsfloat a) {
	/*�N���X�̒l���琺���쐬
	* out	...�o�͔z��
	* size	...out�̑傫��
	* a		...���߂̊p�x
	*/
	makeFilter();

	makeSinWave(hosize, harmonicOvertones, harmonictoneFilters, out, a);

	return 0;
}

//�N���X���̃p�����[�^�������̎��Ԃ̎��g�����擾
nsfloat mainMakeVoiseF::makeMomentSinWaveFromClass(int t) {
	/*�N���X�̒l���琺���쐬
	* out	...�o�͔z��
	* size	...out�̑傫��
	* a		...���߂̊p�x
	*/
	makeFilter();

	return makeMomentSinWave(hosize, harmonicOvertones, harmonictoneFilters, t % SMPL);
}

//���݂�mainMakeVoiseF.cpp�̏�Ԃ��擾����B
int mainMakeVoiseF::getstate(int state) {

	if (state == 0) {
		if (formants.size())
			return 1;
		else
			return 0;
	}
	else if (state == 1) {

	}

	return 0;
}

//softness�ϐ���ύX
int mainMakeVoiseF::setSoftness(nsfloat sn) {
	softness = sn;
	return 0;
}


nsfloat mainMakeVoiseF::mostMax(std::vector<nsfloat> list) {

	nsfloat a = 0.0;

	for (nsfloat now : list)
		a = MAX(a, now);

	return a;
}

int mainMakeVoiseF::hipassFilter(std::vector<nsfloat> input, std::vector<nsfloat>& out, nsfloat samplerate, nsfloat freq, nsfloat q) {

	// ���ꂼ��̕ϐ��͉��L�̂Ƃ���Ƃ���
	// float samplerate �c �T���v�����O���g��
	// float freq �c �J�b�g�I�t���g��
	// float q    �c �t�B���^��Q�l
	nsfloat omega = 2.0f * 3.14159265f * freq / samplerate;
	nsfloat alpha = sin(omega) / (2.0f * q);

	nsfloat a0 = 1.0f + alpha;
	nsfloat a1 = -2.0f * cos(omega);
	nsfloat a2 = 1.0f - alpha;
	nsfloat b0 = (1.0f + cos(omega)) / 2.0f;
	nsfloat b1 = -(1.0f + cos(omega));
	nsfloat b2 = (1.0f + cos(omega)) / 2.0f;

	// ���ꂼ��̕ϐ��͉��L�̂Ƃ���Ƃ���
	// �@float input[]  �c���͐M���̊i�[���ꂽ�o�b�t�@�B
	// �@flaot output[] �c�t�B���^���������l�������o���o�͐M���̃o�b�t�@�B
	// �@int   size     �c���͐M���E�o�͐M���̃o�b�t�@�̃T�C�Y�B
	// �@float in1, in2, out1, out2  �c�t�B���^�v�Z�p�̃o�b�t�@�ϐ��B�����l��0�B
	// �@float a0, a1, a2, b0, b1, b2 �c�t�B���^�̌W���B �ʓr�Z�o����B

	nsfloat in1 = 0.0, in2 = 0.0, out1 = 0.0, out2 = 0.0;
	for (size_t i = 0; i < out.size(); i++)
	{
		// ���͐M���Ƀt�B���^��K�p���A�o�͐M���Ƃ��ď����o���B
		out[i] = b0 / a0 * input[i] + b1 / a0 * in1 + b2 / a0 * in2
			- a1 / a0 * out1 - a2 / a0 * out2;

		in2 = in1;		// 2�O�̓��͐M�����X�V
		in1 = input[i];	// 1�O�̓��͐M�����X�V

		out2 = out1;	// 2�O�̏o�͐M�����X�V
		out1 = out[i];	// 1�O�̏o�͐M�����X�V
	}

	return 0;
}

int mainMakeVoiseF::lowpassFilter(std::vector<nsfloat> input, std::vector<nsfloat>& out, nsfloat samplerate, nsfloat freq, nsfloat q)
{
	// ���ꂼ��̕ϐ��͉��L�̂Ƃ���Ƃ���
	// float samplerate �c �T���v�����O���g��
	// float freq �c �J�b�g�I�t���g��
	// float q    �c �t�B���^��Q�l
	nsfloat omega = 2.0f * 3.14159265f * freq / samplerate;
	nsfloat alpha = sin(omega) / (2.0f * q);

	nsfloat a0 = 1.0f + alpha;
	nsfloat a1 = -2.0f * cos(omega);
	nsfloat a2 = 1.0f - alpha;
	nsfloat b0 = (1.0f - cos(omega)) / 2.0f;
	nsfloat b1 = 1.0f - cos(omega);
	nsfloat b2 = (1.0f - cos(omega)) / 2.0f;

	// ���ꂼ��̕ϐ��͉��L�̂Ƃ���Ƃ���
	// �@float input[]  �c���͐M���̊i�[���ꂽ�o�b�t�@�B
	// �@flaot output[] �c�t�B���^���������l�������o���o�͐M���̃o�b�t�@�B
	// �@int   size     �c���͐M���E�o�͐M���̃o�b�t�@�̃T�C�Y�B
	// �@float in1, in2, out1, out2  �c�t�B���^�v�Z�p�̃o�b�t�@�ϐ��B�����l��0�B
	// �@float a0, a1, a2, b0, b1, b2 �c�t�B���^�̌W���B �ʓr�Z�o����B

	nsfloat in1 = 0.0, in2 = 0.0, out1 = 0.0, out2 = 0.0;
	for (size_t i = 0; i < out.size(); i++)
	{
		// ���͐M���Ƀt�B���^��K�p���A�o�͐M���Ƃ��ď����o���B
		out[i] = b0 / a0 * input[i] + b1 / a0 * in1 + b2 / a0 * in2
			- a1 / a0 * out1 - a2 / a0 * out2;

		in2 = in1;		// 2�O�̓��͐M�����X�V
		in1 = input[i];	// 1�O�̓��͐M�����X�V

		out2 = out1;	// 2�O�̏o�͐M�����X�V
		out1 = out[i];	// 1�O�̏o�͐M�����X�V
	}

	return 0;
}

int mainMakeVoiseF::notchpassFilter(std::vector<nsfloat> input, std::vector<nsfloat>& out, nsfloat samplerate, nsfloat freq, nsfloat bw)
{
	// ���ꂼ��̕ϐ��͉��L�̂Ƃ���Ƃ���
	// float samplerate �c �T���v�����O���g��
	//float freq �c �J�b�g�I�t���g��
	// float bw   �c �ш敝
	nsfloat omega = 2.0f * 3.14159265f * freq / samplerate;
	nsfloat alpha = sin(omega) * sinh(log(2.0f) / 2.0 * bw * omega / sin(omega));

	nsfloat a0 = 1.0f + alpha;
	nsfloat a1 = -2.0f * cos(omega);
	nsfloat a2 = 1.0f - alpha;
	nsfloat b0 = 1.0f;
	nsfloat b1 = -2.0f * cos(omega);
	nsfloat b2 = 1.0f;

	// ���ꂼ��̕ϐ��͉��L�̂Ƃ���Ƃ���
	// �@float input[]  �c���͐M���̊i�[���ꂽ�o�b�t�@�B
	// �@flaot output[] �c�t�B���^���������l�������o���o�͐M���̃o�b�t�@�B
	// �@int   size     �c���͐M���E�o�͐M���̃o�b�t�@�̃T�C�Y�B
	// �@float in1, in2, out1, out2  �c�t�B���^�v�Z�p�̃o�b�t�@�ϐ��B�����l��0�B
	// �@float a0, a1, a2, b0, b1, b2 �c�t�B���^�̌W���B �ʓr�Z�o����B

	nsfloat in1 = 0.0, in2 = 0.0, out1 = 0.0, out2 = 0.0;
	for (size_t i = 0; i < out.size(); i++)
	{
		// ���͐M���Ƀt�B���^��K�p���A�o�͐M���Ƃ��ď����o���B
		out[i] = b0 / a0 * input[i] + b1 / a0 * in1 + b2 / a0 * in2
			- a1 / a0 * out1 - a2 / a0 * out2;

		in2 = in1;		// 2�O�̓��͐M�����X�V
		in1 = input[i];	// 1�O�̓��͐M�����X�V

		out2 = out1;	// 2�O�̏o�͐M�����X�V
		out1 = out[i];	// 1�O�̏o�͐M�����X�V
	}

	return 0;
}



//	���}�덆�@ �t�@�C���v���O����
//	
//	���}�덆�@�֌W�̃t�@�C���𓝊����ĊǗ�����v���O�����ł��B
//  
//  -----------------------------------------------------------------------------------------------
// 
//	Copyright (c) 2021 MucchoSP

mainMakeVoiseF mvffMMVF;

//=====�ǂݏグ�֌W=====

//���} ������g��
int makeVoiseFromFile::setDefaulFurin() {

	//���}�̕W�������u���} ����v�̉����t�@�C����蔲��
	char data[68] = { 0x44, 0x41, 0x54, 0x41, 0x62, 0x66, 0xB8, 0x01, 0x56, 0x46, 0x46, 0x41, 0x4C, 0x04, 0xA4, 0x06, 0xA0, 0x0F, 0x5C, 0x12, 0x56, 0x46, 0x46, 0x49, 0x80, 0x02, 0x42, 0x0E, 0xA0, 0x0F, 0x5C, 0x12, 0x56, 0x46, 0x46, 0x55, 0x58, 0x02, 0xEF, 0x06, 0xA0, 0x0F, 0x5C, 0x12, 0x56, 0x46, 0x46, 0x45, 0x0C, 0x03, 0x54, 0x0B, 0xA0, 0x0F, 0x5C, 0x12, 0x56, 0x46, 0x46, 0x4F, 0x20, 0x03, 0xDC, 0x05, 0xA0, 0x0F, 0x5C, 0x12 };

	decodeVoise0(data);

	return 0;
}

//���} �������g��
int makeVoiseFromFile::setShion() {

	char data[68] = { 0x44,0x41,0x54,0x41,0x62,0x66,0x88,0x01,0x56,0x46,0x46,0x41,0x54,0x04,0xA4,0x06,0x6F,0x0F,0x9A,0x14,0x56,0x46,0x46,0x49,0x93,0x02,0xC0,0x0D,0x6F,0x0F,0x9A,0x14,0x56,0x46,0x46,0x55,0x93,0x02,0xE0,0x06,0x6F,0x0F,0x9A,0x14,0x56,0x46,0x46,0x45,0x10,0x03,0x90,0x0B,0x6F,0x0F,0x9A,0x14,0x56,0x46,0x46,0x4F,0x10,0x03,0x75,0x05,0x6F,0x0F,0x9A,0x14 };

	decodeVoise0(data);

	return 0;
}

//���}�����ŏ����ꂽ���͂�ǂݍ���
int makeVoiseFromFile::textread(const char* t) {

	/*
	* text...�ǂݏグ����
	* ���}�`���̐���
	* ����      ...�������̂݁B����ȂɃ}���`�o�C�g�����Ă������ǁA���p�J�^�J�i���̂߂�ǂ��Ȃ����B�������A�����ɂ͑Ή����Ă��܂���B�N�����R���ꏈ���v���O���������
	* <S040>    ...�X�s�[�h�̕ύX�B�ꕶ���̒������w��B�ő�256�A�ŏ�01
	* <P�}000>  ...�s�b�`�̕ύX�Bbf����ǂ̂��炢����邩�B-128 �` +127
	* <pu><pd>  ...�s�b�`�̕ύX�Bpu�Ńs�b�`���\�グ�āApd�ŏ\������B
	*/

	pstringdata = NSString(t);

	return 0;
}

//textread�œǂݍ��񂾕��͂�ǂݏグ
std::vector<nsfloat> makeVoiseFromFile::textreading() {

	//�S�̂̎���[s]
	const size_t alltime = pstringdata.alltime() * (size_t)CHANGETIMEMAGN;

	//�����i
	std::vector<nsfloat> out;

	//���������Ă��鎞��
	int targettime = 0;

	//�O�̕����A�X�s�[�h�A�s�b�`
	NSCHAR oldmoji = pstringdata[0].c;
	int oldspeed = pstringdata[0].ctime;
	int16_t oldpitch = pstringdata[0].pitch;

	//���̕����A�X�s�[�h�A�s�b�`
	NSCHAR nowmoji = 0;
	int nowspeed = 0;
	int16_t nowpitch = 0;

	//���̕����A�X�s�[�h�A�s�b�`
	NSCHAR nextmoji = 0;
	int nextspeed = 0;
	int16_t nextpitch = 0;

	//�I��
	bool fin = false;

	//mvffMMVF��������
	mvffMMVF.setSoftness(softness);

	ftInit(MAXSHIONSPEED);
	//���C������
	for (size_t nowmojinum = 0;nowmojinum < pstringdata.length();nowmojinum++) {
		//���ꂼ��̕ϐ����X�V
		nowmoji = pstringdata[nowmojinum].c;
		nowspeed = pstringdata[nowmojinum].ctime * CHANGETIMEMAGN;
		nowpitch = pstringdata[nowmojinum].pitch;
		if (nowmojinum < pstringdata.length() - 1) {
			nextmoji = pstringdata[nowmojinum + 1].c;
			nextspeed = pstringdata[nowmojinum + 1].ctime * CHANGETIMEMAGN;
			nextpitch = pstringdata[nowmojinum + 1].pitch;
		}
		else {
			nextmoji = nextspeed = nextpitch = 0;
		}
		targettime = out.size() + nowspeed;
		//�{���ݒ�
		mvffMMVF.makeHarmonicOvertone(privatebf + nowpitch);

		nsfloat formantmagn = 0;
		//���̑O�������C��(�q����)
		switch (nowmoji) {
		case NSNULL:
			fin = true;
			break;
		case NSa:
		case NSi:
		case NSu:
		case NSe:
		case NSo:
			//���`��
			//�q������
			break;
		case NSya:
		case NSyu:
		case NSye:
		case NSyo:
		case NSwa:
		case NSwi:
		case NSwe:
		case NSwo:
			//��`��A��`��

			textreadingHanboin(out, nowmoji, nowpitch, targettime);

			break;
			//==========���s�E���s===========
		case NSka:
		case NSki:
		case NSku:
		case NSke:
		case NSko:
			//���`��

			textreadingHaretuon(out, nowmoji, nowmoji, nowpitch, targettime);

			break;
		case NSkya:
		case NSkyu:
		case NSkye:
		case NSkyo:
			//����`����

			textreadingHaretuon(out, nowmoji, 0x12, nowpitch, targettime);
			textreadingHanboin(out, nowmoji & 0x0f, nowpitch, targettime);

			break;
		case NSkwa:
		case NSkwi:
		case NSkwe:
		case NSkwo:
			//�����`����

			textreadingHaretuon(out, nowmoji, 0x17, nowpitch, targettime);
			textreadingHanboin(out, nowmoji & 0x0f, nowpitch, targettime);

			break;
		case NSga:
		case NSgi:
		case NSgu:
		case NSge:
		case NSgo:
			//���`��

			textreadingYuuseiHaretuon(out, nowmoji, nowmoji, nowpitch, targettime);

			break;
		case NSgya:
		case NSgyu:
		case NSgye:
		case NSgyo:
			//����`����

			textreadingYuuseiHaretuon(out, nowmoji, 0x22, nowpitch, targettime);
			textreadingHanboin(out, nowmoji & 0x0f, nowpitch, targettime);

			break;
		case NSgwa:
		case NSgwi:
		case NSgwe:
		case NSgwo:
			//�����`����

			textreadingYuuseiHaretuon(out, nowmoji, 0x27, nowpitch, targettime);
			textreadingHanboin(out, nowmoji & 0x0f, nowpitch, targettime);

			break;
			//==========���s�E���s===========
		case NSsa:
		case NSsi:
		case NSsu:
		case NSse:
		case NSso:
			//���`��

			textreadingMasatuon(out, nowmoji, nowmoji, nowpitch, targettime);

			break;
		case NSsya:
		case NSsyu:
		case NSsye:
		case NSsyo:
			//����`����

			textreadingMasatuon(out, nowmoji, 0x32, nowpitch, targettime);
			textreadingHanboin(out, nowmoji & 0x0f, nowpitch, targettime);

			break;
		case NSswa:
		case NSswi:
		case NSswe:
		case NSswo:
			//�����`����

			textreadingMasatuon(out, nowmoji, 0x37, nowpitch, targettime);
			textreadingHanboin(out, nowmoji & 0x0f, nowpitch, targettime);

			break;
		case NSza:
		case NSzi:
		case NSzu:
		case NSze:
		case NSzo:
			//���`��

			textreadingYuuseiMasatuon(out, nowmoji, nowmoji, nowpitch, targettime);

			break;
		case NSja:
		case NSju:
		case NSje:
		case NSjo:
			//����`����

			textreadingYuuseiMasatuon(out, nowmoji, 0x42, nowpitch, targettime);
			textreadingHanboin(out, nowmoji & 0x0f, nowpitch, targettime);

			break;
		case NSzwa:
		case NSzwi:
		case NSzwe:
		case NSzwo:
			//����`����

			textreadingYuuseiMasatuon(out, nowmoji, 0x47, nowpitch, targettime);
			textreadingHanboin(out, nowmoji & 0x0f, nowpitch, targettime);

			break;
			//==========���s�E���s===========
		case NSta:
		case NSti:
		case NStu:
		case NSte:
		case NSto:
			//���`��

			textreadingHaretuon(out, nowmoji, nowmoji, nowpitch, targettime);

			break;
		case NStya:
		case NStyu:
		case NStye:
		case NStyo:
			//����`����

			textreadingHaretuon(out, nowmoji, 0x52, nowpitch, targettime);
			textreadingHanboin(out, nowmoji & 0x0f, nowpitch, targettime);

			break;
		case NStwa:
		case NStwi:
		case NStwe:
		case NStwo:
			//���`��

			textreadingHaretuon(out, nowmoji, 0x57, nowpitch, targettime);
			textreadingHanboin(out, nowmoji & 0x0f, nowpitch, targettime);

			break;
		case NSda:
		case NSdi:
		case NSdu:
		case NSde:
		case NSdo:
			//���`��

			textreadingYuuseiHaretuon(out, nowmoji, nowmoji, nowpitch, targettime, false);

			break;
		case NSdya:
		case NSdyu:
		case NSdye:
		case NSdyo:
			//����`����

			textreadingYuuseiHaretuon(out, nowmoji, 0x62, nowpitch, targettime, false);
			textreadingHanboin(out, nowmoji & 0x0f, nowpitch, targettime);

			break;
		case NSdwa:
		case NSdwi:
		case NSdwe:
		case NSdwo:
			//�Â��`�Â�

			textreadingYuuseiHaretuon(out, nowmoji, 0x67, nowpitch, targettime, false);
			textreadingHanboin(out, nowmoji & 0x0f, nowpitch, targettime);

			break;
			//==========�ύs�E�΍s===========
		case NSpa:
		case NSpi:
		case NSpu:
		case NSpe:
		case NSpo:
			//�ρ`��

			textreadingHaretuon(out, nowmoji, nowmoji, nowpitch, targettime);

			break;
		case NSpya:
		case NSpyu:
		case NSpye:
		case NSpyo:
			//�҂�`�҂�

			textreadingHaretuon(out, nowmoji, 0x72, nowpitch, targettime);
			textreadingHanboin(out, nowmoji & 0x0f, nowpitch, targettime);

			break;
		case NSpwa:
		case NSpwi:
		case NSpwe:
		case NSpwo:
			//�Ղ��`�Ղ�

			textreadingHaretuon(out, nowmoji, 0x77, nowpitch, targettime);
			textreadingHanboin(out, nowmoji & 0x0f, nowpitch, targettime);

			break;
		case NSba:
		case NSbi:
		case NSbu:
		case NSbe:
		case NSbo:
			//�΁`��

			textreadingYuuseiHaretuon(out, nowmoji, nowmoji, nowpitch, targettime, false);

			break;
		case NSbya:
		case NSbyu:
		case NSbye:
		case NSbyo:
			//�т�`�т�

			textreadingYuuseiHaretuon(out, nowmoji, 0x82, nowpitch, targettime, false);
			textreadingHanboin(out, nowmoji & 0x0f, nowpitch, targettime);

			break;
		case NSbwa:
		case NSbwi:
		case NSbwe:
		case NSbwo:
			//�Ԃ��`�Ԃ�

			textreadingYuuseiHaretuon(out, nowmoji, 0x87, nowpitch, targettime, false);
			textreadingHanboin(out, nowmoji & 0x0f, nowpitch, targettime);

			break;
			//==========�͍s==========
		case NSha:
		case NShi:
		case NShu:
		case NShe:
		case NSho:
			//�́`��

			textreadingMASATUON(out, nowmoji, nowpitch, targettime);

			break;
		case NShya:
		case NShyu:
		case NShye:
		case NShyo:
			//�Ђ�`�Ђ�

			textreadingMASATUON(out, 0x92, nowpitch, targettime);
			textreadingHanboin(out, nowmoji & 0x0f, nowpitch, targettime);

			break;
		case NShwa:
		case NShwi:
		case NShwe:
		case NShwo:
			//�ӂ��`�ӂ�

			textreadingMASATUON(out, 0x97, nowpitch, targettime);
			textreadingHanboin(out, nowmoji & 0x0f, nowpitch, targettime);

			break;
			//==========�ȍs�E�܍s==========
		case NSna:
		case NSni:
		case NSnu:
		case NSne:
		case NSno:
			//�ȁ`��

			textreadingBion(out, nowmoji, nowmoji, oldmoji, nowpitch, targettime);

			break;
		case NSnya:
		case NSnyu:
		case NSnye:
		case NSnyo:
			//�ɂ�`�ɂ�

			textreadingBion(out, nowmoji, 0xa2, oldmoji, nowpitch, targettime);
			textreadingHanboin(out, nowmoji & 0x0f, nowpitch, targettime);

			break;
		case NSnwa:
		case NSnwi:
		case NSnwe:
		case NSnwo:
			//�ʂ��`�ʂ�

			textreadingBion(out, nowmoji, 0xa7, oldmoji, nowpitch, targettime);
			textreadingHanboin(out, nowmoji & 0x0f, nowpitch, targettime);

			break;
		case NSma:
		case NSmi:
		case NSmu:
		case NSme:
		case NSmo:
			//�܁`��

			textreadingBion(out, nowmoji, nowmoji, oldmoji, nowpitch, targettime);

			break;
		case NSmya:
		case NSmyu:
		case NSmye:
		case NSmyo:
			//�݂�`�݂�

			textreadingBion(out, nowmoji, 0xb2, oldmoji, nowpitch, targettime);
			textreadingHanboin(out, nowmoji & 0x0f, nowpitch, targettime);

			break;
		case NSmwa:
		case NSmwi:
		case NSmwe:
		case NSmwo:
			//�ނ��`�ނ�

			textreadingBion(out, nowmoji, 0xb7, oldmoji, nowpitch, targettime);
			textreadingHanboin(out, nowmoji & 0x0f, nowpitch, targettime);

			break;
			//==========��s==========
		case NSra:
		case NSri:
		case NSru:
		case NSre:
		case NSro:
			//��`��

			textreadingHajikion(out, nowmoji, nowmoji, oldmoji, nowpitch, targettime);

			break;
		case NSrya:
		case NSryu:
		case NSrye:
		case NSryo:
			//���`���

			textreadingHajikion(out, nowmoji, 0xc2, oldmoji, nowpitch, targettime);
			textreadingHanboin(out, nowmoji & 0x0f, nowpitch, targettime);

			break;
		case NSrwa:
		case NSrwi:
		case NSrwe:
		case NSrwo:
			//�邟�`�邧

			textreadingHajikion(out, nowmoji, 0xc7, oldmoji, nowpitch, targettime);
			textreadingHanboin(out, nowmoji & 0x0f, nowpitch, targettime);

			break;
		case NSnn1:
			//��
			//�q������
			break;
		case NSspc:
			//�󔒕���
			for (int i = out.size(); i < targettime;i++)
				out.push_back(0.0);
			break;
		default:
			break;
		}


		//���̕ꉹ�����C��(�ꉹ����)
		textreadingBoin1(out, nowmoji, nowpitch, targettime);

		//���̌㔼�����C��(���̉��֌����Ẵt�H���}���g�ψڕ�)
		if (nowmoji == NSspc)
			unprocessed;
		else {
			textreadingBoin2(out, nowmoji, nextmoji, nowpitch, nextpitch, targettime);
		}

		oldmoji = nowmoji;oldspeed = nowspeed;oldpitch = nowpitch;

		if (fin)break;
	}
	return out;
}

//=====���쐬(�q��)=====

void makeVoiseFromFile::textreadingHanboin(std::vector<nsfloat>& out, NSCHAR nowmoji, nsfloat pitch, int targettime) {
	const int size = MAXYOUONSPEED;
	std::vector<nsfloat> vout1(size + CTIME * 2, 1.0);
	std::vector<nsfloat> vout2(size + CTIME * 2, 1.0);

	mvffMMVF.setFormants(getMojiFormant(0, nowmoji, 0) + pitch, getMojiFormant(0, nowmoji, 1) + pitch, getMojiFormant(0, nowmoji, 2) + pitch, getMojiFormant(0, nowmoji, 3) + pitch);
	mvffMMVF.makeSinWaveFromClass(vout1, out.size() - CTIME);
	mvffMMVF.setFormants(getMojiFormant(1, nowmoji, 0) + pitch, getMojiFormant(1, nowmoji, 1) + pitch, getMojiFormant(1, nowmoji, 2) + pitch, getMojiFormant(1, nowmoji, 3) + pitch);
	mvffMMVF.makeSinWaveFromClass(vout2, out.size() - CTIME);

	for (int j = 0; j < MAXSHIONSPEED;j++)
		out.push_back(vout1[j + CTIME] * ((MAXSHIONSPEED - (nsfloat)j) / MAXSHIONSPEED) + vout2[j + CTIME] * ((nsfloat)j / MAXSHIONSPEED));
}

void makeVoiseFromFile::textreadingHaretuon(std::vector<nsfloat>& out, NSCHAR nowmoji1, NSCHAR nowmoji2, nsfloat pitch, int targettime) {
	for (int j = 0;j < MAXSHIONSPEED / 2;j++)
		out.push_back(0.0);

	const int size = MAXSHIONSPEED / 2;
	std::vector<nsfloat> vout1(size + CTIME * 2, 1.0);
	std::vector<nsfloat> vout2(size + CTIME * 2, 1.0);

	mvffMMVF.setFormants(getMojiFormant(0, nowmoji1, 0) + pitch, getMojiFormant(0, nowmoji1, 1) + pitch, getMojiFormant(0, nowmoji1, 2) + pitch, getMojiFormant(0, nowmoji1, 3) + pitch);
	mvffMMVF.makeSinWaveFromClass(vout1, out.size() - CTIME);
	mvffMMVF.setFormants(getMojiFormant(1, nowmoji2, 0) + pitch, getMojiFormant(1, nowmoji2, 1) + pitch, getMojiFormant(1, nowmoji2, 2) + pitch, getMojiFormant(1, nowmoji2, 3) + pitch);
	mvffMMVF.makeSinWaveFromClass(vout2, out.size() - CTIME);

	for (int j = 0; j < size;j++)
		out.push_back(((j < PLOSIVESPEED * 2) ? vout1[j + CTIME] * ((j < PLOSIVESPEED) ? ((nsfloat)j / PLOSIVESPEED * 2.0) : ((PLOSIVESPEED * 2.0 - (nsfloat)j) / PLOSIVESPEED * 2.0)) * PLOSIVEPOWER : 0) / 2.0 + vout2[j + CTIME] * ((nsfloat)j / (nsfloat)size));


}

void makeVoiseFromFile::textreadingYuuseiHaretuon(std::vector<nsfloat>& out, NSCHAR nowmoji1, NSCHAR nowmoji2, nsfloat pitch, int targettime, bool select) {

	if (select) {
		for (int j = 0;j < MAXSHIONSPEED / 4;j++)
			out.push_back(0.0);

		const int size = MAXSHIONSPEED / 4;
		std::vector<nsfloat> vout2(size + CTIME * 2, 1.0);
		std::vector<nsfloat> vout3(size + CTIME * 2, 1.0);
		mvffMMVF.setFormants(getMojiFormant(1, nowmoji1, 0) + pitch, getMojiFormant(1, nowmoji1, 1) + pitch, getMojiFormant(1, nowmoji1, 2) + pitch, getMojiFormant(1, nowmoji1, 3) + pitch);
		mvffMMVF.makeSinWaveFromClass(vout2, out.size() - CTIME);
		mvffMMVF.setFormants(getMojiFormant(0, 0xd1, 0) + pitch, getMojiFormant(0, 0xd1, 1) + pitch, getMojiFormant(0, 0xd1, 2) + pitch, getMojiFormant(0, 0xd1, 3) + pitch);
		mvffMMVF.makeSinWaveFromClass(vout3, out.size() - CTIME);

		for (int j = 0; j < size;j++)
			out.push_back((vout2[j + CTIME] * ((j < size / 2) ? ((nsfloat)j / size) : ((size - (nsfloat)j) / size)) + vout3[j + CTIME] * ((j < size / 2) ? ((nsfloat)j / size) : ((size - (nsfloat)j) / size))) / 4.0);

		std::vector<nsfloat> vout1(size + CTIME * 2, 1.0);
		std::fill(vout2.begin(), vout2.end(), 1.0);
		std::fill(vout3.begin(), vout3.end(), 1.0);

		mvffMMVF.setFormants(getMojiFormant(0, nowmoji1, 0) + pitch, getMojiFormant(0, nowmoji1, 1) + pitch, getMojiFormant(0, nowmoji1, 2) + pitch, getMojiFormant(0, nowmoji1, 3) + pitch);
		mvffMMVF.makeSinWaveFromClass(vout1, out.size() - CTIME);
		mvffMMVF.setFormants(getMojiFormant(1, nowmoji2, 0) + pitch, getMojiFormant(1, nowmoji2, 1) + pitch, getMojiFormant(1, nowmoji2, 2) + pitch, getMojiFormant(1, nowmoji2, 3) + pitch);
		mvffMMVF.makeSinWaveFromClass(vout2, out.size() - CTIME);
		mvffMMVF.setFormants(getMojiFormant(0, 0xd1, 0) + pitch, getMojiFormant(0, 0xd1, 1) + pitch, getMojiFormant(0, 0xd1, 2) + pitch, getMojiFormant(0, 0xd1, 3) + pitch);
		mvffMMVF.makeSinWaveFromClass(vout3, out.size() - CTIME);

		for (int j = 0; j < size;j++)
			out.push_back(((j < PLOSIVESPEED * 2) ? vout1[j + CTIME] * ((j < PLOSIVESPEED) ? ((nsfloat)j / PLOSIVESPEED * 2) : ((PLOSIVESPEED * 2 - (nsfloat)j) / PLOSIVESPEED * 2)) : 0) / 4 + (vout2[j + CTIME] * ((nsfloat)j / (nsfloat)size) + vout3[j + CTIME] * (((nsfloat)size - (nsfloat)j) / (nsfloat)size) / 3.0));

	}
	else {
		const int size = MAXSHIONSPEED / 2;
		std::vector<nsfloat> vout1(size + CTIME * 2, 1.0);
		std::vector<nsfloat> vout2(size + CTIME * 2, 1.0);
		mvffMMVF.setFormants(getMojiFormant(1, nowmoji1, 0) + pitch, getMojiFormant(1, nowmoji1, 1) + pitch, getMojiFormant(1, nowmoji1, 2) + pitch, getMojiFormant(1, nowmoji1, 3) + pitch);
		mvffMMVF.makeSinWaveFromClass(vout2, out.size() - CTIME);
		mvffMMVF.setFormants(getMojiFormant(0, 0xd1, 0) + pitch, getMojiFormant(0, 0xd1, 1) + pitch, getMojiFormant(0, 0xd1, 2) + pitch, getMojiFormant(0, 0xd1, 3) + pitch);
		mvffMMVF.makeSinWaveFromClass(vout1, out.size() - CTIME);

		for (int j = 0; j < size;j++)
			out.push_back((vout2[j + CTIME] * ((j < size / 2) ? ((nsfloat)j / size) : ((size - (nsfloat)j) / size)) + vout1[j + CTIME] * ((j < size / 2) ? ((nsfloat)j / size) : ((size - (nsfloat)j) / size))) / 4.0);

		std::fill(vout1.begin(), vout1.end(), 1.0);
		std::fill(vout2.begin(), vout2.end(), 1.0);

		mvffMMVF.setFormants(getMojiFormant(0, nowmoji1, 0) + pitch, getMojiFormant(0, nowmoji1, 1) + pitch, getMojiFormant(0, nowmoji1, 2) + pitch, getMojiFormant(0, nowmoji1, 3) + pitch);
		mvffMMVF.makeSinWaveFromClass(vout1, out.size() - CTIME);
		mvffMMVF.setFormants(getMojiFormant(1, nowmoji2, 0) + pitch, getMojiFormant(1, nowmoji2, 1) + pitch, getMojiFormant(1, nowmoji2, 2) + pitch, getMojiFormant(1, nowmoji2, 3) + pitch);
		mvffMMVF.makeSinWaveFromClass(vout2, out.size() - CTIME);

		for (int j = 0; j < size;j++)
			out.push_back(((j < PLOSIVESPEED * 2) ? vout1[j + CTIME] * ((j < PLOSIVESPEED) ? ((nsfloat)j / PLOSIVESPEED * 2.0) : ((PLOSIVESPEED * 2.0 - (nsfloat)j) / PLOSIVESPEED * 2.0)) * PLOSIVEPOWER : 0) / 2.0 + vout2[j + CTIME] * ((nsfloat)j / (nsfloat)size));

	}

}

void makeVoiseFromFile::textreadingMasatuon(std::vector<nsfloat>& out, NSCHAR nowmoji1, NSCHAR nowmoji2, nsfloat pitch, int targettime) {
	const int size = MAXSHIONSPEED / 2;
	//�z���C�g�m�C�Y
	std::vector<nsfloat> voutw(MAXSHIONSPEED, 0.0);
	std::vector<nsfloat> voutw2(MAXSHIONSPEED, 0.0);
	std::vector<nsfloat> voutw3(MAXSHIONSPEED, 0.0);
	std::vector<nsfloat> voutw4(MAXSHIONSPEED, 0.0);

	mvffMMVF.makeSinha(getMojiFormant(1, nowmoji1, 0), 0.5, voutw);
	mvffMMVF.makeSinha(getMojiFormant(1, nowmoji1, 1), 0.5, voutw2);
	mvffMMVF.makeSinha(getMojiFormant(1, nowmoji1, 2), 0.5, voutw3);
	mvffMMVF.makeSinha(getMojiFormant(1, nowmoji1, 3), 0.5, voutw4);

	for (int i = 0; i < MAXSHIONSPEED;i++) {
		voutw[i] += voutw2[i] * 0.5 + voutw3[i] + voutw4[i];
		voutw[i] /= 4;
		voutw2[i] = 0;
	}

	hipassFilter(voutw, voutw2, SMPL, getMojiFormant(1, nowmoji1, 1), 0.707);
	for (int i = 0; i < MAXSHIONSPEED;i++)voutw[i] = 0.0;
	lowpassFilter(voutw2, voutw, SMPL, getMojiFormant(1, nowmoji1, 0), 1.0);

	for (int j = 0; j < (MAXSHIONSPEED - size) / 2;j++)out.push_back(0.0);
	for (int j = 0;j < (MAXSHIONSPEED - size) / 2;j++)
		out.push_back(voutw[j] * ((nsfloat)j / (MAXSHIONSPEED - (nsfloat)size)) / 2.0);

	std::vector<nsfloat> vout2(size + CTIME * 2, 1.0);   //�ꉹ

	mvffMMVF.setFormants(getMojiFormant(1, nowmoji2, 0) + pitch, getMojiFormant(1, nowmoji2, 1) + pitch, getMojiFormant(1, nowmoji2, 2) + pitch, getMojiFormant(1, nowmoji2, 3) + pitch);
	mvffMMVF.makeSinWaveFromClass(vout2, out.size() - CTIME);

	for (int j = 0; j < size;j++)
		out.push_back(vout2[j + CTIME] * ((nsfloat)j / (nsfloat)size) + voutw[j + size] * (((nsfloat)size - (nsfloat)j) / (nsfloat)size) / 2.0);

}

void makeVoiseFromFile::textreadingYuuseiMasatuon(std::vector<nsfloat>& out, NSCHAR nowmoji1, NSCHAR nowmoji2, nsfloat pitch, int targettime) {
	const int size = MAXSHIONSPEED / 2;
	const int size2 = MAXSHIONSPEED / 4;
	std::vector<nsfloat> vout2(size2 + CTIME * 2, 1.0);   //�ꉹ
	std::vector<nsfloat> vout3(size2 + CTIME * 2, 1.0);   //�@��
	mvffMMVF.setFormants(getMojiFormant(1, nowmoji1, 0) + pitch, getMojiFormant(1, nowmoji1, 1) + pitch, getMojiFormant(1, nowmoji1, 2) + pitch, getMojiFormant(1, nowmoji1, 3) + pitch);
	mvffMMVF.makeSinWaveFromClass(vout2, out.size() - CTIME);
	mvffMMVF.setFormants(getMojiFormant(0, 0xd1, 0) + pitch, getMojiFormant(0, 0xd1, 1) + pitch, getMojiFormant(0, 0xd1, 2) + pitch, getMojiFormant(0, 0xd1, 3) + pitch);
	mvffMMVF.makeSinWaveFromClass(vout3, out.size() - CTIME);

	for (int j = 0; j < size2;j++)
		out.push_back((vout2[j + CTIME] * ((j < size2 / 2) ? ((nsfloat)j / size2) : ((size2 - (nsfloat)j) / size2)) + vout3[j + CTIME] * ((j < size2 / 2) ? ((nsfloat)j / size2) : ((size2 - (nsfloat)j) / size2))) / 4.0);

	//�z���C�g�m�C�Y
	std::vector<nsfloat> voutw(MAXSHIONSPEED, 0.0);
	std::vector<nsfloat> voutw2(MAXSHIONSPEED, 0.0);

	mvffMMVF.makeSinha(getMojiFormant(1, nowmoji1, 0), 0.5, voutw);
	mvffMMVF.makeSinha(getMojiFormant(1, nowmoji1, 1), 0.5, voutw2);
	for (int i = 0; i < MAXSHIONSPEED;i++) {
		voutw[i] += voutw2[i];voutw2[i] = 0;
	}
	mvffMMVF.makeSinha(getMojiFormant(1, nowmoji1, 2), 0.5, voutw2);
	for (int i = 0; i < MAXSHIONSPEED;i++) {
		voutw[i] += voutw2[i];voutw2[i] = 0;
	}
	mvffMMVF.makeSinha(getMojiFormant(1, nowmoji1, 3), 0.5, voutw2);
	for (int i = 0; i < MAXSHIONSPEED;i++) {
		voutw[i] += voutw2[i];voutw[i] /= 4;voutw2[i] = 0;
	}

	hipassFilter(voutw, voutw2, SMPL, getMojiFormant(1, nowmoji1, 1), 0.707);
	for (int i = 0; i < MAXSHIONSPEED;i++)voutw[i] = 0.0;
	lowpassFilter(voutw2, voutw, SMPL, getMojiFormant(1, nowmoji1, 0), 1.0);

	for (int j = 0;j < size / 2;j++)
		out.push_back(voutw[j] * ((nsfloat)j / (MAXSHIONSPEED - (nsfloat)size)) / 2.0);

	std::vector<nsfloat> vout1(size + CTIME * 2, 1.0);

	mvffMMVF.setFormants(getMojiFormant(1, nowmoji2, 0) + pitch, getMojiFormant(1, nowmoji2, 1) + pitch, getMojiFormant(1, nowmoji2, 2) + pitch, getMojiFormant(1, nowmoji2, 3) + pitch);
	mvffMMVF.makeSinWaveFromClass(vout1, out.size() - CTIME);

	for (int j = 0; j < size;j++)
		out.push_back(vout1[j + CTIME] * ((nsfloat)j / (nsfloat)size) + voutw[j + size] * (((nsfloat)size - (nsfloat)j) / (nsfloat)size) / 2.0);

}

void makeVoiseFromFile::textreadingMASATUON(std::vector<nsfloat>& out, NSCHAR nowmoji, nsfloat pitch, int targettime) {
	const int size = MAXSHIONSPEED;
	std::vector<nsfloat> vout1(size + CTIME * 2, 1.0);   //���E��
	std::vector<nsfloat> vout2(size + CTIME * 2, 1.0);   //�ꉹ
	FriKILLive h = {};
	h.size = (size_t)(MAXFREQ / privatebf);
	h.Hz.resize(h.size);
	h.s.resize(h.size);
	for (size_t i = 0; i < h.size;i++) {
		h.Hz[i] = privatebf * i;
		h.s[i] = 1.0;
	}

	mvffMMVF.makeSinWave(h.size, h.Hz, h.s, vout1, out.size() - CTIME, false);

	mvffMMVF.setFormants(getMojiFormant(0, nowmoji, 0) + pitch, getMojiFormant(0, nowmoji, 1) + pitch, getMojiFormant(0, nowmoji, 2) + pitch, getMojiFormant(0, nowmoji, 3) + pitch);
	mvffMMVF.makeSinWaveFromClass(vout2, out.size() - CTIME);

	for (int j = 0; j < size;j++)
		out.push_back(((j < size) ? vout1[j + CTIME] * ((j < size / 2) ? ((nsfloat)j / (nsfloat)size) : (((nsfloat)size - (nsfloat)j) / (nsfloat)size)) : 0) / 4 + vout2[j + CTIME] * ((nsfloat)j / (nsfloat)size));

}

void makeVoiseFromFile::textreadingBion(std::vector<nsfloat>& out, NSCHAR nowmoji1, NSCHAR nowmoji2, NSCHAR oldmoji, nsfloat pitch, int targettime) {
	const int size = MAXSHIONSPEED;
	const int ssize = MAXSHIONSPEED / 2 - NASALSPEED;int jtime = 0;
	std::vector<nsfloat> vout1(size + CTIME * 2, 1.0);   //�@��
	std::vector<nsfloat> vout2(size + CTIME * 2, 1.0);   //�ꉹ

	mvffMMVF.setFormants(getMojiFormant(0, nowmoji1, 0) + pitch, getMojiFormant(0, nowmoji1, 1) + pitch, getMojiFormant(0, nowmoji1, 2) + pitch, getMojiFormant(0, nowmoji1, 3) + pitch);
	mvffMMVF.makeSinWaveFromClass(vout1, out.size() - CTIME);
	mvffMMVF.setFormants(getMojiFormant(1, nowmoji2, 0) + pitch, getMojiFormant(1, nowmoji2, 1) + pitch, getMojiFormant(1, nowmoji2, 2) + pitch, getMojiFormant(1, nowmoji2, 3) + pitch);
	mvffMMVF.makeSinWaveFromClass(vout2, out.size() - CTIME);

	if (oldmoji == NSNULL or oldmoji == NSspc) {
		for (int j = 0; j < ssize;j++) {
			out.push_back(vout1[jtime + CTIME] * ((nsfloat)j / ssize) / 2.0);
			jtime++;
		}
	}
	else {
		for (int j = 0; j < ssize;j++) {
			out.push_back(vout1[jtime + CTIME] / 2.0);
			jtime++;
		}
	}
	for (int j = 0;j < NASALSPEED;j++) {
		out.push_back(vout1[jtime + CTIME] * ((NASALSPEED - (nsfloat)j) / NASALSPEED) / 2 + vout2[jtime + CTIME] * ((nsfloat)j / NASALSPEED));
		jtime++;
	}
	for (int j = 0; jtime == size;j++) {
		out.push_back(vout2[jtime + CTIME]);
		jtime++;
	}
}

void makeVoiseFromFile::textreadingHajikion(std::vector<nsfloat>& out, NSCHAR nowmoji1, NSCHAR nowmoji2, NSCHAR oldmoji, nsfloat pitch, int targettime) {
	const int size = MAXSHIONSPEED;
	const int ssize = MAXSHIONSPEED / 2 - TAPSPEED;int jtime = 0;
	std::vector<nsfloat> vout1(size + CTIME * 2, 1.0);   //�@��
	std::vector<nsfloat> vout2(size + CTIME * 2, 1.0);   //�ꉹ

	mvffMMVF.setFormants(getMojiFormant(0, nowmoji1, 0) + pitch, getMojiFormant(0, nowmoji1, 1) + pitch, getMojiFormant(0, nowmoji1, 2) + pitch, getMojiFormant(0, nowmoji1, 3) + pitch);
	mvffMMVF.makeSinWaveFromClass(vout1, out.size() - CTIME);
	mvffMMVF.setFormants(getMojiFormant(1, nowmoji2, 0) + pitch, getMojiFormant(1, nowmoji2, 1) + pitch, getMojiFormant(1, nowmoji2, 2) + pitch, getMojiFormant(1, nowmoji2, 3) + pitch);
	mvffMMVF.makeSinWaveFromClass(vout2, out.size() - CTIME);

	if (oldmoji == NSNULL or oldmoji == NSspc) {
		for (int j = 0; j < ssize;j++) {
			out.push_back(vout1[jtime + CTIME] * ((nsfloat)j / ssize) / 2.0);
			jtime++;
		}
	}
	else {
		for (int j = 0; j < ssize;j++) {
			out.push_back(vout1[jtime + CTIME] / 2.0);
			jtime++;
		}
	}
	for (int j = 0;j < NASALSPEED;j++) {
		out.push_back(vout1[jtime + CTIME] * ((TAPSPEED - (nsfloat)j) / TAPSPEED) / 2 + vout2[jtime + CTIME] * ((nsfloat)j / TAPSPEED));
		jtime++;
	}
	for (int j = 0; jtime == size;j++) {
		out.push_back(vout2[jtime + CTIME]);
		jtime++;
	}
}

//=====������(�ꉹ)=====

void makeVoiseFromFile::textreadingBoin1(std::vector<nsfloat>& out, NSCHAR nowmoji, nsfloat pitch, int targettime) {
	mvffMMVF.setFormants(getMojiFormant(1, nowmoji, 0) + pitch, getMojiFormant(1, nowmoji, 1) + pitch, getMojiFormant(1, nowmoji, 2) + pitch, getMojiFormant(1, nowmoji, 3) + pitch);
	const int size = targettime - SEMIVOWELSPEED - out.size();
	if (size > 0) {
		std::vector<nsfloat> vout(size + CTIME * 2, 1.0);

		mvffMMVF.makeSinWaveFromClass(vout, out.size() - CTIME);

		for (int j = 0; j < size;j++)
			out.push_back(vout[j + CTIME]);
	}
}

void makeVoiseFromFile::textreadingBoin2(std::vector<nsfloat>& out, NSCHAR nowmoji, NSCHAR nextmoji, nsfloat pitch, nsfloat nextpitch, int targettime) {
	//�I��� or ��
	if (nextmoji == NSNULL or nextmoji == NSspc) {
		const int size = SEMIVOWELSPEED;
		std::vector<nsfloat> vout(size + CTIME * 2, 1.0);

		mvffMMVF.makeSinWaveFromClass(vout, out.size() - CTIME);

		for (int j = 0; j < size;j++)
			out.push_back(vout[j + CTIME] * ((size - (nsfloat)j) / size));
	}
	//�j��
	else if (doVoiselessPlosive(nextmoji) or doVoisedPlosive(nextmoji)) {
		const int size = SEMIVOWELSPEED;
		std::vector<nsfloat> vout1(size + CTIME * 2, 1.0);
		std::vector<nsfloat> vout2(size + CTIME * 2, 1.0);

		mvffMMVF.setFormants(getMojiFormant(1, nowmoji, 0) + pitch, getMojiFormant(1, nowmoji, 1) + pitch, getMojiFormant(1, nowmoji, 2) + pitch, getMojiFormant(1, nowmoji, 3) + pitch);
		mvffMMVF.makeSinWaveFromClass(vout1, out.size() - CTIME);
		mvffMMVF.setFormants(getMojiFormant(0, nextmoji, 0) + nextpitch, getMojiFormant(0, nextmoji, 1) + nextpitch, getMojiFormant(0, nextmoji, 2) + nextpitch, getMojiFormant(0, nextmoji, 3) + nextpitch);
		mvffMMVF.makeSinWaveFromClass(vout2, out.size() - CTIME);

		for (int j = 0; j < size / 2;j++)
			out.push_back(vout1[j + CTIME] * ((size - (nsfloat)j) / size) + vout2[j + CTIME] * ((nsfloat)j / size));

		for (int j = out.size();j < targettime;j++)
			out.push_back(0.0);
	}
	//�@��
	else if (doNasal(nextmoji)) {
		const int size = SEMIVOWELSPEED;
		std::vector<nsfloat> vout1(size + CTIME * 2, 1.0);
		std::vector<nsfloat> vout2(size + CTIME * 2, 1.0);

		mvffMMVF.setFormants(getMojiFormant(1, nowmoji, 0) + pitch, getMojiFormant(1, nowmoji, 1) + pitch, getMojiFormant(1, nowmoji, 2) + pitch, getMojiFormant(1, nowmoji, 3) + pitch);
		mvffMMVF.makeSinWaveFromClass(vout1, out.size() - CTIME);
		mvffMMVF.setFormants(getMojiFormant(0, nextmoji, 0) + nextpitch, getMojiFormant(0, nextmoji, 1) + nextpitch, getMojiFormant(0, nextmoji, 2) + nextpitch, getMojiFormant(0, nextmoji, 3) + nextpitch);
		mvffMMVF.makeSinWaveFromClass(vout2, out.size() - CTIME);

		for (int j = 0; j < size;j++)
			out.push_back(vout1[j + CTIME] * ((size - (nsfloat)j) / size) + vout2[j + CTIME] * ((nsfloat)j / size) / 2.0);
	}
	//�͂�����
	else if (doTap(nextmoji)) {
		const int size = SEMIVOWELSPEED;
		std::vector<nsfloat> vout1(size + CTIME * 2, 1.0);
		std::vector<nsfloat> vout2(size + CTIME * 2, 1.0);

		mvffMMVF.setFormants(getMojiFormant(1, nowmoji, 0) + pitch, getMojiFormant(1, nowmoji, 1) + pitch, getMojiFormant(1, nowmoji, 2) + pitch, getMojiFormant(1, nowmoji, 3) + pitch);
		mvffMMVF.makeSinWaveFromClass(vout1, out.size() - CTIME);
		mvffMMVF.setFormants(getMojiFormant(0, nextmoji, 0) + nextpitch, getMojiFormant(0, nextmoji, 1) + nextpitch, getMojiFormant(0, nextmoji, 2) + nextpitch, getMojiFormant(0, nextmoji, 3) + nextpitch);
		mvffMMVF.makeSinWaveFromClass(vout2, out.size() - CTIME);

		for (int j = 0; j < size;j++)
			out.push_back(vout1[j + CTIME] * ((size - (nsfloat)j) / size) + vout2[j + CTIME] * ((nsfloat)j / size));
	}
	//���C��
	else if (doVoiselessFricative(nextmoji)) {
		const int size = SEMIVOWELSPEED;
		std::vector<nsfloat> vout1(size + CTIME * 2, 1.0);

		mvffMMVF.setFormants(getMojiFormant(1, nowmoji, 0) + pitch, getMojiFormant(1, nowmoji, 1) + pitch, getMojiFormant(1, nowmoji, 2) + pitch, getMojiFormant(1, nowmoji, 3) + pitch);
		mvffMMVF.makeSinWaveFromClass(vout1, out.size() - CTIME);

		for (int j = 0; j < size;j++)
			out.push_back(vout1[j + CTIME] * ((size - (nsfloat)j) / size));
	}
	//���E��(��)
	else if (doFriKILLive(nextmoji)) {
		const int size = SEMIVOWELSPEED;
		//�z���C�g�m�C�Y
		std::vector<nsfloat> voutw(MAXSHIONSPEED, 0.0);
		std::vector<nsfloat> voutw2(MAXSHIONSPEED, 0.0);
		ftInit(MAXSHIONSPEED);
		makeWhitenoise1(voutw, out.size(), getMojiFormant(1, nowmoji, 3));

		hipassFilter(voutw, voutw2, SMPL, getMojiFormant(1, nowmoji, 3), 0.707);
		for (int i = 0; i < MAXSHIONSPEED;i++)voutw[i] = 0.0;
		lowpassFilter(voutw2, voutw, SMPL, getMojiFormant(1, nowmoji, 3), 1.0);

		std::vector<nsfloat> vout1(size + CTIME * 2, 1.0);
		std::vector<nsfloat> vout2(size + CTIME * 2, 1.0);

		mvffMMVF.setFormants(getMojiFormant(1, nowmoji, 0) + pitch, getMojiFormant(1, nowmoji, 1) + pitch, getMojiFormant(1, nowmoji, 2) + pitch, getMojiFormant(1, nowmoji, 3) + pitch);
		mvffMMVF.makeSinWaveFromClass(vout1, out.size() - CTIME);
		mvffMMVF.setFormants(getMojiFormant(0, nextmoji, 0) + nextpitch, getMojiFormant(0, nextmoji, 1) + nextpitch, getMojiFormant(0, nextmoji, 2) + nextpitch, getMojiFormant(0, nextmoji, 3) + nextpitch);
		mvffMMVF.makeSinWaveFromClass(vout2, out.size() - CTIME);

		for (int j = 0; j < size;j++)
			out.push_back(vout1[j + CTIME] * ((size - (nsfloat)j) / size));// +(voutw[j] + vout2[j + CTIME] / 2) * ((nsfloat)j / size);
	}
	//���̑�
	else {
		const int size = SEMIVOWELSPEED;
		std::vector<nsfloat> vout1(size + CTIME * 2, 1.0);
		std::vector<nsfloat> vout2(size + CTIME * 2, 1.0);


		mvffMMVF.setFormants(getMojiFormant(1, nowmoji, 0) + pitch, getMojiFormant(1, nowmoji, 1) + pitch, getMojiFormant(1, nowmoji, 2) + pitch, getMojiFormant(1, nowmoji, 3) + pitch);
		mvffMMVF.makeSinWaveFromClass(vout1, out.size() - CTIME);
		mvffMMVF.setFormants(getMojiFormant(0, nextmoji, 0) + nextpitch, getMojiFormant(0, nextmoji, 1) + nextpitch, getMojiFormant(0, nextmoji, 2) + nextpitch, getMojiFormant(0, nextmoji, 3) + nextpitch);
		mvffMMVF.makeSinWaveFromClass(vout2, out.size() - CTIME);

		for (int j = 0; j < size;j++)
			out.push_back(vout1[j + CTIME] * ((size - (nsfloat)j) / size) + vout2[j + CTIME] * ((nsfloat)j / size));
	}
}


//=====�t�@�C���֌W=====

//�����񂩂�f�[�^��ǂݍ���
int makeVoiseFromFile::loadFromChar(char* data) {

	/* �������܂��B(SCP-___-J) */

	return 0;
}

//=====���[�J���ϐ����擾=====

//�f�[�^�ۊǌɂ����f�[�^��ǂݍ���
nsfloat makeVoiseFromFile::getPrivatebf() {
	return privatebf;
}

//�f�[�^�ۊǌɂ���t�H���}���g�f�[�^��ǂݍ���
nsfloat makeVoiseFromFile::getPrivatebFormant(int b, int f) {
	return privateFormant[b][f];
}

//=====�f�R�[�h�֐�=====

//�덆�@�̃f�[�^��ǂݍ���
int makeVoiseFromFile::decodeVoise0(char* data) {

	int ne = 0;                                         //���̔z��̗v�f�ԍ�

	privatebf = 0.0;
	for (int i = 0; i < 5;i++)
		for (int j = 0; j < 4;j++)
			privateFormant[i][j] = 0;

	if (data[ne++] != 'D') return 1;
	if (data[ne++] != 'A') return 1;
	if (data[ne++] != 'T') return 1;
	if (data[ne++] != 'A') return 1;

	//�
	if (data[ne++] != 'b') return 1;
	if (data[ne++] != 'f') return 1;
	short int pf = 0;
	pf += (short int)(data[ne++] & 0xff) << 0;
	pf += (short int)(data[ne++] & 0xff) << 8;
	privatebf = (nsfloat)pf;

	//��
	if (data[ne++] != 'V') return 1;
	if (data[ne++] != 'F') return 1;
	if (data[ne++] != 'F') return 1;
	if (data[ne++] != 'A') return 1;
	for (int i = 0; i < 4;i++) {
		privateFormant[0][i] += (__int64)(data[ne++] & 0xff) << 0;
		privateFormant[0][i] += (__int64)(data[ne++] & 0xff) << 8;
	}

	//��
	if (data[ne++] != 'V') return 1;
	if (data[ne++] != 'F') return 1;
	if (data[ne++] != 'F') return 1;
	if (data[ne++] != 'I') return 1;
	for (int i = 0; i < 4;i++) {
		privateFormant[1][i] += (__int64)(data[ne++] & 0xff) << 0;
		privateFormant[1][i] += (__int64)(data[ne++] & 0xff) << 8;
	}

	//��
	if (data[ne++] != 'V') return 1;
	if (data[ne++] != 'F') return 1;
	if (data[ne++] != 'F') return 1;
	if (data[ne++] != 'U') return 1;
	for (int i = 0; i < 4;i++) {
		privateFormant[2][i] += (__int64)(data[ne++] & 0xff) << 0;
		privateFormant[2][i] += (__int64)(data[ne++] & 0xff) << 8;
	}

	//��
	if (data[ne++] != 'V') return 1;
	if (data[ne++] != 'F') return 1;
	if (data[ne++] != 'F') return 1;
	if (data[ne++] != 'E') return 1;
	for (int i = 0; i < 4;i++) {
		privateFormant[3][i] += (__int64)(data[ne++] & 0xff) << 0;
		privateFormant[3][i] += (__int64)(data[ne++] & 0xff) << 8;
	}

	//��
	if (data[ne++] != 'V') return 1;
	if (data[ne++] != 'F') return 1;
	if (data[ne++] != 'F') return 1;
	if (data[ne++] != 'O') return 1;
	for (int i = 0; i < 4;i++) {
		privateFormant[4][i] += (__int64)(data[ne++] & 0xff) << 0;
		privateFormant[4][i] += (__int64)(data[ne++] & 0xff) << 8;
	}

	createAllMojiFromantFromClass();
	softness = 0;

	return 0;
}

//�덆�@��^�̃f�[�^��ǂݍ���
int makeVoiseFromFile::decodeVoise2(char* data) {

	int ne = 0;                                         //���̔z��̗v�f�ԍ�

	privatebf = 0.0;
	for (int i = 0; i < 5;i++)
		for (int j = 0; j < 4;j++)
			privateFormant[i][j] = 0;

	if (data[ne++] != 'D') return 1;
	if (data[ne++] != 'A') return 1;
	if (data[ne++] != 'T') return 1;
	if (data[ne++] != 'A') return 1;

	//�
	if (data[ne++] != 'b') return 1;
	if (data[ne++] != 'f') return 1;
	short int pf = 0;
	pf += (short int)(data[ne++] & 0xff) << 0;
	pf += (short int)(data[ne++] & 0xff) << 8;
	privatebf = (nsfloat)pf;

	//�f�[�^
	//NSallmojiFormant
	if (data[ne++] != 'N') return 1;
	if (data[ne++] != 'S') return 1;
	if (data[ne++] != 'a') return 1;
	if (data[ne++] != 'l') return 1;
	if (data[ne++] != 'l') return 1;
	if (data[ne++] != 'm') return 1;
	if (data[ne++] != 'o') return 1;
	if (data[ne++] != 'j') return 1;
	if (data[ne++] != 'i') return 1;
	if (data[ne++] != 'F') return 1;
	if (data[ne++] != 'o') return 1;
	if (data[ne++] != 'r') return 1;
	if (data[ne++] != 'm') return 1;
	if (data[ne++] != 'a') return 1;
	if (data[ne++] != 'n') return 1;
	if (data[ne++] != 't') return 1;

	for (int i = 0;i < 2;i++) {
		for (int j = 0;j < 16;j++) {
			for (int k = 0;k < 16;k++) {
				for (int l = 0;l < 4;l++) {
					allmojiFormant[i][j][k][l] = (static_cast<unsigned __int64>(data[ne++] & 0xff) << 0);
					allmojiFormant[i][j][k][l] += (static_cast<unsigned __int64>(data[ne++] & 0xff) << 8);
				}
			}
		}
	}

	//�_�炩��
	if (data[ne++] != 'S') return 1;
	if (data[ne++] != 'O') return 1;
	if (data[ne++] != 'F') return 1;
	if (data[ne++] != 'T') return 1;
	short sn = 0;
	sn += (short)(data[ne++] & 0xff) << 0;
	sn += (short)(data[ne++] & 0xff) << 8;
	softness = (nsfloat)sn;

	return 0;
}

//=====�t�B���^�[�֐�=====

//�n�C�p�X�t�B���^
int makeVoiseFromFile::hipassFilter(std::vector<nsfloat> input, std::vector<nsfloat>& out, nsfloat samplerate, nsfloat freq, nsfloat q) {

	// ���ꂼ��̕ϐ��͉��L�̂Ƃ���Ƃ���
	// float samplerate �c �T���v�����O���g��
	// float freq �c �J�b�g�I�t���g��
	// float q    �c �t�B���^��Q�l
	nsfloat omega = 2.0f * 3.14159265f * freq / samplerate;
	nsfloat alpha = sin(omega) / (2.0f * q);

	nsfloat a0 = 1.0f + alpha;
	nsfloat a1 = -2.0f * cos(omega);
	nsfloat a2 = 1.0f - alpha;
	nsfloat b0 = (1.0f + cos(omega)) / 2.0f;
	nsfloat b1 = -(1.0f + cos(omega));
	nsfloat b2 = (1.0f + cos(omega)) / 2.0f;

	// ���ꂼ��̕ϐ��͉��L�̂Ƃ���Ƃ���
	// �@float input[]  �c���͐M���̊i�[���ꂽ�o�b�t�@�B
	// �@flaot output[] �c�t�B���^���������l�������o���o�͐M���̃o�b�t�@�B
	// �@int   size     �c���͐M���E�o�͐M���̃o�b�t�@�̃T�C�Y�B
	// �@float in1, in2, out1, out2  �c�t�B���^�v�Z�p�̃o�b�t�@�ϐ��B�����l��0�B
	// �@float a0, a1, a2, b0, b1, b2 �c�t�B���^�̌W���B �ʓr�Z�o����B

	nsfloat in1 = 0.0, in2 = 0.0, out1 = 0.0, out2 = 0.0;
	for (size_t i = 0; i < out.size(); i++)
	{
		// ���͐M���Ƀt�B���^��K�p���A�o�͐M���Ƃ��ď����o���B
		out[i] = b0 / a0 * input[i] + b1 / a0 * in1 + b2 / a0 * in2
			- a1 / a0 * out1 - a2 / a0 * out2;

		in2 = in1;		// 2�O�̓��͐M�����X�V
		in1 = input[i];	// 1�O�̓��͐M�����X�V

		out2 = out1;	// 2�O�̏o�͐M�����X�V
		out1 = out[i];	// 1�O�̏o�͐M�����X�V
	}

	return 0;
}

//���[�p�X�t�B���^
int makeVoiseFromFile::lowpassFilter(std::vector<nsfloat> input, std::vector<nsfloat>& out, nsfloat samplerate, nsfloat freq, nsfloat q)
{
	// ���ꂼ��̕ϐ��͉��L�̂Ƃ���Ƃ���
	// float samplerate �c �T���v�����O���g��
	// float freq �c �J�b�g�I�t���g��
	// float q    �c �t�B���^��Q�l
	nsfloat omega = 2.0f * 3.14159265f * freq / samplerate;
	nsfloat alpha = sin(omega) / (2.0f * q);

	nsfloat a0 = 1.0f + alpha;
	nsfloat a1 = -2.0f * cos(omega);
	nsfloat a2 = 1.0f - alpha;
	nsfloat b0 = (1.0f - cos(omega)) / 2.0f;
	nsfloat b1 = 1.0f - cos(omega);
	nsfloat b2 = (1.0f - cos(omega)) / 2.0f;

	// ���ꂼ��̕ϐ��͉��L�̂Ƃ���Ƃ���
	// �@float input[]  �c���͐M���̊i�[���ꂽ�o�b�t�@�B
	// �@flaot output[] �c�t�B���^���������l�������o���o�͐M���̃o�b�t�@�B
	// �@int   size     �c���͐M���E�o�͐M���̃o�b�t�@�̃T�C�Y�B
	// �@float in1, in2, out1, out2  �c�t�B���^�v�Z�p�̃o�b�t�@�ϐ��B�����l��0�B
	// �@float a0, a1, a2, b0, b1, b2 �c�t�B���^�̌W���B �ʓr�Z�o����B

	nsfloat in1 = 0.0, in2 = 0.0, out1 = 0.0, out2 = 0.0;
	for (size_t i = 0; i < out.size(); i++)
	{
		// ���͐M���Ƀt�B���^��K�p���A�o�͐M���Ƃ��ď����o���B
		out[i] = b0 / a0 * input[i] + b1 / a0 * in1 + b2 / a0 * in2
			- a1 / a0 * out1 - a2 / a0 * out2;

		in2 = in1;		// 2�O�̓��͐M�����X�V
		in1 = input[i];	// 1�O�̓��͐M�����X�V

		out2 = out1;	// 2�O�̏o�͐M�����X�V
		out1 = out[i];	// 1�O�̏o�͐M�����X�V
	}

	return 0;
}

//�m�b�`�t�B���^�[
int makeVoiseFromFile::notchpassFilter(std::vector<nsfloat> input, std::vector<nsfloat>& out, nsfloat samplerate, nsfloat freq, nsfloat bw)
{
	// ���ꂼ��̕ϐ��͉��L�̂Ƃ���Ƃ���
	// float samplerate �c �T���v�����O���g��
	//float freq �c �J�b�g�I�t���g��
	// float bw   �c �ш敝
	nsfloat omega = 2.0f * 3.14159265f * freq / samplerate;
	nsfloat alpha = sin(omega) * sinh(log(2.0f) / 2.0 * bw * omega / sin(omega));

	nsfloat a0 = 1.0f + alpha;
	nsfloat a1 = -2.0f * cos(omega);
	nsfloat a2 = 1.0f - alpha;
	nsfloat b0 = 1.0f;
	nsfloat b1 = -2.0f * cos(omega);
	nsfloat b2 = 1.0f;

	// ���ꂼ��̕ϐ��͉��L�̂Ƃ���Ƃ���
	// �@float input[]  �c���͐M���̊i�[���ꂽ�o�b�t�@�B
	// �@flaot output[] �c�t�B���^���������l�������o���o�͐M���̃o�b�t�@�B
	// �@int   size     �c���͐M���E�o�͐M���̃o�b�t�@�̃T�C�Y�B
	// �@float in1, in2, out1, out2  �c�t�B���^�v�Z�p�̃o�b�t�@�ϐ��B�����l��0�B
	// �@float a0, a1, a2, b0, b1, b2 �c�t�B���^�̌W���B �ʓr�Z�o����B

	nsfloat in1 = 0.0, in2 = 0.0, out1 = 0.0, out2 = 0.0;
	for (size_t i = 0; i < out.size(); i++)
	{
		// ���͐M���Ƀt�B���^��K�p���A�o�͐M���Ƃ��ď����o���B
		out[i] = b0 / a0 * input[i] + b1 / a0 * in1 + b2 / a0 * in2
			- a1 / a0 * out1 - a2 / a0 * out2;

		in2 = in1;		// 2�O�̓��͐M�����X�V
		in1 = input[i];	// 1�O�̓��͐M�����X�V

		out2 = out1;	// 2�O�̏o�͐M�����X�V
		out1 = out[i];	// 1�O�̏o�͐M�����X�V
	}

	return 0;
}

//=====���̑�=====

//privateFormant����allmojiFormant���쐬
int makeVoiseFromFile::createAllMojiFromantFromClass() {

	//NULL
	for (int i = 0; i < 4; i++) {
		allmojiFormant[0][0][0][i] = 0;
		allmojiFormant[1][0][0][i] = 0;
	}

	//�ꉹ�t�H���}���g
	for (int i = 0; i < 2;i++) {
		//��
		for (int k = 0; k < 4;k++)
			allmojiFormant[i][0][1][k] = privateFormant[0][k];
		//��
		for (int k = 0; k < 4;k++)
			allmojiFormant[i][0][2][k] = privateFormant[1][k];
		//��
		for (int k = 0; k < 4;k++)
			allmojiFormant[i][0][7][k] = privateFormant[2][k];
		//��
		for (int k = 0; k < 4;k++)
			allmojiFormant[i][0][12][k] = privateFormant[3][k];
		//��
		for (int k = 0; k < 4;k++)
			allmojiFormant[i][0][13][k] = privateFormant[4][k];
	}

	//���ꉹ
	if (true) {
		//��
		for (int k = 0; k < 4;k++)
			allmojiFormant[0][0][3][k] = privateFormant[1][k];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][0][3][k] = privateFormant[0][k];
		//��
		for (int k = 0; k < 4;k++)
			allmojiFormant[0][0][4][k] = privateFormant[1][k];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][0][4][k] = privateFormant[2][k];
		//�]
		for (int k = 0; k < 4;k++)
			allmojiFormant[0][0][5][k] = privateFormant[1][k];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][0][5][k] = privateFormant[3][k];
		//��
		for (int k = 0; k < 4;k++)
			allmojiFormant[0][0][6][k] = privateFormant[1][k];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][0][6][k] = privateFormant[4][k];

		//��
		for (int k = 0; k < 4;k++)
			allmojiFormant[0][0][8][k] = privateFormant[2][k];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][0][8][k] = privateFormant[0][k];
		//��
		for (int k = 0; k < 4;k++)
			allmojiFormant[0][0][9][k] = privateFormant[2][k];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][0][9][k] = privateFormant[1][k];
		//��
		for (int k = 0; k < 4;k++)
			allmojiFormant[0][0][10][k] = privateFormant[2][k];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][0][10][k] = privateFormant[3][k];
		//��
		for (int k = 0; k < 4;k++)
			allmojiFormant[0][0][11][k] = privateFormant[2][k];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][0][11][k] = privateFormant[4][k];
	}

	//����W�j��(���`��)(1x,2x)

	if (true) {
		//��������W�j��(��)
		allmojiFormant[0][1][1][0] = privateFormant[0][0];
		allmojiFormant[0][1][1][1] = privateFormant[0][1];
		allmojiFormant[0][1][1][2] = privateFormant[0][2] / 2.0;
		allmojiFormant[0][1][1][3] = privateFormant[0][3];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][1][1][k] = allmojiFormant[1][0][1][k];
		//��������W�j��(�d�����)(��)
		for (int i = 2;i <= 6; i++) {
			allmojiFormant[0][1][i][0] = privateFormant[1][0];
			allmojiFormant[0][1][i][1] = privateFormant[1][1];
			allmojiFormant[0][1][i][2] = privateFormant[1][2] / 2.0;
			allmojiFormant[0][1][i][3] = privateFormant[1][3];
			for (int k = 0; k < 4;k++)
				allmojiFormant[1][1][i][k] = allmojiFormant[1][0][i][k];
		}
		//��������W�j��(��)
		for (int i = 7;i <= 11; i++) {
			allmojiFormant[0][1][i][0] = privateFormant[2][0];
			allmojiFormant[0][1][i][1] = privateFormant[2][1];
			allmojiFormant[0][1][i][2] = privateFormant[2][2] / 2.0;
			allmojiFormant[0][1][i][3] = privateFormant[2][3];
			for (int k = 0; k < 4;k++)
				allmojiFormant[1][1][i][k] = allmojiFormant[1][0][i][k];
		}
		//��������W�j��(��)
		allmojiFormant[0][1][12][0] = privateFormant[3][0];
		allmojiFormant[0][1][12][1] = privateFormant[3][1];
		allmojiFormant[0][1][12][2] = privateFormant[3][2] / 2.0;
		allmojiFormant[0][1][12][3] = privateFormant[3][3];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][1][12][k] = allmojiFormant[1][0][12][k];
		//��������W�j��(��)
		allmojiFormant[0][1][13][0] = privateFormant[4][0];
		allmojiFormant[0][1][13][1] = privateFormant[4][1];
		allmojiFormant[0][1][13][2] = privateFormant[4][2] / 2.0;
		allmojiFormant[0][1][13][3] = privateFormant[4][3];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][1][13][k] = allmojiFormant[1][0][13][k];


		//�L������W�j��(��)
		allmojiFormant[0][2][1][0] = privateFormant[0][0];
		allmojiFormant[0][2][1][1] = privateFormant[0][1];
		allmojiFormant[0][2][1][2] = privateFormant[0][2] / 2.0;
		allmojiFormant[0][2][1][3] = privateFormant[0][3];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][2][1][k] = allmojiFormant[1][0][1][k];
		//�L������W�j��(�d�����)(��)
		for (int i = 2;i <= 6; i++) {
			allmojiFormant[0][2][i][0] = privateFormant[1][0];
			allmojiFormant[0][2][i][1] = privateFormant[1][1];
			allmojiFormant[0][2][i][2] = privateFormant[1][2] / 2.0;
			allmojiFormant[0][2][i][3] = privateFormant[1][3];
			for (int k = 0; k < 4;k++)
				allmojiFormant[1][2][i][k] = allmojiFormant[1][0][i][k];
		}
		//�L������W�j��(��)
		for (int i = 7;i <= 11; i++) {
			allmojiFormant[0][2][i][0] = privateFormant[2][0];
			allmojiFormant[0][2][i][1] = privateFormant[2][1];
			allmojiFormant[0][2][i][2] = privateFormant[2][2] / 2.0;
			allmojiFormant[0][2][i][3] = privateFormant[2][3];
			for (int k = 0; k < 4;k++)
				allmojiFormant[1][2][i][k] = allmojiFormant[1][0][i][k];
		}
		//�L������W�j��(��)
		allmojiFormant[0][2][12][0] = privateFormant[3][0];
		allmojiFormant[0][2][12][1] = privateFormant[3][1];
		allmojiFormant[0][2][12][2] = privateFormant[3][2] / 2.0;
		allmojiFormant[0][2][12][3] = privateFormant[3][3];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][2][12][k] = allmojiFormant[1][0][12][k];
		//�L������W�j��(��)
		allmojiFormant[0][2][13][0] = privateFormant[4][0];
		allmojiFormant[0][2][13][1] = privateFormant[4][1];
		allmojiFormant[0][2][13][2] = privateFormant[4][2] / 2.0;
		allmojiFormant[0][2][13][3] = privateFormant[4][3];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][2][13][k] = allmojiFormant[1][0][13][k];
	}

	//���s���C��(���`��)(3x,4x)
	if (true) {
		//�������s���C��(��)
		allmojiFormant[0][3][1][0] = privateFormant[0][0] / 1.5;
		allmojiFormant[0][3][1][1] = privateFormant[0][1] / 2.3;
		allmojiFormant[0][3][1][2] = privateFormant[0][2];
		allmojiFormant[0][3][1][3] = privateFormant[0][3];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][3][1][k] = allmojiFormant[1][0][1][k];
		//�������s�d���W���C��(��)
		for (int i = 2;i <= 6; i++) {
			allmojiFormant[0][3][i][0] = privateFormant[1][0] / 1.5;
			allmojiFormant[0][3][i][1] = privateFormant[1][1] / 2.3;
			allmojiFormant[0][3][i][2] = privateFormant[1][2];
			allmojiFormant[0][3][i][3] = privateFormant[1][3];
			for (int k = 0; k < 4;k++)
				allmojiFormant[1][3][i][k] = allmojiFormant[1][0][i][k];
		}
		//�������s���C��(��)
		for (int i = 7;i <= 11; i++) {
			allmojiFormant[0][3][i][0] = privateFormant[2][0] / 1.5;
			allmojiFormant[0][3][i][1] = privateFormant[2][1] / 2.3;
			allmojiFormant[0][3][i][2] = privateFormant[2][2];
			allmojiFormant[0][3][i][3] = privateFormant[2][3];
			for (int k = 0; k < 4;k++)
				allmojiFormant[1][3][i][k] = allmojiFormant[1][0][i][k];
		}
		//�������s���C��(��)
		allmojiFormant[0][3][12][0] = privateFormant[3][0] / 1.5;
		allmojiFormant[0][3][12][1] = privateFormant[3][1] / 2.3;
		allmojiFormant[0][3][12][2] = privateFormant[3][2];
		allmojiFormant[0][3][12][3] = privateFormant[3][3];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][3][12][k] = allmojiFormant[1][0][12][k];
		//�������s���C��(��)
		allmojiFormant[0][3][13][0] = privateFormant[4][0] / 1.5;
		allmojiFormant[0][3][13][1] = privateFormant[4][1] / 2.3;
		allmojiFormant[0][3][13][2] = privateFormant[4][2];
		allmojiFormant[0][3][13][3] = privateFormant[4][3];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][3][13][k] = allmojiFormant[1][0][13][k];


		//�L�����s���C��(��)
		allmojiFormant[0][4][1][0] = privateFormant[0][0] / 1.5;
		allmojiFormant[0][4][1][1] = privateFormant[0][1] / 2.3;
		allmojiFormant[0][4][1][2] = privateFormant[0][2];
		allmojiFormant[0][4][1][3] = privateFormant[0][3];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][4][1][k] = allmojiFormant[1][0][1][k];
		//�L�����s�d���W���C��(��)
		for (int i = 2;i <= 6; i++) {
			allmojiFormant[0][4][i][0] = privateFormant[1][0] / 1.5;
			allmojiFormant[0][4][i][1] = privateFormant[1][1] / 2.3;
			allmojiFormant[0][4][i][2] = privateFormant[1][2];
			allmojiFormant[0][4][i][3] = privateFormant[1][3];
			for (int k = 0; k < 4;k++)
				allmojiFormant[1][4][i][k] = allmojiFormant[1][0][i][k];
		}
		//�L�����s���C��(��)
		for (int i = 7;i <= 11; i++) {
			allmojiFormant[0][4][i][0] = privateFormant[2][0] / 1.5;
			allmojiFormant[0][4][i][1] = privateFormant[2][1] / 2.3;
			allmojiFormant[0][4][i][2] = privateFormant[2][2];
			allmojiFormant[0][4][i][3] = privateFormant[2][3];
			for (int k = 0; k < 4;k++)
				allmojiFormant[1][4][i][k] = allmojiFormant[1][0][i][k];
		}
		//�L�����s���C��(��)
		allmojiFormant[0][4][12][0] = privateFormant[3][0] / 1.5;
		allmojiFormant[0][4][12][1] = privateFormant[3][1] / 2.3;
		allmojiFormant[0][4][12][2] = privateFormant[3][2];
		allmojiFormant[0][4][12][3] = privateFormant[3][3];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][4][12][k] = allmojiFormant[1][0][12][k];
		//�L�����s���C��(��)
		allmojiFormant[0][4][13][0] = privateFormant[4][0] / 1.5;
		allmojiFormant[0][4][13][1] = privateFormant[4][1] / 2.3;
		allmojiFormant[0][4][13][2] = privateFormant[4][2];
		allmojiFormant[0][4][13][3] = privateFormant[4][3];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][4][13][k] = allmojiFormant[1][0][13][k];
	}

	//���s�j��(���`��)(5x,6x)
	if (true) {
		//�������s�j��(��)
		allmojiFormant[0][5][1][0] = privateFormant[0][0] / 1.5;
		allmojiFormant[0][5][1][1] = privateFormant[0][1] / 2.3;
		allmojiFormant[0][5][1][2] = privateFormant[0][2];
		allmojiFormant[0][5][1][3] = privateFormant[0][3];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][5][1][k] = allmojiFormant[1][0][1][k];
		//�������s�d���W�j�C��(��)
		for (int i = 2;i <= 6; i++) {
			allmojiFormant[0][5][i][0] = privateFormant[1][0] / 1.5;
			allmojiFormant[0][5][i][1] = privateFormant[1][1] / 2.3;
			allmojiFormant[0][5][i][2] = privateFormant[1][2];
			allmojiFormant[0][5][i][3] = privateFormant[1][3];
			for (int k = 0; k < 4;k++)
				allmojiFormant[1][5][i][k] = allmojiFormant[1][0][i][k];
		}
		//�������s�j�C��(��)
		for (int i = 7;i <= 11; i++) {
			allmojiFormant[0][5][i][0] = privateFormant[2][0] / 1.5;
			allmojiFormant[0][5][i][1] = privateFormant[2][1] / 2.3;
			allmojiFormant[0][5][i][2] = privateFormant[2][2];
			allmojiFormant[0][5][i][3] = privateFormant[2][3];
			for (int k = 0; k < 4;k++)
				allmojiFormant[1][5][i][k] = allmojiFormant[1][0][i][k];
		}
		//�������s�j��(��)
		allmojiFormant[0][5][12][0] = privateFormant[3][0] / 1.5;
		allmojiFormant[0][5][12][1] = privateFormant[3][1] / 2.3;
		allmojiFormant[0][5][12][2] = privateFormant[3][2];
		allmojiFormant[0][5][12][3] = privateFormant[3][3];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][5][12][k] = allmojiFormant[1][0][12][k];
		//�������s�j��(��)
		allmojiFormant[0][5][13][0] = privateFormant[4][0] / 1.5;
		allmojiFormant[0][5][13][1] = privateFormant[4][1] / 2.3;
		allmojiFormant[0][5][13][2] = privateFormant[4][2];
		allmojiFormant[0][5][13][3] = privateFormant[4][3];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][5][13][k] = allmojiFormant[1][0][13][k];


		//�L�����s�j��(��)
		allmojiFormant[0][6][1][0] = privateFormant[0][0] / 1.5;
		allmojiFormant[0][6][1][1] = privateFormant[0][1] / 2.3;
		allmojiFormant[0][6][1][2] = privateFormant[0][2];
		allmojiFormant[0][6][1][3] = privateFormant[0][3];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][6][1][k] = allmojiFormant[1][0][1][k];
		//�L�����s�d���W�j�C��(��)
		for (int i = 2;i <= 6; i++) {
			allmojiFormant[0][6][i][0] = privateFormant[1][0] / 1.5;
			allmojiFormant[0][6][i][1] = privateFormant[1][1] / 2.3;
			allmojiFormant[0][6][i][2] = privateFormant[1][2];
			allmojiFormant[0][6][i][3] = privateFormant[1][3];
			for (int k = 0; k < 4;k++)
				allmojiFormant[1][6][i][k] = allmojiFormant[1][0][i][k];
		}
		//�L�����s�j�C��(��)
		for (int i = 7;i <= 11; i++) {
			allmojiFormant[0][6][i][0] = privateFormant[2][0] / 1.5;
			allmojiFormant[0][6][i][1] = privateFormant[2][1] / 2.3;
			allmojiFormant[0][6][i][2] = privateFormant[2][2];
			allmojiFormant[0][6][i][3] = privateFormant[2][3];
			for (int k = 0; k < 4;k++)
				allmojiFormant[1][6][i][k] = allmojiFormant[1][0][i][k];
		}
		//�L�����s�j��(��)
		allmojiFormant[0][6][12][0] = privateFormant[3][0] / 1.5;
		allmojiFormant[0][6][12][1] = privateFormant[3][1] / 2.3;
		allmojiFormant[0][6][12][2] = privateFormant[3][2];
		allmojiFormant[0][6][12][3] = privateFormant[3][3];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][6][12][k] = allmojiFormant[1][0][12][k];
		//�L�����s�j��(��)
		allmojiFormant[0][6][13][0] = privateFormant[4][0] / 1.5;
		allmojiFormant[0][6][13][1] = privateFormant[4][1] / 2.3;
		allmojiFormant[0][6][13][2] = privateFormant[4][2];
		allmojiFormant[0][6][13][3] = privateFormant[4][3];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][6][13][k] = allmojiFormant[1][0][13][k];
	}

	//���O�j��(�ρ`��)(7x,8x)
	if (true) {
		//�������O�j��(��)
		allmojiFormant[0][7][1][0] = privateFormant[0][0];
		allmojiFormant[0][7][1][1] = privateFormant[0][1] / 2.0;
		allmojiFormant[0][7][1][2] = privateFormant[0][2];
		allmojiFormant[0][7][1][3] = privateFormant[0][3];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][7][1][k] = allmojiFormant[1][0][1][k];
		//�L�����O�d���W�ڋ߉�(��)
		for (int i = 2;i <= 6; i++) {
			allmojiFormant[0][7][i][0] = privateFormant[1][0];
			allmojiFormant[0][7][i][1] = privateFormant[1][1] / 2.0;
			allmojiFormant[0][7][i][2] = privateFormant[1][2];
			allmojiFormant[0][7][i][3] = privateFormant[1][3];
			for (int k = 0; k < 4;k++)
				allmojiFormant[1][7][i][k] = allmojiFormant[1][0][i][k];
		}
		//�������O�j��(��)
		for (int i = 7;i <= 11; i++) {
			allmojiFormant[0][7][i][0] = privateFormant[2][0];
			allmojiFormant[0][7][i][1] = privateFormant[2][1] / 2.0;
			allmojiFormant[0][7][i][2] = privateFormant[2][2];
			allmojiFormant[0][7][i][3] = privateFormant[2][3];
			for (int k = 0; k < 4;k++)
				allmojiFormant[1][7][i][k] = allmojiFormant[1][0][i][k];
		}
		//�������O�j��(��)
		allmojiFormant[0][7][12][0] = privateFormant[3][0];
		allmojiFormant[0][7][12][1] = privateFormant[3][1] / 2.0;
		allmojiFormant[0][7][12][2] = privateFormant[3][2];
		allmojiFormant[0][7][12][3] = privateFormant[3][3];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][7][12][k] = allmojiFormant[1][0][12][k];
		//�������O�j��(��)
		allmojiFormant[0][7][13][0] = privateFormant[4][0];
		allmojiFormant[0][7][13][1] = privateFormant[4][1] / 2.0;
		allmojiFormant[0][7][13][2] = privateFormant[4][2];
		allmojiFormant[0][7][13][3] = privateFormant[4][3];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][7][13][k] = allmojiFormant[1][0][13][k];


		//�L�����O�j��(��)
		allmojiFormant[0][8][1][0] = privateFormant[0][0];
		allmojiFormant[0][8][1][1] = privateFormant[0][1] / 2.0;
		allmojiFormant[0][8][1][2] = privateFormant[0][2];
		allmojiFormant[0][8][1][3] = privateFormant[0][3];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][8][1][k] = allmojiFormant[1][0][1][k];
		//�L�����O�d���W�j��(��)
		for (int i = 2;i <= 6; i++) {
			allmojiFormant[0][8][i][0] = privateFormant[1][0];
			allmojiFormant[0][8][i][1] = privateFormant[1][1] / 2.0;
			allmojiFormant[0][8][i][2] = privateFormant[1][2];
			allmojiFormant[0][8][i][3] = privateFormant[1][3];
			for (int k = 0; k < 4;k++)
				allmojiFormant[1][8][i][k] = allmojiFormant[1][0][i][k];
		}
		//�L�����O�j��(��)
		for (int i = 7;i <= 11; i++) {
			allmojiFormant[0][8][i][0] = privateFormant[2][0];
			allmojiFormant[0][8][i][1] = privateFormant[2][1] / 2.0;
			allmojiFormant[0][8][i][2] = privateFormant[2][2];
			allmojiFormant[0][8][i][3] = privateFormant[2][3];
			for (int k = 0; k < 4;k++)
				allmojiFormant[1][8][i][k] = allmojiFormant[1][0][i][k];
		}
		//�L�����O�j��(��)
		allmojiFormant[0][8][12][0] = privateFormant[3][0];
		allmojiFormant[0][8][12][1] = privateFormant[3][1] / 2.0;
		allmojiFormant[0][8][12][2] = privateFormant[3][2];
		allmojiFormant[0][8][12][3] = privateFormant[3][3];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][8][12][k] = allmojiFormant[1][0][12][k];
		//�L�����O�j��(��)
		allmojiFormant[0][8][13][0] = privateFormant[4][0];
		allmojiFormant[0][8][13][1] = privateFormant[4][1] / 2.0;
		allmojiFormant[0][8][13][2] = privateFormant[4][2];
		allmojiFormant[0][8][13][3] = privateFormant[4][3];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][8][13][k] = allmojiFormant[1][0][13][k];
	}

	//���E��(��)(�́`��)(9x)
	if (true) {
		//�������喀�C��(��)
		//�����d���W���C��(��)
		//�������O���C��(��)
		//�������喀�C��(��)
		//�������喀�C��(��)
		for (int i = 0;i < 15;i++)
			for (int j = 0; j < 2;j++)
				for (int k = 0; k < 4;k++)
					allmojiFormant[j][9][i][k] = allmojiFormant[j][0][i][k];
	}

	//���s�@��(�ȁ`��)(ax)
	if (true) {
		//���s�@��(��)
		allmojiFormant[0][10][1][0] = privateFormant[0][0] / 2.0;
		allmojiFormant[0][10][1][1] = privateFormant[0][1] / 3.0;
		allmojiFormant[0][10][1][2] = privateFormant[0][2];
		allmojiFormant[0][10][1][3] = privateFormant[0][3];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][10][1][k] = allmojiFormant[1][0][1][k];
		//�d���W�@��(��)
		for (int i = 2;i <= 6; i++) {
			allmojiFormant[0][10][i][0] = privateFormant[1][0] / 2.0;
			allmojiFormant[0][10][i][1] = privateFormant[1][1] / 3.0;
			allmojiFormant[0][10][i][2] = privateFormant[1][2];
			allmojiFormant[0][10][i][3] = privateFormant[1][3];
			for (int k = 0; k < 4;k++)
				allmojiFormant[1][10][i][k] = allmojiFormant[1][0][i][k];
		}
		//���s�@��(��)
		for (int i = 7;i <= 11; i++) {
			allmojiFormant[0][10][i][0] = privateFormant[2][0] / 2.0;
			allmojiFormant[0][10][i][1] = privateFormant[2][1] / 3.0;
			allmojiFormant[0][10][i][2] = privateFormant[2][2];
			allmojiFormant[0][10][i][3] = privateFormant[2][3];
			for (int k = 0; k < 4;k++)
				allmojiFormant[1][10][i][k] = allmojiFormant[1][0][i][k];
		}
		//���s�@��(��)
		allmojiFormant[0][10][12][0] = privateFormant[3][0] / 2.0;
		allmojiFormant[0][10][12][1] = privateFormant[3][1] / 3.0;
		allmojiFormant[0][10][12][2] = privateFormant[3][2];
		allmojiFormant[0][10][12][3] = privateFormant[3][3];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][10][12][k] = allmojiFormant[1][0][12][k];
		//���s�@��(��)
		allmojiFormant[0][10][13][0] = privateFormant[4][0] / 2.0;
		allmojiFormant[0][10][13][1] = privateFormant[4][1] / 3.0;
		allmojiFormant[0][10][13][2] = privateFormant[4][2];
		allmojiFormant[0][10][13][3] = privateFormant[4][3];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][10][13][k] = allmojiFormant[1][0][13][k];
	}

	//���O�@��(�܁`��)(bx)
	if (true) {
		//���O�@��(��)
		allmojiFormant[0][11][1][0] = privateFormant[0][0] / 3.0;
		allmojiFormant[0][11][1][1] = privateFormant[0][1] / 2.0;
		allmojiFormant[0][11][1][2] = privateFormant[0][2];
		allmojiFormant[0][11][1][3] = privateFormant[0][3];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][11][1][k] = allmojiFormant[1][0][1][k];
		//���O�@��(��)
		for (int i = 2;i <= 6; i++) {
			allmojiFormant[0][11][i][0] = privateFormant[1][0] / 3.0;
			allmojiFormant[0][11][i][1] = privateFormant[1][1] / 2.0;
			allmojiFormant[0][11][i][2] = privateFormant[1][2];
			allmojiFormant[0][11][i][3] = privateFormant[1][3];
			for (int k = 0; k < 4;k++)
				allmojiFormant[1][11][i][k] = allmojiFormant[1][0][i][k];
		}
		//���O�@��(��)
		for (int i = 7;i <= 11; i++) {
			allmojiFormant[0][11][i][0] = privateFormant[2][0] / 3.0;
			allmojiFormant[0][11][i][1] = privateFormant[2][1] / 2.0;
			allmojiFormant[0][11][i][2] = privateFormant[2][2];
			allmojiFormant[0][11][i][3] = privateFormant[2][3];
			for (int k = 0; k < 4;k++)
				allmojiFormant[1][11][i][k] = allmojiFormant[1][0][i][k];
		}
		//���O�@��(��)
		allmojiFormant[0][11][12][0] = privateFormant[3][0] / 3.0;
		allmojiFormant[0][11][12][1] = privateFormant[3][1] / 2.0;
		allmojiFormant[0][11][12][2] = privateFormant[3][2];
		allmojiFormant[0][11][12][3] = privateFormant[3][3];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][11][12][k] = allmojiFormant[1][0][12][k];
		//���O�@��(��)
		allmojiFormant[0][11][13][0] = privateFormant[4][0] / 3.0;
		allmojiFormant[0][11][13][1] = privateFormant[4][1] / 2.0;
		allmojiFormant[0][11][13][2] = privateFormant[4][2];
		allmojiFormant[0][11][13][3] = privateFormant[4][3];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][11][13][k] = allmojiFormant[1][0][13][k];
	}

	//�L�����s�͂�����(��`��)(cx)
	if (true) {
		//�L�����s�͂�����(��)
		allmojiFormant[0][12][1][0] = privateFormant[0][0] / 1.5;
		allmojiFormant[0][12][1][1] = privateFormant[0][1] / 2.3;
		allmojiFormant[0][12][1][2] = privateFormant[0][2];
		allmojiFormant[0][12][1][3] = privateFormant[0][3];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][12][1][k] = allmojiFormant[1][0][1][k];
		//���s�d���W�͂�����(��)
		for (int i = 2;i <= 6; i++) {
			allmojiFormant[0][12][i][0] = privateFormant[1][0] / 1.5;
			allmojiFormant[0][12][i][1] = privateFormant[1][1] / 2.3;
			allmojiFormant[0][12][i][2] = privateFormant[1][2];
			allmojiFormant[0][12][i][3] = privateFormant[1][3];
			for (int k = 0; k < 4;k++)
				allmojiFormant[1][12][i][k] = allmojiFormant[1][0][i][k];
		}
		//�L�����s�͂�����(��)
		for (int i = 7;i <= 11; i++) {
			allmojiFormant[0][12][i][0] = privateFormant[2][0] / 1.5;
			allmojiFormant[0][12][i][1] = privateFormant[2][1] / 2.3;
			allmojiFormant[0][12][i][2] = privateFormant[2][2];
			allmojiFormant[0][12][i][3] = privateFormant[2][3];
			for (int k = 0; k < 4;k++)
				allmojiFormant[1][12][i][k] = allmojiFormant[1][0][i][k];
		}
		//�L�����s�͂�����(��)
		allmojiFormant[0][12][12][0] = privateFormant[3][0] / 1.5;
		allmojiFormant[0][12][12][1] = privateFormant[3][1] / 2.3;
		allmojiFormant[0][12][12][2] = privateFormant[3][2];
		allmojiFormant[0][12][12][3] = privateFormant[3][3];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][12][12][k] = allmojiFormant[1][0][12][k];
		//�L�����s�͂�����(��)
		allmojiFormant[0][12][13][0] = privateFormant[4][0] / 1.5;
		allmojiFormant[0][12][13][1] = privateFormant[4][1] / 2.3;
		allmojiFormant[0][12][13][2] = privateFormant[4][2];
		allmojiFormant[0][12][13][3] = privateFormant[4][3];
		for (int k = 0; k < 4;k++)
			allmojiFormant[1][12][13][k] = allmojiFormant[1][0][13][k];
	}

	//��
	if (true) {
		//���W���@��(��)
		allmojiFormant[0][13][1][0] = allmojiFormant[1][13][1][0] = privateFormant[2][0] / 2.0;
		allmojiFormant[0][13][1][1] = allmojiFormant[1][13][1][1] = privateFormant[2][1] / 3.0;
		allmojiFormant[0][13][1][2] = allmojiFormant[1][13][1][2] = privateFormant[2][2];
		allmojiFormant[0][13][1][3] = allmojiFormant[1][13][1][3] = privateFormant[2][3];
	}

	return 0;
}

//���}�R�[�h����t�H���}���g���g�����擾
nsfloat makeVoiseFromFile::getMojiFormant(int f, int moji, int formant) {

	return allmojiFormant[f][(moji & 0xf0) >> 4][(moji & 0x0f)][formant];
}

//�����j�􉹂��ǂ���
bool makeVoiseFromFile::doVoiselessPlosive(NSCHAR moji) {

	if ((moji & 0xf0) == 0x10 or (moji & 0xf0) == 0x50 or (moji & 0xf0) == 0x70)
		return true;
	return false;
}

//�L���j�􉹂��ǂ���
bool makeVoiseFromFile::doVoisedPlosive(NSCHAR moji) {

	if ((moji & 0xf0) == 0x20 or (moji & 0xf0) == 0x60 or (moji & 0xf0) == 0x80)
		return true;
	return false;
}

//�@�����ǂ���
bool makeVoiseFromFile::doNasal(NSCHAR moji) {

	if ((moji & 0xf0) == 0xa0 or (moji & 0xf0) == 0xb0)
		return true;
	return false;
}

//�͂��������ǂ���
bool makeVoiseFromFile::doTap(NSCHAR moji) {

	if ((moji & 0xf0) == 0xc0)
		return true;
	return false;
}

//�������C�����ǂ���
bool makeVoiseFromFile::doVoiselessFricative(NSCHAR moji) {

	if ((moji & 0xf0) == 0x30)
		return true;
	return false;
}

//�L�����C�����ǂ���
bool makeVoiseFromFile::doVoisedFricative(NSCHAR moji) {

	if ((moji & 0xf0) == 0x40)
		return true;
	return false;
}

//���E�����ǂ���
bool makeVoiseFromFile::doFriKILLive(NSCHAR moji) {

	if ((moji & 0xf0) == 0x90)
		return true;
	return false;
}

//���}�`���̎��ԒP�ʂ��琺�̒���[�b]�֕ϊ�
int makeVoiseFromFile::getTimeFromSpeed(char speed, char moji) {
	char mojiboin = moji & 0x0f;
	return (int)((nsfloat)SMPL * (10.0 / (nsfloat)speed) + ((mojiboin >= 0x03 and mojiboin <= 0x0b and mojiboin != 0x07 and (unsigned char)moji >= 0x10 and (nsfloat)SMPL * (10.0 / (nsfloat)speed) > MAXSHIONSPEED + MAXBYOUONSPEED + MAXYOUONSPEED) ? MAXBYOUONSPEED + MAXYOUONSPEED : 0));
}

//�z���C�g�m�C�Y�̗����̓�����������
int makeVoiseFromFile::ftInit(int size) {

	ft = new nsfloat[size];

	for (int i = 0; i < size;i++)
		ft[i] = (nsfloat)rand() / RAND_MAX * 2.0 * PI;

	return 0;
}

//�z���C�g�m�C�Y���쐬
int makeVoiseFromFile::makeWhitenoise(std::vector<nsfloat> out, int time, nsfloat hz, nsfloat um) {

	nsfloat magn = FRICATIVENOISEACC / (nsfloat)(MAXFREQ - hz);

	std::vector<nsfloat> out1(out.size(), 0.0), out2(out.size(), 0.0);

	for (int j = 0; j < out.size();j++) {
		for (int i = (int)hz; i < MAXFREQ;i += FRICATIVENOISEACC)
			out1[j] += sin(((nsfloat)i + (nsfloat)time + ft[i]) * 2.0 * (nsfloat)PI / ((nsfloat)SMPL / (nsfloat)i));
	}
	nsfloat max = mvffMMVF.mostMax(out1);
	magn = 1.0 / max;
	for (int i = 0; i < out.size();i++)
		out1[i] *= magn;


	hipassFilter(out1, out2, SMPL, hz, 0.707);
	lowpassFilter(out2, out, SMPL, um, 1.0);

	return 0;
}

//�z���C�g�m�C�Y���쐬
int makeVoiseFromFile::makeWhitenoise1(std::vector<nsfloat> out, int time, nsfloat hz) {

	nsfloat magn = FRICATIVENOISEACC / (nsfloat)(MAXFREQ - hz);

	std::vector<nsfloat> out1(out.size(), 0.0), out2(out.size(), 0.0);

	for (int j = 0; j < out.size();j++) {

		for (int i = (int)hz; i < MAXFREQ;i += FRICATIVENOISEACC)
			out1[j] += (POW2(sin(((nsfloat)i + (nsfloat)time + ft[j]) * 2.0 * (nsfloat)PI / ((nsfloat)SMPL / (nsfloat)i))) / POW2(i + hz));
	}
	nsfloat max = mvffMMVF.mostMax(out1);
	magn = 1.0 / max;
	for (int i = 0; i < out.size();i++)
		out1[i] *= magn;

	hipassFilter(out1, out2, SMPL, hz - FRICATIVENOISESCOPE, 0.707);
	lowpassFilter(out2, out, SMPL, hz - FRICATIVENOISESCOPE, 1.0);

	return 0;
}




