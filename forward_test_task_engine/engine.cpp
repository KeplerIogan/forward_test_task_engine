#include "engine.h"

using namespace std;


DVSEngine::DVSEngine(float at) {

	ifstream input_data("input_data.txt");
	if (!input_data.is_open())
	{
		cout << "Файл не может быть открыт!\n";
		check_file = 0;
	}
	else
	{

		M.resize(size_MV);
		V.resize(size_MV);

		input_data.seekg(3, ios_base::cur);
		input_data >> engine_inertia;
		input_data.seekg(8, ios_base::cur);

		for (int i = 0; i < size_MV; i++)
		{
			input_data >> M[i];
			input_data.seekg(1, ios_base::cur);
		}

		input_data.seekg(9, ios_base::cur);

		for (int i = 0; i < size_MV; i++)
		{
			input_data >> V[i];
			input_data.seekg(1, ios_base::cur);
		}

		input_data.seekg(7, ios_base::cur);
		input_data >> temperature_overheat;
		input_data.seekg(6, ios_base::cur);
		input_data >> Hm;
		input_data.seekg(6, ios_base::cur);
		input_data >> Hv;
		input_data.seekg(5, ios_base::cur);
		input_data >> C;
		input_data.close();

		ambient_temperature = at;
		engine_temperature = ambient_temperature;
		Vh = 0;
		Vc = 0;
	}
}

int DVSEngine::start() {

	int acceleration = 0;

	while (engine_temperature < temperature_overheat)
	{
		Vh = M[acceleration] * Hm + V[acceleration] * V[acceleration] * Hv;
		Vc = C * (ambient_temperature - engine_temperature);
		engine_temperature += Vh + Vc;
		time_overhead++;

		if (acceleration < M.size() - 1)
		{
			acceleration++;
		}
		if (time_overhead > MAX_TIME)
		{
			cout << "Двигатель не нагревается!" << endl;
			return 0;
		}
	}
	cout << "Время перегрева двигателя: " << time_overhead << " сек" << endl;
	return 0;
}
