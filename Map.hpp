#include <iostream>
#include <utility>
#include <iterator>
#include <vector>
#include <limits>
#include <initializer_list>

using namespace std;

template <typename Key_T, typename Mapped_T>
class Map{
	public:
	//constructor_and_assignments:
		struct ValueType{
			pair<const Key_T, Mapped_T>types;
		};
		struct node{
			Key_T key;
			Mapped_T val;
			vector<node*> forward;
			node(Key_T k, Mapped_T v, int level): key(k), val(v) {
				for(int i = 0; i < level; ++i) forward.emplace_back(nullptr);
			}
		};
		node* head;
		node* tail;
		float probability;
		int maxLevel;
		Map(): probability(0.5), maxLevel(16){
			//*****Chance to segfault for adding uninitialised data
			head = nullptr;
			tail = nullptr;
			for(size_t i = 0; i < head->forward.size(); ++i){
				head->forward[i] = tail;
			}
		}
		Map(const Map& m): probability(0.5), maxLevel(16){
			if(m->head != nullptr){
				head->key = m->head->key;
				head->val = m->head->val;
			}
			else{
				head = nullptr;
			}
			if(m->tail != nullptr){
				tail->key = m->tail->key;
				tail->val = m->tail->val;
			}
			else{
				tail = nullptr;
			}
			for(int i = 0; i < m->head->forward.size(); ++i){
				head->foward[i] = tail;;
			}
		}
		Map &operator=(const Map& m){
			probability = 0.5;
			maxLevel = 16;
			if(m->head != nullptr){
				Key_T headKey = numeric_limits<Key_T>::min();
				head = new node(headKey, m->head->val, maxLevel);
			}
			else{
				head = nullptr;
			}
			if(m->tail != nullptr){
				Key_T tailKey = numeric_limits<Key_T>::max();
				tail = new node(tailKey, m->tail->val, maxLevel);
			}
			else{
				tail = nullptr;
			}
			Key_T tempk;
			Mapped_T tempv;
			for(int i = 0; i < m->head->forward.size(); ++i){
				tempk = m->forward[i]->key;
				tempv = m->foward[i]->key;
				head->forward[i] = new node(tempk, tempv, maxLevel);
			}

		}
		void insert(Key_T key, Mapped_T val){
			
		}
		Map(initializer_list<pair<const Key_T, Mapped_T>> l): probability(0.5), maxLevel(16){
			//Potentially could set the head and tail to the same node and perhaps create an infinte loop?
			Key_T headKey = numeric_limits<Key_T>::min();
			head = new node(headKey, l.begin()->second, maxLevel);
			Key_T tailKey = numeric_limits<Key_T>::max();
			tail = new node(tailKey, l.end()->second, maxLevel);
			for(size_t i = 0; i <  head->forward.size(); ++i){
				head->forward[i] = tail;
			}
			for(auto curr : l){
				if((head->key != curr.first && head->val != curr.second) || (tail->key != curr.first && tail->val != curr.second)){
					insert(curr.first, curr.second);
					cout << "inserted element from init that isnt head or tail" << endl;
				}
			}
		}
		~Map(){
			delete head;
			delete tail;
			cout << "Map has been destroyed" <<endl;
		}
	//size:
		size_t size() const;
		bool empty() const;
	//nested_classes:
		class Skip_list{
			public:
				~Skip_list();
				void print();
				node* find(Key_T key);
				void erase(Key_T key);
				int randomLevel();
				int nodeLevel(const vector<node*> v);
				node* makeNode(Key_T key, Mapped_T val, int level);
		};
		class Iterator{
			public:
				Iterator(const Iterator& addr);
				~Iterator();
				Iterator& operator=(const Iterator& addr);
				Iterator& operator++();
				Iterator& operator++(int);
				Iterator& operator--();
				Iterator& operator--(int);
				ValueType& operator*() const;
				ValueType* operator->() const;
				bool operator==(const Iterator& addr2);
		};

		class ConstIterator{
			public:
				ConstIterator(const ConstIterator& addr);
				ConstIterator(const Iterator& addr);
				~ConstIterator();
				ConstIterator& operator=(const ConstIterator& addr);
				ConstIterator& operator++();
				ConstIterator operator++(int);
				ConstIterator& operator--();
				ConstIterator operator--(int);
				const ValueType& operator*() const;
				const ValueType* operator->() const;
				bool operator==(const ConstIterator& addr2);
				bool operator==(const Iterator& addr2);
				bool operator!=(const ConstIterator& addr2);
				bool operator!=(const Iterator& addr2);
		};

		class ReverseIterator{
			public:
				ReverseIterator(const ReverseIterator& addr);
				~ReverseIterator();
				ReverseIterator& operator=(const ReverseIterator& addr);
				ReverseIterator& operator++();
				ReverseIterator operator++(int);
				ReverseIterator& operator--();
				ReverseIterator operator--(int);
				const ValueType& operator*() const;
				const ValueType* operator->() const;
		};
	//Iterators:
		Iterator begin();
		Iterator end();
		ConstIterator begin() const;
		ConstIterator end() const;
		ReverseIterator rbegin();
		ReverseIterator rend();
	//Element Access:
		Iterator find(const Key_T& addr);
		const Iterator find(const Key_T& addr) const;
		Mapped_T &at(const Key_T &) const;
		Mapped_T &operator[](const Key_T &);
	//modifiers:
		pair<Iterator, bool> insert(const ValueType &);
		template <typename IT_T>
		void insert(IT_T range_beg, IT_T range_end);
		void erase(Iterator pos);
		void erase(const Key_T& addr);
		void clear();
	//comparison (keep in mind the first argument is 'this':
		bool operator==(const Map& addr2);
		bool operator!=(const Map& addr2);
		bool operator<(const Map& addr2);

		bool operator==(const ConstIterator& addr2);


		bool operator!=(const Iterator& addr2);
		bool operator!=(const ConstIterator& addr2);

		bool operator==(const ReverseIterator& addr2);
		bool operator!=(const ReverseIterator& addr2);

};

