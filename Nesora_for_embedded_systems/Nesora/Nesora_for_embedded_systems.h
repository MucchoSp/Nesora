#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <fstream>
#include <iostream>
#include <vector>


// +--------------------------------------------------------------------------------------------+
// |	���}�R�[�h�֌W																			|
// +--------------------------------------------------------------------------------------------+


//���}�R�[�h�̒萔�Q
// 
//NS[����������]
// 
//�Ŏg�����Ƃ��ł��܂��B


//�ꉹ
#define NSNULL			0x00			//���}�R�[�hNULL�E�I�[����
#define NS��			0x01			//���}�R�[�h��
#define NS��			0x02			//���}�R�[�h��
#define NS��			0x03			//���}�R�[�h��
#define NS��			0x04			//���}�R�[�h��
#define NS����			0x05			//���}�R�[�h����
#define NS��			0x06			//���}�R�[�h��
#define NS��			0x07			//���}�R�[�h��
#define NS��			0x08			//���}�R�[�h��
#define NS��			0x09			//���}�R�[�h��
#define NS����			0x09			//���}�R�[�h��
#define NS��			0x0a			//���}�R�[�h��
#define NS����			0x0a			//���}�R�[�h��
#define NS��			0x0b			//���}�R�[�h��
#define NS��			0x0c			//���}�R�[�h��
#define NS��			0x0d			//���}�R�[�h��
#define NS_0e			0x0e			//���}�R�[�h����`
#define NS_0f			0x0f			//���}�R�[�h����`

//�j��
#define NSk				0x10			//���}�R�[�hk
#define NS��			0x11			//���}�R�[�h��
#define NS��			0x12			//���}�R�[�h��
#define NS����			0x13			//���}�R�[�h����
#define NS����			0x14			//���}�R�[�h����
#define NS����			0x15			//���}�R�[�h����
#define NS����			0x16			//���}�R�[�h����
#define NS��			0x17			//���}�R�[�h��
#define NS����			0x18			//���}�R�[�h����
#define NS����			0x18			//���}�R�[�h����
#define NS����			0x19			//���}�R�[�h����
#define NS����			0x1a			//���}�R�[�h����
#define NS����			0x1b			//���}�R�[�h����
#define NS��			0x1c			//���}�R�[�h��
#define NS��			0x1d			//���}�R�[�h��
#define NS_1e			0x1e			//���}�R�[�h����`
#define NS_1f			0x1f			//���}�R�[�h����`

#define NSg				0x20			//���}�R�[�hg
#define NS��			0x21			//���}�R�[�h��
#define NS��			0x22			//���}�R�[�h��
#define NS����			0x23			//���}�R�[�h����
#define NS����			0x24			//���}�R�[�h����
#define NS����			0x25			//���}�R�[�h����
#define NS����			0x26			//���}�R�[�h����
#define NS��			0x27			//���}�R�[�h��
#define NS����			0x28			//���}�R�[�h����
#define NS����			0x28			//���}�R�[�h����
#define NS����			0x29			//���}�R�[�h����
#define NS����			0x2a			//���}�R�[�h����
#define NS����			0x2b			//���}�R�[�h����
#define NS��			0x2c			//���}�R�[�h��
#define NS��			0x2d			//���}�R�[�h��
#define NS_2e			0x2e			//���}�R�[�h����`
#define NS_2f			0x2f			//���}�R�[�h����`

#define NSt				0x30			//���}�R�[�ht
#define NS��			0x31			//���}�R�[�h��
#define NS��			0x32			//���}�R�[�h��
#define NS����			0x33			//���}�R�[�h����
#define NS����			0x34			//���}�R�[�h����
#define NS����			0x35			//���}�R�[�h����
#define NS����			0x36			//���}�R�[�h����
#define NS��			0x37			//���}�R�[�h��
#define NS��			0x38			//���}�R�[�h��
#define NS��			0x38			//���}�R�[�h��
#define NS��			0x39			//���}�R�[�h��
#define NS��			0x3a			//���}�R�[�h��
#define NS��			0x3b			//���}�R�[�h��
#define NS��			0x3c			//���}�R�[�h��
#define NS��			0x3d			//���}�R�[�h��
#define NS_3e			0x3e			//���}�R�[�h����`
#define NS_3f			0x3f			//���}�R�[�h����`

#define NSd				0x40			//���}�R�[�hd
#define NS��			0x41			//���}�R�[�h��
#define NS��			0x42			//���}�R�[�h��
#define NS����			0x43			//���}�R�[�h����
#define NS����			0x44			//���}�R�[�h����
#define NS����			0x45			//���}�R�[�h����
#define NS����			0x46			//���}�R�[�h����
#define NS��			0x47			//���}�R�[�h��
#define NS�Â�			0x48			//���}�R�[�h�Â�
#define NS�Â�			0x48			//���}�R�[�h�Â�
#define NS�Â�			0x49			//���}�R�[�h�Â�
#define NS�Â�			0x4a			//���}�R�[�h�Â�
#define NS�Â�			0x4b			//���}�R�[�h�Â�
#define NS��			0x4c			//���}�R�[�h��
#define NS��			0x4d			//���}�R�[�h��
#define NS_4e			0x4e			//���}�R�[�h����`
#define NS_4f			0x4f			//���}�R�[�h����`

#define NSp				0x50			//���}�R�[�hp
#define NS��			0x51			//���}�R�[�h��
#define NS��			0x52			//���}�R�[�h��
#define NS�҂�			0x53			//���}�R�[�h�҂�
#define NS�҂�			0x54			//���}�R�[�h�҂�
#define NS�҂�			0x55			//���}�R�[�h�҂�
#define NS�҂�			0x56			//���}�R�[�h�҂�
#define NS��			0x57			//���}�R�[�h��
#define NS�Ղ�			0x58			//���}�R�[�h�Ղ�
#define NS�Ղ�			0x58			//���}�R�[�h�Ղ�
#define NS�Ղ�			0x59			//���}�R�[�h�Ղ�
#define NS�Ղ�			0x5a			//���}�R�[�h�Ղ�
#define NS�Ղ�			0x5b			//���}�R�[�h�Ղ�
#define NS��			0x5c			//���}�R�[�h��
#define NS��			0x5d			//���}�R�[�h��
#define NS_5e			0x5e			//���}�R�[�h����`
#define NS_5f			0x5f			//���}�R�[�h����`

