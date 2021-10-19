#include <iostream>
#include <utility>
#include <iterator>

using namespace std;

template <typename Key_T, typename Mapped_T>
class Map{
	public:
	//constructor_and_assignments:
		struct ValueType{
			pair<const Key_T, Mapped_T>types;
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

