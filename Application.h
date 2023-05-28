#ifndef __APPLICATION__H
#define __APPLICATION__H

#include <iostream>
#include <string>

#include "BaseObject.h"
#include "DerivedObject2.h"
#include "DerivedObject3.h"
#include "DerivedObject4.h"
#include "DerivedObject5.h"
#include "DerivedObject6.h"


class Application : public BaseObject {
public:
	Application(BaseObject* root_node);
	void init();
	int run();
};

#endif
