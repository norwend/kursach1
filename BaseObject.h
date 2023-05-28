#ifndef __BASEOBJECT__H
#define __BASEOBJECT__H

#include <iostream>
#include <string>
#include <vector>

class BaseObject {
private:
	std::string name;
	BaseObject* root_node;
	std::vector<BaseObject*> child_nodes;
	
	int readiness_level = 0;
public:
	BaseObject(BaseObject* root_node, std::string object_name = "base_name");
	~BaseObject();
	bool edit_name(std::string new_name);
	std::string get_name();
	BaseObject* get_root_node();
	BaseObject* get_child_node(std::string child_node_name);
	
	void set_readiness(int level);
	BaseObject* find_in_branch(std::string object_name);
	BaseObject* find_in_tree(std::string object_name);
	void print_hierarchy(int tabulation_level = 0);
	void print_readiness_hierarchy(int tabulation_level = 0);
};

#endif
