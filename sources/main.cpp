#include <iostream>
#include "headers\main_window.hpp"

int wmain()
{
	MainWindow mw1(L"qwe", 300, 300, 500, 400);

	mw1.Show();
	return 0;
}
