#pragma once
#include <iostream>
#include <vector>
#include <fstream>

#define MAX_TIME 180

using namespace std;

class samleEngine {
protected:
	static const int size_MV = 6;
	float engine_inertia;
	vector <float> M;
	vector <float> V;
	float Hm;
	float Hv;
	float C;
	float temperature_overheat;
	float time_overhead;
	float ambient_temperature;
	float engine_temperature;
};
