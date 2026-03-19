#include <fstream>
#include "storage.hpp"
#include <cstddef>
#include <iostream>

void Storage::add(const Item &item)
{
	if (count_ >= LIMIT)
		return;
	if (is_exist(item))
		return;
	items_[count_++] = item;
}

void Storage::remove(Item &item)
{
	if (!is_exist(item))
		return;
	items_[current_id_] = items_[--count_];
}

void Storage::write() const
{
	char filename[5] = { "file" };
	std::ofstream file(filename, std::ios::binary);

	if (!file.is_open()) {
		std::cerr << "Error: Could not open file for writing\n";
		return;
	}

	// 1. Сначала записываем количество элементов (метаданные)
	file.write(reinterpret_cast<const char *>(&count_), sizeof(count_));

	// 2. Затем записываем весь массив "живых" данных целиком
	file.write(reinterpret_cast<const char *>(items_),
		   sizeof(Item) * count_);

	file.close();
}

void Storage::read()
{
	char filename[5] = { "file" };
	std::ifstream file(filename, std::ios::binary);
	if (!file)
		return;

	// 1. Читаем, сколько элементов было сохранено
	file.read(reinterpret_cast<char *>(&count_), sizeof(count_));

	// 2. Читаем данные прямо в массив items_
	file.read(reinterpret_cast<char *>(items_), sizeof(Item) * count_);

	file.close();
}

void Storage::get_all() const
{
	for (unsigned int i = 0; i < count_; i++) {
		std::cout << i + 1 << " name: " << items_[i].name
			  << " plu: " << items_[i].plu << "\n";
	}std::cout << "\n";
}

int Storage::get_id(const Item &item)
{
	for (unsigned int i = 0; i < count_; i++) {
		if (item.plu == items_[i].plu &&
		    item.exp_date == items_[i].exp_date) {
			current_id_ = (int)i;
			return current_id_;
		}
	}
	return -1;
}

bool Storage::is_exist(const Item &item)
{
	if (get_id(item) != -1)
		return true;
	return false;
}
