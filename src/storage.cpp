#include "storage.hpp"
#include <fstream>
#include <iostream>

void Storage::add(const Item &item)
{
	if (count_ >= LIMIT)
		return;
	if (is_exist(item))
		return;
	items_[count_++] = item;
}

void Storage::remove(const Item &item)
{
	if (!is_exist(item))
		return;
	items_[current_id_] = items_[--count_];
}

void Storage::get_all() const
{
	if (count_ == 0) {
		std::cout << "null\n";
		return;
	}
	for (unsigned int i = 0; i < count_; i++) {
		std::cout << i + 1 << " name: " << items_[i].name
			  << " plu: " << items_[i].plu
			  << " exp: " << items_[i].exp_date << "\n";
	}
	std::cout << "\n";
}

void Storage::save() const
{
	std::ofstream file(path_, std::ios::binary);

	if (!file.is_open()) {
		return;
	}

	file.write(reinterpret_cast<const char *>(&count_), sizeof(count_));
	file.write(reinterpret_cast<const char *>(items_),
		   sizeof(Item) * count_);
	file.close();
}

void Storage::load()
{
	std::ifstream file(path_, std::ios::binary);
	if (!file)
		return;

	file.read(reinterpret_cast<char *>(&count_), sizeof(count_));
	file.read(reinterpret_cast<char *>(items_), sizeof(Item) * count_);
	file.close();
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
