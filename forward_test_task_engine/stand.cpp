#include "stand.h"

Stand::Stand()
{
	cout << "������� ����������� ���������� �����: ";
	cin >> ambient_temperature;
}

void Stand::start()
{
	DVSEngine engine(ambient_temperature);
	if (engine.check_file == 0)
	{
		cout << "��������� ������� ����� input_data.txt" << endl;
	}
	else
	{
		engine.start();
	}
}