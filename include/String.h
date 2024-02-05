#ifndef STRING
#define STRING

#include <cstring>
#include <iostream>

namespace Util
{
	class String
	{

	private:
		char* m_Buffer;
		size_t m_size;

	public:
		static const size_t eos = -1;
		static String toString(int num);

		String(const char* str = "");
		String(const String& other);
		String(String&& other) noexcept;

		bool empty() const;
		size_t length() const;
		size_t indexOf(char character) const;
		String substring(size_t index = 0, size_t size = eos) const;
		String reverse() const;
		String& append(const String &other);
		String& toUpperCase();
		String& toLowerCase();

		String &operator=(const String &other);
		String &operator=(String &&other) noexcept;
		char &operator[](size_t index) const;

		friend String operator+(const String& str1, const String& str2);
		friend bool operator==(const String& str1, const String& str2);
		friend bool operator!=(const String& str1, const String& str2);
		friend std::ostream& operator<<(std::ostream& stream, const String& string);

		~String()
		{
			delete[] m_Buffer;
		}
	};

	String operator+(const String& str1, const String& str2);
	bool operator==(const String& str1, const String& str2);
	bool operator!=(const String& str1, const String& str2);
	std::ostream& operator<<(std::ostream& stream, const String& string);

}

#endif