#define NSb				0x60			//���}�R�[�hb
#define NS��			0x61			//���}�R�[�h��
#define NS��			0x62			//���}�R�[�h��
#define NS�т�			0x63			//���}�R�[�h�т�
#define NS�т�			0x64			//���}�R�[�h�т�
#define NS�т�			0x65			//���}�R�[�h�т�
#define NS�т�			0x66			//���}�R�[�h�т�
#define NS��			0x67			//���}�R�[�h��
#define NS�Ԃ�			0x68			//���}�R�[�h�Ԃ�
#define NS�Ԃ�			0x68			//���}�R�[�h�Ԃ�
#define NS�Ԃ�			0x69			//���}�R�[�h�Ԃ�
#define NS�Ԃ�			0x6a			//���}�R�[�h�Ԃ�
#define NS�Ԃ�			0x6b			//���}�R�[�h�Ԃ�
#define NS��			0x6c			//���}�R�[�h��
#define NS��			0x6d			//���}�R�[�h��
#define NS_6e			0x6e			//���}�R�[�h����`
#define NS_6f			0x6f			//���}�R�[�h����`

//���C��
#define NSs				0x70			//���}�R�[�hs
#define NS��			0x71			//���}�R�[�h��
#define NS��			0x72			//���}�R�[�h��
#define NS����			0x73			//���}�R�[�h����
#define NS����			0x74			//���}�R�[�h����
#define NS����			0x75			//���}�R�[�h����
#define NS����			0x76			//���}�R�[�h����
#define NS��			0x77			//���}�R�[�h��
#define NS����			0x78			//���}�R�[�h����
#define NS����			0x78			//���}�R�[�h����
#define NS����			0x79			//���}�R�[�h����
#define NS����			0x7a			//���}�R�[�h����
#define NS����			0x7b			//���}�R�[�h����
#define NS��			0x7c			//���}�R�[�h��
#define NS��			0x7d			//���}�R�[�h��
#define NS_7e			0x7e			//���}�R�[�h����`
#define NS_7f			0x7f			//���}�R�[�h����`

#define NSz				0x80			//���}�R�[�hz
#define NS��			0x81			//���}�R�[�h��
#define NS��			0x82			//���}�R�[�h��
#define NS����			0x83			//���}�R�[�h����
#define NS����			0x84			//���}�R�[�h����
#define NS����			0x85			//���}�R�[�h����
#define NS����			0x86			//���}�R�[�h����
#define NS��			0x87			//���}�R�[�h��
#define NS����			0x88			//���}�R�[�h����
#define NS����			0x88			//���}�R�[�h����
#define NS����			0x89			//���}�R�[�h����
#define NS����			0x8a			//���}�R�[�h����
#define NS����			0x8b			//���}�R�[�h����
#define NS��			0x8c			//���}�R�[�h��
#define NS��			0x8d			//���}�R�[�h��
#define NS_8e			0x8e			//���}�R�[�h����`
#define NS_8f			0x8f			//���}�R�[�h����`

#define NSh				0x90			//���}�R�[�hh
#define NS��			0x91			//���}�R�[�h��
#define NS��			0x92			//���}�R�[�h��
#define NS�Ђ�			0x93			//���}�R�[�h�Ђ�
#define NS�Ђ�			0x94			//���}�R�[�h�Ђ�
#define NS�Ђ�			0x95			//���}�R�[�h�Ђ�
#define NS�Ђ�			0x96			//���}�R�[�h�Ђ�
#define NS��			0x97			//���}�R�[�h��
#define NS�ӂ�			0x98			//���}�R�[�h�ӂ�
#define NS�ӂ�			0x98			//���}�R�[�h�ӂ�
#define NS�ӂ�			0x99			//���}�R�[�h�ӂ�
#define NS�ӂ�			0x9a			//���}�R�[�h�ӂ�
#define NS�ӂ�			0x9b			//���}�R�[�h�ӂ�
#define NS��			0x9c			//���}�R�[�h��
#define NS��			0x9d			//���}�R�[�h��
#define NS_9e			0x9e			//���}�R�[�h����`
#define NS_9f			0x9f			//���}�R�[�h����`

//�@��
#define NSn				0xa0			//���}�R�[�hn
#define NS��			0xa1			//���}�R�[�h��
#define NS��			0xa2			//���}�R�[�h��
#define NS�ɂ�			0xa3			//���}�R�[�h�ɂ�
#define NS�ɂ�			0xa4			//���}�R�[�h�ɂ�
#define NS�ɂ�			0xa5			//���}�R�[�h�ɂ�
#define NS�ɂ�			0xa6			//���}�R�[�h�ɂ�
#define NS��			0xa7			//���}�R�[�h��
#define NS�ʂ�			0xa8			//���}�R�[�h�ʂ�
#define NS�ʂ�			0xa8			//���}�R�[�h�ʂ�
#define NS�ʂ�			0xa9			//���}�R�[�h�ʂ�
#define NS�ʂ�			0xaa			//���}�R�[�h�ʂ�
#define NS�ʂ�			0xab			//���}�R�[�h�ʂ�
#define NS��			0xac			//���}�R�[�h��
#define NS��			0xad			//���}�R�[�h��
#define NS_ae			0xae			//���}�R�[�h����`
#define NS_af			0xaf			//���}�R�[�h����`

