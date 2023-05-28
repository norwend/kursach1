#include "Application.h"
	
Application::Application(BaseObject* root_node) : BaseObject(root_node) {}

void Application::init() {
	std::string appendee_name, child_name;
	int level;
	std::cin >> appendee_name;
	this->edit_name(appendee_name);
	BaseObject* prev = this;
	
	while (true) {
		std::cin >> appendee_name;
		if (appendee_name == "endtree") break;
		prev = this->find_in_tree(appendee_name);
		std::cin >> child_name >> level;
		auto found = this->find_in_branch(child_name);
		if (found != nullptr || level > 6 || level < 2) 
			continue;
		switch (level) {
			case 2:
				prev = new DerivedObject2(prev, child_name);
				break;
			case 3:
				prev = new DerivedObject3(prev, child_name);
				break;
			case 4:
				prev = new DerivedObject4(prev, child_name);
				break;
			case 5:
				prev = new DerivedObject5(prev, child_name);
				break;
			case 6:
				prev = new DerivedObject6(prev, child_name);
				break;
			default:
				break;
		}
	}

	while (std::cin >> appendee_name) {
		std::cin >> level;
		prev = this->find_in_tree(appendee_name);
		if (prev != nullptr) prev->set_readiness(level);
	}
}

int Application::run() {
	std::cout << "Object tree";
	this->print_hierarchy();
	std::cout << "\nThe tree of objects and their readiness";
	this->print_readiness_hierarchy();
	return 0;
}
