#include "stand.h"

Stand::Stand()
{
	cout << "Введите температуру окружающей среды: ";
	cin >> ambient_temperature;
}

void Stand::start()
{
	DVSEngine engine(ambient_temperature);
	if (engine.check_file == 0)
	{
		cout << "Проверьте наличие файла input_data.txt" << endl;
	}
	else
	{
		engine.start();
	}
}