#define NSm				0xb0			//���}�R�[�hm
#define NS��			0xb1			//���}�R�[�h��
#define NS��			0xb2			//���}�R�[�h��
#define NS�݂�			0xb3			//���}�R�[�h�݂�
#define NS�݂�			0xb4			//���}�R�[�h�݂�
#define NS�݂�			0xb5			//���}�R�[�h�݂�
#define NS�݂�			0xb6			//���}�R�[�h�݂�
#define NS��			0xb7			//���}�R�[�h��
#define NS�ނ�			0xb8			//���}�R�[�h�ނ�
#define NS�ނ�			0xb8			//���}�R�[�h�ނ�
#define NS�ނ�			0xb9			//���}�R�[�h�ނ�
#define NS�ނ�			0xba			//���}�R�[�h�ނ�
#define NS�ނ�			0xbb			//���}�R�[�h�ނ�
#define NS��			0xbc			//���}�R�[�h��
#define NS��			0xbd			//���}�R�[�h��
#define NS_be			0xbe			//���}�R�[�h����`
#define NS_bf			0xbf			//���}�R�[�h����`

//�͂�����
#define NSr				0xc0			//���}�R�[�hr
#define NS��			0xc1			//���}�R�[�h��
#define NS��			0xc2			//���}�R�[�h��
#define NS���			0xc3			//���}�R�[�h���
#define NS���			0xc4			//���}�R�[�h���
#define NS�肥			0xc5			//���}�R�[�h�肥
#define NS���			0xc6			//���}�R�[�h���
#define NS��			0xc7			//���}�R�[�h��
#define NS���			0xc8			//���}�R�[�h���
#define NS�邟			0xc8			//���}�R�[�h�邟
#define NS�邡			0xc9			//���}�R�[�h�邡
#define NS�邥			0xca			//���}�R�[�h�邥
#define NS�邧			0xcb			//���}�R�[�h�邧
#define NS��			0xcc			//���}�R�[�h��
#define NS��			0xcd			//���}�R�[�h��
#define NS_ce			0xce			//���}�R�[�h����`
#define NS_cf			0xcf			//���}�R�[�h����`

//��
#define NSnn			0xd0			//���}�R�[�hnn
#define NS��1			0xd1			//���}�R�[�h��1
#define NS��2			0xd2			//���}�R�[�h��2
#define NS_d3			0xd3			//���}�R�[�h����`
#define NS_d4			0xd4			//���}�R�[�h����`
#define NS_d5			0xd5			//���}�R�[�h����`
#define NS_d6			0xd6			//���}�R�[�h����`
#define NS_d7			0xd7			//���}�R�[�h����`
#define NS_d8			0xd8			//���}�R�[�h����`
#define NS_d9			0xd9			//���}�R�[�h����`
#define NS_da			0xda			//���}�R�[�h����`
#define NS_db			0xdb			//���}�R�[�h����`
#define NS_dc			0xdc			//���}�R�[�h����`
#define NS_dd			0xdd			//���}�R�[�h����`
#define NS_de			0xde			//���}�R�[�h����`
#define NS_df			0xdf			//���}�R�[�h����`

//���̑�
#define NS_e0			0xe0			//���}�R�[�h����`
#define NS��			0xe1			//���}�R�[�h��
#define NS��			0xe2			//���}�R�[�h���p
#define NS_e3			0xe3			//���}�R�[�h����`
#define NS_e4			0xe4			//���}�R�[�h����`
#define NS_e5			0xe5			//���}�R�[�h����`
#define NS_e6			0xe6			//���}�R�[�h����`
#define NS_e7			0xe7			//���}�R�[�h����`
#define NS_e8			0xe8			//���}�R�[�h����`
#define NS_e9			0xe9			//���}�R�[�h����`
#define NS_ea			0xea			//���}�R�[�h����`
#define NS_eb			0xeb			//���}�R�[�h����`
#define NS_ec			0xec			//���}�R�[�h����`
#define NS_ed			0xed			//���}�R�[�h����`
#define NS_ee			0xee			//���}�R�[�h����`
#define NS_ef			0xef			//���}�R�[�h����`

#define NS_f0			0xf0			//���}�R�[�h����`
#define NSp1			0xf1			//���}�R�[�h�X+1
#define NSp2			0xf2			//���}�R�[�h�X+2
#define NSp3			0xf3			//���}�R�[�h�X+3
#define NSp4			0xf4			//���}�R�[�h�X+4
#define NS_f5			0xf5			//���}�R�[�h����`
#define NS_f6			0xf6			//���}�R�[�h����`
#define NS_f7			0xf7			//���}�R�[�h����`
#define NS_f8			0xf8			//���}�R�[�h����`
#define NS_f9			0xf9			//���}�R�[�h����`
#define NS_fa			0xfa			//���}�R�[�h����`
#define NS_fb			0xfb			//���}�R�[�h����`
#define NS_fc			0xfc			//���}�R�[�h����`
#define NS_fd			0xfd			//���}�R�[�h����`
#define NS_fe			0xfe			//���}�R�[�h����`
#define NS_ff			0xff			//���}�R�[�h����`


// +--------------------------------------------------------------------------------------------+
// |	�������牺�́A���[�}���̒萔�ł��B														|
// |	NS[���[�}��]�Ŏg�����Ƃ��ł��܂��B														|
// |	�R���p�C���[�ɂ���Ă͕������g���Ȃ�����ˁB											|
// |	��A��̂�Ƃ͊֘A�t������ĂȂ�����A�R�[�h�ς������Ȃ痼���ς��Ăˁ�				|
// +--------------------------------------------------------------------------------------------+


//�ꉹ
#define NSNUL			0x00			//���}�R�[�hNULL�E�I�[����
#define NSa				0x01			//���}�R�[�h��
#define NSi				0x02			//���}�R�[�h��
#define NSya			0x03			//���}�R�[�h��
#define NSyu			0x04			//���}�R�[�h��
#define NSye			0x05			//���}�R�[�h����
#define NSyo			0x06			//���}�R�[�h��
#define NSu				0x07			//���}�R�[�h��
#define NSwa			0x08			//���}�R�[�h��
#define NSwi			0x09			//���}�R�[�h��
#define NSwe			0x0a			//���}�R�[�h��
#define NSwo			0x0b			//���}�R�[�h��
#define NSe				0x0c			//���}�R�[�h��
#define NSo				0x0d			//���}�R�[�h��
#define NS_0e			0x0e			//���}�R�[�h����`
#define NS_0f			0x0f			//���}�R�[�h����`

