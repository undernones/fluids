// License: See distributed LICENSE file.

#ifndef FLUID_ARRAY_H
#define FLUID_ARRAY_H

#include <vector>
#include <stdexcept>

/// A 3-dimensional array of objects of any type.
template <class T>
class Array
{
public:
    // Default constructor
    //
    explicit Array()
        : mData()
        , mWidth(0)
        , mHeight(0)
        , mDepth(0)
    {}

    // Typical constructor
    //
    explicit Array(unsigned width, unsigned height, unsigned depth)
        : mData()
        , mWidth(width)
        , mHeight(height)
        , mDepth(depth)
    {
        mData.resize(width * height * depth);
    }

    // Copy constructor
    explicit Array(const Array& other)
        : mData(other.mData)
        , mWidth(other.mWidth)
        , mHeight(other.mHeight)
        , mDepth(other.mDepth)
    {}

    // Destructor
    //
    ~Array()
    {}

    // Assignment operator
    //
    Array& operator =(const Array& rhs)
    {
        if (this != &rhs) {
            mData = rhs.mData;
            mWidth = rhs.mWidth;
            mHeight = rhs.mHeight;
            mDepth = rhs.mDepth;
        }
        return *this;
    }

    unsigned size() const
    {
        return mData.size();
    }

    T& operator ()(unsigned i, unsigned j, unsigned k)
    {
        if (i >= mWidth) throw std::out_of_range("i");
        if (j >= mHeight) throw std::out_of_range("j");
        if (k >= mDepth) throw std::out_of_range("k");

        return mData[(i*mHeight*mDepth) + (j*mDepth) + k];
    }

    const T& operator ()(unsigned i, unsigned j, unsigned k) const
    {
        const Array<T>* arr = const_cast<Array<T>*>(this);
        return const_cast<T&>((*arr)(i, j, k));
    }

private:
    std::vector<T> mData;
    unsigned mWidth;
    unsigned mHeight;
    unsigned mDepth;
};

#endif // FLUID_ARRAY_H

