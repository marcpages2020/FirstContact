#ifndef __DUMMY_H__
#define __DUMMY_H__

#include "Module.h"
#include "Globals.h"

class ModuleDummy : public Module
{
	bool Init()
	{
		LOG("Dummy Init! \n");
		return true;
	}

	update_status PreUpdate()
	{
		LOG("Dummy PreUpdate! \n");
		return update_status::UPDATE_CONTINUE;
	}

	update_status Update()
	{
		LOG("Dummy Update! \n");
		return update_status::UPDATE_CONTINUE;
	}

	update_status PostUpdate()
	{
		LOG("Dummy PostUpdate! \n");
		return update_status::UPDATE_CONTINUE;
	}

	bool CleanUp()
	{
		LOG("Dummy CleanUp! \n");
		return true;
	}
};

#endif // __DUMMY_H__