#include "item.hpp"
#define LIMIT 128

class Storage {
    public:
	void add(const Item &item);
	void remove(Item &item);
	void get_all() const;

        void write() const;
        void read();
    private:
	Item items_[128];
	int current_id_{ -1 };
	unsigned int count_{ 0 };

	int get_id(const Item &item);
	bool is_exist(const Item &item);

        Item *find_item(Item &item);
};
