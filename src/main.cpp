#include "storage.hpp"
#include <cstring>

int main()
{
	Item item1;
	item1.plu = 12345;
	item1.exp_date = 20262203;
        strncpy(item1.name, "Milk", 64);

	Item item2;
	item2.plu = 22345;
	item2.exp_date = 20262203;
        strncpy(item2.name, "Milk", 64);

	Item item3;
	item3.plu = 32345;
	item3.exp_date = 20262203;
        strncpy(item3.name, "Milk", 64);

	Item item4;
	item4.plu = 15345;
	item4.exp_date = 20262203;
        strncpy(item4.name, "Milk", 64);

	Storage str;

	str.get_all();

	str.add(item1);
	str.add(item2);
	str.add(item3);
	str.add(item4);

	str.get_all();
}