//�j��
#define NSk				0x10			//���}�R�[�hk
#define NSka			0x11			//���}�R�[�h��
#define NSki			0x12			//���}�R�[�h��
#define NSkya			0x13			//���}�R�[�h����
#define NSkyu			0x14			//���}�R�[�h����
#define NSkye			0x15			//���}�R�[�h����
#define NSkyo			0x16			//���}�R�[�h����
#define NSku			0x17			//���}�R�[�h��
#define NSkwa			0x18			//���}�R�[�h����
#define NSkwi			0x19			//���}�R�[�h����
#define NSkwe			0x1a			//���}�R�[�h����
#define NSkwo			0x1b			//���}�R�[�h����
#define NSke			0x1c			//���}�R�[�h��
#define NSko			0x1d			//���}�R�[�h��
#define NS_1e			0x1e			//���}�R�[�h����`
#define NS_1f			0x1f			//���}�R�[�h����`

#define NSg				0x20			//���}�R�[�hg
#define NSga			0x21			//���}�R�[�h��
#define NSgi			0x22			//���}�R�[�h��
#define NSgya			0x23			//���}�R�[�h����
#define NSgyu			0x24			//���}�R�[�h����
#define NSgye			0x25			//���}�R�[�h����
#define NSgyo			0x26			//���}�R�[�h����
#define NSgu			0x27			//���}�R�[�h��
#define NSgwa			0x28			//���}�R�[�h����
#define NSgwi			0x29			//���}�R�[�h����
#define NSgwe			0x2a			//���}�R�[�h����
#define NSgwo			0x2b			//���}�R�[�h����
#define NSge			0x2c			//���}�R�[�h��
#define NSgo			0x2d			//���}�R�[�h��
#define NS_2e			0x2e			//���}�R�[�h����`
#define NS_2f			0x2f			//���}�R�[�h����`

#define NSt				0x30			//���}�R�[�ht
#define NSta			0x31			//���}�R�[�h��
#define NSti			0x32			//���}�R�[�h��
#define NStya			0x33			//���}�R�[�h����
#define NStyu			0x34			//���}�R�[�h����
#define NStye			0x35			//���}�R�[�h����
#define NStyo			0x36			//���}�R�[�h����
#define NSchi			NSti			//���}�R�[�h��
#define NScha			NStya			//���}�R�[�h����
#define NSchu			NStyu			//���}�R�[�h����
#define NSche			NStye			//���}�R�[�h����
#define NScho			NStyo			//���}�R�[�h����
#define NStu			0x37			//���}�R�[�h��
#define NStwa			0x38			//���}�R�[�h��
#define NStwi			0x39			//���}�R�[�h��
#define NStwe			0x3a			//���}�R�[�h��
#define NStwo			0x3b			//���}�R�[�h��
#define NStsu			NStu			//���}�R�[�h��
#define NStsa			NStwa			//���}�R�[�h��
#define NStsi			NStwi			//���}�R�[�h��
#define NStse			NStwe			//���}�R�[�h��
#define NStso			NStwo			//���}�R�[�h��
#define NSte			0x3c			//���}�R�[�h��
#define NSto			0x3d			//���}�R�[�h��
#define NS_3e			0x3e			//���}�R�[�h����`
#define NS_3f			0x3f			//���}�R�[�h����`

#define NSd				0x40			//���}�R�[�hd
#define NSda			0x41			//���}�R�[�h��
#define NSdi			0x42			//���}�R�[�h��
#define NSdya			0x43			//���}�R�[�h����
#define NSdyu			0x44			//���}�R�[�h����
#define NSdye			0x45			//���}�R�[�h����
#define NSdyo			0x46			//���}�R�[�h����
#define NSdu			0x47			//���}�R�[�h��
#define NSdwa			0x48			//���}�R�[�h�Â�
#define NSdwi			0x49			//���}�R�[�h�Â�
#define NSdwe			0x4a			//���}�R�[�h�Â�
#define NSdwo			0x4b			//���}�R�[�h�Â�
#define NSde			0x4c			//���}�R�[�h��
#define NSdo			0x4d			//���}�R�[�h��
#define NS_4e			0x4e			//���}�R�[�h����`
#define NS_4f			0x4f			//���}�R�[�h����`

#define NSp				0x50			//���}�R�[�hp
#define NSpa			0x51			//���}�R�[�h��
#define NSpi			0x52			//���}�R�[�h��
#define NSpya			0x53			//���}�R�[�h�҂�
#define NSpyu			0x54			//���}�R�[�h�҂�
#define NSpye			0x55			//���}�R�[�h�҂�
#define NSpyo			0x56			//���}�R�[�h�҂�
#define NSpu			0x57			//���}�R�[�h��
#define NSpwa			0x58			//���}�R�[�h�Ղ�
#define NSpwi			0x59			//���}�R�[�h�Ղ�
#define NSpwe			0x5a			//���}�R�[�h�Ղ�
#define NSpwo			0x5b			//���}�R�[�h�Ղ�
#define NSpe			0x5c			//���}�R�[�h��
#define NSpo			0x5d			//���}�R�[�h��
#define NS_5e			0x5e			//���}�R�[�h����`
#define NS_5f			0x5f			//���}�R�[�h����`

#define NSb				0x60			//���}�R�[�hb
#define NSba			0x61			//���}�R�[�h��
#define NSbi			0x62			//���}�R�[�h��
#define NSbya			0x63			//���}�R�[�h�т�
#define NSbyu			0x64			//���}�R�[�h�т�
#define NSbye			0x65			//���}�R�[�h�т�
#define NSbyo			0x66			//���}�R�[�h�т�
#define NSbu			0x67			//���}�R�[�h��
#define NSbwa			0x68			//���}�R�[�h�Ԃ�
#define NSbwi			0x69			//���}�R�[�h�Ԃ�
#define NSbwe			0x6a			//���}�R�[�h�Ԃ�
#define NSbwo			0x6b			//���}�R�[�h�Ԃ�
#define NSbe			0x6c			//���}�R�[�h��
#define NSbo			0x6d			//���}�R�[�h��
#define NS_6e			0x6e			//���}�R�[�h����`
#define NS_6f			0x6f			//���}�R�[�h����`

