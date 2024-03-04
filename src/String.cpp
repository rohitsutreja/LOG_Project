#include <iostream>
#include <stdio.h>
#include <memory>
#include "..\include\String.h"

using Exception::StringException;
using Util::String;

String::String(const char* str) : m_size(strlen(str))
{
	try
	{
		m_Buffer = std::make_unique<char[]>(m_size + 1);
	}
	catch (std::bad_alloc)
	{
		throw StringException{ "String: No enough memory" };
	}

	memcpy(m_Buffer.get(), str, m_size);
	m_Buffer.get()[m_size] = '\0';
}

String::String(const String& other) : m_size(other.m_size)
{
	try
	{
		m_Buffer = std::make_unique<char[]>(m_size + 1);
	}
	catch (std::bad_alloc)
	{
		throw StringException{ "String: No enough memory" };
	}

	memcpy(m_Buffer.get(), other.m_Buffer.get(), m_size + 1);
}

String::String(String&& other) noexcept
	: m_Buffer{ std::move(other.m_Buffer) }, m_size{ other.m_size } {}

size_t String::length() const { return m_size; }

bool String::empty() const
{
	if (m_size == 0)
		return true;
	return false;
};

size_t String::indexOf(char character) const
{
	auto i{ 0 };
	while (i < m_size)
	{
		if (m_Buffer.get()[i] == character)
		{
			return i;
		}
		++i;
	}
	return -1;
}

String String::substring(size_t index, size_t size) const
{
	if (size == -1)
	{
		size = m_size;
	}

	if (index >= m_size || index < 0)
	{
		throw StringException{ "Index out bound" };
	}

	std::unique_ptr<char[]> newBuffer;
	try
	{
		newBuffer = std::make_unique<char[]>(m_size + 1);
	}
	catch (std::bad_alloc)
	{
		throw StringException{ "String: No enough memory" };
	}
	memcpy(newBuffer.get(), m_Buffer.get() + index, size);

	newBuffer.get()[size] = '\0';

	String result{ newBuffer.get() };

	return result;
};

String String::toString(int num)
{
	if (num == 0)
	{
		return { "0" };
	}

	auto size{ 0 };
	auto temp{ num };

	if (num < 0)
	{
		size++;
		temp = -num;
	}

	while (temp > 0)
	{
		temp /= 10;
		++size;
	}

	std::unique_ptr<char[]> newBuffer;
	try
	{
		newBuffer = std::make_unique<char[]>(size + 1);
	}
	catch (std::bad_alloc)
	{
		throw StringException{ "String: No Enough Memory" };
	}

	newBuffer.get()[size] = '\0';

	if (num < 0)
	{
		newBuffer.get()[0] = '-';
		num = -num;
	}

	auto i{ size - 1 };
	while (num > 0)
	{
		newBuffer.get()[i] = num % 10 + '0';
		num /= 10;
		i--;
	}

	String result{ newBuffer.get() };

	return result;
}

String& String::append(const String& other)
{

	std::unique_ptr<char[]> newBuffer;
	try
	{
		newBuffer = std::make_unique<char[]>(m_size + other.m_size + 1);
	}
	catch (std::bad_alloc)
	{
		throw StringException{ "String: No Enough memory available" };
	}

	memcpy(newBuffer.get(), m_Buffer.get(), m_size);
	memcpy(newBuffer.get() + m_size, other.m_Buffer.get(), other.m_size + 1);

	m_Buffer = std::move(newBuffer);
	m_size = m_size + other.m_size;

	return *this;
}

String String::reverse() const
{

	std::unique_ptr<char[]> newBuffer;
	try
	{
		newBuffer = std::make_unique<char[]>(m_size + 1);
	}
	catch (std::bad_alloc)
	{

		throw StringException{ "String: No Enough memory available" };
	}

	for (auto i{ 0 }; i < m_size; i++)
	{
		newBuffer.get()[i] = m_Buffer.get()[m_size - i - 1];
	}
	newBuffer.get()[m_size] = '\0';

	String result{ newBuffer.get() };

	return result;
};

String& String::toUpperCase() noexcept
{
	auto i{ 0 };
	while (m_Buffer.get()[i] != 0)
	{
		if (m_Buffer.get()[i] >= 'a' && m_Buffer.get()[i] <= 'z')
		{
			m_Buffer.get()[i] = m_Buffer.get()[i] - 32;
		}

		++i;
	}
	return *this;
};
String& String::toLowerCase() noexcept
{
	auto i{ 0 };
	while (m_Buffer.get()[i] != 0)
	{
		if (m_Buffer.get()[i] >= 'A' && m_Buffer.get()[i] <= 'Z')
		{
			m_Buffer.get()[i] = m_Buffer.get()[i] + 32;
		}
		++i;
	}

	return *this;
};

String Util::operator+(const String& str1, const String& str2)
{

	std::unique_ptr<char[]> newBuffer;
	try
	{
		newBuffer = std::make_unique<char[]>(str1.m_size + str2.m_size + 1);
	}
	catch (std::bad_alloc)
	{
		throw StringException{ "String: No Enough memory available" };
	}

	memcpy(newBuffer.get(), str1.m_Buffer.get(), str1.m_size);
	memcpy(newBuffer.get() + str1.m_size, str2.m_Buffer.get(), str2.m_size + 1);

	String result{ newBuffer.get() };

	return result;
}

String& Util::String::operator=(const String& other)
{
	m_size = other.m_size;
	m_Buffer = std::make_unique<char[]>(m_size + 1);
	memcpy(m_Buffer.get(), other.m_Buffer.get(), m_size + 1);
	return *this;
}

String& Util::String::operator=(String&& other) noexcept
{
	m_Buffer = std::move(other.m_Buffer);
	m_size = other.m_size;
	return *this;
};

bool Util::operator==(const String& str1, const String& str2) noexcept
{
	return (*(str1.m_Buffer.get()) == *(str2.m_Buffer.get()));
}

bool Util::operator!=(const String& str1, const String& str2) noexcept
{
	return (*(str1.m_Buffer.get()) != *(str2.m_Buffer.get()));
}

char& Util::String::operator[](size_t index) const
{
	if (index >= m_size || index < 0)
	{
		throw StringException{ "Index out bound" };
	}
	return m_Buffer.get()[index];
}

std::ostream& Util::operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_Buffer.get();
	return stream;
}


const char* String::getCStyleString() const{
	char* newBuffer = new char[m_size + 1];
	memcpy(newBuffer, m_Buffer.get(), m_size + 1);
	return newBuffer;
}