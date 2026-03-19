#include "storage.hpp"
#include <iostream>

void Storage::add(const Item &item)
{
	if (is_exist(item))
		return;
	if (count_ >= LIMIT)
		return;

	items_[count_] = item;
	count_++;
}

void Storage::remove(const uint32_t plu, uint32_t exp_date)
{
	Item *item = find_item(plu, exp_date);
	if (!item)
		return;
	items_[get_id(*item)] = items_[count_ - 1];
	count_--;
}

void Storage::get_all() const
{
	for (unsigned int i = 0; i < count_; i++) {
		std::cout << i + 1 << ": name: " << items_[i].name
			  << " plu: " << items_[i].plu
			  << " exp date: " << items_[i].exp_date << "\n";
	}
}

int Storage::get_id(const Item &item)
{
	if (is_exist(item))
		return current_id_;
	return -1;
}

bool Storage::is_exist(const Item &item)
{
	for (unsigned int i = 0; i < count_; i++) {
		if (item.plu == items_[i].plu &&
		    item.exp_date == items_[i].exp_date) {
			current_id_ = (int)i;
			return true;
		}
	}
	return false;
}

Item *Storage::find_item(const uint32_t plu, uint32_t exp_date)
{
	for (unsigned int i = 0; i < count_; i++) {
		if (plu == items_[i].plu && exp_date == items_[i].exp_date) {
			return &items_[i];
		}
	}
	return nullptr;
}
