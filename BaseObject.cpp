#include "BaseObject.h"

BaseObject::BaseObject(BaseObject* root_node, std::string object_name) 
    : name(object_name), root_node(root_node) {
	if (root_node != nullptr && root_node->get_child_node(object_name) == nullptr)
		root_node->child_nodes.push_back(this);
}

BaseObject::~BaseObject() {
	for (auto obj : child_nodes) delete obj;
}

bool BaseObject::edit_name(std::string new_name) {
	if (root_node != nullptr) {
		if (root_node->get_child_node(new_name)) return false;
	}
	this->name = new_name;
	return true;
}

std::string BaseObject::get_name() {
	return this->name;
}

BaseObject* BaseObject::get_root_node() {
	return this->root_node;
}

BaseObject* BaseObject::get_child_node(std::string child_node_name) {
	for (auto node : child_nodes)
		if (node->name == child_node_name) return node;
	return nullptr;
}

void BaseObject::set_readiness(int level) {
	if (this->root_node == nullptr || this->root_node->readiness_level != 0) 
		this->readiness_level = level;
	if (level == 0)
		this->readiness_level = 0;
	for (auto node : this->child_nodes) {
		node->set_readiness(0);
	}
}

BaseObject* BaseObject::find_in_branch(std::string object_name) {
	BaseObject* found = this->name == object_name ? this : nullptr;
	for (auto lower_node : this->child_nodes) {
		BaseObject* lower_level_found = lower_node->find_in_branch(object_name);
		if (lower_level_found != nullptr && found == nullptr) found = lower_level_found;
		else if (lower_level_found != nullptr && found != nullptr) found = nullptr;
	}
	return found;
}

BaseObject* BaseObject::find_in_tree(std::string object_name) {
	auto root = this;
	while (root->get_root_node() != nullptr) root = root->get_root_node();
	return root->find_in_branch(object_name);
}

void BaseObject::print_hierarchy(int tabulation_level) {
	std::cout << '\n';
	for (int i = 0; i < tabulation_level; i++) std::cout << "    ";
	tabulation_level++;
	std::cout << name;
	for (auto node : child_nodes) {
		node->print_hierarchy(tabulation_level);
	}
}

void BaseObject::print_readiness_hierarchy(int tabulation_level) {
	std::cout << '\n';
	for (int i = 0; i < tabulation_level; i++) std::cout << "    ";
	tabulation_level++;
	std::cout << name << " is" << ((readiness_level != 0) ? " ready" : " not ready");
	for (auto node : child_nodes) {
		node->print_readiness_hierarchy(tabulation_level);
	}
}
