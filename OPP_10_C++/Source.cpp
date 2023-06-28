#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <array>

template <typename Type,const int _size>
class MyClass {
public:
	// Type and At ��� ������ ���� ���������� ������ 
	const Type& operator[](int  i)const {
		return data_[i];
	}

	Type& operator[](int  i) {
		return data_[i];
	}

	auto at(int  i) -> Type& {
		return data_[i];
	}

	auto at(int  i)const ->Type & {
		return data_[i];
	}

	int size()const {
		return size_;
	}

	class iterator {
	private:
		Type* data_;
		
	public:
		iterator() = delete;
		iterator(Type*data) : data_(data){ }
		iterator& operator ++() {
			data_++;
			return *this;
		}
		iterator& operator ++(int) {
			iterator tmp(*this);
			data_++;
			return tmp;
		}

		bool operator == (const iterator& obj)const {
			return this->data_ == obj.data_;
		}

		bool operator != (const iterator& obj)const {
			return !this->operator== (obj);
			//����� ����� �������� ���� ������� �������� �������� ������� ������� ��� ������ �������
		}

		Type& operator*() {
			return *data_;
		}
	};
	iterator begin() {
		return iterator(data_);
	}

	iterator end() {
		return iterator(data_ + size_);
	}

private:
	Type data_[_size];
	const int size_{_size};
};

void f01(MyClass <int,10> a) {
	for (size_t i = 0; i < a.size(); i++) {
		std::cout << a[i] << ' ';
	}
}
int main() {
	setlocale(LC_ALL, "ru");
	MyClass<int, 10> a;
	for (size_t i = 0; i < a.size(); i++) {
		a[i] = i + 1;
	}
	f01(a);

	int arr[10];
	for (size_t i = 0; i < std::size(arr); i++) {
		arr[i] = i + 1;
	}
	std::cout << '\n';
	for (int &it : arr) {
		std::cout << it << ' ';
	}

	std::cout << "\n\n";

	std::array<int, 10> arrObj;
	for (size_t i = 0; i < std::size(arrObj); i++) {
		arrObj[i] = i + 10;
	}
	std::cout << '\n';
	for (const auto& it : arrObj) {
		std::cout << it << ' ';
	}

	std::cout << '\n';
	for (auto it = arrObj.begin(); it != arrObj.end();++ it) {
		const auto& el = *it;
		//it->operator[](0);
		std::cout << el << ' ';
		/*arrObj.rbegin(); ������ ������, ������� ������� � �����
		arrObj.cbegin(); ����������� ������
		arrObj.crbegin(); ����������� ������ ������ ��� �� � �����*/
	}

	// auto == std::array<int, 10 > :: iterator �� �� ����� ������ 
	std::cout << '\n';
	for (const auto& el : a) {
		std::cout << el << ' ';
	}



	return 0;
} 