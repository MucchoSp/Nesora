


#include "Nesora/Nesora_for_embedded_systems.h"

makeVoiseFromFile MVFF;

int NesoraWave(std::string filename, std::vector<nsfloat> wave) {
    std::ofstream file(filename, std::ios::out | std::ios::binary);
    if (!file) return 1;

    const int smpl = 44100;

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

//���}�덆�@��ԃ��C�����[�v
int mainLoop() {

    char* option = new char[MAXTEXTS]();
    while (1) {
        printf("���点�錾�t����͂��Ă�������(fin�ŏI��): ");
        (void)scanf("%s", option);
        printf("\n");

        //�I��
        if (strstr(option, "fin")) {
            break;
        }

        MVFF.textread(option);
        std::vector<nsfloat> wave = MVFF.textreading();
        NesoraWave("NesoraWave.wav", wave);

        //���[�v�I�[
        printf("\n");
    }

    delete[] option;
    return 0;
}

//main�֐�
int main() {
    //�f�t�H���g����
    MVFF.setDefaulFurin();
    printf("���}�덆�@��^\nCopyright (c) 2021 - 2022 MucchoSP\n\n");

    mainLoop();

    printf("\n\n�����p���肪�Ƃ��������܂����B\n");
    printf("\n���}�덆�@��^\nCopyright (c) 2021 - 2022 MucchoSP\n\n");
    (void)getchar();

    return 0;
}
