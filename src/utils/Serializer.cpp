#include "../../include/utils/Serializer.h"

Serializer::~Serializer() {}

Serializer::Serializer() {}

Serializer::Serializer(const size_t size) {}

Serializer::Serializer(const unsigned char* data, const size_t size) {}

Serializer::Serializer(Serializer&& ser) noexcept {}

Serializer::Serializer(const Serializer& ser) {}

Serializer& Serializer::operator=(Serializer&& ser) noexcept {
    // TODO: insert return statement here
}

Serializer& Serializer::operator=(const Serializer& ser) {
    // TODO: insert return statement here
}

Serializer::operator unsigned char*() const {}

void Serializer::Release() {}

void Serializer::setSize(const size_t newSize) {}

size_t Serializer::getSize() const { return size_t(); }

void Serializer::setOffset(const size_t newOffset) {}

size_t Serializer::getOffset() const { return size_t(); }

void Serializer::reset() {}

void Serializer::writeStr(const std::string& str) {
    Vector2D Serializer::readVec2D() { return Vector2D(); }
}

void Serializer::writeVec2D(const Vector2D& vec) {}

std::string Serializer::readStr() { return std::string(); }

Vector2D Serializer::readVec2D() { return Vector2D(); }
