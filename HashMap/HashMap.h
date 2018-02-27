#pragma once
#include <memory>

class HashMap {
public:
	HashMap(unsigned int mapSize);
	~HashMap();
	int addNode(char* newValue);

private:
	struct HashMapNode
	{
		char payload[20];
		std::shared_ptr<HashMapNode> next;
	};
	unsigned int hashMapSize;
	std::shared_ptr<HashMapNode>* nodeArray;
	HashMap();
	void GetIndex(unsigned long &ulIndex, const char *zKey1);
	std::shared_ptr<HashMapNode> getLastNode(std::shared_ptr<HashMapNode> start);
};

inline HashMap::HashMap(unsigned int mapSize)
{
	hashMapSize = mapSize;
	nodeArray = new std::shared_ptr<HashMapNode>[mapSize];
	memset(nodeArray, 0, sizeof(nodeArray) * hashMapSize);
}

inline HashMap::~HashMap()
{
	delete[] nodeArray;
}

inline int HashMap::addNode(char * newValue)
{
	unsigned long mapIndex = 0;
	std::shared_ptr<HashMapNode> newNode = std::make_shared<HashMapNode>();
	strcpy_s(newNode->payload, 20, newValue);
	newNode->next = nullptr;
	GetIndex(mapIndex, newNode->payload);
	if (nodeArray[mapIndex] == nullptr) {
		nodeArray[mapIndex] = newNode;
	}
	else {
		std::shared_ptr<HashMapNode> lastNode = getLastNode(nodeArray[mapIndex]);
		lastNode->next = newNode;
	}
	return mapIndex;
}

inline std::shared_ptr<HashMap::HashMapNode> HashMap::getLastNode(std::shared_ptr<HashMapNode> start)
{
	while (start->next != nullptr) {
		start = start->next;
	}
	return start;
}

inline void HashMap::GetIndex(unsigned long & ulIndex, const char * zKey1)
{
	ulIndex = 0;
	char *acIndex = (char*)&ulIndex;

	int i;
	for (i = 0; zKey1[i] != '\0'; i++)
	{
		int n = i % 4;
		acIndex[n] = acIndex[n] ^ zKey1[i];
	}

	ulIndex = ulIndex % hashMapSize;

}