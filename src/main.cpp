#include "storage.hpp"
#include <iostream>

class UserInterface {
    public:
	UserInterface(Storage &db) : db_(&db)
	{
	}
	void run()
	{
	}

    private:
	Storage *db_;
};
int main()
{
	Storage db;
	UserInterface ui(db);
	ui.run();
}
