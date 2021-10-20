#include <iostream>
#include <utility>
#include <iterator>
#include <vector>

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
			node(int k, Key_T v, int level){

			}
			vector<node*> forwrad;

		};
		Map();
		Map(const Map& addr);
		Map &operator=(const Map & addr);
		Map(initializer_list<pair<const Key_T, Mapped_T>>);
		~Map();
	//size:
		size_t size() const;
		bool empty() const;
	//nested_classes:
		class Skip_list{
			public:
				Skip_list();
				~Skip_list();
				void print();
				node* find(Key_T key);
				void insert(Key_T key, Mapped_T val);
				void erase(Key_T key);
				node* head;
				node* tail;
				int randomLevel();
				int nodeLevel(const vector<node*> v);
				node* makeNode(Key_T key, Mapped_T val, int level);
				float probability;
				int maxLevel;
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

	//iterators:
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

