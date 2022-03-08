#include <iostream>
#include <fstream>
#include <cmath> // sin( )
using namespace std;

class waveHeader {
public:
    waveHeader() {};
    int chunkID, chunkSize, Format, subChunkID, subChunk1size;
    short   audioFormat, numChannels;
    int sampleRate, byteRate; // sampleTate : 1초에 몇개 조각으로 sample화?(=fs) , byteRate : SampleRate * Numchannels * BitsPerSample/8
    short blockAlign, bitsPerSample; // bitsPerSample : sample당 bit수. 1초를 sample로 나누고, 각각 sample을 몇 개의 비트로 표현?? 
    int subChunk2ID, subChunk2size;
}; // waveHeader의 사이즈는 44byte. 


int main() {

    // Sprint 1
    ifstream xx("Beatles.wav", ios::binary | ios::in); // ifstream에서 ios::in을 사용함.
    if (!xx) return 999;

    waveHeader myHeader;
    xx.read((char*)&myHeader, sizeof(waveHeader)); // myHeader의 시작주소를 받으면서 44byte만큼 값을 읽는다.


    // wav파일 출력.
    // int = 4byte
    cout << "chunkID : " << (char)myHeader.chunkID << endl; // (char)로 형변환시도.
    cout << "chunkSize : " << myHeader.chunkSize << endl;
    cout << "Format : " << myHeader.Format << endl;
    cout << "subchunkID : " << myHeader.subChunkID << endl;
    cout << "Shubchunk1size : " << myHeader.subChunk1size << endl; // 16


    //short = 2byte
    cout << "audioFormat : " << myHeader.audioFormat << endl; // 1
    cout << "numChannels : " << myHeader.numChannels << endl; // 2 -> 1(?), how??

    myHeader.numChannels = 1;
    cout << "-----------------------------------" << endl;
    cout << "Sprint3, 변경된 numChannels값 : " << myHeader.numChannels << endl;
    cout << "-----------------------------------" << endl;

    // int = 4byte
    cout << "sampleRate = " << myHeader.sampleRate << endl; // fs = 44,100Hz
    cout << "ByteRate = " << myHeader.byteRate << endl; //176,400(=44,100 * 4)

    //short = 2byte
    cout << "blockAlign : " << myHeader.blockAlign << endl; //4
    cout << "bitsPerSample : " << myHeader.bitsPerSample << endl; //16

    //int = 4byte
    cout << "subChunk2ID : " << myHeader.subChunk2ID << endl;
    cout << "subChunk2size : " << myHeader.subChunk2size << endl;

    xx.close();


    // Sprint 2
    short* data;

    int n = myHeader.sampleRate * 1; // 1초동안 재생, sampleRate(=fs) = 44,100(Hz)
    data = new short[n * myHeader.numChannels]; // 2n = 2 * (44,100) * 1 = 88,200
    float dt = 1. / (float)(myHeader.sampleRate); // dt = fs(샘플링주파수)
    // float f1 = 261.63, f2 = 329.63, A = 10000.0; // f1= 도, f2= 미
    float f = 440, A = 10000.0;
    // 변수값 미리보기.
    cout << "=================" << endl;
    cout << "n : " << n << endl; // n = fs =44,100 
    cout << "data size : " << n * myHeader.numChannels; // 88,200 = 44,100 * 2(채널 수 2개) 

    for (int i = 0; i < n; i++) { // n = 0 ~ 44,099까지.
        float t = i * dt;

        // data가 최대 88,200개. data[0] ~ data[88199] 
        data[i] = (short)(A * cos(2. * 3.141592 * f * t)); // '라'

    }
    ofstream mydata("mydata.wav", ios::binary | ios::out);
    mydata.write((char*)data, sizeof(short) * n * (myHeader.numChannels));
    mydata.close();

    //sprint 4
    ofstream mywave("mywave.wav", ios::binary | ios::out); //ofstream으로 선언해서 ios::out으로 표현.

    mywave.write((char*)&myHeader, sizeof(waveHeader)); // sizeof(waveHeader) = 44
    mywave.write((char*)data, sizeof(short) * n * (myHeader.numChannels));
    mywave.close();

    getchar();

    return 1;
}