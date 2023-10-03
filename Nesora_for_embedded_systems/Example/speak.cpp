#include "../Nesora/Nesora_for_embedded_systems.h"

inline int NesoraWave(std::string filename, std::vector<nsfloat> wave) {
	std::ofstream file(filename, std::ios::out | std::ios::binary);
	if (!file) return 1;

	const int smpl = SMPL;

	size_t waveChankSize = 4 + 24 + (wave.size() * sizeof(nsfloat) + 8);
	file.write("RIFF", 4);
	file.write((char*)&(waveChankSize), 4);

	// 4byte
	file.write("WAVE", 4);

	// 24 bytes
	int work = 0;
	file.write("fmt ", 4);											//fmt
	file.write((char*)&(work = 16), 4);								//size
	file.write((char*)&(work = 3), 2);								//format(32bit float)
	file.write((char*)&(work = 1), 2);								//channel(monaural)
	file.write((char*)&(work = smpl), 4);								//sampling frequency
	file.write((char*)&(work = smpl * sizeof(nsfloat)), 4);	//bytes per sec
	file.write((char*)&(work = sizeof(nsfloat)), 2);				//block size
	file.write((char*)&(work = sizeof(nsfloat) * 8), 2);			//bits per sample

	// wave.mainWave.size() * sizeof(nsfloat) + 8 bytes
	file.write("data", 4);
	file.write((char*)&(work = wave.size() * sizeof(nsfloat)), 4);	//size
	nsfloat* out = new nsfloat[wave.size()];
	nsfloat* workout = out;
	for (auto workWave : wave)
		*workout++ = workWave;
	file.write((char*)out, static_cast<std::streamsize>(wave.size()) * sizeof(nsfloat));

	file.close();
}

int unuse_main() {
	// ���̖{�̂ƂȂ�C���X�^���X�ł��B
	// �����ɐ��̃f�[�^���{�̃f�[�^�A���̐����Ɏg���N���X�̃C���X�^���X�Ȃ񂩂������Ă��܂��B
	makeVoiseFromFile MVFF;

	// ���̊֐��Ő����������ł��܂��B
	// ���}�́A�l�X�Ȑ����g����悤�ɐ����p�����[�^�Ƃ��Ď��悤�ɐ݌v����Ă���A
	// windows�łł̓t�@�C���Ƃ��ēǂݍ��݂܂����A�g�ݍ��ݗp�Ȃ̂ł���Ő������������Ă��������B
	// ���̒ǉ��͂������܂��B
	MVFF.setDefaulFurin();
	//MVFF.setShion();	//������ƃ��C���ۂ���

	// �����ɒ��点�������͂���͂��܂��B
	// �Ђ炪�Ȃ��g���ꍇ�Ashift-jis���g���Ă��������B
	// shift-jis���g���Ȃ��ꍇ�́AEncoder_for_Nesora.hpp ���̴�԰�ł���֐����g��(�񐄏�)�����[�}���œ��͂��Ă��������B
	// �ڍׂ͓��f�B���N�g���ɂ���sing.cpp���Q�ƁB
	MVFF.textread("����ɂ��킠");

	// ����Ŏ��ۂɐ������ꂽ�g�`���擾�ł��܂��B
	// -1~1�͈̔͂ŏo�͂���܂��̂ŁA�ς�Ȃ�Ă��Ȃ肵�Ă��������B
	// �Ȃ��A�W�{�����g����44100Hz�ł��B
	// �ق��̎��g�����g�������ꍇ�A�w�b�_�[�t�@�C���̉��̕��ɂ���"SMPL"�Ƃ����萔��ς��邱�ƂŕύX�\�ł��B(������)
	std::vector<nsfloat> wave = MVFF.textreading();

	// wav.�t�@�C���ɏo�͂���֐��ł��B
	// windows�̕��p�B
	NesoraWave("NesoraWave.wav", wave);

	return 0;
}