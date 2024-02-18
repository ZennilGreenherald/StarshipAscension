#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <cstdint>
#include <string>

#include "vector2d.h"

class Serializer
{
private:
	unsigned char* data;
	size_t size;
	size_t offset;

public:
	~Serializer();

	Serializer();

	Serializer(const size_t size);

	Serializer(const unsigned char* data, const size_t size);

	Serializer(Serializer&& ser) noexcept;

	Serializer(const Serializer& ser);

	Serializer& operator=(Serializer&& ser) noexcept;

	Serializer& operator=(const Serializer& ser);

	operator unsigned char*() const;

	void Release();

	void setSize(const size_t newSize);

	size_t getSize() const;

	void setOffset(const size_t newOffset);

	size_t getOffset() const;

	void reset();

	template<typename T>
	void write(const T in)
	{
		if (sizeof(T) > size - offset)
			setSize(size + sizeof(T) - size - offset);

		*(T*)&data[offset] = in;
		offset += sizeof(T);
	}

	void writeStr(const std::string& str);

	void writeVec2D(const Vector2D& vec);

	template<typename T>
	T read()
	{
		if (sizeof(T) > size - offset)
			return {};

		T result = *(T*)&data[offset];
		offset += sizeof(T);
		return result;
	}

	std::string readStr();

	Vector2D readVec2D();
};


#endif