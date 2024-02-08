#include <iostream>
#include "..\include\String.h"
#include <stdio.h>

using Util::String;


String::String(const char *str) : m_size(strlen(str))
{
	m_Buffer = new char[m_size + 1];
	memcpy(m_Buffer, str, m_size);
	m_Buffer[m_size] = '\0';
}

String::String(const String &other) : m_size(other.m_size)
{
	m_Buffer = new char[other.m_size + 1];
	memcpy(m_Buffer, other.m_Buffer, m_size + 1);
}

String::String(String &&other) noexcept
	: m_Buffer{other.m_Buffer}, m_size{other.m_size}
{
	other.m_Buffer = nullptr;
	other.m_size = 0;
}

size_t String::length() const
{
	return m_size;
}

bool String::empty() const
{
	if (m_size == 0)
		return true;
	return false;
};

size_t String::indexOf(char character) const
{

	auto i{0};
	while (i < m_size)
	{
		if (m_Buffer[i] == character)
		{
			return i;
		}
		++i;
	}

}

String String::substring(size_t index, size_t size) const
{	
	
	if (size == -1)
	{
		size = m_size;
	}

	if(index >= m_size || index < 0)
	{

	}
	

	auto *newBuffer = new char[size + 1];

	memcpy(newBuffer, m_Buffer + index, size);

	newBuffer[size] = '\0';

	String result{newBuffer};

	delete[] newBuffer;

	return result;
};

String String::toString(int num)
{

	if (num == 0)
	{
		return {"0"};
	}

	auto size{0};
	auto temp{num};

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

	auto *newBuffer = new char[size + 1];
	newBuffer[size] = '\0';

	if (num < 0)
	{
		newBuffer[0] = '-';
		num = -num;
	}

	auto i{size - 1};
	while (num > 0)
	{
		newBuffer[i] = num % 10 + '0';
		num /= 10;
		i--;
	}

	String result{newBuffer};

	delete[] newBuffer;
	newBuffer = nullptr;

	return result;
}

String &String::append(const String &other)
{
	auto *newBuffer = new char[m_size + other.m_size + 1];

	memcpy(newBuffer, m_Buffer, m_size);
	memcpy(newBuffer + m_size, other.m_Buffer, other.m_size + 1);

	delete[] m_Buffer;
	m_Buffer = nullptr;

	m_Buffer = newBuffer;
	m_size = m_size + other.m_size;

	return *this;
}

String String::reverse() const
{
	auto *newBuffer = new char[m_size + 1];

	for (auto i{0}; i < m_size; i++)
	{
		newBuffer[i] = m_Buffer[m_size - i - 1];
	}
	newBuffer[m_size] = '\0';

	String result{newBuffer};

	delete[] newBuffer;
	newBuffer = nullptr;

	return result;
};

String &String::toUpperCase()
{
	auto i{0};
	while (m_Buffer[i] != 0)
	{
		if (m_Buffer[i] >= 'a' && m_Buffer[i] <= 'z')
		{
			m_Buffer[i] = m_Buffer[i] - 32;
		}

		++i;
	}
	return *this;
};
String &String::toLowerCase()
{
	auto i{0};
	while (m_Buffer[i] != 0)
	{
		if (m_Buffer[i] >= 'A' && m_Buffer[i] <= 'Z')
		{
			m_Buffer[i] = m_Buffer[i] + 32;
		}
		++i;
	}

	return *this;
};

String Util::operator+(const String &str1, const String &str2)
{
	auto *newBuffer = new char[str1.m_size + str2.m_size + 1];

	memcpy(newBuffer, str1.m_Buffer, str1.m_size);
	memcpy(newBuffer + str1.m_size, str2.m_Buffer, str2.m_size + 1);

	String result{newBuffer};

	delete[] newBuffer;
	newBuffer = nullptr;

	return result;
}

String &String::operator=(const String &other)
{
	m_size = other.m_size;
	m_Buffer = new char[m_size + 1];
	memcpy(m_Buffer, other.m_Buffer, m_size + 1);
	return *this;
}

String &String::operator=(String &&other) noexcept
{

	delete[] m_Buffer;

	m_Buffer = other.m_Buffer;
	m_size = other.m_size;

	other.m_Buffer = nullptr;
	other.m_size = 0;

	return *this;
};

bool Util::operator==(const String &str1, const String &str2)
{
	return (*(str1.m_Buffer) == *(str2.m_Buffer));
}

bool Util::operator!=(const String &str1, const String &str2)
{
	return (*(str1.m_Buffer) != *(str2.m_Buffer));
}

char &String::operator[](size_t index) const
{

	if(index >= m_size || index < 0)
	{
		
	}
	return m_Buffer[index];
}

std::ostream &Util::operator<<(std::ostream &stream, const String &string)
{
	stream << string.m_Buffer;
	return stream;
}
