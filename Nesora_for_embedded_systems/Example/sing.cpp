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

int main() {
	// ���̖{�̂ƂȂ�C���X�^���X�ł��B
	// �����ɐ��̃f�[�^���{�̃f�[�^�A���̐����Ɏg���N���X�̃C���X�^���X�Ȃ񂩂������Ă��܂��B
	// �ڍׂ͓��f�B���N�g���ɂ���speak.cpp���Q�ƁB
	makeVoiseFromFile MVFF;
	MVFF.setDefaulFurin();


	// �����ɒ��点�������͂���͂��܂��B
	// �Ђ炪�Ȃ��g���ꍇ�Ashift-jis���g���Ă��������B
	// shift-jis���g���Ȃ��ꍇ�́AEncoder_for_Nesora.hpp ���̴�԰�ł���֐����g��(�񐄏�)��
	// ���[�}���œ��͂��Ă��������B
	//
	// �����ł́A���}�̑�{�̕��@�ł���u���}�����v�ɂ��Đ������܂��B
	// �Ƃ͂����Ă�������Ƃ͂Ȃ��A��{�I��xml�݂����Ȃ��̂ł��B
	// 
	// ��{�I�ɕ�����(���邢�̓��[�}��)�ŏ����ꂽ��{�̕����ƕ����̊ԂɃ^�O�����ރC���[�W�ł��B
	// �^�O�͈ȉ��̓��
	// <s> ...�����̐���
	// <p> ...�����̐���
	// 
	// �����̐���
	// <sxx>��xx�̕����Ɏ��Ԃ��w�肵�Ă�����ƁA����ȍ~�A�ꕶ�������̒����Řb���悤�ɂȂ�܂��B�P�ʂ�[cs](�Z���`�b = 0.01s)
	// <s20>�Ƃ���΁A����ȍ~�A�ꕶ����0.2�b�̒����ł���ׂ�悤�ɂȂ�܂��B
	// �����l��0.25�b�ł��B(<s25>)
	// 
	// �����̐���
	// <p�}xx>�́}xx�����ɁA���ΓI�Ȏ��g���l�𕄍��t���œ��͂��邱�ƂŐ��̍�����ς��邱�Ƃ��ł��܂��B�P�ʂ�[Hz]�A��l�͎g���Ă��鐺�̊����g���ł��B
	// �����g���͐��ɂ���ĈقȂ�A����̏ꍇ440Hz(A4)�A�����̏ꍇ392Hz(G4)�ł��B
	// ������g���Ă���ꍇ�A<p+54>��494Hz(B4)�A<p-48>��392Hz(G4)�ɂȂ�܂��B
	// �����l��+0Hz�ł��B(<p+0>)
	// 
	// �����̃^�O���g���đ�{����邱�ƂɂȂ�܂��B
	// 
	// 
	// ���{�ꂩ���[�}�����͎����Ŕ��肳��܂��B��̓I�ɂ́A�����񒆂ɓ�o�C�g�����̂Ђ炪��(0x82)���܂܂�Ă���΂Ђ炪�ȁA�܂܂�Ă��Ȃ���΃��[�}���ŃG���R�[�h���s���܂��B
	// �Ђ炪�Ȃƃ��[�}�������������邱�Ƃ͂ł��܂���B
	// ���{����g���ꍇ�͂Ђ炪�Ȃ����g���Ă͂Ȃ炸�A���[�}�����g���ꍇ�͉p���������g���Ă͂Ȃ�܂���B
	// 
	// ���{�ꂪ�܂܂�Ă���ꍇ�A�u�A�v�ňꕶ�����̋x���A�u�B�v�œ񕶎����̋x���ɂȂ�܂��B
	// ���[�}���ŏ�����Ă���ꍇ�ɂ́A�u,�v�ňꕶ�����̋x���A�u.�v�œ񕶎����̋x���ɂȂ�܂��B
	// 
	// ���p����()�ň͂܂ꂽ�����̓R�����g�ɂȂ�A���ۂ̓ǂݏグ���ɂ͔��f����܂���B�������A���{�ꂩ���[�}�����̔���ɂ͈���������̂ŁA�����͒��ӂ��Ă��������B
	// 
	
	//MVFF.textread("(���E�@�����ȏ��́@�q�포�w�Z���́@�O�w�N�p)(���)<s60>�A<p-48>��<p+83>��<p+147>��<s90><p+219>��<s30>��<s60>�Â�<s90><p+344>��<s30>��<s60>����<p+219>��<p+147>��<p+83>��<p+147>��A�A<p+344>�̂�<p+219>��<s90><p+147>��<s30>��<s60><p+83>��<p+0>��<s90><p+219>��<s30>��<s60><p+147>��<p+83>��<p+0>����<p-48>��A�A��<p+83>��<p+147>��<s90><p+219>��<s30>��<s60>���<s90><p+344>����<s30>��<s60>��<p+219>����<p+147>��<p+83>��<p+147>���A�A<p+344>����<p+219>��<s90><p+147>��<s30>��<s60><p+83>��<p+0>��<p-48>��<p+83>��<s90><p+147>��<s30><p+219>��<s180><p+83>��<s60>�A�A(���)<p-48>��<p+83>��<p+147>��<s90><p+219>��<s30>��<s60>����<s90><p+344>����<s30>��<s60>��<p+219>��<p+147>��<p+83>��<p+147>���A�A<p+344>����<p+219>��<s90><p+147>��<s30>��<s60><p+83>��<p+0>��<s90><p+219>��<s30>��<s60><p+147>��<p+83>��<p+0>����<p-48>���A�A��<p+83>��<p+147>��<s90><p+219>��<s30>��<s60>��<s90><p+344>��<s30>��<s60>��<p+219>��<p+147>��<p+83>��<p+147>�ʁA�A<p+344>��<p+219>�ɂ�<s90><p+147>��<s30>��<s60><p+83>��<p+0>��<p-48>����<p+83>��<s90><p+147>��<s30><p+219>��<s180><p+83>��<s60>�A");
	MVFF.textread("(Chatumi - Monbusho shoka for third year of elementary school)(1)<s60>,<p-48>Na<p+83>tu<p+147>mo<s90><p+219>ti<s30>ka<s60>duku<s90><p+344>ha<s30>ti<s60>zu<p+219>u<p+147>ha<p+83>ti<p+147>ya,,<p+344>noni<p+219>mo<s90><p+147>ya<s30>ma<s60><p+83>ni<p+0>mo<s90><p+219>wa<s30>ka<s60><p+147>ba<p+83>ga<p+0>sige<p-48>ru,,a<p+83>re<p+147>ni<s90><p+219>mi<s30>e<s60>ruwa<s90><p+344>tya<s30>tu<s60>mi<p+219>zya<p+147>na<p+83>i<p+147>ka,,<p+344>aka<p+219>ne<s90><p+147>da<s30>su<s60><p+83>ki<p+0>ni<p-48>su<p+83>ge<s90><p+147>no<s30><p+219>ka<s180><p+83>sa<s60>,,(2)<p-48>hi<p+83>yo<p+147>ri<s90><p+219>tu<s30>du<s60>kino<s90><p+344>kyo<s30>u<s60>ko<p+219>no<p+147>go<p+83>ro<p+147>wo,,<p+344>koko<p+219>ro<s90><p+147>no<s30>do<s60><p+83>ka<p+0>ni<s90><p+219>tu<s30>mi<s60><p+147>tu<p+83>tu<p+0>uta<p-48>u,,tu<p+83>me<p+147>yo<s90><p+219>tu<s30>me<s60>tume<s90><p+344>tu<s30>ma<s60>ne<p+219>ba<p+147>na<p+83>ra<p+147>nu,,<p+344>tuma<p+219>nya<s90><p+147>ni<s30>ho<s60><p+83>nn<p+0>no<p-48>tya<p+83>ni<s90><p+147>na<s30><p+219>ra<s180><p+83>nu<s60>,");


	std::vector<nsfloat> wave = MVFF.textreading();
	NesoraWave("NesoraWave.wav", wave);

	return 0;
}

//
// �Z�p�җp����
// 
// �ȉ��̃v���Z�b�T��1��16�b�̉����𐶐�����̂ɖ�3�b������܂����B
// 
// Intel(R) Core(TM) i7-10700K CPU @ 3.80GHz   3.79 GHz
// 
// �g�p�����������͖�20MByte�ł��B
// 
// 
// OS�͈ȉ��̒ʂ�
// 
// �G�f�B�V����			Windows 10 Home
// �o�[�W����			22H2
// �C���X�g�[����		�ߘa3�N3��31��
// OS �r���h			19045.3448
// �G�N�X�y���G���X		Windows Feature Experience Pack 1000.19044.1000.0
// 
// 
// �f�o�b�O�ɂ͈ȉ��̃\�t�g�E�G�A���g�p���܂����B
// 
// Microsoft Visual Studio Community 2019
// Version 16.11.26
// VisualStudio.16.Release / 16.11.26 + 33529.622
// Microsoft.NET Framework
// Version 4.8.04084
// 
// Microsoft Visual C++ 2019
//
// �\���͈ȉ��̒ʂ�ł��B
//
// �\��:Release
// �v���b�g�t�H�[��:Win32
// 
