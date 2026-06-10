#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

template <typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

template <typename T1, typename T2>
auto addValues(T1 a, T2 b) -> decltype(a + b) {
    return a + b;
}

template <typename A, typename B>
class Pair {
private:
    A first_;
    B second_;

public:
    Pair(A first, B second)
        : first_(first), second_(second) {
    }

    A getFirst() const {
        return first_;
    }

    B getSecond() const {
        return second_;
    }

    void setFirst(A value) {
        first_ = value;
    }

    void setSecond(B value) {
        second_ = value;
    }

    void swapValues() {
        auto temp = first_;
        first_ = second_;
        second_ = temp;
    }
};

template <typename T>
class Box {
private:
    std::vector<T> items_;

public:
    void add(const T& item) {
        items_.push_back(item);
    }

    int size() const {
        return static_cast<int>(items_.size());
    }

    T get(int index) const {
        if (index < 0 || index >= size()) {
            throw std::out_of_range("Invalid index");
        }
        return items_[index];
    }

    T total() const {
        T sum = T();

        for (const auto& item : items_) {
            sum += item;
        }

        return sum;
    }
};

template <typename T>
int describe(const T& value) {
    return 1;
}

template <>
int describe<std::string>(const std::string& value) {
    return 2 + static_cast<int>(value.length());
}

template <typename T, int N>
class FixedArray {
private:
    T data_[N];

public:
    FixedArray() {
        for (int i = 0; i < N; ++i) {
            data_[i] = T();
        }
    }

    int capacity() const {
        return N;
    }

    void set(int index, const T& value) {
        if (index < 0 || index >= N) {
            throw std::out_of_range("Invalid index");
        }

        data_[index] = value;
    }

    T at(int index) const {
        if (index < 0 || index >= N) {
            throw std::out_of_range("Invalid index");
        }

        return data_[index];
    }
};

int main() {
    std::cout << "=== C++ Templates Lab ===\n";

    std::cout << "maxValue(3, 7) = " << maxValue(3, 7) << "\n";
    std::cout << "addValues(5, 2.5) = " << addValues(5, 2.5) << "\n";

    Pair<int, int> p(10, 20);
    p.swapValues();
    std::cout << "Pair: " << p.getFirst() << ", " << p.getSecond() << "\n";

    Box<int> b;
    b.add(5);
    b.add(10);
    b.add(15);
    std::cout << "Box total = " << b.total() << "\n";

    std::cout << "describe(42) = " << describe(42) << "\n";
    std::cout << "describe(\"hello\") = " << describe(std::string("hello")) << "\n";

    FixedArray<int, 3> arr;
    arr.set(0, 100);
    arr.set(1, 200);
    arr.set(2, 300);

    std::cout << "FixedArray capacity = " << arr.capacity() << "\n";
    std::cout << "arr[1] = " << arr.at(1) << "\n";

    return 0;
}
