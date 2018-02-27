#pragma once
#include "Node.h"

template <typename T>
class LinkedList
{
public:

	LinkedList()
	{
		head = nullptr;
	}

	void addElement(T elementPayload) {
		std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>();
		newNode->payload = elementPayload;
		newNode->next = nullptr;
		if (head == nullptr) {
			head = newNode;
			return;
		}
		std::shared_ptr<Node<T>> curNode = head;
		while (curNode->next) {
			curNode = curNode->next;
		}
		curNode->next = newNode;
	}

	void addElementAt(T elementPayload, int index) {
		std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>();
		newNode->payload = elementPayload;
		if (index == 0) {
			newNode->next = head;
			head = newNode;
			return;
		}

		auto targetNode = getNthNode(index - 1);
		newNode->next = targetNode->next;
		targetNode->next = newNode;
	}

	void removeElementAt(int index) {
		if (index == 0) {
			head = head->next;
			return;
		}
		auto targetNode = getNthNode(index - 1);
		targetNode->next = targetNode->next->next;
	}

	void updateElementAt(T newPayload, int index) {
		getNthNode(index)->payload = newPayload;
	}

	T getElementAt(int index) {
		return getNthNode(index)->payload;
	}

	void empty() {
		head = nullptr;
	}

	std::shared_ptr<Node<T>> getNthNode(int index) {
		std::shared_ptr<Node<T>> cur = head;
		for (int i = 0; i < index; i++) {
			cur = cur->next;
			if (!cur) {
				auto blankShared = std::make_shared<Node<T>>();
				return blankShared;
			}
		}
		return cur;
	}

	~LinkedList()
	{
	}

private:
	std::shared_ptr<Node<T>> head;
};

