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
			key = -1;
			val = 1;
			key++;
		}
		Map(initializer_list<pair<const Key_T, Mapped_T>> l): probability(0.5), maxLevel(16){
			//Potentially could set the head and tail to the same node and perhaps create an infinte loop?
			//Key_T headKey = numeric_limits<Key_T>::min();
			head = new node(l.begin()->first, l.begin()->second, maxLevel);
			auto lastElem = l.end()-sizeof(l.begin());
			tail = new node(lastElem->first, lastElem->second,maxLevel);
			for(size_t i = 0; i <  head->forward.size(); ++i){
				head->forward[i] = tail;
			}
			pair<Key_T,Mapped_T> prev;
			for(auto curr : l){
				if(head->key != curr.first && head->val != curr.second){
					insert(curr.first, curr.second);
					cout << "inserted key:" << curr.first << " val: " << curr.second <<  endl;
					prev = curr;
				}
			}
			tail = new node(prev.first, prev.second, maxLevel);
		}
		~Map(){
			delete head;
			delete tail;
			cout << "Map has been destroyed" <<endl;
		}
		Key_T randomLevel(){
			Key_T v = 1;
			while((((Key_T)std::rand()/ RAND_MAX)) < probability && abs(v) < maxLevel){
				v += 1;
			}
			return abs(v);
		}
		Key_T nodeLevel(const vector<node*> v){
			Key_T currentLevel = 1;
			Key_T tailKey = numeric_limits<Ket_T>::max();
			if(v[0]->key == tailKey){
				return currentLevel;
			}
			for(size_t i = 0; i < v.size(); ++i){
				if(v[i] != nullptr && v[i]->key != tailKey){
					++currentLevel;
				}else{
					break;
				}
			}
			return currentLevel;
		}
		void print(){
			node* list = head;
			int lineLength = 1;
			cout << "{";
			while(list->forward[0] != nullptr){
				cout << "value: " << list->forward[0]->value
				<<", key: "<< list->fowrad[0]->key
				<<", level: " nodeLevel(list->forward);

				list = list->forward[0];
				if(list->forward[0] != nullptr) cout<<" :";
				if(++lineLength %2 == 0) cout<<"\n";
			}
			cout << "}" << endl;;
		}
	//size:
		size_t size() const;
		bool empty() const;
	//nested_classes:
		class Skip_list{
			public:
				node* find(Key_T key);
				void erase(Key_T key);
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
		pair<Iterator, bool> insert(const ValueType &){
			
		}
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

