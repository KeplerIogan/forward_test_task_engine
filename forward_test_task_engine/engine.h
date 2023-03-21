#pragma once
#include "sample_engine.h"

using namespace std;


class DVSEngine : samleEngine
{
protected:
	float Vh;
	float Vc;
public:
	int check_file = 1;
	DVSEngine(float at);
	int start();
};