//���C��
#define NSs				0x70			//���}�R�[�hs
#define NSsa			0x71			//���}�R�[�h��
#define NSsi			0x72			//���}�R�[�h��
#define NSsya			0x73			//���}�R�[�h����
#define NSsyu			0x74			//���}�R�[�h����
#define NSsye			0x75			//���}�R�[�h����
#define NSsyo			0x76			//���}�R�[�h����
#define NSshi			NSsi			//���}�R�[�h��
#define NSsha			NSsya			//���}�R�[�h����
#define NSshu			NSsyu			//���}�R�[�h����
#define NSshe			NSsye			//���}�R�[�h����
#define NSsho			NSsyo			//���}�R�[�h����
#define NSsu			0x77			//���}�R�[�h��
#define NSswa			0x78			//���}�R�[�h����
#define NSswi			0x79			//���}�R�[�h����
#define NSswe			0x7a			//���}�R�[�h����
#define NSswo			0x7b			//���}�R�[�h����
#define NSse			0x7c			//���}�R�[�h��
#define NSso			0x7d			//���}�R�[�h��
#define NS_7e			0x7e			//���}�R�[�h����`
#define NS_7f			0x7f			//���}�R�[�h����`

#define NSz				0x80			//���}�R�[�hz
#define NSza			0x81			//���}�R�[�h��
#define NSzi			0x82			//���}�R�[�h��
#define NSzya			0x83			//���}�R�[�h����
#define NSzyu			0x84			//���}�R�[�h����
#define NSzye			0x85			//���}�R�[�h����
#define NSzyo			0x86			//���}�R�[�h����
#define NSji			NSzi			//���}�R�[�h��
#define NSja			NSzya			//���}�R�[�h����
#define NSju			NSzyu			//���}�R�[�h����
#define NSje			NSzye			//���}�R�[�h����
#define NSjo			NSzyo			//���}�R�[�h����
#define NSzu			0x87			//���}�R�[�h��
#define NSzwa			0x88			//���}�R�[�h����
#define NSzwi			0x89			//���}�R�[�h����
#define NSzwe			0x8a			//���}�R�[�h����
#define NSzwo			0x8b			//���}�R�[�h����
#define NSze			0x8c			//���}�R�[�h��
#define NSzo			0x8d			//���}�R�[�h��
#define NS_8e			0x8e			//���}�R�[�h����`
#define NS_8f			0x8f			//���}�R�[�h����`

#define NSh				0x90			//���}�R�[�hh
#define NSha			0x91			//���}�R�[�h��
#define NShi			0x92			//���}�R�[�h��
#define NShya			0x93			//���}�R�[�h�Ђ�
#define NShyu			0x94			//���}�R�[�h�Ђ�
#define NShye			0x95			//���}�R�[�h�Ђ�
#define NShyo			0x96			//���}�R�[�h�Ђ�
#define NShu			0x97			//���}�R�[�h��
#define NShwa			0x98			//���}�R�[�h�ӂ�
#define NShwi			0x99			//���}�R�[�h�ӂ�
#define NShwe			0x9a			//���}�R�[�h�ӂ�
#define NShwo			0x9b			//���}�R�[�h�ӂ�
#define NSfu			NShu			//���}�R�[�h��
#define NSfa			NShwa			//���}�R�[�h�ӂ�
#define NSfi			NShwi			//���}�R�[�h�ӂ�
#define NSfe			NShwe			//���}�R�[�h�ӂ�
#define NSfo			NShwo			//���}�R�[�h�ӂ�
#define NShe			0x9c			//���}�R�[�h��
#define NSho			0x9d			//���}�R�[�h��
#define NS_9e			0x9e			//���}�R�[�h����`
#define NS_9f			0x9f			//���}�R�[�h����`

//�@��
#define NSn				0xa0			//���}�R�[�hn
#define NSna			0xa1			//���}�R�[�h��
#define NSni			0xa2			//���}�R�[�h��
#define NSnya			0xa3			//���}�R�[�h�ɂ�
#define NSnyu			0xa4			//���}�R�[�h�ɂ�
#define NSnye			0xa5			//���}�R�[�h�ɂ�
#define NSnyo			0xa6			//���}�R�[�h�ɂ�
#define NSnu			0xa7			//���}�R�[�h��
#define NSnwa			0xa8			//���}�R�[�h�ʂ�
#define NSnwi			0xa9			//���}�R�[�h�ʂ�
#define NSnwe			0xaa			//���}�R�[�h�ʂ�
#define NSnwo			0xab			//���}�R�[�h�ʂ�
#define NSne			0xac			//���}�R�[�h��
#define NSno			0xad			//���}�R�[�h��
#define NS_ae			0xae			//���}�R�[�h����`
#define NS_af			0xaf			//���}�R�[�h����`

#define NSm				0xb0			//���}�R�[�hm
#define NSma			0xb1			//���}�R�[�h��
#define NSmi			0xb2			//���}�R�[�h��
#define NSmya			0xb3			//���}�R�[�h�݂�
#define NSmyu			0xb4			//���}�R�[�h�݂�
#define NSmye			0xb5			//���}�R�[�h�݂�
#define NSmyo			0xb6			//���}�R�[�h�݂�
#define NSmu			0xb7			//���}�R�[�h��
#define NSmwa			0xb8			//���}�R�[�h�ނ�
#define NSmwi			0xb9			//���}�R�[�h�ނ�
#define NSmwe			0xba			//���}�R�[�h�ނ�
#define NSmwo			0xbb			//���}�R�[�h�ނ�
#define NSme			0xbc			//���}�R�[�h��
#define NSmo			0xbd			//���}�R�[�h��
#define NS_be			0xbe			//���}�R�[�h����`
#define NS_bf			0xbf			//���}�R�[�h����`

