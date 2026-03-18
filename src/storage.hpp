#include "item.hpp"
#include <cstdint>
#define LIMIT 128
class Storage {
    public:
	void add(const Item &item);
	void remove(const uint32_t plu, const uint32_t exp_date);
	void get_all() const;

    private:
	Item items_[128];
	int current_id_{ -1 };
	unsigned int count_{ 0 };

	Item *find_item(const uint32_t plu, const uint32_t exp_date);
	int get_id(const Item &item);
	bool is_exist(const Item &item);
};
