#include "../include/game.h"

// Начинаем игру
void game(Desk *desk, Figure_Color &color_passage)
{
	// Отслеживание ничьи
	bool players_draw = false;

	// Ввод игрока
	std::string step;

	// Вывод текста для игроков
	do
	{
		// begin_game первый раз вернул black для этого цикла;
		// Ходят чёрные
		if (color_passage == White)
		{
			color_passage = Black;
			std::cout << "\nХод второго игрока\nПример(d6e5): ";
		}
		// Ходят белые
		else
		{
			color_passage = White;
			std::cout << "\nХод первого игрока\nПример(e3f4): ";
		}

		// Игрок ходит
		do
		{
			// Проверка на ввод
			check_input(step, players_draw, desk, color_passage); 
		} while (move_checkers(desk, step, color_passage, players_draw) != true 
								&& step != "сдаюсь" && step != "выйти");

		// Отрисовываем доску заново
		print_desk(desk, color_passage);

	} while (quantity_checkers(desk, color_passage) && !deadlock(desk) &&
				step != "выйти" && step != "сдаюсь" && !players_draw);
	if (step == "выйти")
	{
		std::cout << '\n';
		menu();
	}

	if (step == "сдаюсь")
	{
		if (color_passage == White)
		{
			std::cout << '\n';
			std::cout << "Победили чёрные!\n";

			// Спрашиваем о рестарте игры
			question_restart_game(desk);
		}
		else
		{
			std::cout << '\n';
			std::cout << "Победили белые!\n";

			// Спрашиваем о рестарте игры
			question_restart_game(desk);
		}
	}
}