//�͂�����
#define NSr				0xc0			//���}�R�[�hr
#define NSra			0xc1			//���}�R�[�h��
#define NSri			0xc2			//���}�R�[�h��
#define NSrya			0xc3			//���}�R�[�h���
#define NSryu			0xc4			//���}�R�[�h���
#define NSrye			0xc5			//���}�R�[�h�肥
#define NSryo			0xc6			//���}�R�[�h���
#define NSru			0xc7			//���}�R�[�h��
#define NSrwa			0xc8			//���}�R�[�h���
#define NSrwi			0xc9			//���}�R�[�h�邡
#define NSrwe			0xca			//���}�R�[�h�邥
#define NSrwo			0xcb			//���}�R�[�h�邧
#define NSre			0xcc			//���}�R�[�h��
#define NSro			0xcd			//���}�R�[�h��
#define NS_ce			0xce			//���}�R�[�h����`
#define NS_cf			0xcf			//���}�R�[�h����`

//��
#define NSnn			0xd0			//���}�R�[�hnn
#define NSnn1			0xd1			//���}�R�[�h��1
#define NSnn2			0xd2			//���}�R�[�h��2
#define NS_d3			0xd3			//���}�R�[�h����`
#define NS_d4			0xd4			//���}�R�[�h����`
#define NS_d5			0xd5			//���}�R�[�h����`
#define NS_d6			0xd6			//���}�R�[�h����`
#define NS_d7			0xd7			//���}�R�[�h����`
#define NS_d8			0xd8			//���}�R�[�h����`
#define NS_d9			0xd9			//���}�R�[�h����`
#define NS_da			0xda			//���}�R�[�h����`
#define NS_db			0xdb			//���}�R�[�h����`
#define NS_dc			0xdc			//���}�R�[�h����`
#define NS_dd			0xdd			//���}�R�[�h����`
#define NS_de			0xde			//���}�R�[�h����`
#define NS_df			0xdf			//���}�R�[�h����`

//���̑�
#define NS_e0			0xe0			//���}�R�[�h����`
#define NSspc			0xe1			//���}�R�[�h��
#define NSvls			0xe2			//���}�R�[�h���p
#define NS_e3			0xe3			//���}�R�[�h����`
#define NS_e4			0xe4			//���}�R�[�h����`
#define NS_e5			0xe5			//���}�R�[�h����`
#define NS_e6			0xe6			//���}�R�[�h����`
#define NS_e7			0xe7			//���}�R�[�h����`
#define NS_e8			0xe8			//���}�R�[�h����`
#define NS_e9			0xe9			//���}�R�[�h����`
#define NS_ea			0xea			//���}�R�[�h����`
#define NS_eb			0xeb			//���}�R�[�h����`
#define NS_ec			0xec			//���}�R�[�h����`
#define NS_ed			0xed			//���}�R�[�h����`
#define NS_ee			0xee			//���}�R�[�h����`
#define NS_ef			0xef			//���}�R�[�h����`

#define NS_f0			0xf0			//���}�R�[�h����`
#define NSp1			0xf1			//���}�R�[�h�X+1
#define NSp2			0xf2			//���}�R�[�h�X+2
#define NSp3			0xf3			//���}�R�[�h�X+3
#define NSp4			0xf4			//���}�R�[�h�X+4
#define NStt			0xf5			//���}�R�[�h����
#define NS_f6			0xf6			//���}�R�[�h����`
#define NS_f7			0xf7			//���}�R�[�h����`
#define NS_f8			0xf8			//���}�R�[�h����`
#define NS_f9			0xf9			//���}�R�[�h����`
#define NS_fa			0xfa			//���}�R�[�h����`
#define NS_fb			0xfb			//���}�R�[�h����`
#define NS_fc			0xfc			//���}�R�[�h����`
#define NS_fd			0xfd			//���}�R�[�h����`
#define NS_fe			0xfe			//���}�R�[�h����`
#define NS_ff			0xff			//���}�R�[�h����`


#define NSDATAINIT_P	0				//���}�f�[�^�̃s�b�`�̏����l
#define NSDATAINIT_T	25				//���}�f�[�^�̑����̏����l


typedef float nsfloat;

typedef unsigned char NSCHAR;							//���}�R�[�h�p�̕ϐ�
typedef NSCHAR* NSSTRING;								//���}�R�[�h�̕�����p�̕ϐ�

// ���}�̐��̃f�[�^�\����
// 
// �ꕶ��9byte
// 
// ���e�p��(400��)300�� = 120,000������
// 1.08Mbyte
// 
typedef struct NSCHARDATA {

	uint32_t time;										//�S�̂ł̎���(0.01�b)(0~4,294,967,295)
	uint16_t ctime;										//�����̎���(0.01�b)(0~65,535)
	NSCHAR c;											//����(0~255)
	int16_t pitch;										//Hz�P�ʂł̃s�b�`(Hz)(-32,768~32,767)

} NSCHARDATA;

typedef NSCHARDATA* NSSTRINGDATA;						//NSCHARDATA�̔z��


//���}�R�[�h�֌W
namespace nsc {

	//---- �G���R�[�h�֌W ----

	//���}�����ŏ����ꂽ�}���`�o�C�g����������}�R�[�h�ɃG���R�[�h
	NSSTRINGDATA nsstrencode(const char* str);
	//���}�����ŏ����ꂽ�}���`�o�C�g����������}�R�[�h�ɃG���R�[�h
	NSSTRINGDATA nsstrencode(const unsigned char* str);
	//shift-jis�̏�ʃr�b�g0x82�����}�R�[�h�ɃG���R�[�h
	NSCHAR nscharencode(unsigned char c);

	//���}�����ŏ����ꂽ���[�}������������}�R�[�h�ɃG���R�[�h
	NSSTRINGDATA nsromajiencode(const char* str);
	//���}�����ŏ����ꂽ���[�}������������}�R�[�h�ɃG���R�[�h
	NSSTRINGDATA nsromajiencode(const unsigned char* str);

	//----- �f�R�[�h�֐� -----

