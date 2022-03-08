#include <iostream>
#include <cmath>
#include <fstream>
#define PI 3.1415926535
#define sec 0.01

using namespace std;

// .을 쓴 이유는 , (float) 자료형을 맞춰주기 위함. 

int main() {

	//file open
	ofstream out("test.txt");

	if (!out) {
		cout << "test.txt파일을 찾을 수 없습니다.\n";
		return -1;
	}

	// sin
	float t, dt, sint, f1, f2, f3, f4; // f2=330, f3=440,f4=660. 

	
	f1 = 220.0; // 220Hz, 330Hz, 440Hz, 660Hz
	f2 = 330.0;
	f3 = 440.0;
	f4 = 660.0;

	dt = 1. / 44100.; // fs=44100Hz

	int A = 10000;

	//f1
	cout << "<f1 = 220Hz>\n";
	for (t = 0; t < sec; t += dt) { // 10ms까지만 구현하기 위함. 
		
		sint = A * sin(2. * PI * f1 * t);

		 

		cout << t << "(s), sin값 : " << sint << endl;
		out << t << " " << sint << endl;
		
	}

	cout << endl;
	cout << "<f2 = 330Hz>\n";
	out << endl;

	//f2
	for (t = 0; t < sec; t += dt) { // 10ms까지만 구현하기 위함. 

		sint = A * sin(2. * PI * f2 * t);

		cout << t << "(s), sin값 : " << sint << endl;
		out << t << " " << sint << endl;

	}

	cout << endl;
	cout << "<f3 = 440Hz>\n";
	out << endl;

	//f3
	for (t = 0; t < sec; t += dt) { // 10ms까지만 구현하기 위함. 

		sint = A * sin(2. * PI * f3 * t);

		cout << t << "(s), sin값 : " << sint << endl;
		out << t << " " << sint << endl;

	}

	cout << endl;
	cout << "<f4 = 660Hz>\n";
	out << endl;

	//f4
	for (t = 0; t < sec; t += dt) { // 10ms까지만 구현하기 위함. 

		sint = A * sin(2. * PI * f4 * t);

		cout << t << "(s), sin값 : " << sint << endl;
		out << t << " " << sint << endl;

	}

	cout << endl;
	out << endl;

	out.close();
}


