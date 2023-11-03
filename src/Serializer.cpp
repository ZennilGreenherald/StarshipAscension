#include "./include/Serializer.h"

#include <cstring>
#include <cstddef>

Serializer::~Serializer()
{
	delete[] data;
}

Serializer::Serializer()
	: data(nullptr), size(0), offset(0)
{
}

Serializer::Serializer(const size_t size)
	: data(new unsigned char[size]), size(size), offset(0)
{
}

Serializer::Serializer(const unsigned char* data, const size_t size)
	: data(new unsigned char[size]), size(size), offset(0)
{
	memcpy(this->data, data, size);
}

Serializer::Serializer(Serializer&& ser) noexcept
	: data(ser.data), size(ser.size), offset(ser.offset)
{
	ser.data = nullptr;
	ser.size = 0;
	ser.offset = 0;
}

Serializer::Serializer(const Serializer& ser)
	: data(new unsigned char[ser.size]), size(ser.size), offset(ser.offset)
{
	memcpy(data, ser.data, size);
}

Serializer& Serializer::operator=(Serializer&& ser) noexcept
{
	if (this == &ser)
		return *this;

	delete[] data;
	data = ser.data;
	size = ser.size;
	offset = ser.offset;

	ser.data = nullptr;
	ser.size = 0;
	ser.offset = 0;

	return *this;
}

Serializer& Serializer::operator=(const Serializer& ser)
{
	if (this == &ser)
		return *this;

	delete[] data;
	data = new unsigned char[ser.size];

	memcpy(data, ser.data, ser.size);

	size = ser.size;
	offset = ser.offset;

	return *this;
}

Serializer::operator unsigned char*() const
{
	return data;
}

void Serializer::Release()
{
	delete[] data;
	data = nullptr;
	size = 0;
	offset = 0;
}

void Serializer::setSize(const size_t newSize)
{
	if (size == newSize)
		return;

	unsigned char* result = new unsigned char[newSize];
	memcpy(result, data, size);
	delete[] data;
	data = result;
	size = newSize;
}

size_t Serializer::getSize() const
{
	return size;
}

void Serializer::setOffset(const size_t newOffset)
{
	if (newOffset > size - 1)
		offset = size - 1;
	else
		offset = newOffset;
}

size_t Serializer::getOffset() const
{
	return offset;
}

void Serializer::reset()
{
	offset = 0;
}

void Serializer::writeStr(const std::string& str)
{
	if (str.size() + sizeof(size_t) > size - offset)
		setSize(size + str.size() + sizeof(size_t) - size - offset);

	*(size_t*)&data[offset] = str.size();
	offset += sizeof(size_t);

	memcpy(data, &str[0], str.size());
	offset += str.size();
}

void Serializer::writeVec2D(const Vector2D& vec)
{
	if (sizeof(uint32_t) * 2 > size - offset)
		setSize(size + sizeof(uint32_t) * 2 - size - offset);

	memcpy(data, &((char*)&vec)[offsetof(Vector2D, x_)], sizeof(uint32_t));

	offset += sizeof(uint32_t) * 2;
}

std::string Serializer::readStr()
{
	if (sizeof(size_t) > size - offset)
		return {};

	std::string result(&data[offset + sizeof(size_t)], &data[offset]);

	offset += sizeof(size_t) + result.size();

	return result;
}

Vector2D Serializer::readVec2D()
{
	if (sizeof(uint32_t) * 2 > size - offset)
		return {};

	Vector2D result;

	memcpy(&((char*)&result)[offsetof(Vector2D, x_)], &data[offset], sizeof(uint32_t));

	offset += sizeof(uint32_t) * 2;

	return result;
}