	const char* nsstrdecode(NSSTRINGDATA str);
	const char* nsstrdecode(NSSTRING str);
	const char* nschardecode(NSCHAR c);

	//NSSTRINGDATA�^�̕ϐ����R�s�[
	void nsstrcpy(NSSTRINGDATA destination, const NSSTRINGDATA source);

	//NSCHARDATA�^�̕ϐ����쐬
	NSCHARDATA nscreateCharData(uint32_t time, uint16_t ctime, NSCHAR c, int16_t pitch);

	size_t nsstrlen(NSSTRINGDATA str);
	size_t nsstrlen(NSSTRING str);
	size_t nsstrlen(const unsigned char* str);

};

//���}������^
class NSString {

	size_t n_size;										//�f�[�^�T�C�Y
	size_t n_capacity;									//�ő�f�[�^�T�C�Y
	size_t n_wsize;										//������
	size_t n_wcapacity;									//�ő啶����
	NSSTRINGDATA n_string;								//������

public:

	NSString();
	NSString(const char* c);
	NSString(const NSSTRING c);
	NSString(const NSSTRINGDATA c);
	NSString(const NSString& s);
	//�f�X�g���N�^
	~NSString();
	//���Z�q
	NSCHARDATA& operator [](const size_t n);
	const NSCHARDATA& operator [](const size_t n) const;
	NSString operator +(const char* c);
	NSString operator +(const NSString& str);
	NSString& operator +=(const char* c);
	NSString& operator +=(const NSString& str);
	//�����o�֐�
	bool empty() const;
	size_t size() const;
	size_t length() const;
	size_t capacity() const;
	const NSCHARDATA& front() const;
	const NSCHARDATA& back() const;
	NSCHARDATA& front();
	NSCHARDATA& back();
	const char* c_str() const;
	size_t alltime() const;

};



//	+-------------------------------------------------------------------------------------------+
//	|	���}�덆�@																				|
//	+-------------------------------------------------------------------------------------------+



#define SMPL		44100										//�T���v�����O���g��
#define TRANSTIME	5											//?
#define MAXFREQ		20000										//�ő���g��
#define PI			3.141592653589793238462643					//�~����
#define DB			1.0											//wav�t�@�C���̏���A����
#define MAXTEXTS	65536										//�ő啶����

#define BIT 8													//wav�t�@�C���쐬�p
#define FILTERWIDTH 1000										//�t�B���^�[�̕�(�t�H���}���g���g������ǂ͈̔͂܂ł�ʂ���)

#define GETSIZE(a)  (sizeof(a)/sizeof(a[0]))					//�ϐ��̃T�C�Y���擾
#define POW2(a)     ((a) * (a))									//���
#define MAX(a,b)    (((a)<(b))?(b):(a))							//�ǂ��炪�傫����
#define MIN(a,b)    (((a)<(b))?(a):(b))							//�ǂ�������������

#define unprocessed	0											//�����Ȃ�

#define TESTPLAYVOISEFILENAME		"NesoraTestVoiseFromMvff.wav"	//��������wav�t�@�C���̕W���̖��O

#define GEMINATE_CONSONANT_SPEED	2							//�u���v�̒���
#define GEMINATE_CONSONANT_TMAG		1.5							//�u���v�̂��Ƃ̒����̔{��
#define MAXSHIONSPEED				4410						//�q���̒���
#define MAXBYOUONSPEED				2200						//�X���̑O�̕ꉹ�̒���
#define MAXYOUONSPEED				2200						//�X���̒���
#define SEMIVOWELSPEED				882							//���̌㔼�̕ω�����Ƃ���̒���
#define PLOSIVESPEED				220							//�j�􉹂̒���
#define PLOSIVEPOWER				2							//�j�􉹂̋���
#define NASALSPEED					331							//�@���̒���
#define TAPSPEED					331							//�͂������̒���
#define FRICATIVENOISESCOPE			50							//���C���̎G���͈̔�
#define FRICATIVENOISEACC			200							//���C���̎G���̐��x
#define PLOSIVEPOWER				2							//���E���̋���
#define CTIME						4410						//����̒����̉���؂���Ƃ��̑O��̗]��

#define SPACE						0xd3						//��
#define SPARETIME					441000						//�\������
#define CHANGETIMEMAGN				0.01 * SMPL					//���Ԃ̔䗦

struct FriKILLive {
	std::vector<nsfloat> Hz, s;
	size_t size;
};


class mainMakeVoiseF {
public:

	int makeSinWave(int num, std::vector<nsfloat> Hz, std::vector<nsfloat> s, std::vector<nsfloat>& out, nsfloat a = 0.0, bool doformant = true);	//���X�g���獇�����ꂽsin�g�𐶐�
	int makeSinha(nsfloat Hz, nsfloat s, std::vector<nsfloat>& out);													//�P����sin�g�𐶐�

	int makeHarmonicOvertone(nsfloat bf);																			//��{�{���ݒ�
	int setFormants(nsfloat F1, nsfloat F2, nsfloat F3, nsfloat F4);													//�t�H���}���g���X�g�Ɏ��g����ݒ�
	int makeFilter();																								//��{�{���̑傫������������
	int makeSinWaveFromClass(std::vector<nsfloat>& out, nsfloat a = 0.0);												//�N���X���̃p�����[�^����sin�g������

	nsfloat makeMomentSinWave(int num, std::vector<nsfloat> Hz, std::vector<nsfloat> s, int gets);												//����̎��Ԃ̎��g�����擾
	nsfloat makeMomentSinWaveFromClass(int t);																		//�N���X���̃p�����[�^�������̎��Ԃ̎��g�����擾


	nsfloat mostMax(std::vector<nsfloat> list);																	//�z����̍ł��傫���l��Ԃ��֐�

