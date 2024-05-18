#pragma once

#include <iostream>
#include <memory>
#include <initializer_list>
#include <limits>
#include <algorithm>
#include <stdexcept>

template <typename T>
class Vector {
public:
    using size_type = size_t;
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using iterator = T*;
    using const_iterator = const T*;

    // Constructors
    Vector() noexcept : dat(nullptr), avail(nullptr), limit(nullptr) {}
    Vector(std::initializer_list<T> il) { create(il.begin(), il.end()); }
    
    // Fill constructor
    explicit Vector(size_type n) { create(n, T{}); }

    // Destructor
    ~Vector() { uncreate(); }

    // Copy constructor
    Vector(const Vector& v) { create(v.begin(), v.end()); }

    // Move constructor
    Vector(Vector&& v) noexcept { move_from(std::move(v)); }

    // Copy assignment
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            uncreate();
            create(other.begin(), other.end());
        }
        return *this;
    }

    // Move assignment
    Vector& operator=(Vector&& other) noexcept {
        if (this != &other) {
            uncreate();
            move_from(std::move(other));
        }
        return *this;
    }

    // Comparison operators
    friend bool operator==(const Vector<T>& lhs, const Vector<T>& rhs) {
        return lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin());
    }

    friend bool operator!=(const Vector<T>& lhs, const Vector<T>& rhs) {
        return !(lhs == rhs);
    }

    // Element access
    reference at(size_type n) {
        if (n >= size())
            throw std::out_of_range("Index out of range");
        return dat[n];
    }

    const_reference at(size_type n) const {
        if (n >= size())
            throw std::out_of_range("Index out of range");
        return dat[n];
    }

    reference operator[](size_type n) { return dat[n]; }
    const_reference operator[](size_type n) const { return dat[n]; }

    reference front() { return dat[0]; }
    const_reference front() const { return dat[0]; }
    reference back() { return dat[size() - 1]; }
    const_reference back() const { return dat[size() - 1]; }

    value_type* data() noexcept { return dat; }
    const value_type* data() const noexcept { return dat; }

    // Iterators
    iterator begin() noexcept { return dat; }
    const_iterator begin() const noexcept { return dat; }
    iterator end() noexcept { return avail; }
    const_iterator end() const noexcept { return avail; }

    // Capacity
    bool empty() const noexcept { return size() == 0; }
    size_type capacity() const noexcept { return limit - dat; }
    size_type size() const noexcept { return avail - dat; }
    size_type max_size() const noexcept { return std::numeric_limits<size_type>::max(); }
    void reserve(size_type n) {
        if (n > capacity()) {
            reallocate(n);
        }
    }

        void resize(size_type sz) {
        if (sz < size()) {
            destroy_elements(dat + sz, avail);
            avail = dat + sz;
        } else {
            if (sz > capacity()) {
                reserve(sz);
            }
            std::uninitialized_fill(avail, dat + sz, T());
            avail = dat + sz;
        }
    }

    void resize(size_type sz, const value_type& value) {
        if (sz < size()) {
            destroy_elements(dat + sz, avail);
            avail = dat + sz;
        } else {
            if (sz > capacity()) {
                reserve(sz);
            }
            std::uninitialized_fill(avail, dat + sz, value);
            avail = dat + sz;
        }
    }

    void shrink_to_fit() {
        if (limit > avail) {
            reallocate(size());
        }
    }

    // Modifiers
    void clear() noexcept { uncreate(); }

    void push_back(const value_type& val) {
        if (avail == limit) {
            grow();
        }
        alloc.construct(avail++, val);
    }

    void push_back(value_type&& val) {
        if (avail == limit) {
            grow();
        }
        alloc.construct(avail++, std::move(val));
    }

    void pop_back() {
        if (avail != dat) {
            alloc.destroy(--avail);
        }
    }

    iterator insert(iterator position, const value_type& val) {
        return insert(position, 1, val);
    }

    iterator insert(iterator position, size_type n, const value_type& val) {
        size_type index = position - begin();
        if (avail + n > limit) {
            grow(size() + n);
            position = begin() + index;
        }
        std::move_backward(position, avail, avail + n);
        std::uninitialized_fill(position, position + n, val);
        avail += n;
        return position;
    }

    iterator erase(iterator position) {
        if (position < dat || position >= avail) {
            throw std::out_of_range("Index out of range");
        }
        std::move(position + 1, avail, position);
        alloc.destroy(--avail);
        return position;
    }

    iterator erase(iterator first, iterator last) {
        if (first < dat || last > avail || first > last) {
            throw std::out_of_range("Index out of range");
        }
        iterator new_avail = std::move(last, avail, first);
        destroy_elements(new_avail, avail);
        avail = new_avail;
        return first;
    }

private:
    iterator dat = nullptr;
    iterator avail = nullptr;
    iterator limit = nullptr;
    std::allocator<T> alloc;

    void create() noexcept { dat = avail = limit = nullptr; }

    template <class InputIterator>
    void create(InputIterator first, InputIterator last) {
        dat = alloc.allocate(last - first);
        avail = limit = std::uninitialized_copy(first, last, dat);
    }

    void uncreate() noexcept {
        if (dat) {
            destroy_elements(dat, avail);
            alloc.deallocate(dat, limit - dat);
        }
        dat = avail = limit = nullptr;
    }

    void grow(size_type new_capacity = 1) {
        size_type new_size = std::max(new_capacity, 2 * capacity());
        reallocate(new_size);
    }

    void reallocate(size_type new_size) {
        iterator new_data = alloc.allocate(new_size);
        iterator new_avail = std::uninitialized_copy(dat, avail, new_data);
        destroy_elements(dat, avail);
        alloc.deallocate(dat, limit - dat);
        dat = new_data;
        avail = new_avail;
        limit = dat + new_size;
    }

    void destroy_elements(iterator first, iterator last) noexcept {
        while (first != last) {
            alloc.destroy(--last);
        }
    }

    void move_from(Vector&& other) noexcept {
        dat = other.dat;
        avail = other.avail;
        limit = other.limit;
        other.dat = other.avail = other.limit = nullptr;
    }

};