	int hipassFilter(std::vector<nsfloat> input, std::vector<nsfloat>& out, nsfloat samplerate, nsfloat freq, nsfloat q);				//�n�C�p�X�t�B���^�[
	int lowpassFilter(std::vector<nsfloat> input, std::vector<nsfloat>& out, nsfloat samplerate, nsfloat freq, nsfloat q);				//���[�p�X�t�B���^�[
	int notchpassFilter(std::vector<nsfloat> input, std::vector<nsfloat>& out, nsfloat samplerate, nsfloat freq, nsfloat bw);			//�m�b�`�p�X�t�B���^�[

	int getstate(int state);																						//���݂�mainMakeVoiseF.cpp�̏�Ԃ��擾����B
	int setSoftness(nsfloat sn);																						//softness�ϐ���ύX
private:

	int fsize = 4, hosize = 0;																						//�t�H���}���g�̐��A�{���̐�
	std::vector<nsfloat> formants = { 0.0,0.0,0.0,0.0 }, harmonicOvertones = { 0.0 }, harmonictoneFilters = { 0.0 };	//�f�[�^�z��
	nsfloat bf = 0;																									//�����g��
	nsfloat softness = 0;																							//�_�炩��

};


class makeVoiseFromFile {
public:

	int setDefaulFurin();																							//���} ������g��
	int setShion();																									//���} �������g��

	//�V
	int textread(const char* text);																					//���}�����ŏ����ꂽ���͂�ǂݍ���
	std::vector<nsfloat> textreading();																				//textread�œǂݍ��񂾕��͂�ǂݏグ

	int loadFromChar(char* data);																					//�����񂩂�f�[�^��ǂݍ���

	nsfloat getPrivatebf();																							//�f�[�^�ۊǌɂ����f�[�^��ǂݍ���
	nsfloat getPrivatebFormant(int b, int f);																		//�f�[�^�ۊǌɂ���t�H���}���g�f�[�^��ǂݍ���

	int decodeVoise0(char* data);																					//�덆�@�̃f�[�^��ǂݍ���
	int decodeVoise2(char* data);																					//�덆�@�̃f�[�^��ǂݍ���

private:

	int makeWhitenoise(std::vector<nsfloat> out, int time, nsfloat hz, nsfloat um);									//�z���C�g�m�C�Y���쐬
	int makeWhitenoise1(std::vector<nsfloat> out, int time, nsfloat hz);												//�z���C�g�m�C�Y���쐬

	int hipassFilter(std::vector<nsfloat> input, std::vector<nsfloat>& out, nsfloat samplerate, nsfloat freq, nsfloat q);				//�n�C�p�X�t�B���^�[
	int lowpassFilter(std::vector<nsfloat> input, std::vector<nsfloat>& out, nsfloat samplerate, nsfloat freq, nsfloat q);				//���[�p�X�t�B���^�[
	int notchpassFilter(std::vector<nsfloat> input, std::vector<nsfloat>& out, nsfloat samplerate, nsfloat freq, nsfloat bw);			//�m�b�`�p�X�t�B���^�[

	nsfloat privatebf = 0, privateFormant[5][4] = { 0 };																//makeVoiseFromFile�̃f�[�^�ۊǌ�
	nsfloat allmojiFormant[2][16][16][4] = { 0 };																	//�����̃t�H���}���g�̕ۊǌ�
	nsfloat softness = 0;																							//�_�炩���̕ۊǌ�

	int createAllMojiFromantFromClass();																			//privateFormant����allmojiFormant���쐬
	nsfloat getMojiFormant(int f, int moji, int formant);															//allmojiFormant����t�H���}���g���擾

	bool doVoiselessPlosive(NSCHAR moji);																			//�����j��
	bool doVoisedPlosive(NSCHAR moji);																				//�L���j��
	bool doNasal(NSCHAR moji);																						//�@��
	bool doTap(NSCHAR moji);																						//�͂�����
	bool doVoiselessFricative(NSCHAR moji);																			//�������C��
	bool doVoisedFricative(NSCHAR moji);																			//�L�����C��
	bool doFriKILLive(NSCHAR moji);																					//���E��

	int ftInit(int size);																							//�j�C���̊p�x�̏�����
	nsfloat* ft;																										//�j�C���̊p�x�̕ۊǌ�

	int getTimeFromSpeed(char speed, char moji = 0x00);																//���}�`���̎��ԒP�ʂ��琺�̒���[�b]�֕ϊ�

	//�V
	NSString pstringdata = NSString();																				//�ǂݏグ�p�̃f�[�^�ۊǌ�

	time_t nextplaytime = 0;

	//���}�����֐��Q

	void textreadingHanboin(std::vector<nsfloat>& out, NSCHAR nowmoji, nsfloat pitch, int targettime);
	void textreadingHaretuon(std::vector<nsfloat>& out, NSCHAR nowmoji1, NSCHAR nowmoji2, nsfloat pitch, int targettime);
	void textreadingYuuseiHaretuon(std::vector<nsfloat>& out, NSCHAR nowmoji1, NSCHAR nowmoji2, nsfloat pitch, int targettime, bool select = true);
	void textreadingMasatuon(std::vector<nsfloat>& out, NSCHAR nowmoji1, NSCHAR nowmoji2, nsfloat pitch, int targettime);
	void textreadingYuuseiMasatuon(std::vector<nsfloat>& out, NSCHAR nowmoji1, NSCHAR nowmoji2, nsfloat pitch, int targettime);
	void textreadingMASATUON(std::vector<nsfloat>& out, NSCHAR nowmoji, nsfloat pitch, int targettime);
	void textreadingBion(std::vector<nsfloat>& out, NSCHAR nowmoji1, NSCHAR nowmoji2, NSCHAR oldmoji, nsfloat pitch, int targettime);
	void textreadingHajikion(std::vector<nsfloat>& out, NSCHAR nowmoji1, NSCHAR nowmoji2, NSCHAR oldmoji, nsfloat pitch, int targettime);

	void textreadingBoin1(std::vector<nsfloat>& out, NSCHAR nowmoji, nsfloat pitch, int targettime);
	void textreadingBoin2(std::vector<nsfloat>& out, NSCHAR nowmoji, NSCHAR nextmoji, nsfloat pitch, nsfloat nextpitch, int targettime);

};

